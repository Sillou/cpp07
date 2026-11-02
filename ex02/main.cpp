#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];
	srand(time(NULL));
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = rand();
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = rand();
	}
	delete [] mirror;//

	std::cout << "--- tableau vide ---" << std::endl;
	Array<int> empty;
	std::cout << "size = " << empty.size() << std::endl;
	try
	{
		empty[0] = 1;
	}
	catch(const std::exception& e)
	{
		std::cout << "erreur : " << e.what() << std::endl;
	}

	std::cout << "--- valeurs par defaut ---" << std::endl;
	Array<int> zeros(3);
	std::cout << zeros[0] << " " << zeros[1] << " " << zeros[2] << std::endl;

	std::cout << "--- copie independante ---" << std::endl;
	Array<int> original(2);
	original[0] = 1;
	original[1] = 2;
	Array<int> copie(original);
	copie[0] = 99;
	std::cout << "original : " << original[0] << " " << original[1] << std::endl;
	std::cout << "copie    : " << copie[0] << " " << copie[1] << std::endl;

	std::cout << "--- operator= ---" << std::endl;
	Array<int> autre;
	autre = original;
	autre[1] = 42;
	std::cout << "original : " << original[0] << " " << original[1] << std::endl;
	std::cout << "autre    : " << autre[0] << " " << autre[1] << std::endl;

	std::cout << "--- tableau de string ---" << std::endl;
	Array<std::string> mots(2);
	mots[0] = "bonjour";
	mots[1] = "monde";
	std::cout << mots[0] << " " << mots[1] << std::endl;
	std::cout << "size = " << mots.size() << std::endl;

	/*std::cout << "--- taille negative ---" << std::endl;
	try
	{
		Array<int> neg(-1);
		std::cout << "size = " << neg.size() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "erreur : " << e.what() << std::endl;
	}*/

	return 0;
}
