#include <stdio.h>
#include "Offer.h"
#include "Repository.h"
#include "Controller.h"
#include "Ui.h"
#include <crtdbg.h>

void test()
{/*
	Offer* o1;
	Offer* o2;
	Offer* o3;
	o1 = createOffer("penthouse", "Tulcea", 32, 200.30);
	o2 = createOffer("house", "Tulcea32", 15, 100.5);
	o3 = createOffer("flat", "Muresului", 32, 150);


	RepoOffers* r;
	r = createRepo();
	/*addOffer(r, o1);
	addOffer(r, o2);
	
	ControllerOffers* c;

	c = createController(r);
	addCtr(c, "penthouse", "Tulcea", 32, 200.30);
	addCtr(c, "house", "Tulcea32", 15, 100.5);

	printf("%s\n", getAddress(r->offers[0]));
	printf("%s\n", getAddress(r->offers[1]));

	printf("%f\n", getPrice(r->offers[0]));
	printf("%f\n", getPrice(r->offers[1]));

	removeCtr(c, "Tulcea");
	printf("%f\n", getPrice(r->offers[0]));


	addCtr(c, "penthouse", "Tulcea", 32, 200.30);
	addCtr(c, "flat", "Muresului", 32, 150);
	updateCtr(c, "house", "Muresului", 32, 150);
	printf("%s\n", getType(r->offers[2]));
	printf("%d", c->repo->lenght);


	/*
	printf("%f\n", getPrice(r->offers[0]));
	printf("%f\n", getPrice(r->offers[1]));

	printf("%f\n", getPrice(c->repo->offers[0]));

	deleteOffer(r, o1);
	printf("%f\n", getPrice(r->offers[0]));
	printf("%d\n", r->lenght);


	addCtr(c, "Tulcea222", "penthouse", 23.3, 234.00);
	printf("%f\n", getPrice(c->repo->offers[1]));

	removeCtr(c, "Tulcea");
	printf("%f\n", getPrice(c->repo->offers[0]));
	printf("%f\n", (c->repo->lenght));
	*/

	/*addOffer(r, o3);
	printf("%f\n", getPrice(r->offers[1]));
	setPrice(o3, 123);
	updateOffer(r, o3);
	printf("%f\n", getPrice(r->offers[1]));
	




	destroyOffer(o1);
	destroyOffer(o2);
	destroyOffer(o3);
	destroyRepo(r);
	destroyController(c);
	_CrtDumpMemoryLeaks();
*/
}

int main()
{

	RepoOffers* repo;
	repo = createRepo();
	//test();
	
	ControllerOffers* ctr;
	ctr = createController(repo);

	addCtr(ctr, "penthouse", "Tulcea", 32, 200.30);
	addCtr(ctr, "house", "Tulcea32", 15, 100.5);
	addCtr(ctr, "apartment", "Tulcea15", 100, 5000);
	addCtr(ctr, "house", "Muresului32", 40, 500.5);
	addCtr(ctr, "penthouse", "Oltului2", 28, 150);
	addCtr(ctr, "house", "Rasaritului2", 105, 10000.5);
	addCtr(ctr, "house", "Jiului5", 50, 10050);
	addCtr(ctr, "apartment", "Tulcea26", 28, 150.5);
	addCtr(ctr, "penthouse", "Paris5", 105, 30000);
	addCtr(ctr, "house", "Albac", 28, 190);
	addCtr(ctr, "penthouse", "Tulcea33", 45, 2000);
	Ui* ui;

	ui = createUi(ctr);
	
	run(ui);

	destroyController(ctr);
	destroyUi(ui);
	_CrtDumpMemoryLeaks();

	return 0;
}