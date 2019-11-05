#pragma once
#include "Controller.h"

class Ui
{
private:
	Controller& contr;

public:
	Ui(Controller& c) : contr{ c } {}

	~Ui();
	void run();


private:

	void ui_print_sort_name();
	void menu_administrator();
	void menu_user();
	void ui_open_ad();
	void ui_open_user();
	void menu();
	void run_administrator();
	void ui_add();
	void ui_remove();
	void ui_update();
	void ui_print();
	void run_user();
	void ui_print_adoption();
	void ui_user_1();
	void see_adoption(std::string, int);
	void menu_adoption();
	void ui_user_2();
};