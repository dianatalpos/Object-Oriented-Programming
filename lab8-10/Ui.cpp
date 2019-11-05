#include "Ui.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <exception>
#include "Validator.h"

using namespace std;

Ui::~Ui()
{

}

void Ui::menu_administrator()
{
	cout << "\t1.Add a dog.\n";
	cout << "\t2.Remove a dog.\n";
	cout << "\t3.Update a dog.\n";
	cout << "\t4.Print all dogs.\n";
	cout << "\t5.Print sorted dogs.\n";
	cout << "\t6.Open file.\n";
	cout << "\t0.Exit Administrator\n";
	cout << "Give your command: ";
}

void Ui::ui_open_ad()
{
	this->contr.open_file_dogs();
}

void Ui::ui_open_user()
{
	this->contr.open_file_adoption();
}

void Ui::ui_add()
{
	std::string breed, name, photo;
	cout << "Give the breed of the dog: ";
	getline(cin, breed);
	cout << "Give the name of the dog: ";
	getline(cin, name);
	int age;
	cout << "Give the age of the dog: ";
	cin >> age;
	cin.ignore();
	cout << "Give the link of the photo with the dog: ";
	getline(cin, photo);
	try {
		this->contr.add_dog(breed, name, age, photo);
	}
	catch (std::exception& e)
	{
		cout << e.what();
	}
}

void Ui::ui_remove()
{
	cout << "Give the name of the dog: ";
	std::string name;
	getline(cin, name);
	this->contr.remove_dog(name);
}

void Ui::ui_update()
{
	std::string breed, name, photo;
	cout << "Give the breed of the dog: ";
	getline(cin, breed);
	cout << "Give the name of the dog: ";
	getline(cin, name);
	int age;
	cout << "Give the age of the dog: ";
	cin >> age;
	cin.ignore();
	cout << "Give the link of the photo with the dog: ";
	getline(cin, photo);
	this->contr.update_dog(breed, name, age, photo);
}


void Ui::ui_print()
{
	for (size_t i = 0; i < this->contr.get_size(0); i++) {
		Dog d = this->contr.get_elem(i, 0);
		cout << d.getName() << " is a " << d.getBreed() << ", age " << d.getAge() << endl; //". Link: "<<d.getSource()<<endl;
		ShellExecuteA(NULL, NULL, "chrome.exe", d.getPhoto().c_str(), NULL, SW_SHOWMAXIMIZED);
	}
}

void Ui::ui_print_sort_name()
{
	this->contr.sort_dogs_name();
}

void Ui::run_administrator()
{
	while (1)
	{
		this->menu_administrator();
		int command;
		cin >> command;
		cin.ignore();
		try {
			if (command == 0)
				return;
			else
				if (command == 1)
				{
					this->ui_add();
				}
				else
					if (command == 2)
					{
						this->ui_remove();
					}
					else
						if (command == 3)
						{
							this->ui_update();
						}
						else
							if (command == 4)
							{
								this->ui_print();
							}
							else
								if (command == 5)
									this->ui_print_sort_name();
								else
									if (command == 6)
										this->ui_open_ad();
									else cout << "Invalid command!\n";

		}
		catch (Validator e)
		{
			std::cout << e.what();
		}
		catch (RepoError e)
		{
			std::cout << e.what();
		}

	}
}

void Ui::menu_user()
{
	cout << "\t1.See the dogs\n";
	cout << "\t2.See the dogs with a given breed and with age less than a given number\n";
	cout << "\t3.See the adoption list\n";
	cout << "\t4.Open file.\n";
	cout << "\t0.Exit User\n";
	cout << "Give the command: ";
}

void Ui::ui_print_adoption()
{
	for (size_t i = 0; i < this->contr.get_size(1); i++) {
		Dog d = this->contr.get_elem(i,1);
		cout << d.getName() << " is a " << d.getBreed() << ", age " << d.getAge() << endl; //". Link: "<<d.getSource()<<endl;
		ShellExecuteA(NULL, NULL, "chrome.exe", d.getPhoto().c_str(), NULL, SW_SHOWMAXIMIZED);
	}
}

void Ui::menu_adoption()
{
	cout << "\t1.Next\n";
	cout << "\t2.Adopt\n";
	cout << "\t0.Exit\n";
	cout << "Give the command\n";

}

void Ui::see_adoption(std::string breed, int age)
{
	std::vector<Dog> dogs(1000);
	this->contr.get_dogs(breed, age, dogs);
	while(1)
	{
		size_t i;
		for ( auto i: dogs  ) {
			cout << "Name: " << i.getName() << "\n";
			cout << "Breed: " << i.getBreed() << "\n";
			cout << "Age " << i.getAge() << endl; //". Link: "<<d.getSource()<<endl;
			ShellExecuteA(NULL, NULL, "chrome.exe", i.getPhoto().c_str(), NULL, SW_SHOWMAXIMIZED);
			this->menu_adoption();
			int command;
			cin >> command;
			cin.ignore();
			if (command == 0)
				return;
			else
				if (command == 2)
					this->contr.add_adoption(i);
		}
		i = 0;
	}
	
}

void Ui::ui_user_1()
{
	std::string breed = "";
	int age = 100000;
	this->see_adoption(breed, age);
	return;
}

void Ui::ui_user_2()
{
	cout << "Give the breed: ";
	std::string breed;
	getline(cin, breed);
	cout << "Give the age: ";
	int age;
	cin >> age;
	cin.ignore();
	this->see_adoption(breed, age);
	return;

}
void Ui::run_user()
{
	while (1)
	{
		this->menu_user();
		int command;
		cin >> command;
		cin.ignore();
		if (command == 0)
			return;
		else
			if (command == 1)
			{
				this->ui_user_1();
			}
			else
				if (command == 2)
				{
					this->ui_user_2();
				}
				else
					if (command == 3)
					{
						this->ui_print_adoption();
					}
					else
						if (command == 4)
							this->ui_open_user();

						else cout << "Invalid command!\n";
	}	
}

void Ui::menu()
{
	cout << "\t1.Administrator\n";
	cout << "\t2.User\n";
	cout << "\t0.Exit\n";

	cout << "Choose the mode: ";
}

void Ui::run()
{
	while (1)
	{
		menu();
		int mode;
		cin >> mode;
		cin.ignore();
		if (mode == 0)
			return;
		else
			if (mode == 1)
				this->run_administrator();
			else
				if (mode == 2)
					this->run_user();
	}
}