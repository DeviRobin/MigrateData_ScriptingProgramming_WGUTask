#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"

using namespace std;

class Student
{
public:
	const static int daysArraySize = 3;

private:
	string studentID;
	string studentFName;
	string studentLName;
	string studentEmail;
	int studentAge;
	int daysInCourse[daysArraySize];
	DegreeProgram degreeProgram;


public:
	//Constructors
	Student();
	Student(string studentID, string studentFName, string studentLName, string studentEmail, int studentAge, int daysInCourse[], DegreeProgram degreeProgram); //full constuctor
	~Student(); // destructor

	// accessor (getter) 
	string getStudentID();
	string getFName();
	string getLName();
	string getEmail();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegreeProgram();

	//mutators (setters)
	void setStudentID(string);
	void setFName(string);
	void setLName(string);
	void setEmail(string);
	void setAge(int);
	void setDaysInCourse(int daysInCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);


	void print();





};

