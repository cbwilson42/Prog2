#ifndef Student_H
#define Student_H
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:

string firstName;
string lastName;
string major;
double gpa;
string *courses;

public:
Student(string, string, string, double, string*);
~Student();

};

//Constuctor
Student::Student(string fn, string ln, string m, double g, string *c)
{
    firstName = fn;
    lastName = ln;
    major = m;
    gpa = g;
    courses = new string[];


}
string Student::getfirstName( int f) const
{
    return firstName;
}



#endif