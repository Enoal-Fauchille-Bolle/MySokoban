/*
** EPITECH PROJECT, 2023
** my_strcapitalize
** File description:
** task10
*/

char *my_strcapitalize(char *str)
{
    if (str[0] >= 'a' && str[0] <= 'z') {
        str[0] = str[0] - 32;
    }
    return str;
}
