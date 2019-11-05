#include "Ui.h"

void Ui::run()
{
	while (1)
	{
		this->menu();
		int command;
		cin >> command;
		cin.ignore();
		if (command == 0)
			return;
		else
			if (command == 1)
				this->ui_add();
	}
}

void Ui::menu()
{
	cout << " \t1.Add car.\n";
	cout << "\t0.Exit.\n";
	cout << "Choose a command: ";
}

void Ui::ui_add()
{
	string bodyStyle;
	cout << "Give the body style (Sedan or Convertible):\n";
	std::getline(cin, bodyStyle, '\n');
	string engineType;
	cout << "Give the engineType(turbo or Electric):\n";
	std::getline(cin, engineType, '\n');
	string fuelType;
	cout << "Give the fuel type(gasoline or diesel):\n";
	std::getline(cin, fuelType, '\n');
	int aut = 0;
	if (engineType == "electric") {
		cout << "Give the autonomy of the engine:\n";
		cin >> aut;
	}
	this->ctr.addCar(bodyStyle, engineType, fuelType, aut);

}

