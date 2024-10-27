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
int *courses;

public:
Student(string, string, string, double, int*);
~Student();
string getfirstName()const;
string setfirstName(string);
string getlastName()const;
string setlastName(string);
string getmajor()const;
string setmajor(string);
double getgpa()const;
double setgpa(double);
int getcourses()const;
int setcourses(int*);
friend ostream& operator<<(ostream&, Student&);
bool operator==(const Student&);
bool operator<(const Student&);
bool operator>(const Student&);
};

#endif
