#pragma once
#include <QAbstractTableModel>
#include "Repository.h"
class Model: public QAbstractTableModel
{
private:
	Repository& repo;
public:
	Model(Repository& repo);
	
	void notify();

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
	int rowCount(const QModelIndex &parent = QModelIndex()) const;
	int columnCount(const QModelIndex &parent = QModelIndex()) const;
	~Model();
};

