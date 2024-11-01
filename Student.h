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
        int numCourses;
        int *courses;

    public:
        Student(string fn, string ln, string m, double g, int* c, int numCourses);  // Updated declaration
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
