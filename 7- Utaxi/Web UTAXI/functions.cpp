#include "functions.hpp"

vector<string> read_lines_from_file(char *argv[])
{
    vector<string> lines;
    string temp;
    ifstream my_file;
    my_file.open(argv[1]);
    if (my_file.is_open())
    {
        while (getline(my_file, temp))
        {
            lines.push_back(temp);
        }
        my_file.close();
    }
    return lines;
}

vector<string> split_string(string &input, char delimiter)
{
    stringstream s(input);
    string temp;
    vector<string> output;
    while (getline(s, temp, delimiter))
    {
        output.push_back(temp);
    }
    return output;
}

vector<Location> save_locations(char *argv[])
{
    vector<string> lines = read_lines_from_file(argv);
    vector<Location> locations;

    for (int i = 1; i < lines.size(); i++)
    {
        locations.push_back(Location(split_string(lines[i], ',')));
    }
    return locations;
}