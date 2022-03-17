//
// Created by Alexandra on 6/20/2021.
//

#pragma once
#include "Question.h"
#include "Observer.h"

class RepoQuestions: public Observable{

private:
    vector<Question> questions;
    void LoadData();
    void SaveData();

public:

    RepoQuestions();
    ~RepoQuestions();
    vector<Question>& getQuestions();
    void addQuestion(Question q);
    int checkExistence(Question q);
};

