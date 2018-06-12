//
//  Header.hpp
//  projekt_programowanie_obiektowe
//
//  Created by Phillip on 08/06/2018.
//  Copyright © 2018 Phillip. All rights reserved.
//

#ifndef Activity_h
#define Activity_h
#include <string>

using namespace std;

class Activity {
    static int activity_id;
    string name;                // name of the activity
    int type_id;                // activity type id
    int time_goal_in_minutes;
    double activity_time;       // stores the final activity time in seconds
    string comment;
    
    
public:
    /*
    this function will be executed in the constructor,
    each activity type has some additional starting
    parameters like in sport we would like like to choose the
    type of sport or in studying the faculty.
    */
    virtual void start_new_activity();
    
    Activity();
    ~Activity();
    
    // getters and setter
    void set_id();               // TODO - figure out way to create uniqe id for every new object
    void set_name(string name);
    void set_time_goal(int time_goal_in_min);
    void set_activity_time(double activity_time);
    
    void add_comment(string comment);
    
    int get_id();
    string get_name();
    double get_activity_time();
    string get_comment();
    
    virtual void print();
};

#endif /* Activity_h */
