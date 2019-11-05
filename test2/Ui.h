#include "Controller.h"

class Ui
{
private:
	Controller& ctr;
public:
	Ui(Controller& _ctr) : ctr{_ctr} {}
	void run();
	void menu();
	void ui_add();


};