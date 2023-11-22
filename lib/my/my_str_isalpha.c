/*
** EPITECH PROJECT, 2023
** my_str_isalpha
** File description:
** task12
*/

static int is_uppercase(char c)
{
    return c >= 'A' && c <= 'Z';
}

static int is_lowercase(char c)
{
    return c >= 'a' && c <= 'z';
}

int my_str_isalpha(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (!is_lowercase(str[i]) && !is_uppercase(str[i])) {
            return 0;
        }
        i++;
    }
    return 1;
}
