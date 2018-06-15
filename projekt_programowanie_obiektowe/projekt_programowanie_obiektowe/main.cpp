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
#include <fstream>
#include "Activity.hpp"
#include "Activity_study.hpp"
#include "Activity_hobby.hpp"
#include "Activity_video_games.hpp"
#include "Activity_sport.hpp"
#include <ctime>


void view_activities_form_last_week(vector<Activity*> activitys_vector ,string activity_type = "", string activity_name = "");
double view_activities_summary(vector<Activity*> activitys_vector,string activity_typ);

// check if files is empty


int main(int argc, const char * argv[]) {
    
    vector<Activity*> activitys;    // stores all activity objects
    int option;                     // used for selecting actions in main loop
    int exit = 1;                   // controls when to exit main loop
    
    // *** LOADING ACTIVITYS *** //
    ifstream ifs("activity_list.txt");
    if(!(ifs.peek() == ifstream::traits_type::eof())) {
        while(ifs.good()) {
            Activity *acti = new Activity();
            //if (ifs.() == 0 ) continue;
            ifs >> acti;
            activitys.push_back(acti);
        }
        ifs.close();
    }
    // ************************ //
    
    
    cout << "########### /ACTIVITY TRACKER\\ ###########" << endl;
    
    
    // main program loop
    while(exit) {
        
        // main menu
        cout << endl << "Select action to perform:" << endl;
        cout << "1. Start new activity" << endl;
        cout << "2. Last 3 activities" << endl;
        cout << "3. View all activities" << endl;
        cout << "4. See last week" << endl;
        cout << "5. Exit" << endl;
        
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
            
            case 3:
                // loop through 'activitys' vector
                // and print all
                if(activitys.size() > 0)
                    for (int i = int(activitys.size() - 1); i >= 0; i--) {
                        activitys[i] -> print();
                        if(!i) break;
                    }
                break;
                
            case 4:
                //view_activities_form_last_week(activitys, "sport");
                cout << "You spent " << std::setprecision(2) << view_activities_summary(activitys, "sport") << " minutes on sport." << endl;
                cout << "You spent " << std::setprecision(2) << view_activities_summary(activitys, "study") << " minutes on studying." << endl;
                cout << "You spent " << std::setprecision(2) << view_activities_summary(activitys, "hobby") << " minutes on hobbys." << endl;
                cout << "You spent " << std::setprecision(2) << view_activities_summary(activitys, "video games") << " minutes on video games." << endl;
                cout << "You spent " << std::setprecision(2) << view_activities_summary(activitys, "custom") << " minutes on other activities." << endl;
                break;
                
            case 5:
                exit--;
                break;
                
            default:
                break;
        }
    }
    
    // *** SAVING ACTIVITYS *** //
    
    if(activitys.size()>0) {
        ofstream ofs("activity_list.txt");
        for(int i = 0; i < activitys.size(); i++)
            ofs << activitys[i];
        ofs.close();
    }

    // *********************** //
    
    // string Activity::serialize() // toString
    //zapis : przeiterowac po wszystkich i zapisac do pliku linie serialize()
    
    //static Activity* Activity::createFromString(string description)
    //
     //  description
   /// type = parse(desc) ,    if (type == sport) return new Activity_sport(nazwa,czas,perf,...)
     //   activitys.push_back(Activity::createFromstring(...))
    
    return 0;
}

void view_activities_form_last_week(vector<Activity*> activitys_vector,string activity_typ, string activity_name) {
    if(activitys_vector.size() > 0) {
        
        cout << "These are all your last week activities:" ;
        
        for (int i = int(activitys_vector.size() - 1); i >= 0; i--) {
            
            if(difftime(time(0),activitys_vector[i] -> get_creation_date()) <= 604800) {
                
                if(activitys_vector[i] -> get_type() == activity_typ || activity_typ == ""){
                    
                    if(activitys_vector[i] -> get_name() == activity_name || activity_name == "") {
                        
                       activitys_vector[i] -> print();
                    }
                }
            } else { break; }
        }
    }
}

double view_activities_summary(vector<Activity*> activitys_vector,string activity_typ) {
    
    double time_summary = 0;
    
    if(activitys_vector.size() > 0) {
        for (int i = int(activitys_vector.size() - 1); i >= 0; i--) {
            
            if(difftime(time(0),activitys_vector[i] -> get_creation_date()) <= 604800) {
                
                if(activitys_vector[i] -> get_type() == activity_typ || activity_typ == ""){
                    
                    time_summary += (activitys_vector[i] -> get_activity_time())/60;
                    
                }
            } else { break; }
        }
    }
    return time_summary;
}











