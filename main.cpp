#include "roster.h"
#include <iostream>
#include <string>

int main() {

	cout << "C867 - Scripting & Programming: Applications \nLanguage: C++ \nStudent ID: 010101895 \nName: Devika Prasanth \n" << endl;

	const string studentData[] =
	{
	"A1,John,Smith,John1989@g mail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Devika,Prasanth,dprasan@wgu.edu,26,22,50,58,40,SOFTWARE"
	};

	const int numStudents = 5;
	Roster roster;

	for (int i = 0; i < numStudents; i++) roster.parse(studentData[i]);
	cout << "Displaying All Students: " << endl;
	roster.printAll();
	cout << endl;

	cout << "Displaying Invalid Emails: " << endl;
	roster.printInvalidEmails();
	cout << endl;

	cout << "Displaying Average Days in Course: " << endl;
	for (int i = 0; i < numStudents; i++) {
		roster.printAverageDaysInCourse(roster.classRosterArray[i]->getStudentID());
	}
	cout << endl;

	cout << "Displaying Students in Degree Program: Software " << endl;
	roster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	cout << "Removing Student A3 " << endl;
	roster.removeStudentbyID("A3");
	cout << endl;

	cout << "Removing Student A3 Again " << endl;
	roster.removeStudentbyID("A3");
	cout << endl;

	system("pause");
	return 0;
}



