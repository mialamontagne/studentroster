#include "roster.h"
using namespace std;

// Declare main function:
int main() {

	// Provided data input:
	const string studentData[] =
	{ "A1,Erick,Johnson,ejohnson@gmail.com,20,30,35,40,SECURITY",
	 "A2,Scott,Michael,michaelscott gmail.com,19,50,30,40,NETWORK",
	 "A3,Hannah,Night,hannah_knight@gmail,19,20,40,33,SOFTWARE",
	 "A4,Mary,Jackson,mjackson@hotmail.net,22,50,58,40,SECURITY",
	 "A3,Jane,Doe,Jane.Doe@gmail.com,21,25,35,40,SOFTWARE" };

	// Instance of Roster class:
	Roster classRoster;

	// Number of students in roster:
	const int numOfStudents = 5;

	// Print all students and their specific data:
	for (int i = 0; i < numOfStudents; i++) {
		classRoster.parse(studentData[i]);
	}
	cout << "Here are all currently enrolled students:  " << endl;
	classRoster.printAll();
	cout << endl;

	// Print students with invalid email addresses:
	cout << "The following email addresses are invalid: " << endl;
	classRoster.printInvalidEmail();
	cout << "  " << endl;


	// Print average number of days for each student:
	for (int i = 0; i < numOfStudents; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getID());
	}
	cout << "  " << endl;


	// Print students by degree program:
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << " " << endl;
	classRoster.printByDegreeProgram(SECURITY);
	cout << " " << endl;
	classRoster.printByDegreeProgram(NETWORK);
	cout << " " << endl;
	classRoster.printByDegreeProgram(UNKNOWN);
	cout << " " << endl;

	// Remove student A3:
	cout << "Remove student A3." << endl;
	classRoster.remove("A3");
	cout << endl;

	// Print all students, after deletion:
	cout << "Displaying all Students: " << endl;
	classRoster.printAll();

	// Try to remove student A3 again (error message should be printed):
	cout << endl;
	cout << "Remove student A3.";
	classRoster.remove("A3");
	cout << endl;
}
