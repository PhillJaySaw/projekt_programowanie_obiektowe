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
        cout << "(p)ause" << endl;
        cout << "(f)inish" << endl;
        cout << "(c)ancle" << endl;
        
        cin >> option;
        
        if(option == "p") {
            //this -> stop_time();
            auto stop = std::chrono::steady_clock::now();
            elapsed_time += double (std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count());
            cout << "Press enter to resume timer...";
            cin.ignore();
            cin.get();
            //this -> start_time();
            start = std::chrono::steady_clock::now();
            
        } else if (option == "f") {
            //this -> stop_time();
            auto stop = std::chrono::steady_clock::now();
            elapsed_time += double (std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count());
            return elapsed_time / 1e9;
            
        } else if (option == "c") {
            elapsed_time = 0;
            return elapsed_time;
        }
    }
}
