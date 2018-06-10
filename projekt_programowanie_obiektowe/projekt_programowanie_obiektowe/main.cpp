//
//  main.cpp
//  projekt_programowanie_obiektowe
//
//  Created by Phillip on 07/06/2018.
//  Copyright © 2018 Phillip. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Activity.hpp"


int main(int argc, const char * argv[]) {
    
    vector<Activity> activitys;     // stores all activity object
    int activity_number = 0;        // stores amount of activities
    int option;                     // used for selecting actions in main loop
    
    int exit = 1;
    cout << "########### /ACTIVITY TRACKER\\ ###########" << endl;
    
    
    // main program loop
    while(exit) {
        
        option = 0;
        
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
                activity_number++;
                activitys.resize(activity_number);
                break;
                
            case 2:
                // loop through 'activitys' vector and
                // return activitys names
                for (int i = 0; i < activitys.size() && i < 3; i++) {
                    cout << "Activity name: " << activitys[i].get_name() << endl << "Activity time: " << activitys[i].get_activity_time()/60 << endl << endl;
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
