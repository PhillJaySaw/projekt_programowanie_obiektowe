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
    
    vector<Activity*> activitys;             // stores all activity objects
    //vector<Activity_sport> activitys_sport;
    //vector<Activity_study> activitys_study;
    //vector<Activity_hobby> activitys_hobby;
    //vector<Activity_video_games> activity_video_games;
    
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
                    {
                        Activity_sport *act_sport = new Activity_sport();
                        activitys.push_back(act_sport);
                        activitys.back()->start_new_activity();
                        break;
                    }
                    case 2:
                    {
                        Activity *act = new Activity();
                        activitys.push_back(act);
                        activitys.back()->start_new_activity();
                        break;
                    }
                    default:
                        break;
                }
                
                break;
                
            case 2:
                // loop through 'activitys' vector and
                // return activitys names
                for (unsigned long i = activitys.size() - 1, j = 0; j < 3 ; i--, j++) {
                    activitys[i] -> print();
                    if(!i) break;
                }
                break;
                
            case 4:
                exit--;
                break;
                
            default:
                break;
        }
    }
    

    // string Activity::serialize() // toString
    //zapis : przeiterowac po wszystkich i zapisac do pliku linie serialize()
    
    //static Activity* Activity::createFromString(string description)
    //
     //  description
   /// type = parse(desc) ,    if (type == sport) return new Activity_sport(nazwa,czas,perf,...)
     //   activitys.push_back(Activity::createFromstring(...))
    
    return 0;
}














