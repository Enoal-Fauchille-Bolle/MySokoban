/*
** EPITECH PROJECT, 2023
** my_str_isnum
** File description:
** task13
*/

static int is_number(char c)
{
    return c >= '0' && c <= '9';
}

int my_str_isnum(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!is_number(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}
