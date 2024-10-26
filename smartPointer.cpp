#include <string>
#include "smartPointer.h"
#include "iostream"
using namespace std;

int main() {

    int IDNumber;
    string name;
    string sex;
    double gpa;
    string major;
    string answer;
    int i; 

    StudentRecords sr;

    // for (i=1; i < 3; i++); 
    i = 0;
    while(i<100)
    {

        cout << "Enter Name " << endl;
        getline (cin, name);
        // used getline to allow for space in name

        cout << "Enter Student Number " << endl;
        // used cin because ID Number is an integer.  had to add cin.ignore to input Sex
        cin >> IDNumber; 
        cin.ignore();
    
        cout << "Enter Sex " << endl;
        getline (cin, sex);
    
    
        cout << "Enter GPA " << endl;
        // used cin because gpa is a float.  again needed cin.ignore
        cin >> gpa;
        cin.ignore();

        cout << "Enter major " << endl;
        getline(cin, major);

        sr.addStudent(Student (name, IDNumber ,sex ,gpa ,major ));
        i++;

        cout << "Do you want to enter another student?";
        cin >> answer;
        cin.ignore();
        if (answer == "no" ){
            i = 100;
        }

    }

    sr.displayStudents();

    return 0;
}
