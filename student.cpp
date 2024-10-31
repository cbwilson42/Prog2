#include "Student.h"
using namespace std;

Student::Student(string fn, string ln, string m, double g, int* c)
    : firstName(fn), lastName(ln), major(m), gpa(g), courses(c) {}

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
    return *courses;
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

ostream& operator<<(ostream& os, Student& s)
	{
		os << s.firstName << "#" << s.lastName << "#" << s.major << "#" << s.gpa << "#" << *s.courses << "#";
		return os;
	}