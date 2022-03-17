//
// Created by Alexandra on 6/20/2021.
//

#pragma once
using namespace std;
#include <iostream>
#include <sstream>
#include <string>
#include <vector>


class Question {

private:
    int id;
    string text;
    string correctAnswer;
    int score;

public:
    Question();
    Question(int id, string text, string correctAnswer, int score);
    ~Question();

    int getId();
    string getText();
    string getCorrectAnswer();
    int getScore();
    static vector<string> tokenize(string str, char delimiter);
    friend ostream& operator<<(ostream&, const Question&);

    friend istream& operator>>(istream&, Question&);


};
