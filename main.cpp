#include <iostream>
#include <QApplication>
#include "RepoQuestions.h"
#include "RepoParticipants.h"
#include "PresenterWindow.h"
#include "ParticipantWindow.h"

int main(int argc, char** argv) {
    QApplication a(argc, argv);

    RepoQuestions repoQuestions;
    RepoParticipants repoParticipants;
    vector<ParticipantWindow*> windows;
    for(auto & p: repoParticipants.getParticipants()){
        windows.push_back(new ParticipantWindow(repoQuestions, repoParticipants, p));
    }

    PresenterWindow presenterWindow(repoQuestions);

    return a.exec();
}
