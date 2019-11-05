#include "Ui.h"
#include <iostream>
#include<string>


using namespace std;



Ui::Ui(Controller ctr) : ctr{ ctr }
{

}

void Ui::menu()
{
	cout << "\t1.Add a population.\n";
	cout << "\t2.Show the list\n";
	cout << "\t3.Show the list sorted\n";
	cout << "\t0.Exit.\n";
	cout << "Give your command: ";
}


void Ui::ui_add()
{
	std::string type;
	int number;
	bool isImmune;
	cout << "Give the type: ";
	getline(cin, type);
	cout << "Give the number: ";
	cin >> number;
	cin.ignore();
	cout << "It is immune or not: ";
	cin >> isImmune;
	cin.ignore();

	this->ctr.add(type, number, isImmune);
}




void Ui::print_list()
{
	this->ctr.print_list();
}

void Ui::print_sorted()
{
	this->ctr.print_Sort();
}

void Ui::run()
{
	while (1)
	{
		this->menu();
		int command;
		cin >> command;
		cin.ignore();
		if (command == 0)
		{
			return;
		}
		else
			if (command == 1)
			{
				this->ui_add();
			}
			else
				if (command == 2)
					this->print_list();
				else
					if (command == 3)
						this->print_sorted();
	}
}


Ui::~Ui()
{

}