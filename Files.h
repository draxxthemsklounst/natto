

#pragma once
#include <iostream>
#include <fstream>
#include <string>
//class which manages and creates delimited integer files
class Files
{
private:
	std::string fileName;
	int howMany;
	int *temp;
public:

	Files()
	{
		std::cout << "What would you like the file name to be? " << std::endl;
		std::cin >> fileName;
		fileName += ".txt";
		howMany = 100;
	}
	Files(int amount)
	{
		std::cout << "What would you like the file name to be? " << std::endl;
		std::cin >> fileName;
		fileName += ".txt";
		howMany=amount;
	}

	void createRandIntFile() //creates a file of random ints from 1 to 100
	{
		std::cout << "Writing random ints to " + fileName;
		std::ofstream monty;
		monty.open(fileName);
		for (int i = 0; i < howMany; i++)
		{
			//Grades[i] = rand() % 100 + 1;   //fill array with random numbers from 1 to 100
			monty << (rand() % 100 + 1) << "\t";
		}
		monty.close();
	}
	int* fileToArray() //turns tab delimited file of random ints from 1 - 100 into an array and returns its pointer
	{
		std::ifstream file;
		file.open(fileName);
		temp = new int[howMany];
		std::ifstream in(fileName);
		for(int i = 0;i<howMany;i++)
		{
			std::string tempInt;
			std::getline(file, tempInt, '\t');
			temp[i] = std::stoi(tempInt);
	
		}
		return temp;
	}

	void viewFile() //shows the contents of file on console
	{
		std::ifstream file;
		file.open(fileName);
		for (int i = 0; i < howMany; i++)
		{
			if (i% 10 == 0)
			{
				std::cout << std::endl;
			}
			std::string Word;
			std::getline(file, Word, '\t');
			std::cout << Word << '\t';

		}
		std::cout << std::endl;
	}
	

	std::string getFileName()
	{
		return fileName;
	}
	~Files()
	{
		delete[] temp;
	}
};