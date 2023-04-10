#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;


// Create Student class with respective variables:
class Student {

public:

    // Accessor for each instance variable:
    string getID();
    string getFirst();
    string getLast();
    string getEmail();
    int getAge();
    const static int numOfCourses = 3;
    int* getDaysPerCourse();
    DegreeProgram getDegreeProgram();

    // Mutator for each instance variable:
    void setID(string studentID);
    void setFirst(string first);
    void setLast(string last);
    void setEmail(string email);
    void setAge(int age);
    void setDaysPerCourse(int daysPerCourse[]);
    void setDegreeProgram(DegreeProgram dp);

    // Student constructors:
    Student();
    Student(string studentID, string first, string last, string email, int age, int daysPerCourse[], DegreeProgram degreeProgram);

    // Destructor:
    ~Student();

    // Print specific student data:
    void print();

private:

    // Private Student class variables:
    string studentID;
    string first;
    string last;
    string email;
    int age;
    int daysPerCourse[numOfCourses];
    DegreeProgram degreeProgram;

};
