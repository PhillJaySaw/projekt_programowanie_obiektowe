//
//  main.cpp
//  projekt_programowanie_obiektowe
//
//  Created by Phillip on 07/06/2018.
//  Copyright © 2018 Phillip. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include "Activity.hpp"
#include "Activity_study.hpp"
#include "Activity_hobby.hpp"
#include "Activity_video_games.hpp"
#include "Activity_sport.hpp"


int main(int argc, const char * argv[]) {
    
    vector<Activity> activitys;             // stores all activity object
    vector<Activity_sport> activitys_sport;
    vector<Activity_study> activitys_study;
    vector<Activity_hobby> activitys_hobby;
    vector<Activity_video_games> activity_video_games;
    
    
    int activity_number = 0;        // stores amount of activities
    int activity_sport_number = 0;
    int option;                     // used for selecting actions in main loop
    int option_act_type;            // used for selecting activity type
    
    int exit = 1;
    cout << "########### /ACTIVITY TRACKER\\ ###########" << endl;
    
    
    // main program loop
    while(exit) {
        
        option = 0;
        option_act_type = 0;
        cout << endl << "Select action to perform:" << endl;
        cout << "1. Start new Activity" << endl;
        cout << "2. View last three completed activitys" << endl;
        cout << "3. Something" << endl;
        cout << "4. Exit" << endl;
        
        cout << endl << "action number: ";
        cin >> option;
        
        switch (option) {
            case 1:
                // Add activity to 'activitys' vector
                // a new Activity object is created
                // and the constructor of activity is triggered
                //activity_number++;
                //activitys.resize(activity_number);
                
                cout << "Select activity type:" << endl;
                cout << "1. Sport" << endl;
                cout << "2. Custom" << endl;
                
                cout << endl << "type number: ";
                cin >> option_act_type;
                
                switch (option_act_type) {
                    case 1:
                        activity_sport_number++;
                        activitys_sport.resize(activity_sport_number);
                        break;
                        
                    case 2:
                        activity_number++;
                        activitys.resize(activity_number);
                        break;
                        
                    default:
                        break;
                }
                
                break;
                
            case 2:
                // loop through 'activitys' vector and
                // return activitys names
                for (int i = 0; i < activitys.size() && i < 3; i++) {
                    cout << "Activity name: " << activitys[i].get_name() << endl << "Activity time: " << std::setprecision(2) << activitys[i].get_activity_time()/60 << endl << endl;
                }
                
                for (int i = 0; i < activitys_sport.size() && i < 3; i++) {
                    cout << "Workout name: " << activitys_sport[i].get_name() << endl << "Activity time: " << std::setprecision(2) << activitys_sport[i].get_activity_time()/60 << endl << endl;
                }
                break;
                
            case 4:
                exit--;
                break;
                
            default:
                break;
        }
    }
    
    return 0;
}
