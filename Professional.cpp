#include "Professional.h"
#include <iostream>
using namespace std;

// Professional class
Professional::Professional(string name, int employeeId, double monthlySalary)
    : Employee(name, employeeId), monthlySalary(abs(monthlySalary)) {}

double Professional::calculateWeeklySalary() const {
    // Pre-condition: None.
    // Post-condition: The weekly salary of the Professional employee is calculated based on the monthly salary 
    //                 (assuming a month has 4 weeks) and returned as a double.
    return monthlySalary / 4;
}

double Professional::calculateHealthCareContributions() const {
    // Pre-condition: None.
    // Post-condition: The health care contributions of the Professional employee are calculated as 5% of the 
    //                 weekly salary and returned as a double.
    return calculateWeeklySalary() * .05;
}

int Professional::calculateVacationDays() const {
    // Pre-condition: None.
    // Post-condition: The number of vacation days earned that week by the Professional employee is returned (determined by its weekly salary) as an integer.
    return static_cast<int>(calculateWeeklySalary() / 500);
}

void Professional::displayInfo() const {
    // Pre-condition: None.
    // Post-condition: All information of the Professional employee, including name, employee ID, type, weekly salary, 
    //                 health care contributions, and vacation days, is displayed to the console.
    cout << "\n" << endl;
    cout << "Name: " << name << endl;
    cout << "Employee ID: " << employeeId << endl;
    cout << "Employee Type: Professional" << endl;
    cout << "Weekly Salary: $" << calculateWeeklySalary() << endl;
    cout << "Health Care Contributions: $" << calculateHealthCareContributions() << endl;
    cout << "Vacation Days: " << calculateVacationDays() << endl;

}

double Professional::getMonthlySalary() const {
    return monthlySalary;
}

void Professional::setMonthlySalary(double newMonthlySalary) {
    monthlySalary = abs(newMonthlySalary);
}
