#include "include.h"

void mainMenu();

int main()
{
	mainMenu();
	return 0;
}

void mainMenu()
{
	
	bool keepGoing = true;
	while (keepGoing)
	{
		int Which;
		LOG("(1) Search an array");
		LOG("(2) Sort an array");
		LOG("(3) Use the Hash Table");
		LOG("(4) Nth Fibonacci Function");
		std::cin >> Which;

		if(Which == 1)
		{
			int howMany;
			int searchForThis;

			LOG("How many elements?  ");
			std::cin >> howMany;

			Files myFile(howMany);
			myFile.createRandIntFile(); //creates a random int file
			myFile.viewFile(); //displays on console
			int *temporaryArray = myFile.fileToArray(); //converts to array and returns the address

			LOG("What are you searching for? ");
			std::cin >> searchForThis;          //input

			listAlgo::searchTypes searchInstance(searchForThis);

			LOG("Would you like to execute a Linear search (1) on this list or Binary search (2)?");
			std::cin >> Which;  //input
			if (Which == 1)
			{
				int result;
				
				result = searchInstance.linearSearch(temporaryArray);
				if (result == -1)
					LOG("Value not found.");
				else 
				{
					LOG("Value located at: ");
					std::cout << result << std::endl;
				}
			}
			else if (Which == 2)
			{
				listAlgo::sortTypes sortInstance(howMany);
				LOG("Sorting array... ");
				
				int result;
				result = searchInstance.binarySearch(   sortInstance.bubbleSort(temporaryArray)  );//bubble sort the array in order the temporary array then return its pointer address to begin searching
				if(result == -1)
				{ 
					LOG("Value not found.");
				}
				else
				{
					LOG("Value located at: ");
					LOG(result);
				}
			}
			else
			{
				LOG("Enter valid input please.");
			}
		}
		else if (Which == 2)
		{
			int howMany;

			LOG("How many elements?  ");
			std::cin >> howMany;

			Files myFile(howMany);
			myFile.createRandIntFile(); //creates a random int file
			myFile.viewFile(); //displays on console
			int* temporaryArray = myFile.fileToArray(); //converts to array and returns the address

			LOG("What type of sort would you like to execute?");
			LOG("Bubble Sort (1)");
			LOG("Selection Sort (2)");
			LOG("Insertion Sort (3)");
			std::cin >> Which;
			switch(Which) {
				case 1: {
					LOG("Sorting... ");
					listAlgo::sortTypes sortInstance(howMany);
					int* temp = sortInstance.bubbleSort(temporaryArray);
					listAlgo::DisplayIntArray( temp , howMany );
					std::cout<<std::endl;
					break;
				}
				case 2: {
					LOG("Sorting... ");
					listAlgo::sortTypes sortInstance(howMany);
					int* temp = sortInstance.selectionSort(temporaryArray);
					listAlgo::DisplayIntArray( temp , howMany );
					std::cout<<std::endl;
					break;
				}
				case 3: {
					LOG("Sorting... ");
					listAlgo::sortTypes sortInstance(howMany);
					int* temp = sortInstance.insertionSort(temporaryArray);
					listAlgo::DisplayIntArray( temp , howMany );
					std::cout<<std::endl;
					break;
				} 
				default: {
					LOG("Enter valid choice.");
					break;
				}
			}
		}
		else if (Which == 3)
		{
			hashClass hashInstance; //instance 
			bool hashKeepGoing = true;
			std::string static key;
			
			while(hashKeepGoing) 
			{
				std::cout << "Would you like to... " << std::endl;
				std::cout << "(1) Add to hash table " << std::endl;
				std::cout << "(2) Read from hash table with key" << std::endl;
				LOG("(3) Print the hash table");
			
				std::cin >> Which;
				if (Which == 1)
				{
					std::cout << "Please enter a key." << std::endl;
					std::cin >> key; //input
					std::string Name, Food, Drink;
					std::cout << "Enter a name." << std::endl;
					std::cin >> Name;
					std::cout << "Enter a food." << std::endl;
					std::cin >> Food;
					std::cout << "Enter a drink." << std::endl;
					std::cin >> Drink;
					
					hashInstance.addItem(key,Name,Food,Drink);
				}
				else if (Which == 2)
				{
					LOG("Enter a key: ");
					std::cin >> key;
					if(!std::cin)
						key = "unknown";
					hashInstance.returnTable(key);
				}
				else if (Which == 3)
				{
					hashInstance.printTable();
				}
				else
				{
					LOG("Please enter a valid input.");
				}
				
				LOG("Would you like to do another Hash Operation?\nYes (1) or No (0)?");
				std::cin >> hashKeepGoing;
				if (!std::cin)
					hashKeepGoing = 0;
				
			}
		}
		else if (Which == 4)
		{

			std::cout << "Which type of fibonacci function would you like to use?" << std::endl;
			std::cout << "(1) Memoized " << std::endl;
			std::cout << "(2) Non-Memoized " << std::endl;

			std::cin >> Which;
			if (Which == 1)
			{
				std::cout << "Enter the Nth fibonacci sum you would like to calculate " << std::endl;
				int n;
				std::cin >> n;
				
				listAlgo::fibclass fibObject;
				std::vector<unsigned long long int> cache(n+1); //+1 to account for the 0 index
				
				for (int i = 0; i < n + 1; i++)
				{
					std::cout << "Fib(" << i << "): " << fibObject.fibMemo(i,cache) << std::endl;
				}
			}
			else if (Which == 2)
			{
				

				std::cout << "Enter the Nth fibonacci sum you would like to calculate " << std::endl;
				int n;
				std::cin >> n;
				
				listAlgo::fibclass fibObject;
				for (int i = 0; i < n + 1; i++)
				{
					std::cout << "Fib(" << i << "): " << fibObject.fib(i) << std::endl;
				}
			}

		}
		else
		{
			LOG("Enter valid choice.");
		}

		LOG("Do you want to perform another operation? (1)Yes or (0)No?");
		std::cin >> keepGoing;
		if (!std::cin)
			keepGoing = 0;

	}
	
}


