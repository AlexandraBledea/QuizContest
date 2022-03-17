//
// Created by Alexandra on 6/20/2021.
//

#include "RepoQuestions.h"
#include <fstream>
#include <algorithm>

RepoQuestions::RepoQuestions() {
    this->LoadData();
}

RepoQuestions::~RepoQuestions() {

}

vector <Question> &RepoQuestions::getQuestions() {
    return this->questions;
}

void RepoQuestions::LoadData() {
    ifstream inFile("questions.txt");
    Question currentElement;
    this->questions.clear();
    while(inFile >> currentElement) {
        this->questions.push_back(currentElement);
    }
    ::sort(this->questions.begin(), this->questions.end(), [](Question q1, Question q2){
       return q1.getId()<q2.getId();
    });
    inFile.close();
}

void RepoQuestions::addQuestion(Question q) {
    int pos = this->checkExistence(q);
    if(pos == -1){
        this->questions.push_back(q);
        ::sort(this->questions.begin(), this->questions.end(), [](Question q1, Question q2){
            return q1.getId()<q2.getId();
        });
        this->SaveData();
        this->notify();
    }
    else
    {
        throw exception();
    }
}

int RepoQuestions::checkExistence(Question q) {
    for(int i = 0; i < this->questions.size(); i++){
        if(this->questions[i].getId() == q.getId())
            return i;
    }
    return -1;
}

void RepoQuestions::SaveData() {
    ofstream OutFile("questions.txt");
    for(auto & q: this->questions){
        OutFile<<q<<'\n';
    }
}

