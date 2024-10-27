#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    double gpa;
    string major;


public:
    // Constructor to allocate memory
    Student(const string name, double gpa, string major)
        : name(name), gpa(gpa), major(major){}

    // Getters
    string getName() const { return name; }
    double getgpa() const { return gpa; }
    string getmajor() const {return major; }

    // Destructor
    ~Student() {}
};

class Node 
{
private:
    Student data;
    Node* next;

public:
    // Constructor
    Node(const Student& data) : data(data), next(nullptr) {}

    // Getters and Setters
    Student getData() const { return data; }
    Node* getNext() const { return next; }
    void setNext(Node* next) { this->next = next; }
};

class StudentRecords 
{
private:
    Node* head;

public:
    // Constructor
    StudentRecords() : head(nullptr) {}

    // Add a student to the list
    void addStudent(const Student& student) 
    {
        Node* newNode = new Node(student);
        newNode->setNext(head);
        head = newNode;
    }

    // Display all students
    void displayStudents() const 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            cout << "Name: " << current->getData().getName()
                      << ", GPA: " << current->getData().getgpa()
                      << ", Major: " << current->getData().getmajor() << endl;
                      current = current->getNext();
        }
    }

    // Destructor to clean up memory
    ~StudentRecords() 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            Node* temp = current;
            current = current->getNext();
            delete temp;
        }
    }
};

