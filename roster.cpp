#include "roster.h"
#include <string>
using namespace std;

// Parse each set of data and add to student object, add each object to classRosterArray:
void Roster::parse(string input) {

	// Assigns student ID:
	long long int rhs = input.find(",");

	string studentID = input.substr(0, rhs);

	// Assigns first name:
	long long int lhs = rhs + 1;
	rhs = input.find(",", lhs);

	string first = input.substr(lhs, rhs - lhs);

	// Assigns last name:
	lhs = rhs + 1;
	rhs = input.find(",", lhs);

	string last = input.substr(lhs, rhs - lhs);

	// Assigns email:
	lhs = rhs + 1;
	rhs = input.find(",", lhs);

	string email = input.substr(lhs, rhs - lhs);

	// Assigns age:
	lhs = rhs + 1;
	rhs = input.find(",", lhs);

	int age = stoi(input.substr(lhs, rhs - lhs));

	// Assigns days per first course:
	lhs = rhs + 1;
	rhs = input.find(",", lhs);

	int daysPerFirst = stoi(input.substr(lhs, rhs - lhs));

	// Assigns days per second course:
	lhs = rhs + 1;
	rhs = input.find(",", lhs);

	int daysPerSecond = stoi(input.substr(lhs, rhs - lhs));

	// Assigns days per third course:
	lhs = rhs + 1;
	rhs = input.find(",", lhs);

	int daysPerThird = stoi(input.substr(lhs, rhs - lhs));

	// Assigns degree program type:
	lhs = rhs + 1;
	rhs = input.find(",", lhs);

	string degreeProgram = input.substr(lhs, rhs - lhs);

	DegreeProgram degreeType = UNKNOWN;

	if (degreeProgram == "SECURITY") {
		degreeType = SECURITY;
	}
	else if (degreeProgram == "NETWORK") {
		degreeType = NETWORK;
	}
	else if (degreeProgram == "SOFTWARE") {
		degreeType = SOFTWARE;
	}

	// Add student object with assigned information to roster:
	add(studentID, first, last, email, age, daysPerFirst, daysPerSecond, daysPerThird, degreeType);
}

// Add student object with days per course for each course:
void Roster::add(string studentID, string first, string last, string email, int age, int daysPerFirst, int daysPerSecond, int daysPerThird, DegreeProgram degreeType) {

	// Create int array of days per course (3 in total)
	int daysPerEach[3] = { daysPerFirst, daysPerSecond, daysPerThird };
	classRosterArray[++lastIndex] = new Student(studentID, first, last, email, age, daysPerEach, degreeType);
}

// Remove student by ID number:
void Roster::remove(string studentID) {
	cout << endl;
	for (int i = 0; i < 5; ++i) {
		if (classRosterArray[i]->getID() == studentID) {
			cout << "Deleting Student " << classRosterArray[i]->getID() << "...." << endl;
			classRosterArray[i]->setID("null");
			cout << "Student has been deleted." << endl;
			return;
		}
	}

	// If student does not exist, print error message:
	cout << "ERROR: STUDENT NOT FOUND..." << endl;
	return;
}


// Print tab separated list of student data in proper formatting:
void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getID() != "null") {
			cout << "  ";
			// Using print() function for each student:
			classRosterArray[i]->print();
		}
	}
}


// Prints a student's average number of days in 3 courses:
void Roster::printAverageDaysInCourse(string studentID) {

	int first;
	int second;
	int third;
	double averageDays;

	for (int i = 0; i < numOfStudents; i++) {
		first = classRosterArray[i]->getDaysPerCourse()[0];
		second = classRosterArray[i]->getDaysPerCourse()[1];
		third = classRosterArray[i]->getDaysPerCourse()[2];

		averageDays = (first + second + third) / 3.0;

		if (classRosterArray[i]->getID() == studentID) {
			cout << "Student " << classRosterArray[i]->getID() << " takes an average of " << averageDays << " days to complete a course." << endl;
		}
	}
}

// Print invalid email addresses:
void Roster::printInvalidEmail() {
	bool valid;
	bool symbol;
	string email;
	size_t n;

	for (int i = 0; i < numOfStudents; i++) {
		email = classRosterArray[i]->getEmail();
		valid = true;
		symbol = true;

		// Check if "@" is present:
		n = email.find("@");
		if (n < email.length()) {
			n++;
			symbol = isalnum(email[n]);
		}

		if (symbol == false) {
			valid = false;
		}

		if (n > email.length()) {
			valid = false;
		}

		// Check if ".". is present:
		n = email.find(".");
		if (n > email.length()) {
			valid = false;
		}

		// Check if " " is present:
		n = email.find(" ");
		if (n < email.length()) {
			valid = false;
		}

		if (valid == false) {
			cout << email << "\t" << endl;
		}
	}
}

// Print by degree program:
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

	string degreeTypes[] = { "UNKNOWN", "SECURITY", "NETWORK", "SOFTWARE" };
	int j = 0;

	cout << "Students in " << degreeTypes[degreeProgram] << " Degree Program:" << endl;
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			cout << "  ";
			classRosterArray[i]->print();
			j++;
		}
	}

	// When list of students is parsed and none are found for given program:
	if (j == 0) {
		cout << "  No students are currently enrolled in this program." << endl;
	}
	return;
}

// Destructor is implemented, releases dynamically allocated memory.
Roster::~Roster() {
	cout << "Destructor is now running..." << endl;
	for (int i = 0; i < numOfStudents; i++) {
		// Delete allocated memory and throw null pointer:
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}
