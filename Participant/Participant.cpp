//
// Created by Alexandra on 6/20/2021.
//

#include "Participant.h"

Participant::Participant() {

}

Participant::Participant(string name, int score): name{name}, score{score} {

}

Participant::~Participant() {

}

string Participant::getName() {
    return this->name;
}

int Participant::getScore() {
    return this->score;
}

void Participant::setScore(int s) {
    this->score = s;
}

istream &operator>>(istream &input, Participant &p) {
    input>>p.name>>p.score;
    return input;
}
