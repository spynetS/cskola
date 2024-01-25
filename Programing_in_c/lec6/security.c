// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    int salary = 12000;
    char name[12];
    char job[12] = "programmer";

    printf("Type your name: ");
    scanf("%11s", name);

    printf("Hi %s!\n", name);
    printf("Your job is %s.\n", job);
    printf("Your salary is %d kr.\n", salary);
}
