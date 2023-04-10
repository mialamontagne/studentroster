#include "student.h"
using namespace std;


// Defining function of Student:
Student::Student() {
	this->studentID = "";
	this->first = "";
	this->last = "";
	this->email = "";
	this->age = 0;

	for (int i = 0; i < numOfCourses; i++) {
		this->daysPerCourse[i] = 0;
	}

	degreeProgram = UNKNOWN;
}


// Defining overloaded constructor:
Student::Student(string studentID, string first, string last, string email, int age, int daysPerCourse[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->first = first;
	this->last = last;
	this->email = email;
	this->age = age;

	for (int i = 0; i < numOfCourses; i++) {
		this->daysPerCourse[i] = daysPerCourse[i];
	}

	this->degreeProgram = degreeProgram;
}

// Accessor for each instance variable:
string Student::getID() {
	return this->studentID;
}

string Student::getFirst() {
	return this->first;
}

string Student::getLast() {
	return this->last;
}

string Student::getEmail() {
	return this->email;
}

int Student::getAge() {
	return this->age;
}

int* Student::getDaysPerCourse() {
	return this->daysPerCourse;
}

DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}


// Mutator for each instance variable:
void Student::setID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirst(string first) {
	this->first = first;
}

void Student::setLast(string last) {
	this->last = last;
}

void Student::setEmail(string email) {
	this->email = email;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysPerCourse(int daysPerCourse[]) {
	this->daysPerCourse[0] = daysPerCourse[0];
	this->daysPerCourse[1] = daysPerCourse[1];
	this->daysPerCourse[2] = daysPerCourse[2];
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}


// Print specific student data:
void Student::print() {

	string degreeNames[] = { "UNKNOWN", "SECURITY", "NETWORK", "SOFTWARE" };

	int width = 15;

	cout << left
		<< setw(width) << this->getID()
		<< setw(width) << this->getFirst()
		<< setw(width) << this->getLast()
		<< setw(25) << this->getEmail()
		<< setw(7) << this->getAge()
		<< ' ' << "{" << this->getDaysPerCourse()[0] << ',' << this->getDaysPerCourse()[1] << ',' << this->getDaysPerCourse()[2] << "}"
		<< '\t' << "   " << degreeNames[this->degreeProgram] << '\t' << endl;
}

// Destructor releases memory allocated in Roster:
Student::~Student() {
	cout << "Destructor has successfully released the memory." << endl;
}
