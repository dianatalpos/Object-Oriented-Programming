#pragma once
#include "Repository.h"
#include <QAbstractTableModel>

class MyModel:public QAbstractTableModel
{
private:
	Repository& repo;
public:
	MyModel(Repository& repo);

	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	~MyModel();
};

