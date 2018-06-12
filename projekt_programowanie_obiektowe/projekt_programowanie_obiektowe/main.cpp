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
    
    vector<Activity*> activitys;    // stores all activity objects
    int option;                     // used for selecting actions in main loop
    int exit = 1;                   // controls when to exit main loop
    
    
    cout << "########### /ACTIVITY TRACKER\\ ###########" << endl;
    
    
    // main program loop
    while(exit) {
        
        // main menu
        cout << endl << "Select action to perform:" << endl;
        cout << "1. Start new Activity" << endl;
        cout << "2. View last three completed activitys" << endl;
        cout << "3. Something" << endl;
        cout << "4. Exit" << endl;
        
        cout << endl << "action number: ";
        cin >> option;
        cout << endl;
        
        switch (option) {
            case 1:
                
                // activity type seldction
                cout << "Select activity type:" << endl;
                cout << "1. Sport" << endl;
                cout << "2. Study" << endl;
                cout << "3. Hobby" << endl;
                cout << "4. Video Games" << endl;
                cout << "5. Custom" << endl;
                cout << "6. <-- Back";
                
                cout << endl << "type number: ";
                cin >> option;
                
                
                switch (option) {
                    case 1:
                    {
                        // adding new activity to vector and
                        // triggering start_new_activity
                        Activity_sport *act_sport = new Activity_sport();
                        activitys.push_back(act_sport);
                        activitys.back()->start_new_activity();
                        break;
                    }
                    case 2:
                    {
                        Activity_study *act = new Activity_study();
                        activitys.push_back(act);
                        activitys.back()->start_new_activity();
                        break;
                    }
                    case 3:
                    {
                        Activity_hobby *act = new Activity_hobby();
                        activitys.push_back(act);
                        activitys.back()->start_new_activity();
                        break;
                    }
                    case 4:
                    {
                        Activity_video_games *act = new Activity_video_games();
                        activitys.push_back(act);
                        activitys.back()->start_new_activity();
                        break;
                    }
                    case 5:
                    {
                        Activity *act = new Activity();
                        activitys.push_back(act);
                        activitys.back()->start_new_activity();
                        break;
                    }
                    case 6:
                        break;
                    default:
                        break;
                }
                
                break;
                
            case 2:
                // loop through 'activitys' vector and
                // return last 3 activitys
                if(activitys.size() > 0)
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














