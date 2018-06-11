//
//  Activity_sport.hpp
//  projekt_programowanie_obiektowe
//
//  Created by Phillip on 11/06/2018.
//  Copyright © 2018 Phillip. All rights reserved.
//

#ifndef Activity_sport_h
#define Activity_sport_h
#include "Activity.hpp"

class Activity_sport : public Activity {
    int performance;        // performance in scale form 1-5
    
public:
    
    void start_new_activity();
    void set_performance(int performance);
    void performance_prompt();
};

#endif /* Activity_sport_h */
