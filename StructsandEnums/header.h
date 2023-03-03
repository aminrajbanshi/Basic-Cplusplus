#include "splashkit.h"
#include <string>
#include <vector>

using namespace std;
using std::vector;

struct knight_data
{
    string name;
    int age;
    string quest;
    string color;
};

struct kingdom_data
{
    string name;
    vector<knight_data> knights;
};

enum knight_update_option
{
    UPDATE_NAME,
    UPDATE_AGE,
    UPDATE_QUEST,
    UPDATE_COLOR,
    FINISH_UPDATE
};

enum kingdom_update_option
{
    ADD_KNIGHT,
    SELECT_KNIGHT,
    DELETE_KNIGHT,
    DISPLAY_KNIGHT,
    UPDATE_KNIGHT,
    FINISH
};

string read_string(string prompt);

int read_integer(string prompt);
