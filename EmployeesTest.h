#include "Professional.h"
#include "Nonprofessional.h"
#include <iostream>

bool testProfessionalClass() {
    // Create a Professional object
    Professional prof("Alice Johnson", 3, 5000.0);

    // Test 1: Check if calculateWeeklySalary returns the correct value
    if (prof.calculateWeeklySalary() != 5000.0 / 4) {
        cerr << "Professional Test 1 Failed: calculateWeeklySalary() returned an incorrect value." << endl;
        return false;
    }

    // Test 2: Check if calculateHealthCareContributions returns the correct value
    if (prof.calculateHealthCareContributions() != (5000.0 / 4) * 0.05) {
        cerr << "Professional Test 2 Failed: calculateHealthCareContributions() returned an incorrect value." << endl;
        return false;
    }

    // Test 3: Check if calculateVacationDays returns the correct value
    if (prof.calculateVacationDays() != int((5000.0 / 4) / 500)) {
        cerr << "Professional Test 3 Failed: calculateVacationDays() returned an incorrect value." << endl;
        return false;
    }

    return true;
}

bool testNonprofessionalClass() {
    // Create a Nonprofessional object
    Nonprofessional nonprof("Bob Brown", 4, 15.0, 45);

    // Test 3: Check if calculateWeeklySalary returns the correct value
    if (nonprof.calculateWeeklySalary() != 15.0 * 45) {
        cerr << "Nonprofessional Test 1 Failed: calculateWeeklySalary() returned an incorrect value." << endl;
        return false;
    }

    // Test 4: Check if calculateHealthCareContributions returns the correct value
    if (nonprof.calculateHealthCareContributions() != (15.0 * 45) * 0.05) {
        cerr << "Nonprofessional Test 2 Failed: calculateHealthCareContributions() returned an incorrect value." << endl;
        return false;
    }

    // Test 5: Check if calculateVacationDays returns the correct value
    if (nonprof.calculateVacationDays() != 45/40) {
        cerr << "Nonprofessional Test 3 Failed: calculateVacationDays() returned an incorrect value." << endl;
        return false;
    }

    return true;
}

bool runAllTests() { // function to run tests for both classes
    if (testNonprofessionalClass() && testProfessionalClass()) {
        cout << "All tests successful" << endl;
        return true;
    }
    return false;
}
