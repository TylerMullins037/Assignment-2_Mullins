#ifndef PROFESSIONAL_H
#define PROFESSIONAL_H
#include "Employee.h"
using namespace std;
#include <string>


// Derived class Professional, inheriting from Employee
class Professional : public Employee {
private:
    double monthlySalary;

public:
    Professional(string name, int employeeId, double monthlySalary);
    // Override base class methods
    double calculateWeeklySalary() const override; // function to convert monthly salary to weekly salary
    double calculateHealthCareContributions() const override; // function to calculate health care contributions
    int calculateVacationDays() const override; // function to calculate the number of vacation days earned that week
    void displayInfo() const; // Showcases its functionality

    double getMonthlySalary() const; // returns monthlySalary
    void setMonthlySalary(double newMonthlySalary); // sets a new monthlySalary
};

#endif // PROFESSIONAL.H
