#include <stdio.h>
#include <stdlib.h>

/**
* main - Multiplies two numbers
* @argc: Number of command-line arguments
* @argv: Array of command-line arguments
* Return: 0 if successful, 1 if error
*/
int main(int argc, char *argv[])
{
if (argc != 3)
{
printf("Error\n");
return (1);
}
printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
return (0);
}
