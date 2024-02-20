#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

#define START_TIME_MINUTE 0
#define END_TIME_MINUTE 480
#define START_HOUR 12
#define END_HOUR 20

void split_string(string& input, vector <string>& output , char delimiter){
    stringstream s(input);
    string temp;
    while (getline(s, temp, delimiter)){
        output.push_back(temp);
    }
}

vector <string> record_events(int& events_number) {
    string temp;
    vector <string> lines;
    while (getline(cin, temp)) {
        if (temp == "#")
            break;
        lines.push_back(temp);
        events_number += 1;
    }
    return lines;
}

vector <vector <string>> split_events( int& events_number) {
    vector <vector <string>> events;
    vector <string> lines = record_events(events_number);
    vector <string> temp;
    for (int i = 0; i < events_number; i++)
        events.push_back(vector<string>());

    for (int i = 0; i < lines.size(); i++) {
        split_string(lines[i], temp, '-');
        split_string(temp[0], events[i], ':');
        split_string(temp[1], events[i], ':');
        temp.clear();
    }
    return events;
}

vector <vector<int>> convert_to_int(int& events_number){
    vector <vector <string>> events = split_events(events_number);
    vector <vector<int>> events_in_integer;
    for (int i = 0; i < events_number; i++)
        events_in_integer.push_back(vector <int>());
    for (int i = 0; i < events_number; i++) {
        events_in_integer[i].push_back(stoi(events[i][0]));
        events_in_integer[i].push_back(stoi(events[i][1]));
        events_in_integer[i].push_back(stoi(events[i][2]));
        events_in_integer[i].push_back(stoi(events[i][3]));
    }
    return events_in_integer;
}
void convert_to_minute(vector <vector<int>> events_in_integer,vector <vector<int>>& events_in_minute,int& events_number ) {
     for (int i = 0; i < events_number; i++)
         events_in_minute.push_back(vector <int>());
     for (int i = 0; i < events_number; i++) {
         events_in_minute[i].push_back((events_in_integer[i][0] - START_HOUR) * 60 + events_in_integer[i][1]);
         events_in_minute[i].push_back((events_in_integer[i][2] - START_HOUR) * 60 + events_in_integer[i][3]);
     }
}

void empty_time_check(vector <vector<int>>& empty_times, int& empty_times_number){
    for (int i = 0; i < empty_times.size(); i++) {
        if (empty_times[i][0] == empty_times[i][1]) {
            empty_times.erase(empty_times.begin() + i);
            i -= 1;
        }
    }
    empty_times_number = empty_times.size();
}

void calculate_empty_time(vector <vector<int>> events_in_minute,vector <vector<int>>& empty_times,int events_number,int &empty_times_number) {
    for (int i = 0; i < events_number + 1; i++){
        empty_times.push_back(vector <int>());
    }
    empty_times[0].push_back(START_TIME_MINUTE);
    empty_times[0].push_back(events_in_minute[0][0]);
    for (int i = 0; i < events_number - 1; i++) {
        empty_times[i+1].push_back(events_in_minute[i][1]);
        empty_times[i + 1].push_back(events_in_minute[i+1][0]);
    }
    empty_times[events_number].push_back(events_in_minute[events_number-1][1]);
    empty_times[events_number].push_back(END_TIME_MINUTE);
    empty_time_check(empty_times, empty_times_number);
}

void record_tasks(vector <vector<int>>& tasks) {
    string temp;
    vector <string> lines;
    while (getline(cin, temp)) {
        lines.push_back(temp);
    }
    vector <vector<string>> tasks_temp;
    for (int i = 0; i < lines.size(); i++) {
        tasks_temp.push_back(vector<string>());
    }
    for (int i = 0; i < lines.size(); i++) {
        split_string(lines[i], tasks_temp[i], ' ');
    }
    for (int i = 0; i < tasks_temp.size(); i++) {
        tasks.push_back(vector<int>());
    }
    for (int i = 0; i < tasks_temp.size(); i++) {
        tasks[i].push_back(stoi(tasks_temp[i][0]));
        tasks[i].push_back(stoi(tasks_temp[i][1]));
    }
}

void convert_to_hour(int  time) {
    int minute = time % 60;
    int hour = (time / 60) + START_HOUR;
    cout << hour << ":";
    cout << setfill('0') << setw(2) << minute;
}

void planning(vector <vector<int>>& tasks, vector <vector<int>>& empty_times,vector<vector<int>>& final_plan) {
    for (int i = 0; i < tasks.size(); i++){
        final_plan.push_back(vector<int>());
    }
    for (int i = 0; i < tasks.size(); i++) {
        final_plan[i].push_back(empty_times[tasks[i][1] - 1][0]);
        final_plan[i].push_back(empty_times[tasks[i][1] - 1][0]+tasks[i][0]);
        empty_times[tasks[i][1] - 1][0] += tasks[i][0];
    }
    for (int i = 0; i < final_plan.size(); i++) {
        cout << i + 1 << " ";
        convert_to_hour(final_plan[i][0]);
        cout << "-";
        convert_to_hour(final_plan[i][1]);
        cout << endl;
    }
}

int main() {
    int events_number = 0;
    vector <vector<int>> events_in_minute;
    vector <vector<int>> empty_times;
    int empty_times_number;
    vector <vector<int>> tasks;
    vector<vector<int>> final_plan;
    vector <vector<int>> events_in_integer = convert_to_int(events_number);
    convert_to_minute(events_in_integer, events_in_minute, events_number);
    calculate_empty_time(events_in_minute, empty_times, events_number, empty_times_number);
    record_tasks(tasks);
    planning(tasks, empty_times, final_plan);
	return 0;
}