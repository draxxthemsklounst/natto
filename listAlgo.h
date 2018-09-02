#include "include.h"

//algorithms regarding lists of numbers
class listAlgo
{	
//NOTE: remember to add a method in listAlgo class that prints out an array on the console in any search type.
public:
	static void DisplayIntArray(const int* array, const int howMany)
	{
		for (int i = 0; i < howMany; i++)
		{
			if (i % 10 == 0)
				std::cout << std::endl;
			
			std::cout << array[i] << '\t';
		}
	}
	
	class sortTypes
	{
	private:
		int howMany;
		int *temp;
	public:
		sortTypes();
		sortTypes(int amount);
		~sortTypes();
		
		void swap(int *X, int *Y);
		int* bubbleSort(int array[]);
		int* selectionSort(int array[]);
		int* insertionSort(int array[]);
	};

	class searchTypes
	{
	private:
		int searchForThis;
		int howMany;
	public:
		searchTypes(int value);
		searchTypes(int value, int amount);
		int linearSearch(int array[]);
		int binarySearch(int array[]);
	};

	class fibclass
	{
	private:
		
	public:
		int fib(int n);
		unsigned long long int fibMemo(int n,std::vector<unsigned long long int>&);
	};
	
	
};
