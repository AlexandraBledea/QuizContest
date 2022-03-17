//
// Created by Alexandra on 6/20/2021.
//

#pragma once
#include "RepoQuestions.h"
#include <QWidget>
#include "Observer.h"
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QLabel>
#include "TableModel.h"
#include <QTableView>
#include <QVBoxLayout>
#include <QSortFilterProxyModel>
#include <QMessageBox>
#include "Participant.h"
#include "RepoParticipants.h"


class ParticipantWindow: public QWidget, public Observer {

private:
    RepoParticipants& repoParticipants;
    RepoQuestions& repo;
    Participant& p;
    TableModel* tableModel;
    QTableView* questionsTableView;
    QLineEdit* answerLineEdit;
    QPushButton* answerButton;
    QLabel* answerLabel;
    QVBoxLayout* mainLayout;
    QGridLayout* buttonsLayout;
    QLabel* scoreLabel;

public:
    ParticipantWindow(RepoQuestions& repo, RepoParticipants& repoParticipants, Participant& p, QWidget*parent = Q_NULLPTR);
    ~ParticipantWindow();
    void update() override;
    void notifyModel();
    void initGUI();
    void connectSignals();
    void answerQuestion();
    void checkIfAnswered(const QModelIndex& index);
};
