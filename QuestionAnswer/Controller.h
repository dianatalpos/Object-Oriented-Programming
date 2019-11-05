#pragma once
#include "Repository.h"
#include <vector>
#include <string>

class Controller
{
private:
	Repository& repo;
public:
	Controller(Repository& repo);
	std::vector<std::string> getUsers() { return this->repo.getUsers(); }
	std::vector<Question> getQuestions() { return this->repo.getQuestions(); }
	void addQuestion(std::string name, std::string text,int id);
	std::vector<Answer> getAnswers(int i);

	~Controller();

};

