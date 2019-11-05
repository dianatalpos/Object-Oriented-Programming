// lab5-6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include "Dog.h"
#include "Repository.h"
#include <crtdbg.h>
#include "Controller.h"
#include "Ui.h"
#include "Validator.h"




int main()
{
	{
		cout << "Choose the mode to store the data: (1)HTML or (2)CSV\n";
		int n;
		cin >> n;
		cin.ignore();
		Repository* repo;
		Repository* adoption;

		if (n == 1)
		{

			repo = new HTMLRepository{ "dogsHTML.html" };
			adoption = new HTMLRepository{ "adoptionHTML.html" };
		}
		else
		{
			repo = new CSVRepository{ "dogsCSV.csv" };
			adoption = new CSVRepository{ "adoptionCSV.csv"}; 
		}
		/*
		Repository* repo = new FileRepository{"dogs.txt"};
		Repository* adoption = new FileRepository{"adoption.txt"};*/
	// add some songs
	/*Dog d1{ "Labrador", "Lola", 4, "https://embarkvet.com/wp-content/uploads/2018/07/LabradorRetriever_dogdnatest.jpg" };
	Dog d2{ "Labrador", "Bruno", 7, "https://cdn3-www.dogtime.com/assets/uploads/gallery/golden-retriever-dogs-and-puppies/golden-retriever-dogs-puppies-7.jpg" };
	Dog d3{ "GermanShepard", "Laika", 3, "https://s3.amazonaws.com/cdn-origin-etr.akc.org/wp-content/uploads/2017/11/12213218/German-Shepherd-on-White-00.jpg" };
	Dog d4{ "Pudel", "Lisa", 1, "http://lovesweetpets.weebly.com/uploads/5/2/0/3/52031347/_9998440_orig.jpg" };
	Dog d5{ "Beagle", "Rex", 2, "https://previews.123rf.com/images/olgacov/olgacov1504/olgacov150400099/39487923-dog-beagle-breed-standing-on-the-green-grass.jpg" };
	Dog d6{ "Husky", "Nero", 7, "https://upload.wikimedia.org/wikipedia/commons/thumb/d/dd/Le%C3%AFko_au_bois_de_la_Cambre.jpg/220px-Le%C3%AFko_au_bois_de_la_Cambre.jpg" };
	Dog d7{ "Pug", "Josh", 5, "https://s3.amazonaws.com/cdn-origin-etr.akc.org/wp-content/uploads/2017/11/05085531/Pug-1-resized.jpg" };
	Dog d8{ "Chihuahua", "Acky", 11, "https://www.bakerstownah.com/sites/default/files/styles/large/adaptive-image/public/chihuahua-dog-breed-info.jpg?itok=7FGBYosq" };
	Dog d9{ "Pomeranian", "Angry", 8, "https://s3.amazonaws.com/cdn-origin-etr.akc.org/wp-content/uploads/2017/11/12225627/Pomeranian-On-White-01.jpg" };
	Dog d10{ "Buldog", "Lazy", 2,"https://cdn.shopify.com/s/files/1/2253/9875/products/HTB1Ua4RXdHO8KJjSZFLq6yTqVXaf.jpg?v=1527543055" };
	repo.addDog(d1);
	repo.addDog(d2);
	repo.addDog(d3);
	repo.addDog(d4);
	repo.addDog(d5);
	repo.addDog(d6);
	repo.addDog(d7);
	repo.addDog(d8);
	repo.addDog(d9);
	repo.addDog(d10);*/
	DogValidator valid{};
	Controller ctr{ repo, adoption , valid};
	Ui ui{ ctr };

	ui.run(); 
	delete repo;
	delete adoption;
	}
	_CrtDumpMemoryLeaks();
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
