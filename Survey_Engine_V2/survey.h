/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   survey.h
 * Author: error
 *
 * Created on April 18, 2023, 9:21 PM
 */

#ifndef SURVEY_H
#define SURVEY_H

#include <vector>
#include <string>

using namespace std;


class Survey {
public:
    Survey(int numQuestions);

    void setQuestion(int index, const string& question);
    void addAnswerChoice(int questionIndex, const string& answerChoice);
    void display() const;

   
    int getNumQuestions() const;
    string getQuestion(int index) const;
    int getNumAnswerChoices(int questionIndex) const;
    string getAnswerChoice(int questionIndex, int answerChoiceIndex) const;
    
private:
    struct Question {
        string questionText;
        vector<string> answerChoices;
    };

    vector<Question> questions;
};


#endif /* SURVEY_H */

