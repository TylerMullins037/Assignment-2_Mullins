#include "Nonprofessional.h"
#include <iostream>
using namespace std;

// Nonprofessional class
Nonprofessional::Nonprofessional(string name, int employeeId, double hourlyRate, int hoursWorked)
    : Employee(name, employeeId), hourlyRate(abs(hourlyRate)), hoursWorked(abs(hoursWorked)) {}

double Nonprofessional::calculateWeeklySalary() const {
    // Pre-condition: None.
    // Post-condition: The weekly salary of the Nonprofessional employee is calculated based on hours worked and 
    //                 hourly rate and returned as a double.
    return hourlyRate * hoursWorked;
}

double Nonprofessional::calculateHealthCareContributions() const {
    // Pre-condition: None.
    // Post-condition: The health care contributions of the Nonprofessional employee are calculated as 5% of the 
    //                 weekly salary and returned as a double.
    return calculateWeeklySalary() * .05;
}

int Nonprofessional::calculateVacationDays() const {
    // Pre-condition: None.
    // Post-condition: The number of vacation days earned by the Nonprofessional employee is calculated based on 
    //                 hours worked (1 day for every 30 hours worked) and returned as an integer.
    return hoursWorked / 30;
}

void Nonprofessional::displayInfo() const {
    // Pre-condition: None.
    // Post-condition: All information of the Nonprofessional employee, including name, employee ID, type, weekly salary,
    //                 health care contributions, and vacation days, is displayed to the console.
    cout << "\n" << endl;
    cout << "Name: " << name << endl;
    cout << "Employee ID: " << employeeId << endl;
    cout << "Employee Type: Nonprofessional" << endl;
    cout << "Weekly Salary: $" << calculateWeeklySalary() << endl;
    cout << "Health Care Contributions: $" << calculateHealthCareContributions() << endl;
    cout << "Vacation Days: " << calculateVacationDays() << endl;

}

double Nonprofessional::getHourlyRate() const { // returns the hourly Rate
    return hourlyRate;
}

int Nonprofessional::getHoursWorked() const { // returns the hours worked
    return hoursWorked;
}

void Nonprofessional::setHourlyRate(double newHourlyRate) { // modifies the hourly rate
    hourlyRate = abs(newHourlyRate);
}

void Nonprofessional::setHoursWorked(int newHoursWorked) { // modifies the hours worked
    hoursWorked = abs(newHoursWorked);
}
