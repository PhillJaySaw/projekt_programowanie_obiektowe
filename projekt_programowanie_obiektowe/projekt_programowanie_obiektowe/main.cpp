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
        
        cout << "Select action to perform:" << endl;
        cout << "1. Start new Activity" << endl;
        cout << "2. View last three completed activitys" << endl;
        cout << "3. Something" << endl;
        cout << "4. Exit" << endl;
        
        cout << endl << "action number: ";
        cin >> option;
        
        switch (option) {
            case 1:
                activity_number++;
                activitys.resize(activity_number);
                break;
                
            case 2:
                for (int i = 0; i < 3 || i < activitys.size(); i++) {
                    cout << activitys[i].get_name() << endl;
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
