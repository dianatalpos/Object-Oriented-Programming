#pragma once
#include <QAbstractListModel>
#include "Repository.h"

class MyModel:public  QAbstractListModel
{
private:
	Repository& repo;
public:

	MyModel(Repository& repo);
	
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	~MyModel();
};

