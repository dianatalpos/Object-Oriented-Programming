#pragma once
#include <qwidget.h>
#include <Controller.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qradiobutton.h>
#include <qlistwidget.h>


class MyGuiByHand :
	public QWidget
{
private:
	Controller& ctr;
	QListWidget* dogs;
	QLineEdit* name, *breed, *age, *photo;
	QPushButton* add, *remove, *update, *undo, *redo;
	void my_init();
	void populateDogs();
	void sortedHandler();
	void shuffledHandler();
	void addDog();
	void removeDog();
	void updateDog();
	void perform_undo();
	void perform_redo();

public:
	MyGuiByHand(Controller& _ctr);
	~MyGuiByHand();
};

