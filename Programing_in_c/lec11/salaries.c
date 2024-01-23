// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_NAME 60

struct employee {
    char name[MAX_NAME];
    int salary;
};

int total_salary(const struct employee employees[], size_t n_employees){
  int total = 0;
  for(size_t i = 0; i < n_employees; i ++){
    total+= employees[i].salary;
  }
  return total;
}

struct employee highest_salary(const struct employee employees[], size_t n){
  struct employee highest = employees[0];
  for(size_t i = 0; i < n; i ++){
    if(employees[i].salary > highest.salary) highest = employees[i];
  }
  return highest;
}

struct employee lowest_salary(const struct employee employees[], size_t n){
  struct employee lowest = employees[0];
  for(size_t i = 0; i < n; i ++){
    if(employees[i].salary < lowest.salary) lowest = employees[i];
  }
  return lowest;
}

int main(){
  int value;
  scanf("%d",&value);
  struct employee employees[value];

  for(int i = 0; i < value; i ++){
    struct employee empl;
    scanf("%s %d",empl.name, &empl.salary);
    employees[i] = empl;
  }

  struct employee richest = highest_salary(employees, value);
  printf("%s has the highest salary: %d kr\n",richest.name, richest.salary);
  struct employee poorest = lowest_salary(employees, value);
  printf("%s has the lowest salary: %d kr\n",poorest.name, poorest.salary);

  printf("The total monthly cost is %d kr\n",total_salary(employees, value));

  return 0;
}
