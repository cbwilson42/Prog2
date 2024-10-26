#include "Student.h"
using namespace std;

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

string Student::setlastName(string ln)
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

int Student::getcourses()const
{
    return *courses;
}

int Student::setcourses(int *c)
{
    courses = c;
}

//Constuctor
Student::Student(string fn, string ln, string m, double g, int *c)
{
    firstName = fn;
    lastName = ln;
    major = m;
    gpa = g;
    courses = c;
}

Student::~Student()
{
    delete[] courses;
}