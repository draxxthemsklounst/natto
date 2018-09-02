#include <iostream>

int* selectSort(int [], int);
int* insertionSort(int[],int);
void swap(int*, int*);
void displayArray(int [], int);

int main()
{
	const unsigned short int arraySize = 7;
	int Array[arraySize] = {5,43,2,123,1,42,14};
	
	displayArray(Array, arraySize);
	
	displayArray(insertionSort(Array,arraySize),arraySize);	
}

int* insertionSort(int array[], int arraySize)
{
	int* temp = new int[arraySize];
		for (int i = 0; i < arraySize; i++)
			temp[i] = array[i];
		
	int sortedIndex = 0; //starts with sorted array section at 0
	for(int i = 1;i<arraySize;i++)//loop for "n-1" amount of inputs in array
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



int* selectSort(int array[], int arraySize)
{
	int* temp = new int[arraySize];
		for (int i = 0; i < arraySize; i++)
			temp[i] = array[i];
		
	for(int i = 0;i<arraySize - 1;i++)
	{
		int smallestIndex = i;
		for(int j = i+1;j<arraySize;j++)
		{
			if(temp[j] <= temp[smallestIndex])
				smallestIndex = j;
		}
		swap(&temp[i], &temp[smallestIndex]);
	}
	return temp;
}

void swap(int* first, int* second)
{
	int temp = *first;
	*first = *second;
	*second = temp;
}

void displayArray(int temp[],int size)
{
	for(int i = 0; i < size; i++) 
	{
		std::cout << temp[i] << " ";
		if( ((i+1)%10) == 0) 
			std::cout << std::endl;
	}
	std::cout <<std::endl;
}