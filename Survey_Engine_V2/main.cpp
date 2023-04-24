/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: error
 *
 * Created on April 18, 2023, 9:18 PM
 */

#include <iostream>
#include <fstream>
#include <ctime>
#include "survey.h"

using namespace std;


string generateFileName();
void saveSurveyToFile(const Survey&);
    

int main() {
    int numQuestions;
    cout << "Welcome to the survey creator!" << endl;
    cout << "Enter the number of questions for your survey: ";
    
    while (!(cin >> numQuestions) || numQuestions <= 0) {
        cerr << "Invalid input. Please enter a positive number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    Survey survey(numQuestions);

    for (int i = 0; i < numQuestions; ++i) {
        string question;

        cin.ignore(); // Ignore newline from previous input
        cout << "Enter question " << i + 1 << ": ";
        getline(cin, question);
        survey.setQuestion(i, question);

        cout << endl;
        cout << "Enter 4 answers for this question." << endl;
        


        for (int j = 0; j < 4; ++j) { // iterate only 4 times
            string option;
            cout << "Enter option " << j + 1 << " for question " << i + 1 << ": ";
            getline(cin, option);
            survey.addAnswerChoice(i, option);
        }
    }
    
    cout << endl;
    survey.display();
    saveSurveyToFile(survey);

    return 0;
}



string generateFileName() {
    time_t now = time(nullptr);
    tm* localTime = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "survey_%Y%m%d_%H%M%S.txt", localTime);
    return string(buffer);
}

void saveSurveyToFile(const Survey& survey) {
    string fileName = generateFileName();
    ofstream outFile(fileName);

    if (!outFile.is_open()) {
        cerr << "Error: Unable to create file " << fileName << endl;
        return;
    }

    int numQuestions = survey.getNumQuestions();

    for (int i = 0; i < numQuestions; ++i) {
        outFile << "Question " << i + 1 << ": " << survey.getQuestion(i) << endl;
        int numOptions = survey.getNumAnswerChoices(i);

        for (int j = 0; j < numOptions; ++j) {
            outFile << "  " << j + 1 << ". " << survey.getAnswerChoice(i, j) << endl;
        }
    }

    outFile.close();
    cout << "Survey saved to file: " << fileName << endl;
}

