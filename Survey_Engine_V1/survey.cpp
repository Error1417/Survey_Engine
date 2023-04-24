/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <string>
#include "survey.h"

using namespace std;

Survey::Survey(int numQuestions) {
    questions.resize(numQuestions);
}

void Survey::setQuestion(int index, const string& question) {
    questions[index].questionText = question;
}

void Survey::addAnswerChoice(int questionIndex, const string& answerChoice) {
    questions[questionIndex].answerChoices.push_back(answerChoice);
}

void Survey::display() const {
    cout << "Here is your survey:" << endl;
    for (int i = 0; i < questions.size(); ++i) {
        std::cout << "Question " << i + 1 << ": " << questions[i].questionText << endl;
        for (int j = 0; j < questions[i].answerChoices.size(); ++j) {
            std::cout << "  " << j + 1 << ". " << questions[i].answerChoices[j] << endl;
        }
    }
}