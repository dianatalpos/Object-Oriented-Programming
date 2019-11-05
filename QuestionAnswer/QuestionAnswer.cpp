#include "QuestionAnswer.h"

QuestionAnswer::QuestionAnswer(MyModel* model,Controller* ctr, std::string name, QWidget *parent)
	: QMainWindow(parent), ctr{ctr},name{name}, model{model}
{
	ui.setupUi(this);

	this->setWindowTitle(QString::fromStdString(name));
	this->ui.questionView->setModel(model);
	QObject::connect(ui.addButton, &QPushButton::clicked, this, &QuestionAnswer::addQuestion);
	QObject::connect(ui.questionView, &QListView::clicked, this, &QuestionAnswer::displayAnswer);
}

void QuestionAnswer::addQuestion()
{
	std::string text = this->ui.questionEdit->text().toStdString();
	try
	{
		this->ctr->addQuestion(this->name, text, this->ctr->getQuestions().size() + 1);
		this->model->layoutChanged();
	}
	catch (std::exception& e)
	{
		QMessageBox* m = new QMessageBox{};
		m->setText(e.what());
		m->exec();
	}

}

void QuestionAnswer::displayAnswer()
{
	this->ui.answerList->clear();
	int line = this->ui.questionView->currentIndex().row();
	int idq = this->ctr->getQuestions()[line].getId();
	std::vector<Answer> ans = this->ctr->getAnswers(line);
	for (auto i : ans)
	{
		if (i.getIdQuestion() == idq)
		{
			QListWidgetItem *x = new QListWidgetItem{ QString::fromStdString(std::to_string(i.getId()) + "-" + i.getName() + "-" + std::to_string(i.getVotes()) + "-" + i.getText()) };
			if (i.getName() == this->name)
			{
				x->setBackgroundColor("yellow");
			}
			this->ui.answerList->addItem(x);
				
		}
	}
}
