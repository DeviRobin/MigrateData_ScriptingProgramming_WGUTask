#include "roster.h"

using namespace std;

//Parse 
void Roster::parse(string studentData) {
	size_t rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string studentFName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string studentLName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string studentEmail = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int studentAge = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int days1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int days2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int days3 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string strDegreeProgram = studentData.substr(lhs, rhs - lhs);

	DegreeProgram degreeProgram = DegreeProgram::NETWORK;
	if (strDegreeProgram.at(0) == 'S' && strDegreeProgram.at(1) == 'O') {
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (strDegreeProgram.at(0) == 'N') {
		degreeProgram = DegreeProgram::NETWORK;
	}
	else {
		degreeProgram = DegreeProgram::SOFTWARE;
	}

	add(studentID, studentFName, studentLName, studentEmail, studentAge, days1, days2, days3, degreeProgram);
}

void Roster::add(string studentID, string studentFName, string studentLName, string studentEmail, int studentAge, int days1, int days2, int days3, DegreeProgram degreeProgram) {
	int daysArray[3] = { days1, days2, days3 };
	classRosterArray[++lastIndex] = new Student(studentID, studentFName, studentLName, studentEmail, studentAge, daysArray, degreeProgram);
}

void Roster::printAll() {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		Roster::classRosterArray[i]->print();
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) classRosterArray[i]->print();
	}
	cout << endl;
}

//Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
void Roster::printInvalidEmails() {
	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		string studentEmail = (classRosterArray[i]->getEmail());
		if ((studentEmail.find('@') == string::npos) || (studentEmail.find('.') == string::npos) || (studentEmail.find(' ') != string::npos)) {
			any = true;
			cout << studentEmail << " - is invalid" << endl;
		}
	}
	if (!any) cout << "All emails are valid" << endl;
}

void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			cout << "Student ID: " << studentID << " average days in course is:  ";
			cout << (classRosterArray[i]->getDaysInCourse()[0] +
				classRosterArray[i]->getDaysInCourse()[1] +
				classRosterArray[i]->getDaysInCourse()[2]) / 3 << endl;
		}
	}
}




void Roster::removeStudentbyID(string studentID) {
	bool success = false;
	for (int i = 0; i <= Roster::lastIndex; i++)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			success = true;
			if (i < numStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numStudents - 1];
				classRosterArray[numStudents - 1] = temp;
			}
			Roster::lastIndex--;
		}
	}
	if (success)
	{
		cout << studentID << " removed." << endl;
		this->printAll();
	}
	else cout << studentID << " not found." << endl;
}

Roster:: ~Roster() {
	cout << "Destructor called" << endl;
	for (int i = 0; i < numStudents; i++) {
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}