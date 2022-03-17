//
// Created by Alexandra on 6/20/2021.
//

#include "RepoParticipants.h"
#include <fstream>

RepoParticipants::RepoParticipants() {
    this->LoadData();
}

RepoParticipants::~RepoParticipants() {

}

vector <Participant> &RepoParticipants::getParticipants() {
    return this->participants;
}

void RepoParticipants::LoadData() {
    ifstream inFile("participants.txt");
    Participant currentElement;
    this->participants.clear();
    while(inFile >> currentElement) {
        this->participants.push_back(currentElement);
    }
    inFile.close();
}

void RepoParticipants::updateParticipantScore(Question q, string answer, Participant& p) {
    if(q.getCorrectAnswer() == answer){
        int newScore = p.getScore() + q.getScore();
        p.setScore(newScore);
    }
    else
    {
        throw exception();
    }
}
