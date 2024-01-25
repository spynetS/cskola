// 2023 Alfred Roos
#include <stdio.h>

#define MAX_NAME 60

struct person {
    char name[MAX_NAME];
    int age;
    double height;
};


// the function grow()
// should increase
// the age of a person by 1 year
// and the height by 5%.
void grow(struct person *person){
  person->age++;
  person->height*=1.05;
}


int main()
{
    struct person person;
    while (scanf("%59s %d %lf", person.name, &person.age, &person.height)==3) {
        printf("%s is %d years old and %.2lfm tall.\n",
            person.name, person.age, person.height);
        grow(&person);
        printf("In a year,\n");
        printf("%s will be %d years old and %.2lfm tall.\n\n",
            person.name, person.age, person.height);
    }
}
