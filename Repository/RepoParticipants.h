//
// Created by Alexandra on 6/20/2021.
//

#pragma once
#include "Participant.h"
#include <vector>
#include "Question.h"

class RepoParticipants {

private:
    vector<Participant> participants;
    void LoadData();

public:
    RepoParticipants();
    ~RepoParticipants();

    vector<Participant>& getParticipants();
    void updateParticipantScore(Question q, string answer, Participant& p);
};
