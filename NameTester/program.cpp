#include "splashkit.h"

#define STOUHAL 0.33

double air_speed(double freq, double amp)
{
    double result;
    result = freq * amp / STOUHAL;
    return result;
}

void output_air_speed(string name, double freq, double amp)
{
    write(name + "; ");
    write_line(air_speed(freq, amp));
}

string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}

void test_user_details()
{
    string name;
    string line;
    int age;
    name = read_string("What is your name?: ");
    line = read_string("What is your age?: ");
    age = convert_to_integer(line);

    write_line("Hello " + name);

    if (to_lowercase(name) == "binod")
    {
        write_line("The entrepenuer Binod");
        write_line("He is the one and only billionaire from Nepal");
    }
    else if (to_lowercase(name) == "amin")
    {
        write_line("Oh! that's me...");
    }
    else if (to_lowercase(name) == "Muhammad")
    {
        write_line("That's the world's most common name!");
    }
    else
    {
        write_line("Do I know you?");
    }
    
    write("Age: ");
    write_line(age);   
}

void play_guess_that_number()
{
    string line;
    int guess;
    int target;
    target = rnd(100) + 1;
    write_line("I'm thinking of a number between 1 and 100");
    
    while (guess != target)
    {
        write("Enter your guess: ");
        line = read_line();
        guess = convert_to_integer(line);

        if (guess < target)
        {
            write_line("Sorry, my number is greater than " + std::to_string(guess));
        }
        else if (guess > target)
        {
            write_line("No, my number is less than " + std::to_string(guess));
        }       
    }
    write_line("WOW!.. you got it. My number was " + std::to_string(target));
}

int main()
{
    string line;
    int option;
    do
    {
        write_line("1. Test your name");
        write_line("2. Calculate Air Speed");
        write_line("3. Geuss that number");
        write_line("4. Quit");
        write("Choose option: ");

        line = read_line();
        option = convert_to_integer(line);

        switch(option)
        {
            case 1:
                test_user_details();
            break;
            case 2:
                output_air_speed("African Swallow", 15, 0.21);
                output_air_speed("European Swallow", 100, 0.10);
            break;
            case 3:
                play_guess_that_number();
            break;
            case 4:
                write_line("See you later..");
            break;
            default:
                write_line("Please enter a correct option");
            break;
        }
    } while (option != 4);    

    return 0;
}