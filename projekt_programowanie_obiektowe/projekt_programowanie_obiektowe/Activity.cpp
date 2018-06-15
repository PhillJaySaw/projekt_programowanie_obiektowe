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
#include <iomanip>
#include <fstream>
#include "timer.hpp"
#include <chrono>

using namespace std;

Activity::Activity() {
    creation_date = time(0);
}

Activity::~Activity() {}

void Activity::start_new_activity() {
    char comment[100];      // activity comment
    char input[100];        // name of activity
    int t = 0;              // time goal
    this -> set_type_name("custom");
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
    
    cout << "Timer started!" << endl;
    this -> set_activity_time(timer());
    
    cout << "Activity finished!" << "Time: " << std::setprecision(2) << activity_time/60 << " minutes" << endl;
    cout << "Write comment: " << endl;
    
    cin.ignore();
    cin.getline(comment, 100);
    
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

void Activity::set_activity_time(double activity_time) {
    this -> activity_time = activity_time;
}

void Activity::set_type_name(string type_name) {
    this -> type_name = type_name;
}



/* **************** GETTERS **************** */

string Activity::get_name() const {
    return name;
}

double Activity::get_activity_time() const {
    return activity_time;
}

string Activity::get_comment() const {
    return comment;
}

string Activity::get_type() const{
    return type_name;
}

void Activity::print() {
    cout << "Activity name: " << this -> get_name() << endl << "Activity time: " << std::setprecision(2) << this -> get_activity_time()/60 << endl << endl;
}

time_t Activity::get_creation_date() const {
    return creation_date;
}

/* **************** SERIALIZATION **************** */


std::ostream& operator<<(std::ostream& os, const Activity* s) {
    
    os << s -> get_name() << '\n';
    os << s -> get_type() << '\n';
    os << s -> get_activity_time() << '\n';
    //os << s -> get_comment();
    return os;
}

istream& operator>>(istream& is, Activity* s) {
        is >> s -> name;
        is >> s -> type_name;
        is >> s -> activity_time;
    
    return is;
}













/* **************** FUNCTIONS **************** */

