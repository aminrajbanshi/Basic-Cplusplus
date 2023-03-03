#include "splashkit.h"
#include "terminal_user_input.h"

#include <vector>
using std::vector;

using namespace std;

int total_length(const vector<string> &names)
{
    int result = 0;
    int x;
    string name;

    x = 0;

    for (x = 0; x < names.size(); x = x + 1)
    {
        name = names[x];
        result = result + name.length();
    }

    return result;
}

void print_summary(const vector<string> &names)
{
    int y = 0;
    int length = 0;
    string name;
    for (y = 0; y < names.size(); y = y + 1)
    {
        name = names[y];
        length = name.length();
        write_line("Name: " + name + " | Length: " + to_string(length));
    }
}

bool contains(const vector<string> &names, string name)
{
    for (int i = 0; i < names.size(); i = i + 1)
    {
        if (to_lowercase(names[i]) == to_lowercase(name))
        {
            return true;
        }
    }
    return false;
}

string shortest_name(const vector<string> &names)
{
    string min;
    min = names[0];

    for (int i = 1; i < names.size(); i = i + 1)
    {
        if (min.length() > names[i].length())
        {
            min = names[i];
        }
    }
    return min;
}

int index_of(const vector<string> &names)
{
    string name_to_search;
    name_to_search = read_string("Enter name to search: ");

    for (int i = 0; i < names.size(); i = i + 1)
    {
        if (to_lowercase(names[i]) == to_lowercase(name_to_search))
        {
            return i;
        }
    }

    return -1;
}

int change_name(const vector<string> &names)
{
    string name_to_change;
    string retry;
    name_to_change = read_string("Enter the name you want to change: ");
    do
    {

        for (int i = 0; i < names.size(); i = i + 1)
        {
            if (to_lowercase(names[i]) == to_lowercase(name_to_change))
            {
                return i;
            }
        }

        write_line("Name entered was not found");

        retry = read_string("Do you want to change names again?: ");

    } while (trim(to_lowercase(retry)) == "yes" or trim(to_lowercase(retry)) == "y");
    return -1;
}

void print_reverse(const vector<string> &names)
{
    for (int i = names.size() - 1; i >= 0; i = i - 1)
    {
        write_line(names[i]);
    }
}

int main()
{
    vector<string> names;
    int i, no_of_data;
    int total;

    no_of_data = read_integer("How many values would you like to enter?: ");

    i = 0;
    while (i < no_of_data)
    {
        names.push_back(read_string("Enter a name: "));
        i = i + 1;
    }

    i = 0;
    for (i = 0; i < names.size(); i = i + 1)
    {
        write_line(names[i]);
    }

    total = total_length(names);
    write_line("Total length of all names : " + to_string(total));

    print_summary(names);

    bool has_andrew;
    has_andrew = contains(names, "andrew");

    if (has_andrew)
    {
        write_line("Contains Andrew");
    }

    write_line("The shortest name is : " + shortest_name(names));

    int index_no;
    index_no = index_of(names);
    if (index_no == -1)
    {
        write_line("Name couldn't be found");
    }
    else
    {
        write_line("Name is in " + to_string(index_no + 1) + " position");
    }

    string edit_list;
    string new_name;
    int new_name_index;
    edit_list = read_string("Do you want to change a name in the list?: ");
    if (trim(to_lowercase(edit_list)) == "yes" or trim(to_lowercase(edit_list)) == "y")
    {
        new_name_index = change_name(names);
        if (new_name_index != -1)
        {
            new_name = read_string("Enter new name: ");
            names[new_name_index] = new_name;
        }
    }

    write_line("The new list: ");
    print_summary(names);

    write_line("List in reverse: ");
    print_reverse(names);

    write_line("The End");

    return 0;
}