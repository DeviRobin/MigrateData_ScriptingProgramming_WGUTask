#include "student.h"

Student::Student() {
	this->studentID = "";
	this->studentFName = "";
	this->studentLName = "";
	this->studentEmail = "";
	this->studentAge = 0;
	for (int i = 0; i < daysArraySize; i++) this->daysInCourse[i] = 0;
	this->degreeProgram = DegreeProgram::NETWORK;
}

Student::Student(string studentID, string studentFName, string studentLName, string studentEmail, int studentAge, int daysInCourse[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->studentFName = studentFName;
	this->studentLName = studentLName;
	this->studentEmail = studentEmail;
	this->studentAge = studentAge;
	for (int i = 0; i < daysArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student() {}

//getters

string Student::getStudentID() {
	return this->studentID;
}
string Student::getFName() {
	return this->studentFName;
}
string Student::getLName() {
	return this->studentLName;
}
string Student::getEmail() {
	return this->studentEmail;
}
int Student::getAge() {
	return this->studentAge;
}
int* Student::getDaysInCourse() {
	return this->daysInCourse;
}
DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

//setters
void Student::setStudentID(string studentID) { this->studentID = studentID; }
void Student::setFName(string studentFName) { this->studentFName = studentFName; }
void Student::setLName(string studentLName) { this->studentLName = studentLName; }
void Student::setEmail(string studentEmail) { this->studentEmail = studentEmail; }
void Student::setAge(int  studentAge) { this->studentAge = studentAge; }
void Student::setDaysInCourse(int daysInCourse[]) {
	for (int i = 0; i < daysArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }


void Student::print() {
	cout << this->getStudentID() << '\t';
	cout << this->getFName() << '\t';
	cout << this->getLName() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDaysInCourse()[0] << ',';
	cout << this->getDaysInCourse()[1] << ',';
	cout << this->getDaysInCourse()[2] << '\t';
	cout << degreeTypeStrings[this->getDegreeProgram()] << '\n';
}