#pragma once
#include <string>

class Answer
{

private:
	int id;
	int idQuestion;
	std::string name;
	std::string text;
	int votes;

public:
	Answer(int id, int idq, std::string name, std::string text, int votes);
	int getId() { return this->id; }
	int getIdQuestion() { return this->idQuestion; }
	std::string getText() { return this->text; }
	std::string getName() { return this->name; }
	int getVotes() { return this->votes; }
	~Answer();
};

