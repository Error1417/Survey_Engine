/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   survey_taker.h
 * Author: error
 *
 * Created on April 23, 2023, 4:46 PM
 */

#ifndef SURVEY_TAKER_H
#define SURVEY_TAKER_H

#include <vector>
#include <string>

using namespace std;

class SurveyTaker {
public:
    SurveyTaker();

    void listAvailableSurveys();
    void takeSurvey();
    void saveAnswers(const string& surveyFileName);

private:
    vector<string> availableSurveys;
    vector<int> userAnswers;

    void loadAvailableSurveys();
};

#endif /* SURVEY_TAKER_H */

