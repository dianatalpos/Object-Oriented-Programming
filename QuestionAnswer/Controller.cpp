#include "Controller.h"



Controller::Controller(Repository& repo): repo{repo}
{
}


void Controller::addQuestion(std::string name, std::string text, int id)
{
	Question q{ text, id, name };
	this->repo.addQuestion(q);
}

std::vector<Answer> Controller::getAnswers(int i)
{
	std::vector<std::string> ansstr;
	return this->repo.getAnswers();
	/*int idq = this->repo.getQuestions()[i].getId();
	for (auto answer : ans)
	{
		if (answer.getIdQuestion() == idq)
		{

		}
	}*/
	//return std::vector<Answer>();
}

Controller::~Controller()
{
}
