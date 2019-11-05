#pragma once
#include "Repository.h"
#include <QAbstractListModel>

class MyModel: public QAbstractListModel
{
private:
	Repository& repo;

public:
	MyModel(Repository& repo);
	

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	~MyModel();
};

