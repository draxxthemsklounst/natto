#include "include.h"

hashClass::hashClass()
{
	for (int i = 0; i < tableSize; i++)
	{
		hashTable[i] = new desc();
		hashTable[i]->name = "empty";
		hashTable[i]->drink = "empty";
		hashTable[i]->food = "empty";
		hashTable[i]->next = NULL;
	}
	
}


int hashClass::keyToIndex(std::string key)
{

	int index,
		keyASCII = 0;

	for (unsigned short int i = 0; i < key.length(); i++)
	{
		keyASCII += (int)key[i]; //typecast the character to an ascii int
	}

	index = keyASCII % tableSize; //the index is determined by the int produced by adding the ASCII values and then taking its modulus of the tableSize
	return index;
}

void hashClass::returnTable(std::string key)
{
	int index;
	index = keyToIndex(key); 
	
	std::cout << "Name: " << hashTable[index]->name << std::endl;
	std::cout << "Food: " << hashTable[index]->food << std::endl;
	std::cout << "Drink: " << hashTable[index]->drink << std::endl;
	
}

void hashClass::addItem(std::string key)
{
	LOG("Enter a name: ");
	std::cin >> hashTable[keyToIndex(key)]->name;
	LOG("Enter a food: ");
	std::cin >> hashTable[keyToIndex(key)]->food;
	LOG("Enter a drink: ");
	std::cin >> hashTable[keyToIndex(key)]->drink;

}
void hashClass::addItem(std::string key, std::string name, std::string food, std::string drink)
{
	if (hashTable[keyToIndex(key)]->name == "empty")
	{
		hashTable[keyToIndex(key)]->name = name;
		hashTable[keyToIndex(key)]->food = food;
		hashTable[keyToIndex(key)]->drink = drink;
	}
	else
	{ // if the hash table is used at index, create linked list and move the list down the line
		desc* Ptr = hashTable[keyToIndex(key)];
		desc* n = new desc;
		n->name = name;
		n->drink = drink;             //linked list
		n->next = NULL;
		while (Ptr->next != NULL)
			Ptr = Ptr->next;
		Ptr->next = n;
	}
}
int hashClass::numberOfItems(const int index) 
{
	unsigned int count = 0;
	if (hashTable[index]->name == "empty")
		return count;
	else
	{
		count++;
		desc* Ptr = hashTable[index];
		while (Ptr->next != NULL)
		{
			count++;
			Ptr = Ptr->next;
		}
	}

	return 0;
}

void hashClass::printTable()
{
	unsigned int number;
	for (int i = 0; i < tableSize; i++)
	{
		number = numberOfItems(i);
		std::cout << "---------------------\n";
		std::cout << "index = " << i << std::endl;
		std::cout << hashTable[i]->name << std::endl;
		std::cout << hashTable[i]->drink << std::endl;
		LOG(hashTable[i]->food);
		std::cout << "# of items = " << number << std::endl;
		std::cout << "---------------------\n";
	}
}
hashClass::~hashClass()
{
	for (int i = 0; i < tableSize; i++)
	{
		delete hashTable[i];
	}
}

