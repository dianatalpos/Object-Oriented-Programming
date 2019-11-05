#pragma once
#include "Repository.h"
#include "Comparator.h"
#include "Validator.h"
#include <vector>
#include "UndoAction.h"


class Controller
{
private:
	Repository* list;
	Repository* adoption;
	DogValidator& valid;
	void sort(Comparator<Dog>* compare, std::vector<Dog>& dogs);
	std::vector<std::unique_ptr<UndoAction>> undos;
	int dim = 0;
	int index = 0;

public:
	void sort_dogs_name();

	Controller(Repository* repo, Repository* adoprion, DogValidator& _valid);

	~Controller();
	void open_file_dogs();
	void open_file_adoption();
	int get_size(bool);
	Dog get_elem(int, bool);
	void add_dog(std::string&, std::string&, int, std::string&);
	void remove_dog(std::string&);
	Dog search_dog(std::string);
	void update_dog(std::string&, std::string&, int, std::string&);
	void get_dogs(std::string, int, std::vector<Dog>&);
	void add_adoption(Dog);
	void sorted();
	void shuffled();
	std::vector<Dog> getAlldogs() const ;

	std::vector<Dog> getAllAdoption() const;

	void perform_undo();
	void perform_redo();
};