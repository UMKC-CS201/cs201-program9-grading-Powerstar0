#include "functions.h"

//PRE: accepts a string
//POST: returns true if the string contains only digits, false otherwise
bool isDigits(string str) { 
	cout << "CODE THIS FUNCTION: isDigits\n";
	return true;
}

//PRE: accepts calculated score out of 40
//POST: returns a character 'A'-'F' based on the score
char calcGrade(int score) {
	cout << "CODE THIS FUNCTION: calcGrade\n";
	return 'W';
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
    inFile.open("/Users/johnnydiep/CLionProjects/cs201-program9-grading-Powerstar0/CS201PGM9-GradingTemplate/student.txt");
    if (!inFile.is_open()) {
        cout << "INPUT FILE NOT OPEN\n";
        return;
    }
    string inRec, answers, studAns, studIDStr;
    int studScore;
    float studPerc;
    char studGrade;
    getline(inFile, inRec);
    answers = inRec;
    while (getline(inFile, inRec)) {
        studScore = 0;
        studAns = inRec.substr(7,20);
        for (int i = 0; i < studAns.length(); i++) {
            if (studAns[i] == answers[i]) {
                studScore += 2;
            }
            else if (studAns[i] != ' ') {
                studScore += 1;
            }
        }
        studentInfo* newStud = new studentInfo;
        newStud->studentID = 0;
        newStud->score = studScore;
        newStud->answers = studAns;
        newStud->percent =0;
        newStud->grade = 'F';
        studentData.push_back(newStud);
    }
    inFile.close();
}


void printReport(ofstream& outFile, vector<studentInfo*>& studentData) {
	//cout << "CODE THIS FUNCTION: printReport\n";
    for (auto i : studentData) {
        cout << i->answers << endl;
    }
}