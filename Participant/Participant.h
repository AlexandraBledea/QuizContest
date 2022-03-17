//
// Created by Alexandra on 6/20/2021.
//

#pragma once
using namespace std;
#include <iostream>
#include <sstream>
#include <string>

class Participant {

private:
    string name;
    int score;

public:

    Participant();
    Participant(string name, int score);
    ~Participant();
    string getName();
    int getScore();
    void setScore(int s);
    friend istream& operator>>(istream&, Participant&);

};
