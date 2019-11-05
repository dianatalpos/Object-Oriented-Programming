#pragma once
#include "Controller.h"

class Ui
{
private:
	Controller ctr;

public:
	Ui(Controller);


	void print_sorted();
	void run();
	void print_list();
	void ui_add();
	void menu();
	~Ui();
};