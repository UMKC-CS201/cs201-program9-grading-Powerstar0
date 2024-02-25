// CS201PGM9-GradingTemplate.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "functions.h"
#include <iostream>
using namespace std;

int main()
{
    cout << "CREATE YOUR PROGRAM HERE!\n";
    ofstream errFile, reportFile;
    errFile.open("error.txt");
    reportFile.open("report.txt");

    vector<studentInfo*> studentData;
    processStudentData(errFile, studentData);
    printReport(reportFile, studentData);
}
 