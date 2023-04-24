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
 * 
 * 
 * 
 * 
 * 
 * 
 */

//System Libraries
#include <iostream>  //Input/Output Library
#include <cstdlib> // rand()
#include <ctime>   // time()
#include <string> //string
#include <cstring> //c-strings
#include <cctype> // tolower()
#include <cmath>


#include "survey.h"
#include "survey_taker.h"
#include "User.h"
#include "Admin.h"

using namespace std;


//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes

//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    
    //Set random number seed once here
    srand(static_cast<unsigned int>(time(0)));

    int choice = 0;
    cout << "Welcome to Survey Maker!" << endl;
    cout<<"\n\n\tMenu\n"
        <<"1: Admin Login\n"
        <<"2: Sign Up\n"
        <<"3: User Login\n"
        <<"4: ReadInputFile()\n"
        <<"9: Exit\n"
        <<"Enter a number: ";
        cin>>choice;
        cin.ignore();
        
        switch(choice){
            case 1: // Admin login
            {
                Admin admin;
                admin.adminLogin();
                break;
            } 
            case 2: // User sign up for new account
            {
                User user1;
                user1.signUp();                 
                //user1.printUsr();
                break;
            }
            case 3:  // User login. If successful, then play game          
            {       
                
                Admin admin1;
                if(admin1.isUsrLogin()){
                    
                    cout<<"\n\nUser login was successful.\n"; 
                    //cout<<"\n inside main()";
                    //admin.printAdUsr();                    
                    
                    
                    // Create new User & copy admin values to user
                    User user2;
                    admin1.copy2Usr(user2);    
                    cout << "\nWelcome " << user2.getName();
                    user2.printUsr(); 
                    
                    //############################################################
                    //survey code
                    int numsur = 0; //number of surveys they have taken
                    char resp;
                    //this one will be used for the user
                    cout << endl << endl;
                    
                    do
                    { 
                        cout << endl << endl;
                        SurveyTaker surveyTaker;
                        surveyTaker.takeSurvey();
                        numsur++;
                        
                        cout << "Do you want to take another survey? Y/N" << endl;
                        cin >> resp;
                    
                    }while(resp=='y'||resp=='Y');
                    
                    
                    
                    long recLoc = admin1.getBegnFile();
                    
                    user2.setHiScore(numsur);
                    user2.reWrtBin(recLoc);

                    user2.printUsr();
                    admin1.findByIndx(user2.getNumRec());
                    admin1.printAdUsr();
                    //############################################################                      
                }
                break;
            }             
            case 4: // Read inputs to fill User binary with records
            {
                User user5;
                user5.readInputFile(); 
                break;
            }
            default: 
            {
                cout<<"\nGood Bye.\n";                
                exit(0);
            }
        }
    
    return 0;
}




