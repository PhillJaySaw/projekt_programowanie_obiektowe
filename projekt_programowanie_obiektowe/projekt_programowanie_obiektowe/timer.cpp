//
//  Timer.cpp
//  projekt_programowanie_obiektowe
//
//  Created by Phillip on 10/06/2018.
//  Copyright © 2018 Phillip. All rights reserved.
//

#include "timer.hpp"
#include <iostream>
#include <chrono>

using namespace std;

double timer(int time_goal) {
    string option;
    double elapsed_time = 0;
    auto start = std::chrono::steady_clock::now();
    
    while (true) {
        cout << "Options:" << endl;
        cout << "(pause) activity" << endl;
        cout << "(finish) activity" << endl;
        cout << "(cancle) activity" << endl;
        
        cin >> option;
        
        if(option == "pause") {
            //this -> stop_time();
            auto stop = std::chrono::steady_clock::now();
            elapsed_time += double (std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count());
            cout << "Press enter to resume timer...";
            cin.ignore();
            cin.get();
            //this -> start_time();
            start = std::chrono::steady_clock::now();
            
        } else if (option == "finish") {
            //this -> stop_time();
            auto stop = std::chrono::steady_clock::now();
            elapsed_time += double (std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count());
            return elapsed_time / 1e9;
            
        } else if (option == "cancle") {
            elapsed_time = 0;
            return elapsed_time;
        }
    }
}
