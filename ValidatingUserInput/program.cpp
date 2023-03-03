#include "splashkit.h"
#include "terminal_user_input.h"

using namespace std;

#define STOUHAL 0.33

double air_speed(double freq, double amp)
{
    double result;
    result = freq * amp / STOUHAL;
    return result;
}

void output_air_speed(string name, double freq, double amp)
{
    write(name + ": ");
    write_line(air_speed(freq, amp));
}

int main()
{
    string name, birdname;
    bool choice1;
    int age, choice, test1, test2;
    double birdfreq, birdamp;
    name = read_string("What is your name?: ");
    age = read_integer("What is your age?: ");
    write_line();
    write_line("Here is your menu: ");
    write_line();
    write_line("1. Calculate Air Speed Velocity for African Swallow");
    write_line("2. Calculate Air Speed Velocity for European Swallow");
    write_line("3. Calculate Air Speed Velocity of the bird of your choice");
    write_line("4. Exit");
    write_line();

    do
    {
        write_line();
        choice = read_integer("Hi " + name + ", What would you like to do today?(1, 2, 3 or 4): ");
        switch (choice)
        {
        case 1:
            write_line();
            output_air_speed("African Swallow", 15, 0.21);
            break;
        case 2:
            write_line();
            output_air_speed("European Swallow", 14, 0.22);
            break;
        case 3:
            write_line();
            birdname = read_string("What is the name of the Bird?: ");
            birdfreq = read_double("What is the frequency of this bird?: ");
            birdamp = read_double("What is the amplitude of this bird?: ");
            write_line();
            output_air_speed(birdname, birdfreq, birdamp);
            break;
        case 4:
            write_line();
            choice1 = read_boolean_ans("Are you sure you want to exit?: ");
            write_line();
            break;
        default:
            write("Please enter a valid choice");
            break;
        }

    } while (choice1 == false);

    write_line();
    write_line("Have a good day! " + name + " !");
    write_line();
    write_line("But before you go I need you to guess some numbers :)");
    write_line();
    test1 = read_integer_with_range("Enter first test value: ", 1, 10);
    write_line("Good number choice!");
    write_line();
    test2 = read_double_range("Enter second test value: ", 0.0, 1.0);
    write_line("You are awesome at entering numbers!!");

    return 0;
}