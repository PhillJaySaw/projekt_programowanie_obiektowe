//
//  Activity.cpp
//  projekt_programowanie_obiektowe
//
//  Created by Phillip on 08/06/2018.
//  Copyright © 2018 Phillip. All rights reserved.
//

#include "Activity.hpp"
#include <iostream>
#include <string>
#include <limits>


using namespace std;

Activity::Activity() {
    this -> start_new_activity();
}

Activity::~Activity() {
    
}

void Activity::start_new_activity() {
    char input[100]; // name of activity
    int t = 0;       // time goal
    
    this -> set_id();
    
    cout << "Name of activity: ";
    cin.ignore();
    cin.getline(input, 100);
    
    cout << "Set time goal in minutes (optional, you can leave this empty): ";  // TODO - you can't leave this empty
    cin >> t;
    
    set_name(input);
    set_time_goal(t);
    
    cout << "Press ENTER to start timer...";
    cin.ignore();
    cin.get();
    
    start_time();
    cout << "Timer started!" << endl;
    
}

/* **************** SETTERS **************** */

void Activity::set_id() {
    
}

void Activity::set_name(string name) {
    this -> name = name;
}

void Activity::set_time_goal(int time_goal_in_minutes = 0) {
    this -> time_goal_in_minutes = time_goal_in_minutes;
}

void Activity::add_comment(string comment) {
    this -> comment.append(comment);
}

/* **************** GETTERS **************** */

//int Activity::get_id() {
//    return this -> activity_id;
//}

string Activity::get_name() {
    return this -> name;
}

int Activity::get_activity_time() {
    return activity_time;
}

string Activity::get_comment() {
    return comment;
}

/* **************** TIMER **************** */

void Activity::start_time() {
    
}

void Activity::stop_time() {
    
}

void Activity::pause_time() {
    
}
