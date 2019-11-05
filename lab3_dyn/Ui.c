#include "Ui.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Ui* createUi(ControllerOffers* ctr)
{
	Ui* ui = (Ui*)malloc(sizeof(Ui));
	ui->ctr = ctr;
	return ui;
}

void menu()
{
	printf("Commands: \n");
	printf("\t1.Add an offer.\n");
	printf("\t2.Update an offer.\n");
	printf("\t3.Delete an offer.\n");
	printf("\t4.Print the offers.\n");
	printf("\t5.All offers which contain a given string, sorted ascending by their price.\n");
	printf("\t6.All offers which have a given surface, sorted ascending by their price.\n");
	printf("\t7.All offers which have a given type and have the surface greater than a given surface.\n");
	printf("\t8.All offers which have a given price, sorted alphabetical by the address.\n");
	printf("\t9.Undo.\n");
	printf("\t10.Redo.\n");

	printf("\t0.Exit\n");
	printf("Give the number of the command: ");
}

void ui_add(Ui* ui)
{
	char* address = malloc(sizeof(char) * 50);
	char *type = malloc(sizeof(char) * 50);
	double price, surface;
	printf("Give the address: ");
	scanf("%s", address);
	if (address == NULL)
	{
		printf("Invalid address!\n");
		free(address);
		free(type);
		return;
	}
	printf("Give the type: ");
	scanf("%s", type);
	if (!(strcmp(type, "house") == 0 || strcmp(type, "apartment") == 0 || strcmp(type, "penthouse") == 0))
	{
		printf("Invalid type!\n");
		free(address);
		free(type);
		return;
	}
	printf("Give the surface: ");
	scanf("%lf", &surface);
	if (surface <= 0)
	{
		printf("Invalid surface!\n");
		free(address);
		free(type);
		return;
	}
	printf("Give the price: ");
	scanf("%lf", &price);
	if (price <= 0)
	{
		printf("Invalid price!\n");
		free(address);
		free(type);
		return;
	}
	
	addCtr(ui->ctr, type, address, surface, price);
	free(address);
	free(type);
}

void ui_update(Ui* ui)
{
	char* address = malloc(sizeof(char) * 50);
	char *type = malloc(sizeof(char)*50);
	double price, surface;
	printf("Give the address: ");
	scanf("%s", address);
	if (address == NULL)
	{
		printf("Invalid address!\n");
		free(address);
		free(type);
		return;
	}
	printf("Give the type: ");
	scanf("%s", type);
	if (!(strcmp(type, "house") == 0 || strcmp(type, "apartment") == 0 || strcmp(type, "penthouse") == 0))
	{
		printf("Invalid type!\n");
		free(address);
		free(type);
		return;
	}
	printf("Give the surface: ");
	scanf("%lf", &surface);
	if (surface <= 0)
	{
		printf("Invalid surface!\n");
		free(address);
		free(type);
		return;
	}
	printf("Give the price: ");
	scanf("%lf", &price);
	if (price <= 0)
	{
		printf("Invalid price!\n");
		free(address);
		free(type);
		return;
	}
	updateCtr(ui->ctr, type, address, surface, price);
	free(address);
	free(type);
}

void ui_delete(Ui* ui)
{
	char* address = malloc(sizeof(char) * 50);
	printf("Give the address: ");

	scanf("%s", address);
	if (address == NULL)
	{
		printf("Invalid address!\n"); 
		free(address);
		return;
	}
	removeCtr(ui->ctr, address);
	free(address);
}

void ui_print(Ui* ui)
{
	int i;

	for (i = 0; i < getLenght(ui->ctr->repo); i++)
	{
		char*  p;
		p = toString(ui->ctr->repo->offers->elements[i]);
		printf("%s\n", p);
		free(p);
	}

}

void ui_six(Ui* ui)
{
	double surface;
	printf("Give the surface: \n");
	scanf("%lf", &surface);

	asc_surface(ui->ctr, surface);
}


void ui_five(Ui* ui)
{
	printf("Give the string: \n");
	char *s = malloc(sizeof(char) * 50);
	fflush(stdin);
	fgets(s, 50, stdin);
	fgets(s, 50, stdin);

	asc_string(ui->ctr, s);
	free(s);
}

void ui_seven(Ui* ui)
{
	char *type = malloc(sizeof(char) * 50);
	printf("Give the type: \n");
	scanf("%s", type);
	if (!(strcmp(type, "house") == 0 || strcmp(type, "apartment") == 0 || strcmp(type, "penthouse") == 0))
	{
		printf("Invalid type!\n");
		free(type);
		return;
	}

	double surface;
	printf("Give the surface: \n");
	scanf("%lf", &surface);

	int order = 0;
	printf("Give the order(1 for ascending, -1 for descending): \n");
	scanf("%d", &order);

	type_surface(ui->ctr, type, surface, order);

	free(type);
}

void ui_eight(Ui* ui)
{
	double price;
	printf("Give the price: \n");
	scanf("%lf", &price);

	asc_price(ui->ctr,price);

}


void ui_nine(Ui* ui)
{
	perform_undo(ui->ctr);
}

void ui_ten(Ui* ui)
{
	perform_redo(ui->ctr);
}

void run(Ui* ui)
{
	while (1)
	{
		int command = -1;
		menu();
		scanf("%d", &command);
		//system("cls");
		if (command == 1)
			ui_add(ui);
		else
			if (command == 2)
				ui_update(ui);
			else
				if (command == 3)
					ui_delete(ui);
				else
					if (command == 0)
						return;
					else
						if (command == 4)
							ui_print(ui);
						else
							if (command == 5)
								ui_five(ui);
							else
								if (command == 6)
									ui_six(ui);
								else
									if (command == 7)
										ui_seven(ui);
									else
										if (command == 8)
											ui_eight(ui);
										else
											if (command == 9)
												ui_nine(ui);
											else
												if (command == 10)
													ui_ten(ui);
												else
													printf("Invalid command!");
		
	}
}


void destroyUi(Ui* ui)
{
	free(ui);
}