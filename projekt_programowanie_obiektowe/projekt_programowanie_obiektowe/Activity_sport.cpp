//
//  Activity_sport.cpp
//  projekt_programowanie_obiektowe
//
//  Created by Phillip on 11/06/2018.
//  Copyright © 2018 Phillip. All rights reserved.
//

#include "Activity_sport.hpp"
#include <iostream>
#include <iomanip>
#include "timer.hpp"

using namespace std;

void Activity_sport::start_new_activity() {
    char comment[100];      // activity comment
    char input[100];        // name of activity
    int t = 0;              // time goal
    
    this -> set_id();
    
    cout << "Name of workout: ";
    cin.ignore();
    cin.getline(input, 100);
    
    cout << "Set time goal in minutes (optional, you can leave this empty): ";  // TODO - you can't leave this empty
    cin >> t;
    
    set_name(input);
    set_time_goal(t);
    
    cout << "Press ENTER to start timer...";
    cin.ignore();
    cin.get();
    
    cout << "Timer started!" << endl;
    this -> set_activity_time(timer());
    
    cout << "Workout finished!" << "Time: " << std::setprecision(2) << get_activity_time()  /60 << " minutes" << endl;
    cout << "Set workout performance: " << endl;
    this -> performance_prompt();
    
    cout << "Write comment: " << endl;
    
    cin.ignore();
    cin.getline(comment, 100);
    
}

void Activity_sport::set_performance(int performance) {
    this -> performance = performance;
}

void Activity_sport::performance_prompt() {
    int input_performance = 0;
    
    while (performance == 0) {
        cout << "Enter workout performance on a scale from 1 to 5: ";
        cin >> input_performance;
        
        if(input_performance > 5 || input_performance < 1) {
            cout << "Entered number MUST be on a scale from 1 to 5.";
            input_performance = 0;
        } else this -> set_performance(input_performance);
    }
}
