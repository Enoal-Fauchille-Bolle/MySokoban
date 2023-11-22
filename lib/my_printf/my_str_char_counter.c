/*
** EPITECH PROJECT, 2023
** my_str_char_counter
** File description:
** Counts chars in a string
*/

int my_str_char_counter(char c, char *str)
{
    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            counter++;
    }
    return counter;
}
