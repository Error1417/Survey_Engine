/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "survey_taker.h"

using namespace std;

SurveyTaker::SurveyTaker() {
    loadAvailableSurveys();
}

void SurveyTaker::loadAvailableSurveys() {
    ifstream inFile("survey_names.txt");

    if (!inFile.is_open()) {
        cerr << "Error: Unable to open file survey_names.txt" << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) {
        availableSurveys.push_back(line);
    }

    inFile.close();
}

void SurveyTaker::listAvailableSurveys() {
    cout << "Available surveys:" << endl;
    for (int i = 0; i < availableSurveys.size(); i++) {
        cout << i + 1 << ". " << availableSurveys[i] << endl;
    }
}

void SurveyTaker::takeSurvey() {
    if (availableSurveys.empty()) {
        cout << "No surveys available." << endl;
        return;
    }

    listAvailableSurveys();
    cout << "Enter the number of the survey you want to take: ";

    int choice;
    while (!(cin >> choice) || choice <= 0 || choice > availableSurveys.size()) {
        cerr << "Invalid input. Please enter a valid survey number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    string surveyFileName = availableSurveys[choice - 1];
    ifstream inFile(surveyFileName);

    if (!inFile.is_open()) {
        cerr << "Error: Unable to open survey file " << surveyFileName << endl;
        return;
    }

    string line;
    int questionCounter = 0;
    while (getline(inFile, line)) {
        stringstream ss(line);
        string token;
        ss >> token;

        if (token == "Question") {
            questionCounter++;
            cout << line << endl;

            for (int i = 0; i < 4; i++) { // Display all 4 answer choices
                getline(inFile, line);
                cout << line << endl;
            }

            cout << "Enter your choice (1-4): ";
            int answer;
            while (!(cin >> answer) || answer <= 0 || answer > 4) {
                cerr << "Invalid input. Please enter a valid answer choice (1-4): ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            userAnswers.push_back(answer);
        }
    }

    inFile.close();
    saveAnswers(surveyFileName);
}



void SurveyTaker::saveAnswers(const string& surveyFileName) {
    string resultFileName = "results_" + surveyFileName;
    ofstream outFile(resultFileName, ios::app);

    if (!outFile.is_open()) {
        cerr << "Error: Unable to create file " << resultFileName << endl;
        return;
    }

    // Add a timestamp to the results for better organization
    time_t now = time(nullptr);
    tm* localTime = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", localTime);
    outFile << "Timestamp: " << buffer << endl;
    
    
    // Save the user's answers in a structured way
    for (int i = 0; i < userAnswers.size(); i++) {
        outFile << "Question " << i + 1 << ": " << userAnswers[i] << endl;
    }

    outFile << endl; // Add an extra newline to separate different user responses

    outFile.close();
    cout << "Your answers have been saved to file: " << resultFileName << endl;
    userAnswers.clear();
}