#include "Model.h"
#include <QBrush>



Model::Model(Repository& repo) : repo{repo}
{
}

void Model::notify()
{
	emit layoutChanged();
}


QVariant Model::data(const QModelIndex & index, int role) const
{
	int row = index.row();
	int column = index.column();
	if (role == Qt::DisplayRole)
	{
		if (column == 0)
		{
			return QString::fromStdString(this->repo.getTeam()[row]->getName());
		}
	}
	if (role == Qt::BackgroundRole)
	{
		if (column == 1)
		{
			if (this->repo.getTeam()[row]->getFiles() == 0)
			{
				QBrush q{ "blue" };
				return q;
			}
		}
	}
	return QVariant();
}

int Model::rowCount(const QModelIndex & parent) const
{
	return this->repo.getTeam().size();
}

int Model::columnCount(const QModelIndex & parent) const
{
	return 2;
}

Model::~Model()
{
}
