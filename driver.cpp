#include "LinkedList.h"
#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

// Function to populate the list with predefined students
void populateStudentList(LinkedList& studentList) {
    // Course counts as dynamic arrays
    int* courses1 = new int[1]{3};  
    int* courses2 = new int[1]{4};  
    int* courses3 = new int[1]{5};  
    int* courses4 = new int[1]{6};  

    // Creating predefined Student objects
    Student student1("Alice", "Johnson", "Computer Science", 3.8, courses1);
    Student student2("Bob", "Smith", "Mathematics", 3.5, courses2);
    Student student3("Charlie", "Brown", "Physics", 3.9, courses3);
    Student student4("Dana", "White", "Chemistry", 3.7, courses4);

    // Append predefined students to the list
    studentList.append(student1);
    studentList.append(student2);
    studentList.append(student3);
    studentList.append(student4);

    cout << "Predefined students have been added to the list.\n";
}

// Function to display menu
void displayMenu() {
    cout << "\n--- Student Management System ---\n";
    cout << "1. Display All Students\n";
    cout << "2. Sort Students by GPA\n";
    cout << "3. Remove Student by Name\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

int main() {
    LinkedList studentList;
    populateStudentList(studentList);  // Add predefined students to the list

    bool running = true;
    while (running) {
        displayMenu();
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                // Display all students
                cout << "\nAll Students:\n";
                studentList.display();
                break;
            case 2:
                // Sort students by GPA
                cout << "Students sorted by GPA (lowest to highest).\n";
                studentList.sortByGPA();
                studentList.display();
                break;
            case 3: {
                // Remove student by name
                string firstName, lastName;
                cout << "Enter first name of student to remove: ";
                cin >> firstName;
                cout << "Enter last name of student to remove: ";
                cin >> lastName;
                studentList.removeByName(firstName, lastName);
                break;
            }
            case 4:
                running = false;
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}
