#include "Student.h"
using namespace std;

Student::Student(string fn, string ln, string m, double g, int* c, int numCourses)
    : firstName(fn), lastName(ln), major(m), gpa(g), numCourses(numCourses) 
{
    courses = new int[numCourses];
    for (int i = 0; i < numCourses; ++i) {
        courses[i] = c[i];
    }
}

// Destructor to delete the dynamically allocated `courses` array
Student::~Student() {
    delete[] courses;
}

string Student::getfirstName()const
{
    return firstName;
}

void Student::setfirstName(string fn)
{
    firstName = fn;
}

string Student::getlastName()const
{
    return lastName;
}

void Student::setlastName(string ln)
{
    lastName = ln;
}

string Student::getmajor()const
{
    return major;
}

void Student::setmajor(string m)
{
    major = m;
}

double Student::getgpa()const
{
    return gpa;
}

void Student::setgpa(double g)
{
    gpa = g;
}

int Student::getcourses()const
{
    return numCourses;
}

void Student::setcourses(int *c)
{
    courses = c;
}

//Constuctor
/*Student::Student(string fn, string ln, string m, double g, int *c)
{
    firstName = fn;
    lastName = ln;
    major = m;
    gpa = g;
    courses = c;
}

//Destructor
Student::~Student()
{
    delete[] courses;
}*/

//Operator comparison
bool Student::operator == (const Student& s)
{
    if(gpa == s.gpa)
        return true;
    else
        return false;
    //return gpa == s.gpa;
}

bool Student::operator < (const Student& s)
{
     if(gpa < s.gpa)
        return true;
    else
        return false;
    //return gpa < s.gpa;
}

bool Student::operator > (const Student& s)
{
     if(gpa > s.gpa)
        return true;
    else
        return false;
    //return gpa > s.gpa;
}

ostream& operator<<(ostream& os, Student& s) {
    os << "Name: " << s.firstName << " " << s.lastName
       << "\nMajor: " << s.major
       << "\nGPA: " << s.gpa
       << "\nCourses: ";
    
    for (int i = 0; i < s.numCourses; ++i) {
        os << s.courses[i] << " ";
    }
    return os;
}
