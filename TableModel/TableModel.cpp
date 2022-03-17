//
// Created by Alexandra on 6/20/2021.
//

#include <QFont>
#include "TableModel.h"
#include <QBrush>

TableModel::TableModel(RepoQuestions &repository, QObject *parent): repository{repository}, QAbstractTableModel(parent), indexes{vector<int>{}} {
}

TableModel::~TableModel() {

}

int TableModel::rowCount(const QModelIndex &parent) const {
    return this->repository.getQuestions().size();
}

int TableModel::columnCount(const QModelIndex &parent) const {
    return 3;
}

QVariant TableModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    int column = index.column();
    if( role == Qt::DisplayRole || role == Qt::EditRole)
    {
        vector<Question> questions = this->repository.getQuestions();
        Question f = questions[row];
        switch(column)
        {
            case 0:
                return QString::fromStdString(to_string(f.getId()));

            case 1:
                return QString::fromStdString(f.getText());

            case 2:
                return QString::fromStdString(to_string(f.getScore()));

            default:
                break;

        }

    }


    if(role == Qt::FontRole)
    {
        QFont font("Times", 15, 10, true);
        font.setBold(true);
        font.setItalic(false);
        return font;
    }

    if(role == Qt::BackgroundRole){
        int row = index.row();
        if(find(this->indexes.begin(), this->indexes.end(), row) != this->indexes.end()){
            return QBrush{QColor{Qt::green}};
        }
    }

    return QVariant{};
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if(role == Qt::DisplayRole)
    {
        if(orientation == Qt::Horizontal)
        {
            switch(section){
                case 0:
                    return QString{"ID"};

                case 1:
                    return QString{"Text"};

                case 2:
                    return QString{"Score"};

                default:
                    break;
            }
        }
    }
    if(role == Qt::FontRole)
    {
        QFont font("Times", 15, 10, true);
        font.setBold(true);
        font.setItalic(false);
        return font;
    }

    return QVariant{};
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const {
    return Qt::ItemIsSelectable | Qt::ItemIsEditable | Qt::ItemIsEnabled;
}

void TableModel::updateInternalData() {
    endResetModel();
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role) {



}

bool TableModel::addBackground(int idx) {
    this->indexes.push_back(idx);
}
