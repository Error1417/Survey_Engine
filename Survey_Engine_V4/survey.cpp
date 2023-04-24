/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <iostream>
#include <string>
#include <fstream>

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
    cout << "Here is your survey:" << std::endl;
    for (int i = 0; i < questions.size(); ++i) {
        cout << "Question " << i + 1 << ": " << questions[i].questionText << endl;
        for (int j = 0; j < questions[i].answerChoices.size(); ++j) {
            cout << "  " << j + 1 << ". " << questions[i].answerChoices[j] << endl;
        }
    }
}

// Implementation of getter functions
int Survey::getNumQuestions() const {
    return questions.size();
}

string Survey::getQuestion(int index) const {
    return questions[index].questionText;
}

int Survey::getNumAnswerChoices(int questionIndex) const {
    return questions[questionIndex].answerChoices.size();
}

string Survey::getAnswerChoice(int questionIndex, int answerChoiceIndex) const {
    return questions[questionIndex].answerChoices[answerChoiceIndex];
}


string generateFileName() {
    time_t now = time(nullptr);
    tm* localTime = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "survey_%Y%m%d_%H%M%S.txt", localTime);
    return string(buffer);
}

string saveSurveyToFile(const Survey& survey) {
    string fileName = generateFileName();
    ofstream outFile(fileName);

    if (!outFile.is_open()) {
        cerr << "Error: Unable to create file " << fileName << endl;
        return "";
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
    return fileName;
}


void saveSurveyName(const string& surveyName) {
    ofstream outFile("survey_names.txt", ios::app);

    if (!outFile.is_open()) {
        cerr << "Error: Unable to open file survey_names.txt" << endl;
        return;
    }

    outFile << surveyName << endl;
    outFile.close();
}


Survey runSurveyCreator() {
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
    string fileName = saveSurveyToFile(survey);
    saveSurveyName(fileName);

    return survey;
}