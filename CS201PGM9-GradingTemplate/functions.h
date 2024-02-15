#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct studentInfo {
	int studentID;
	string answers;
	int score;
	float percent;
	char grade;
};

void processStudentData(ofstream& outErr, vector<studentInfo*>& studentData);
//PRE:   Accepts the output stream for errors and an empty vector of pointers
//POST:  Opens the input file, if the file is valid, it reads each record in the file,
//       writes any records with an error to the error file
//       If data is good, it will calculate the students score and grade 
//       and updates the student's struct values and adds the pointer to the vector
//       close input file

void printReport(ofstream& outFile,  vector<studentInfo*>& studentData);
//PRE:   Accepts the output stream for the report (opened in main) and the vector of pointers
//POST:  prints student data to the output stream 
