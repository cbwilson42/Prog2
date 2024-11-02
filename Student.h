#ifndef Student_H
#define Student_H
#include <iostream>
#include <string>
using namespace std;

class Student
{
    private:
        //Members
        string firstName;
        string lastName;
        string major;
        double gpa;
        int *courses;

    public:
        //Functions
        Student(string, string, string, double, int*);  // Updated declaration
        ~Student();
        string getfirstName()const;
        void setfirstName(string);
        string getlastName()const;
        void setlastName(string);
        string getmajor()const;
        void setmajor(string);
        double getgpa()const;
        void setgpa(double);
        int getcourses()const;
        void setcourses(int*);
        friend ostream& operator<<(ostream&, Student&);
        bool operator==(const Student&);
        bool operator<(const Student&);
        bool operator>(const Student&);
};

#endif
