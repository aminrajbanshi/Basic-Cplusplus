#include "splashkit.h"

#define NUM_VALS 100

void draw_values(const int values[], int size)
{
    int x = 0;
    int y;
    int rect_height;
    int rect_width = screen_width() / size;

    for (int i = 0; i < size; i = i + 1)
    {
        rect_height = values[i];
        y = screen_height() - rect_height;

        fill_rectangle(COLOR_RED, x, y, rect_width, rect_height);
        draw_rectangle(COLOR_WHITE, x, y, rect_width, rect_height);

        x = x + rect_width;
    }
}

void draw_sort(int values[], int size)
{
    clear_screen(COLOR_WHITE);
    draw_values(values, size);
    refresh_screen(60);
}

void swap(int &value1, int &value2)
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}

void bubble_sort(int values[], int size)
{
    for (int j = 0; j < size; j = j + 1)
    {
        for (int i = 0; i < size - 1; i = i + 1)
        {
            if (values[i] > values[i + 1])
            {
                swap(values[i], values[i + 1]);
                draw_sort(values, size);
            }
        }
    }
}

int partition(int values[], int first_index, int last_index, int size)
{
    int pivot = values[first_index];
    int i = first_index;
    int j = last_index;

    for (int a = 0; a < last_index; a = a + 1)
    {
        while (i < j)
        {
            do
            {
                i = i + 1;
            } while (values[i] <= pivot);

            do
            {
                j = j - 1;
            } while (values[j] > pivot);

            if (i < j)
            {
                swap(values[i], values[j]);
            }
        }
    }
    swap(values[first_index], values[j]);
    draw_sort(values, size);
    return j;
}

void quick_sort(int values[], int first_index, int last_index, int size)
{
    if (first_index < last_index)
    {
        int m = partition(values, first_index, last_index, size);
        quick_sort(values, first_index, m, size);
        quick_sort(values, m + 1, last_index, size);
    }
}

void random_fill_array(int values[], int size)
{
    for (int i = 0; i < size; i = i + 1)
    {
        values[i] = rnd(screen_height()) + 1;
    }
}

void handle_input(int values[], int size)
{
    if (key_typed(A_KEY))
    {
        random_fill_array(values, size);
    }
    else if (key_typed(S_KEY))
    {
        bubble_sort(values, size);
    }
    else if (key_typed(D_KEY))
    {
        int first_index = 0;
        int last_index = size;
        quick_sort(values, first_index, last_index, size);
    }
}

int main()
{
    int values[NUM_VALS];

    open_window("Sort Visualiser", 800, 600);

    random_fill_array(values, NUM_VALS);

    while (not quit_requested())
    {
        process_events();
        handle_input(values, NUM_VALS);
        draw_sort(values, NUM_VALS);
    }

    return 0;
}