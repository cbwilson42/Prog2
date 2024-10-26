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

string Student::getfirstName()const
{
    return firstName;
}

string Student::setfirstName(string fn)
{
    firstName = fn;
}

string Student::getlastName()const
{
    return lastName;
}

string Student::setLastName(string ln)
{
    lastName = ln;
}

string Student::getmajor()const
{
    return major;
}

string Student::setmajor(string m)
{
    major = m;
}

double Student::getgpa()const
{
    return gpa;
}

double Student::setgpa(double g)
{
    gpa = g;
}

string Student::getcourses()const
{
    return *courses;
}

string Student::setcourses(string *c)
{
    *courses = *c;
}

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




#endif