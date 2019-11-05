#include "MyModel.h"
#include <Qfont>
#include <QBrush>

MyModel::MyModel(Repository& repo): repo{repo}
{
}


QVariant MyModel::data(const QModelIndex & index, int role) const
{
	int row = index.row();
	SourceFile file = this->repo.getFile(row);
	if (role == Qt::DisplayRole)
	{
		QString str = QString::fromStdString(file.getName() + " " + file.getStatus() + " " + file.getCreator() + " " + file.getReviewer());

		if (file.getStatus() == "not_revised")
		{
			//str.setBold(true);
		}
		return QString::fromStdString(file.getName() + " " + file.getStatus() + " " + file.getCreator() + " " + file.getReviewer());

	}
	if (role == Qt::FontRole)
	{
		QFont q;
		if (file.getStatus() == "not_revised")
		{
			q.setBold(true);
		}
		else
		{
			q.setBold(false);
		}
		return q; //QFont::Bold;
	}
	if (role == Qt::BackgroundRole)
	{
		if (file.changed == 1)
		{
			QBrush q{"green"};
			return q;
		}
	}

	return QVariant();
}

int MyModel::rowCount(const QModelIndex & parent) const
{
	return this->repo.getSize();
}

MyModel::~MyModel()
{
}
