#pragma once
#include <iostream>
#include "student.h"

using namespace std;

class Roster {
public:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* classRosterArray[numStudents];

public:
	void parse(string row);
	void add(string studentID, string studentFName, string studentLName, string studentEmail, int studentAge, int days1, int days2, int days3, DegreeProgram degreeProgram);
	void printAll();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void printInvalidEmails();
	void printAverageDaysInCourse(string studentID);
	void removeStudentbyID(string studentID);
	~Roster();

};
