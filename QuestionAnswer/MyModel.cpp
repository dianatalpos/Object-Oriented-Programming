#include "MyModel.h"



MyModel::MyModel(Repository& repo) : repo{repo}
{

}

int MyModel::rowCount(const QModelIndex & parent) const
{
	return this->repo.getQuestions().size();
	return 0;
}

QVariant MyModel::data(const QModelIndex & index, int role) const
{
	int row = index.row();
	if (role == Qt::DisplayRole)
	{
		Question q = this->repo.getQuestions()[row];
		std::string id = std::to_string(q.getId());
		return QString::fromStdString(id + "-" + q.getName() + "-" + q.getText());
	}


	return QVariant();
}


MyModel::~MyModel()
{
}
