/*
** EPITECH PROJECT, 2023
** my_sort_int_array
** File description:
** task06
*/

static void my_sort_int_array_loop(int *array, int size)
{
    int temp;

    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
        }
    }
}

static int is_int_array_sorted(int *array, int size)
{
    for (int i = 0; i < size - 1; i++) {
        if (array[i] > array[i + 1]) {
            return 0;
        }
    }
    return 1;
}

void my_sort_int_array(int *array, int size)
{
    while (!is_int_array_sorted(array, size)) {
        my_sort_int_array_loop(array, size);
    }
}
