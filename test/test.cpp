// test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Ui.h"
#include "Repository.h"
#include "Controller.h"
#include "assert.h"

void testRepo()
{
	Organism o{ "E_coli", 100, 0 };
	Organism o2{ "mycobacterium", 150, 1 };

	Repo r{};
	r.add_elem(o);
	r.add_elem(o2);

	assert(r.get_size() == 2);
	Organism o3{ "mycobacterium", 150, 1 };
	assert(r.get_size() == 2);



}

void test_Controller()
{
	Repo r{};
	Controller ctr{ r };
	ctr.add("ecoli", 100, 0);
	ctr.add("mycobacterium", 104, 1);
	ctr.add("streptococus", 200, 1);

	ctr.add("mycobacterium", 104, 1);

}


int main()
{
	Repo r{};
	Controller c{ r };
	Ui ui{c};
	test_Controller();
	testRepo();

	ui.run();
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
