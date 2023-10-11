#include <iostream>
#include "SingleLinkedList.h"
#include "Employee.h"
#include "Nonprofessional.h"
#include "Professional.h"
#include "EmployeesTest.h"
using namespace std;

int main() {
    int x;
    cout << "Press (1) to test Single Linked List and anything else to test Employees: ";
    cin >> x;
    if (x == 1) {
        // Question #1
        Single_Linked_List<int> intList;
        Single_Linked_List<double> doubleList;
        Single_Linked_List<string> stringList;
        Single_Linked_List<char> charList;
       
        // Test 1: Check if the list is initially empty
        if (!intList.empty()) {
            cerr << "Integer List Test 1 Failed: The list is not empty initially." << endl;
        }

        // Test 2: Push elements to the front and then the back of the list
        intList.push_front(10);
        intList.push_front(20);
        intList.push_front(30);

        intList.push_back(40);
        intList.push_back(50);
        intList.push_back(60);

        cout << "Integer List: ";
        intList.traverseAndPrint();

        intList.pop_back();
        intList.pop_front();
        cout << "Integer List after popping front and back: ";
        intList.traverseAndPrint();

        // Test 2: Check if size() returns the correct size of the list
        if (intList.size() != 4) {
            cerr << "Test 2 Failed: Incorrect list size." << endl;
        }

        // Test 3: Check if the front() method returns the correct value
        if (intList.front() != 20) {
            cerr << "Test 3 Failed: Incorrect value at the front of the list." << endl;
        }

        // Test 4: Check if the back() method returns the correct value
        if (intList.back() != 50) {
            cerr << "Test 4 Failed: Incorrect value at the back of the list." << endl;
        }
       

        // Test 5: Insert an element at a specific index and out of bounds index handing
        intList.insert(1, 70);
        intList.insert(10, 80);
        intList.insert(-1, 45);

        // Check if the list is modified correctly after insertion
        cout << "Integer List after insertion: ";
        intList.traverseAndPrint();

        // Test 6: Check if remove() method works as expected
        intList.remove(2);
        intList.remove(100); // returns size of list
        cout << "Integer List after removal: ";
        intList.traverseAndPrint();

        // Test 7: Check if find() method returns the correct index
        if (intList.find(40) != 2) {
            cerr << "Test 7 Failed: find() method returned an incorrect index." << endl;
        }

        // Test 8: Clear the list and check if it's empty again
        intList.clear();
        if (!intList.empty()) {
            cerr << "Test 8 Failed: The list is not empty after clearing." << endl;
        }

        // Test 9: Edge case - Insert at index 0 in an empty list
        intList.insert(0, 100);
        if (intList.front() != 100) {
            cerr << "Test 9 Failed: Insert at index 0 did not work correctly." << endl;
        }

        // Test 10: Edge case - Remove the only element in the list
        intList.remove(0);
        if (!intList.empty()) {
            cerr << "Test 10 Failed: Remove the only element did not work correctly." << endl;
        }

        // Test 11: Edge case - Try to remove an element from an empty list
        if (intList.remove(0)) {
            cerr << "Test 11 Failed: Remove from an empty list returned true." << endl;
        }

        // Test 12: Edge case - Find an element in an empty list
        if (intList.find(100) != intList.size()) {
            cerr << "Test 12 Failed: Find in an empty list did not return num_items." << endl;
        }


        
        // doubleList TESTS
        doubleList.push_front(2.5);
        doubleList.push_back(3.5);
        doubleList.push_back(4.5);
        doubleList.push_front(1.5);

        cout << "\nDouble List:" << endl;
        doubleList.traverseAndPrint();

        if (doubleList.size() != 4) {
            cerr << "Double List Test Failed: Incorrect list size." << endl;
        }

        if (doubleList.front() != 1.5) {
            cerr << "Double List Test Failed: Incorrect value at the front of the list." << endl;
        }

        if (doubleList.back() != 4.5) {
            cerr << "Double List Test Failed: Incorrect value at the back of the list." << endl;
        }

        doubleList.insert(2, 2.75);
        doubleList.remove(1);

        cout << "Modified Double List:" << endl;
        doubleList.traverseAndPrint();



        // charList TESTS
        charList.push_front('A');
        charList.push_back('B');
        charList.push_back('C');
        charList.push_front('D');

        cout << "\nChar List:" << endl;
        charList.traverseAndPrint();

        if (charList.size() != 4) {
            cerr << "Char List Test Failed: Incorrect list size." << endl;
        }

        if (charList.front() != 'D') {
            cerr << "Char List Test Failed: Incorrect value at the front of the list." << endl;
        }

        if (charList.back() != 'C') {
            cerr << "Char List Test Failed: Incorrect value at the back of the list." << endl;
        }

        charList.insert(2, 'X');
        charList.remove(1);

        cout << "Modified Char List:" << endl;
        charList.traverseAndPrint();



        // stringList TESTS
        stringList.push_front("Apple");
        stringList.push_back("Banana");
        stringList.push_back("Cherry");
        stringList.push_front("Orange");

        cout << "\nString List:" << endl;
        stringList.traverseAndPrint();

        if (stringList.size() != 4) {
            cerr << "String List Test Failed: Incorrect list size." << endl;
        }

        if (stringList.front() != "Orange") {
            cerr << "String List Test Failed: Incorrect value at the front of the list." << endl;
        }

        if (stringList.back() != "Cherry") {
            cerr << "String List Test Failed: Incorrect value at the back of the list." << endl;
        }
        stringList.insert(1, "Grapes");
        stringList.remove(0);

        cout << "Modified String List:" << endl;
        stringList.traverseAndPrint();
    }
    else {
        // Question #2
        Professional prof("John Doe", 101, 5000.0);
        Nonprofessional nonProf("Jane Smith", 102, -15.0, 40);

        prof.displayInfo();
        nonProf.displayInfo();
        runAllTests();

    }
    return 0;
}


