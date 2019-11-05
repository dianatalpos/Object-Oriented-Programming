#pragma once
#include <vector>
#include <string>
#include "Answer.h"
#include "Question.h"
#include <fstream>
#include "Errors.h"

class Repository
{
private:
	std::vector<std::string> users;
	std::vector<Answer> answers;
	std::vector<Question> questions;
	void readAllFromFile();
	void sortQuestion();

public:
	Repository();
	std::vector<std::string> getUsers() { return this->users; }
	std::vector<Question> getQuestions() { return this->questions; }
	void addQuestion(Question q);
	std::vector<Answer> getAnswers() { return this->answers; }

	~Repository();
};

