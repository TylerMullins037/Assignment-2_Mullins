#ifndef NONPROFESSIONAL_H
#define NONPROFESSIONAL_H
#include "Employee.h"
using namespace std;
#include <string>

// Derived class Nonprofessional, inheriting from Employee
class Nonprofessional : public Employee {
private:
    double hourlyRate;
    int hoursWorked;

public:
    Nonprofessional(string name, int employeeId, double hourlyRate, int hoursWorked);

    // Override base class methods
    double calculateWeeklySalary() const override; // function to convert monthly salary to weekly salary
    double calculateHealthCareContributions() const override; // function to calculate health care contributions
    int calculateVacationDays() const override; // function to calculate the number of vacation days earned that week
    void displayInfo() const; // Shows its fuctionality
     
    // setters and getters for data fields
    double getHourlyRate() const;
    int getHoursWorked() const;
    void setHourlyRate(double newHourlyRate);
    void setHoursWorked(int newHoursWorked);
};

#endif // NONPROFESSIONAL.H
