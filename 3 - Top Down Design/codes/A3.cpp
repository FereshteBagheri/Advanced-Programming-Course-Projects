#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

#define SIXTY 60
#define TEN 10

struct translator {
    string name;
    int start_time;
    int end_time;
    vector <string> languages;
    int language_number;
};

struct event {
    string name;
    int start_time;
    int end_time;
    vector <string> languages;
    vector < vector<int>> available_translators;
    vector <int> language_selection_order;
    vector <int> chosen_tranlators;
};

struct Time {
    int hour;
    int minute;
};

void split_string(string& input, vector <string>& output, char delimiter) {
    stringstream s(input);
    string temp;
    while (getline(s, temp, delimiter)) {
        output.push_back(temp);
    }
}

vector <string> read_lines_from_file(char* argv[]) {
    vector <string> lines;
    string temp;
    ifstream my_file;
    my_file.open(argv[1]);
    if (my_file.is_open()) {
        while (getline(my_file, temp)) {
            lines.push_back(temp);
        }
        my_file.close();
    }
    return lines;
}

int convert_to_minute(string time_hhmm_format) {
    vector <string> temp;
    Time time_in_int;
    split_string(time_hhmm_format, temp, ':');
    time_in_int.hour = stoi(temp[0]);
    time_in_int.minute = stoi(temp[1]);
    return (time_in_int.hour * SIXTY) + time_in_int.minute;
}

void split_line_to_translator(string line, translator& translator) {
    vector <string> temp;
    split_string(line, temp, ' ');
    translator.name = temp[0];
    translator.start_time = convert_to_minute(temp[1]);
    translator.end_time = convert_to_minute(temp[2]);
    for (int i = 3; i < temp.size(); i++) {
        translator.languages.push_back(temp[i]);
    }
    translator.language_number = translator.languages.size();
    temp.clear();
}

void split_line_to_event(string line, event& event) {
    vector <string> temp;
    split_string(line, temp, ' ');
    event.name = temp[0];
    event.start_time = convert_to_minute(temp[1]);
    event.end_time = convert_to_minute(temp[2]);
    for (int i = 3; i < temp.size(); i++) {
        event.languages.push_back(temp[i]);
    }
    temp.clear();
}

void save_information(vector <translator>& translators, vector <event>& events, vector <string> lines) {
    int n = stoi(lines[0]);
    int k = stoi(lines[n + 1]);
    translator temp1;
    for (int i = 0; i < n; i++) {
        translators.push_back(temp1);
    }
    event temp2;
    for (int i = 0; i < k; i++) {
        events.push_back(temp2);
    }
    for (int i = 0; i < n; i++) {
        split_line_to_translator(lines[i + 1], translators[i]);
    }
    for (int j = 0; j < k; j++) {
        split_line_to_event(lines[j + (n + 2)], events[j]);
    }
}

int find_available_translators(event& event,string language, vector <int>& available_translators, vector <translator> translators) {
    int translator_count=0;
    for (int i = 0; i < translators.size(); i++) {
        for (int j = 0; j < translators[i].language_number; j++) {
            if (language == translators[i].languages[j]) {
                translator_count += 1;
                available_translators.push_back(i);
                break;
            }
        }
    }
    for (int i = 0; i < available_translators.size(); i++) {
       if (!(event.start_time >= translators[available_translators[i]].start_time && event.end_time <= translators[available_translators[i]].end_time)) {
            available_translators.erase(available_translators.begin() + i);
            i -= 1;
        }
    }
    return translator_count;
}

void swap(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

vector <int> sort_by_indexes(vector <int> code) {
    vector <int> sorted_by_index;
    for (int i = 0; i < code.size(); i++) {
        sorted_by_index.push_back(i);
    }
    for (int i = 0; i < sorted_by_index.size(); i++) {
        for (int j = 0; j < sorted_by_index.size() - i - 1; j++) {
            if (code[j] > code[j + 1]) {
                swap(sorted_by_index[j], sorted_by_index[j + 1]);
                swap(code[j], code[j + 1]);

            }
        }
    }
    return sorted_by_index;
}

void languages_selection_order(vector <event>& events, vector <translator> translators) {
    vector <vector<int>> code;
    for (int i = 0; i < events.size(); i++) {
        code.push_back(vector <int>());
    }
    for (int i = 0; i < events.size(); i++) {
        for (int j = 0; j < events[i].languages.size(); j++) {
            code[i].push_back(  (find_available_translators(events[i], events[i].languages[j], events[i].available_translators[j], translators)*TEN)+j);
        }
    }
    for (int i = 0; i < events.size(); i++) {
        events[i].language_selection_order = sort_by_indexes(code[i]);
    }
}

int choose_translator(vector <int>& available_translators, vector <translator> translators) {
    if (available_translators.size() == 0)
        return -1;
    else {
        for (int i = 0; i < available_translators.size(); i++) {
            for (int j = 0; j < available_translators.size(); j++) {
                if (translators[available_translators[i]].language_number > translators[available_translators[j]].language_number) {
                    available_translators.erase(available_translators.begin() + i);
                    i -= 1;
                    break;
                }
            }
        }
        if (available_translators.size() > 1) {
            for (int i = 0; i < available_translators.size(); i++) {
                for (int j = 0; j < available_translators.size(); j++) {
                    if (translators[available_translators[i]].name > translators[available_translators[j]].name) {
                        available_translators.erase(available_translators.begin() + i);
                       i -= 1;
                        break;
                    }
                }
            }
        }
        return available_translators[0];
    }
}

void delete_repeated_translators(vector <int> chosen_translators, vector <int>& available_translators) {
    for (int i = 0; i < chosen_translators.size(); i++) {
        for (int j = 0; j < available_translators.size(); j++) {
            if (chosen_translators[i] == available_translators[j]) {
                available_translators.erase(available_translators.begin() + j);
                break;
            }
        }
    }
}

void set_event(event& event, vector <translator> translators) {
    vector <int> disorderly_chosen_translators;
    for (int i = 0; i < event.languages.size(); i++) {
        if (i > 0) {
            delete_repeated_translators(disorderly_chosen_translators, event.available_translators[event.language_selection_order[i]]);
        }
        disorderly_chosen_translators.push_back(choose_translator(event.available_translators[event.language_selection_order[i]], translators));
    }
    for (int i = 0; i < event.languages.size(); i++) {
        event.chosen_tranlators.push_back(-2);
    }
    for (int i = 0; i < disorderly_chosen_translators.size(); i++) {
        event.chosen_tranlators[event.language_selection_order[i]] = disorderly_chosen_translators[i];
    }
}

void interference_check(event event1, event& event2) {
    if ((event1.start_time <= event2.start_time && event2.start_time < event1.end_time) || (event1.start_time < event2.end_time && event2.end_time <= event1.end_time)
        || (event2.start_time < event1.start_time && event1.start_time <= event2.end_time) || (event2.start_time < event1.end_time && event1.end_time <= event2.end_time)) {
        for (int i = 0; i < event1.chosen_tranlators.size(); i++) {
            for (int j = 0; j < event2.available_translators.size(); j++) {
                for (int k = 0; k < event2.available_translators[j].size(); k++) {
                    if (event1.chosen_tranlators[i] == event2.available_translators[j][k]) {
                        event2.available_translators[j].erase(event2.available_translators[j].begin() + k);
                        break;
                    }
                }
            }
        }
    }
}

void final_planning(vector <event>& events, vector <translator> tranlators) {
    for (int i = 0; i < events.size(); i++) {
        if (i > 0) {
            for (int j = 0; j < i; j++) {
                interference_check(events[j], events[i]);
            }
        }
        set_event(events[i],tranlators);
    }
}

void print_schedule(vector <event> events, vector <translator> translators) {
    int temp;
    for (int i = 0; i < events.size(); i++) {
        cout << events[i].name << endl;
        for (int j = 0; j < events[i].languages.size(); j++) {
            cout << events[i].languages[j] << ": ";
            temp = events[i].chosen_tranlators[j];
            if (temp == -1)
                cout << "Not Found" << endl;
            else
                cout << translators[temp].name << endl;
        }
    }
}

int main(int argc, char* argv[]) {
    vector <string> lines = read_lines_from_file(argv);
    vector <translator> translators;
    vector <event> events;
    save_information(translators, events,lines);
    for (int i = 0; i < events.size(); i++) {
        for (int j = 0; j < events[i].languages.size(); j++) {
            events[i].available_translators.push_back(vector <int>());
        }
    }
   languages_selection_order(events, translators);
   final_planning(events, translators);
   print_schedule(events,  translators);
    return 0;
}