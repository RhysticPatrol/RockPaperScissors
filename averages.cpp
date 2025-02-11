#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;  

const int MAX_TESTS = 5;
const int MAX_STUDENTS = 100;
string names[MAX_STUDENTS]; //student array
int scores[MAX_STUDENTS][MAX_TESTS]; //2d array



char calculateletterGrade(double average) { //average calculater
    if (average >= 90) {
        return 'A';
    }
    else if (average >= 80) {
        return 'B';
    }
    else if (average >= 70) {
        return 'C';
    }
    else if (average >= 60) {
        return 'D';
    }
    else {
        return 'F';
    }
}


void readInData(ifstream *inFile, int numberOfLine) { //reading the file
    string line;
    int valuesPerLine = MAX_TESTS + 1;
    int index = 0;
    int lineIndex = 0;
    int lineScores[MAX_TESTS];  
    while(getline(*inFile, line, ' ')) {
        if (index == 0) { 
            names[lineIndex] = line;
        }
        else if (index < valuesPerLine) {
            if (index == valuesPerLine - 1) {
                scores[lineIndex][index-1] = stoi(line);
                if (stoi(line) == 100) {
                    names[++lineIndex] = line.substr(3); 
                }
                else if (stoi(line) >= 10){
                    names[++lineIndex] = line.substr(2);
                }
                else{
                    names[++lineIndex] = line.substr(1);
                }
                index = 0;
            }
            scores[lineIndex][index-1] = stoi(line);
        }
        index++;
    }
}

int getNumOfLine(ifstream *inFile) { //get student number
    string line;
    int numOfLines = 0;
    while(getline(*inFile, line)) {
        numOfLines++;
    }
    return numOfLines;
}

double getAvg(int scores[]) { 
    int sum = 0;
    for (int i = 0; i < MAX_TESTS; i++) {
        sum += scores[i];
    }
    return sum / MAX_TESTS;
}


void printAvgs(string names[], int scores[][MAX_TESTS], int numOfStudents) { //print a line of student name and letter grade
    for (int i = 0; i < numOfStudents; i++) {
        cout << names[i] << " " << calculateletterGrade(getAvg(scores[i]));
    }
}



int main() {
    ifstream inputFile("StudentGrades.txt");

    if (inputFile.is_open()) {
        int numLines = getNumOfLine(&inputFile);
        inputFile.clear();
        inputFile.seekg(0); // resets the getline
        readInData(&inputFile, numLines);
        printAvgs(names, scores, numLines);
    }
    else {
        cout << "File is not open." << endl;
        return 1; // Indicate an error
    }
    inputFile.close();
    return 0;
}
