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
#include <chrono>
#include <ctime>


using namespace std;

class Activity {
    static int activity_id;
    time_t creation_date;
    string name;                // name of the activity
    string type_name;           // activity type
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
    void set_type_name(string type_name);
    void set_creation_date(chrono::steady_clock::time_point date);
    
    void add_comment(string comment);
    
    int get_id() const;
    string get_name() const;
    double get_activity_time() const;
    string get_comment() const;
    string get_type() const;
    time_t get_creation_date() const;
    //string print_creation_date() const;
    
    virtual void print();
    
    // serialize & deserialize
    
    friend std::ostream& operator<<(std::ostream& os, const Activity* s);
    friend std::istream& operator>>(std::istream& is, Activity* s);
};

#endif /* Activity_h */
