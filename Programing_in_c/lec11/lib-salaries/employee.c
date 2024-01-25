
#include "employee.h"

int total_salary(const struct employee employees[], size_t n_employees){
  int total = 0;
  for(size_t i = 0; i < n_employees; i ++){
    total+= employees[i].salary;
  }
  return total;
}

struct employee *highest_salary(struct employee employees[], size_t n){
  int index = 0;
  for(size_t i = 0; i < n; i ++){
    if(employees[i].salary > employees[index].salary) index = i;
  }
  return &employees[index];
}

struct employee* lowest_salary(struct employee employees[], size_t n){
int index = 0;
  for(size_t i = 0; i < n; i ++){
    if(employees[i].salary < employees[index].salary) index = i;
  }
  return &employees[index];
}
