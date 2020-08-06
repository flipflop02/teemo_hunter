/*
** EPITECH PROJECT, 2019
** my_getnbr
** File description:
** returns number sent in the function as a string
*/

long long transform(char const *str)
{
    int i = 0;
    long long ret = 0;
    while (str[i] != '\0'){
        ret = ret * 10 + str[i] - 48;
        i++;
    }
    return ret;
}

int set_sign(char const *str)
{
    int i = 0;
    int neg = 0;
    while (str[i] < 48 || str[i] > 57){
        if (str[i] == 45){
            neg++;
        }
        i++;
    }
    if (neg % 2 ==0){
        return 1;
    }
    else if (neg % 2 != 0){
        return -1;
    }
}

int my_getnbr(char const *str)
{
    char cpy [11] = "";
    int i = 0;
    int a = 0;
    long long ret = 0;
    int fret = 0;
    for (i = 0; str[i] < 48 || str[i] > 57; i++)
        if (str[i] == '\0')
            return 0;
    for (i; str[i] > 47 && str[i] < 58; i++){
        if (a > 10)
            return 0;
        cpy[a] = str[i];
        a++;
    }
    ret = transform(cpy) * set_sign(str);
    if (ret > __INT_MAX__ || ret < -__INT_MAX__ - 1)
        return 0;
    fret = ret;
    return ret;
}
