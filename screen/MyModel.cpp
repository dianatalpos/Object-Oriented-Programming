#include "MyModel.h"



MyModel::MyModel(Repository& repo): repo{repo}
{
}

QVariant MyModel::headerData(int section, Qt::Orientation orientation, int role) const
{

	if (role == Qt::DisplayRole && orientation == Qt::Horizontal)
	{
		switch (section)
		{
		case 0:
			return "Description";
		case 1:
			return "Status";
		case 2:
			return "Creator";
		case 3:
			return "Act";
		default:
			break;
		}
	}

	return QVariant();
}

int MyModel::rowCount(const QModelIndex & parent) const
{
	return this->repo.getIdeas().size();
}

QVariant MyModel::data(const QModelIndex & index, int role) const
{
	int row = index.row();
	int column = index.column();

	if (role == Qt::DisplayRole)
	{
		switch (column)
		{
		case 0:
			return QString::fromStdString(this->repo.getIdeas()[row].getDescription());
			break;
		case 1:
			return QString::fromStdString(this->repo.getIdeas()[row].getStatus());
			break;
		case 2:
			return QString::fromStdString(this->repo.getIdeas()[row].getName());
			break;
		case 3:
			return QString::number(this->repo.getIdeas()[row].getAct());
		}
	}

	return QVariant();
}

int MyModel::columnCount(const QModelIndex & parent) const
{
	return 4;
}


MyModel::~MyModel()
{
}
