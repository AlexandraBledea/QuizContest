//
// Created by Alexandra on 6/20/2021.
//

#pragma once
#include <QAbstractTableModel>
#include "RepoQuestions.h"

class TableModelPresenter: public QAbstractTableModel{

private:
    RepoQuestions& repository;

public:
    TableModelPresenter(RepoQuestions& repository, QObject* parent = NULL);

    ~TableModelPresenter();

// number of rows
    int rowCount(const QModelIndex &parent = QModelIndex{}) const override;

// number of columns
    int columnCount(const QModelIndex &parent = QModelIndex{}) const override;

// Value at a given position
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

// add header data
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

// will be called when a cell is edited
//    bool setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole) override;

// used to set certain properties of a cell
    Qt::ItemFlags flags(const QModelIndex & index) const override;

    void updateInternalData();

};
