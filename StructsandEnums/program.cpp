#include "splashkit.h"
#include <string>
#include "header.h"

using namespace std;

knight_data read_knight()
{
    knight_data result;

    result.name = read_string("Enter name: ");
    result.age = read_integer("Enter age: ");
    result.quest = read_string("Enter your quest: ");
    result.color = read_string("Enter your favorite color: ");

    return result;
}

void write_knight(const knight_data &knight)
{
    write_line("Hello " + knight.name + " aged " + to_string(knight.age));
    write_line("Your quest is: " + knight.quest);
    write_line("Your favorite color is: " + knight.color);
}

knight_update_option read_knight_update_option()
{
    int result;
    write_line("1. Update name");
    write_line("2: Update age");
    write_line("3. Update quest");
    write_line("4. Update color");
    write_line("5. Finish update");
    result = read_integer("Select an option: ");

    return static_cast<knight_update_option>(result - 1);
}

kingdom_update_option read_kingdom_update_option()
{
    int result;
    write_line("Here are your options: ");
    write_line();
    write_line("1. Add knight");
    write_line("2. Select knight");
    write_line("3. Delete knight");
    write_line("4. Display knight");
    write_line("5. Update knight");
    write_line("6. Finish");
    result = read_integer("Select an option: ");

    return static_cast<kingdom_update_option>(result - 1);
}

void update_knight(kingdom_data &kingdom)
{
    string update_knight_name;
    update_knight_name = read_string("What is the name of the knight you would like to update: ");

    for (int i = 0; i < kingdom.knights.size(); i = i + 1)
    {
        if (kingdom.knights[i].name == update_knight_name)
        {
            knight_update_option option;

            do
            {
                write_line();
                write_line("=== Update Knight ===");
                write_line("Current data is:");
                write_knight(kingdom.knights[i]);
                write_line();

                option = read_knight_update_option();

                switch (option)
                {
                case UPDATE_NAME:
                    kingdom.knights[i].name = read_string("Enter new name: ");
                    break;
                case UPDATE_AGE:
                    kingdom.knights[i].age = read_integer("Enter new age: ");
                    break;
                case UPDATE_QUEST:
                    kingdom.knights[i].quest = read_string("Enter new quest: ");
                    break;
                case UPDATE_COLOR:
                    kingdom.knights[i].color = read_string("Enter new favorite color: ");
                    break;
                case FINISH_UPDATE:
                    break;
                default:
                    write_line("PLease enter valid choice");
                    break;
                }
            } while (option != FINISH_UPDATE);
        }
    }
}

void add_knight(kingdom_data &kingdom)
{
    int no_of_knights = read_integer("How many knights would you like to add to your kingdom?: ");
    int i = 0;
    while (i < no_of_knights)
    {
        knight_data new_knight;
        new_knight = read_knight();
        kingdom.knights.push_back(new_knight);
        i = i + 1;
    }
}

void write_kingdom(const kingdom_data &kingdom)
{
    write_line();
    write_line("====" + kingdom.name + "====");
    write_line();

    write_line("=== Knights ===");
    for (int i = 0; i < kingdom.knights.size(); i = i + 1)
    {
        write_knight(kingdom.knights[i]);
    }
    write_line();
}

void delete_knight(kingdom_data &kingdom)
{
    int pos = read_integer("Which position would you like to delete: ") - 1;

    if (pos >= 0 and pos < kingdom.knights.size())
    {
        int last_index;
        last_index = kingdom.knights.size() - 1;
        kingdom.knights[pos] = kingdom.knights[last_index];
        kingdom.knights.pop_back();
    }
}

kingdom_data read_kingdom()
{
    kingdom_data result;
    result.name = read_string("Enter kingdom name: ");
    return result;
}

int select_knight(const kingdom_data &kingdom)
{
    for (int i = 0; i < kingdom.knights.size(); i = i + 1)
    {
        write_knight(kingdom.knights[i]);
    }
    write_line();

    int select = read_integer("Enter the index that you want to select: ");
    if (select >=0 and select < kingdom.knights.size())
    {
        return select;
    }
    write_line();

    return -1;
}

void select_knight_display(const kingdom_data &kingdom)
{
    int k = 0;
    k = select_knight(kingdom);
    if (k > 0)
    {
        write_knight(kingdom.knights[k]);
    }
    else if (k < 0)
    {
        write_line("Index not found");
    }
}

void update_kingdom(kingdom_data &kingdom)
{
    kingdom_update_option option;

    do
    {
        option = read_kingdom_update_option();

        switch (option)
        {
        case ADD_KNIGHT:
            add_knight(kingdom);
            break;
        case SELECT_KNIGHT:
            select_knight_display(kingdom);
            break;
        case DELETE_KNIGHT:
            delete_knight(kingdom);
            write_kingdom(kingdom);
            break;
        case DISPLAY_KNIGHT:
            write_kingdom(kingdom);
            break;
        case UPDATE_KNIGHT:
            update_knight(kingdom);
            write_kingdom(kingdom);
            break;
        case FINISH:
            break;
        default:
            write_line("Please enter a valid choice");
            break;
        }
    } while (option != FINISH);
}

int main()
{
    kingdom_data my_kingdom = read_kingdom();
    write_line();

    update_kingdom(my_kingdom);

    write_line();

    write_line("I wish your kingdom all the best!!");

    return 0;
}

/*
knight_data my_knight;
my_knight = read_knight();
write_knight(my_knight);
update_knight(my_knight);
write_line("Your final knight data is: ");
write_knight(my_knight); 
*/