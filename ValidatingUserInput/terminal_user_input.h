#ifndef TERMINAL_USER_INPUT
#define TERMINAL_USER_INPUT

#include <string>
using std::string;

/**
 * Prompts the user for input and reads the text
 * that the user enters at the Terminal.
 * This will read in a line of text and return this 
 * as a string.
 * @param prompt = The message displayed to the user
 * @returns = The text the user enters
 */
string read_string(string prompt);

/**
 * Prompts the user for input and reads the string
 * that the user enters at the Terminal.
 * This will read in a line of string and return this
 * as an integer.
 * @param prompt = The message displayed to the user
 * @returns = The string the user enters
 */
int read_integer(string prompt);

/**
 * Prompts the user for input and reads the string that
 * the user enters at the terminal.
 * This will read in a line of string and also check
 * whether the user input lies between the minimum and maximum
 * integer or not and return this as an integer.
 * @param prompt = The message displayed to the user
 * @returns = The string the user enters if it correctly
 * lies within the minimum and maximum. If it does not then
 * it will ask to input again.
 */
int read_integer_with_range(string prompt, int min, int max);

/**
 * Prompts the user for input and reads the string that the user
 * enters at the terminal.
 * This will read in a line of string and
 * return this as a double.
 * @param prompy = The message displayed to the user
 * @returns = The string the user enters
 */
double read_double(string prompt);

/**
 * Prompts the user for input and reads the string
 * that the user enters at the terminal.
 * This will read in a line of string and also check whether
 * it lies between the minimum and maximum double
 * and return this as a double.
 * @param prompt = The message displayed to the user.
 * @returns = The string the user enters if it is correctly
 * in between the maximum and minimum double, if not
 * it will ask the user to input again.
 */
double read_double_range(string prompt, double min, double max);

/**
 * Prompts the user for input and reads the string that
 * the user enters at the terminal.
 * This will read in a line of string and also check
 * if it is a valid answer and return this as a boolean.
 * @param prompt = The message displayed to the user.
 * @returns = The string the user enters if it is a valid
 * answer, else will ask for user input again.
 */
bool read_boolean_ans(string prompt);

/**
 * Prompts the user for input and reads the string
 * that the user enters at the terminal.
 * This will read in a line of string and also check
 * if it matches with the given options, and return this
 * as a valid integer.
 * @param prompt = The message displayed to the user
 * @returns = The string the user enters, as long as it is a valid
 * string.
 */
//int read_choice(string prompt);

#endif