/*
** EPITECH PROJECT, 2023
** my_str_include
** File description:
** Returns if a string includes a character
*/

int my_str_include(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            return 1;
    }
    return 0;
}
