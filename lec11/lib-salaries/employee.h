#ifndef _EMPLOYEE_H_
#define _EMPLOYEE_H_

#include <stddef.h>

#define MAX_NAME 60

struct employee {
    char name[MAX_NAME];
    int salary;
};

int total_salary(const struct employee employees[], size_t n_employees);
struct employee *highest_salary(struct employee employees[], size_t n);
struct employee *lowest_salary(struct employee employees[], size_t n);

#endif /* _EMPLOYEE_H_ */