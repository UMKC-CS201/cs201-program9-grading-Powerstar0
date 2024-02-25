#include "functions.h"

//PRE: accepts a string
//POST: returns true if the string contains only digits, false otherwise
bool isDigits(string str) {
    //Checks each character in the string to see if it's a digit.
	for (char i : str) { //CLION recommends to use this loop instead
        if (!isdigit(i)) {
            return false;
        }
    }
	return true;
}

//PRE: accepts calculated score out of 40
//POST: returns a character 'A'-'F' based on the score
char calcGrade(int score) {
    //PRE: accepts an integer score
    //POST: Returns the corresponding char letter grade
    //Calculates the grade based on the percentage
    //Finds the percent grade based of the score
    float percentage = (score / 40.0) * 100;
    // Grade boundaries
    // A: 90-100%; B: 80-89.99%; C: 70-79.99%; D: 60-69.99 F: < 60
	if (percentage >= 90) {
        return 'A';
    }
    else if (percentage >= 80) {
        return 'B';
    }
    else if (percentage >= 70) {
        return 'C';
    }
    else if (percentage >= 60) {
        return 'D';
    }
    else {
        return 'F';
    }
}


void processStudentData(ofstream& outErr, vector<studentInfo*>& studentData) {
    //PRE:   Accepts the output stream for errors and an empty vector of pointers
//POST:  Opens the input file, if the file is valid, it reads each record in the file,
//       writes any records with an error to the error file
//       If data is good, it will calculate the students score and grade
//       and updates the student's struct values and adds the pointer to the vector
//       close input file
/*
 * OPEN File
 * VERIFY FILE
 * GET inRec(1 line of input)
 * SET answers = inRec
 * WHILE (GETLINE inREC)
 *  SET studID to inRec (0,6)
 *  Set studAns to inRec (7,20)
 *  CHECK isDigits(studID)
 *      WRITE inRec to errFile
 *      CONTINUE
 *  FOR (i = 0 - 20)
 *  CHECK studAns[i] == answers[i]
 *      SCORE += 2
 *  Else studAns[i] != ' '
 *      SCORE += 1
 *  CALC studPercent
 *  CALC grade
 *  SET studStruct values
 *  ADD studStruct to vector
 * CLOSE File
 */
	//cout << "CODE THIS FUNCTION: processStudentData\n";
    ifstream inFile;
    //opens file and checks if it's valid/open
    inFile.open(R"(C:\Users\Johnny\CLionProjects\cs201-program9-grading-Powerstar0\CS201PGM9-GradingTemplate\student.txt)");
    if (!inFile.is_open()) {
        cout << "INPUT FILE NOT OPEN\n";
        return;
    }
    //Define variables
    string inRec, answers, studAns, studIDStr;
    int studID;
    int studScore;
    float studPerc;
    char studGrade;
    //Get answers
    getline(inFile, inRec);
    answers = inRec;
    //Get each student's ID and answers
    while (getline(inFile, inRec)) {
        studScore = 0;
        // Check Student ID
        studIDStr = inRec.substr(0,6);
        //Checks to see if ID is valid
        if (isDigits(studIDStr)) {
            studID = stoi(studIDStr);
        }
        //Writes to error file if ID is not valid
        else {
            outErr << "Error found in this line: " << inRec << endl;
            continue;
        }
        //Compares student answers to actual and awards points
        studAns = inRec.substr(7,20);
        for (int i = 0; i < studAns.length(); i++) {
            if (studAns[i] == answers[i]) {
                studScore += 2;
            }
            else if (studAns[i] != ' ') {
                studScore += 1;
            }
        }
        //Sets the student structure values
        studGrade = calcGrade(studScore);
        studPerc = (studScore / 40.0) * 100;
        studentInfo* newStud = new studentInfo;
        newStud->studentID = studID;
        newStud->score = studScore;
        newStud->answers = studAns;
        newStud->percent = studPerc;
        newStud->grade = studGrade;
        studentData.push_back(newStud);
    }
    //close file
    inFile.close();
}


void printReport(ofstream& outFile, vector<studentInfo*>& studentData) {
    //PRE: Accepts output stream and a vector of pointers
    //POST: Writes to output file each students ID, answers, score, percentage, and grade
    //Writes to report using student data
    //SET HEADING in OUTFILE
    //FOR student in STUDENTDATA
        //WRITE the ID, answers, score, percentage, and grade in OUTFILE
    //Heading
    outFile << left << setw(10) << "STUD ID" << setw(25) << "STUDENT ANSWERS" << setw(10) << "SCORE/40" << setw(10) << "PERCENT" << setw(8) << "GRADE" << endl;
    //For each student, writes to the report the ID, answers, score, percentage, and grade
    for (auto i : studentData) {
        outFile << left << setw(10) << i->studentID << setw(25) << i->answers << setw(10) << i->score << fixed << setprecision(2) << setw(10) << i->percent << setw(8) << i->grade << endl;
    }
}