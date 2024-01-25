// 2023 Alfred Roos
#include <stdio.h>
#include <stdlib.h>
#include "employee.h"

int main(){
  int value;
  scanf("%d",&value);
  struct employee employees[value];

  for(int i = 0; i < value; i ++){
    struct employee empl;
    scanf("%s %d",empl.name, &empl.salary);
    employees[i] = empl;
  }

  struct employee* richest = highest_salary(employees, value);
  printf("%s has the highest salary: %d kr\n",richest->name, richest->salary);
  struct employee* poorest = lowest_salary(employees, value);
  printf("%s has the lowest salary: %d kr\n",poorest->name, poorest->salary);

  printf("The total monthly cost is %d kr\n",total_salary(employees, value));

  return 0;
}
