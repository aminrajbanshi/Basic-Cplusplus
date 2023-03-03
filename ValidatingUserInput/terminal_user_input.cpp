#include "splashkit.h"
using namespace std;

string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}

int read_integer(string prompt)
{
    string line;
    int result;
    line = read_string(prompt);
    while (not is_integer(line))
    {
        write_line("Please enter a whole number");
        line = read_string(prompt);
    }
    result = convert_to_integer(line);
    return result;
}

int read_integer_with_range(string prompt, int min, int max)
{
    int result;
    result = read_integer(prompt);
    while (result < min or result > max)
    {
        write_line("Please enter a number between " + to_string(min) + " and " + to_string(max));
        result = read_integer(prompt);
    }
    return result;
}

double read_double(string prompt)
{
    string line;
    line = read_string(prompt);
    while (not is_double(line))
    {
        write_line("Please enter a valid number");
        line = read_string(prompt);
    }
    return convert_to_double(line);
}

double read_double_range(string prompt, double min, double max)
{
    double result;
    result = read_double(prompt);
    while (result < min or result > max)
    {
        write_line("Please enter a value between " + to_string(min) + " and " + to_string(max));
        result = read_double(prompt);
    }
    return result;
}

bool read_boolean_ans(string prompt)
{
    bool line;
    string result;
    result = read_string(prompt);
    while (trim(to_lowercase(result)) != "yes" and trim(to_lowercase(result)) != "y" and trim(to_lowercase(result)) != "no" and trim(to_lowercase(result)) != "n")
    {
        write_line("Plese enter a valid answer");
        result = read_string(prompt);
    }
    if (trim(to_lowercase(result)) == "yes" or trim(to_lowercase(result)) == "y")
    {
        line = true;
    }
    else
    {
        line = false;
    }
    return line;
}

//int read_choice(string prompt)
//{
    //int result;
    //string line;
    //line = read_string(prompt);
    //while (not is_integer(line))
    //{
        //write_line("Please enter a valid choice");
        //line = read_string(prompt);
    //}
    //result = convert_to_integer(line);
    //return result;
//}