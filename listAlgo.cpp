#include "include.h"

//CONSTRUCTOR working
listAlgo::sortTypes::sortTypes()
	{
		std::cin >> howMany;
		if (std::cin.fail())
			howMany = 100;
	}
listAlgo::sortTypes::sortTypes(int amount)
	{
		howMany = amount;
	}
//METHODS OF SORT TYPES working
void listAlgo::sortTypes::swap(int* X, int* Y)
	{
		int tempint = *X;
		*X = *Y;
		*Y = tempint;
	}
int* listAlgo::sortTypes::bubbleSort(int array[])
	{
		temp = new int[howMany];
		for (int i = 0; i < howMany; i++)
			temp[i] = array[i];
		
		//bubble sorting
		for (int i = 0; i < howMany - 1; i++)
		{
			for (int j = 0; j < howMany - 1 - i; j++)//the minus i because we know the last place where the list is properly ordered
			{
				if (temp[j] > temp[j + 1])
				{
					swap(&temp[j], &temp[j + 1]);
				}
			}
		}
		
		
		return temp;
	}

int* listAlgo::sortTypes::selectionSort(int array[])
	{
		
		temp = new int[howMany];
			for (int i = 0; i < howMany; i++)
				temp[i] = array[i];
			
		for(int i = 0;i<howMany - 1;i++)
		{
			int smallestIndex = i;
			for(int j = i+1;j<howMany;j++)
			{
				if(temp[j] <= temp[smallestIndex])
					smallestIndex = j;
			}
			swap(&temp[i], &temp[smallestIndex]);
		}
		return temp;

	}
	
int* listAlgo::sortTypes::insertionSort(int array[])
{
	temp = new int[howMany];
		for (int i = 0; i < howMany; i++)
			temp[i] = array[i];
		
	int sortedIndex = 0; //starts with sorted array section at 0
	for(int i = 1;i<howMany;i++)//loop for "n-1" amount of inputs in array
	{
		sortedIndex = i;
		for(int j = 0; j<sortedIndex; j++) //loop for the "n" amount of inputs of array
		{
			if(temp[sortedIndex] <= temp[j])
				swap(&temp[sortedIndex],&temp[j]);
			
		}
	}
	return temp;
}
//DESTRUCTOR working
listAlgo::sortTypes::~sortTypes()
	{
		delete[] temp;
	}

//CONSTRUCTOR working
listAlgo::searchTypes::searchTypes(int value)
	{
		searchForThis = value;
		howMany = 100;
	}
listAlgo::searchTypes::searchTypes(int value, int amount)
	{
		searchForThis = value;
		howMany = amount;

	}
//METHODS OF SEARCH TYPES
int listAlgo::searchTypes::linearSearch(int array[])
	{
		
		for (int index = 0; index < howMany; index++)
		{
			if (array[index] == searchForThis)
			{
				return index;
			}
			else
				return -1;
		}
	}
int listAlgo::searchTypes::binarySearch(int array[])
	{

		int first = 0,
			last = howMany - 1;
		bool found = false;
		while (!found && first <= last)
		{
			int middle = (first + last) / 2;

			if (array[middle] == searchForThis)
			{
				return middle;
			}
			else if (array[middle] < searchForThis)
				first = middle + 1;
			else
				last = middle - 1;
		}
		return -1;
	}


//NON MEMOIZED RECURSION working
int listAlgo::fibclass::fib(int n)
{
	if (n <= 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);

}

//MEMOIZED RECURSION working
unsigned long long int listAlgo::fibclass::fibMemo(int n, std::vector<unsigned long long int> &cache)
{

	if (cache[n] != 0) //if the fib index of n in cache is not empty then return the contents of that index
	{	
		return cache[n];
	}
	
	unsigned long long int value;

	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else if (n == 2)
		return 1;

	else if (n > 2)
	{
		value = fibMemo(n - 1, cache) + fibMemo(n - 2, cache);
	}	

	cache[n] = value;
	return value;
}




	

