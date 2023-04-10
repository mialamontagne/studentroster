#pragma once
#include "student.h"

// Create Roster class with respective variables:
class Roster {

public:

	// Declare variables necessary for functions:
	int lastIndex = -1;
	const static int numOfStudents = 5;
	Student* classRosterArray[numOfStudents];

	// Declare function names and parameters:
	void parse(string row);
	void add(string studentID, string first, string last, string email, int age, int daysPerFirst, int daysPerSecond, int daysPerThird, DegreeProgram degreeProgram);
	void remove(string removeID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmail();
	void printByDegreeProgram(DegreeProgram degreeProgram);

	// Destructor:
	~Roster();

};
