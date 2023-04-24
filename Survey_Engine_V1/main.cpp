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
#include "survey.h"

using namespace std;

int main() {
    int numQuestions;
    cout << "Welcome to the survey creator!" << endl;
    cout << "Enter the number of questions for your survey: ";
    cin >> numQuestions;

    Survey survey(numQuestions);

    for (int i = 0; i < numQuestions; ++i) {
        string question;
        int numOptions;

        cin.ignore(); // Ignore newline from previous input
        cout << "Enter question " << i + 1 << ": ";
        getline(cin, question);
        survey.setQuestion(i, question);

        cout << "Enter the number of answer choices for question " << i + 1 << ": ";
        cin >> numOptions;

        for (int j = 0; j < numOptions; ++j) {
            string option;
            cin.ignore();
            cout << "Enter option " << j + 1 << " for question " << i + 1 << ": ";
            getline(cin, option);
            survey.addAnswerChoice(i, option);
        }
    }

    survey.display();

    return 0;
}
