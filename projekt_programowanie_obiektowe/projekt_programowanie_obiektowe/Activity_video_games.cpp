//
//  Activity_video_games.cpp
//  projekt_programowanie_obiektowe
//
//  Created by Phillip on 12/06/2018.
//  Copyright © 2018 Phillip. All rights reserved.
//

#include "Activity_video_games.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include "timer.hpp"

void Activity_video_games::start_new_activity() {
    char comment[100];      // activity comment
    char input[100];        // name of activity
    int t = 0;              // time goal
    this -> set_type_name("video games");
    this -> set_id();
    
    cout << "Name of game: ";
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
    
    cout << "Playing " << this -> get_name() << " finished!" << "Time: " << std::setprecision(2) << get_activity_time()/60 << " minutes" << endl;
    cout << "Write comment: " << endl;
    
    cin.ignore();
    cin.getline(comment, 100);
}
