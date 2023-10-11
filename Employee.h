#ifndef EMPLOYEE_H
#define EMPLOYEE_H
using namespace std;
#include <string>

// Abstract class Employee created to contain similarities between different types of employees
class Employee {
protected:
    string name;
    int employeeId;

public:
    Employee(string name, int employeeId) : name(name), employeeId(employeeId) {};
    Employee() { name = "Name", employeeId = 0; }
    virtual double calculateWeeklySalary() const = 0; 
    virtual double calculateHealthCareContributions() const = 0; 
    virtual int calculateVacationDays() const = 0;

    // setters and getters for the data fields
    string getName() {
        return name;
    }
    void setName(string newName) {
        name = newName;
    }
    int getEmployeeId() {
        return employeeId;
    }
    void setEmployeeId(int newEmployeeId) {
        employeeId = newEmployeeId;
    }
};


#endif // EMPLOYEE_H
