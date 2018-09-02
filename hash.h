#include "include.h"

class hashClass
{
private:
	static const int tableSize = 50;

	int keyToIndex(std::string key); //hashes the key to get the index

	struct desc //describes person
	{
		std::string name;
		std::string drink;
		std::string food;
		desc* next;
	};

	desc * hashTable[tableSize]; //creates an array pointer to hashTable

public:
	hashClass(); //constructor
	
	void addItem(std::string key, std::string name, std::string food, std::string drink);
	void addItem(std::string key); //overloaded function
	int numberOfItems(int index); //# of items stored in hash table
	void returnTable(std::string key); //couts contents of the index with provided key
	void printTable();
	~hashClass(); //destructor deletes the hash table
	

};
