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
#include "survey_taker.h"

using namespace std;


int main() {
    cout << "Welcome to the survey application!" << endl;
    cout << "1. Create a new survey" << endl;
    cout << "2. Take an existing survey" << endl;
    cout << "Enter your choice (1 or 2): ";

    int choice;
    while (!(cin >> choice) || (choice != 1 && choice != 2)) {
        cerr << "Invalid input. Please enter 1 to create a new survey or 2 to take an existing survey: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (choice == 1) {
        runSurveyCreator();
    } else {
        SurveyTaker surveyTaker;
        surveyTaker.takeSurvey();
    }

    return 0;
}




