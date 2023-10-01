#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/**
* check_num - check - string there are digit
* @str: array str
* Return: Always 0 (Success)
*/
int check_num(char *str)
{
/*Declaring variables*/
unsigned int track;
track = 0;
while (track < strlen(str)) /*count string*/
{
if (!isdigit(str[track])) /*check if str there are digit*/
{
return (0);
}
track++;
}
return (1);
}
/**
* main - Print the name of the program
* @argc: Count arguments
* @argv: Arguments
*
* Return: Always 0 (Success)
*/
int main(int argc, char *argv[])
{
/*Declaring variables*/
int track;
int str_to_int;
int sum = 0;

track = 1;
while (track < argc) /*Goes through the whole array*/
{
if (check_num(argv[track]))
{
str_to_int = atoi(argv[track]); /*ATOI --> convert string to int*/
sum += str_to_int;
}
/*Condition if one of the number contains symbols that are not digits*/
else
{
printf("Error\n");
return (1);
}
track++;
}
printf("%d\n", sum); /*print sum*/
return (0);
}
