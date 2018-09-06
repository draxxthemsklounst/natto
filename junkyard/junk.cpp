#include <iostream>
int* selectSort(int [], int);
int* insertionSort(int[],int);
int* recursiveInsertionSort(int[],int,int);
int* rBubbleSort(int[],int);
void swap(int*, int*);
void displayArray(int [], int);

int main()
{
	const unsigned short int howMany = 7;
	int Array[howMany] = {5,43,2,123,1,42,14};
	
	displayArray(Array, howMany);
	
	displayArray(recursiveInsertionSort(Array,howMany,0),howMany);	
}

//int* mergeSort(int array[], in

int* rBubbleSort(int array [], int howMany)
{
	if (howMany==1)
		return array;
	for(int i = 0;i<howMany;i++)
	{
		if (array[i] > array[i+ 1])
			swap(&array[i], &array[i+ 1]);
	}
	return rBubbleSort(array,howMany-1);
}

int* insertionSort(int array[], int howMany)
{
	int* temp = new int[howMany];
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
int* recursiveInsertionSort(int array[], int howMany, int sortedIndex)
{
	
	if(sortedIndex == howMany)
		return array;
	
	for(int j = 0; j<sortedIndex; j++) //loop for the "n" amount of inputs of array
	{
		if(array[sortedIndex] <= array[j]) {
			swap(&array[sortedIndex],&array[j]);	
		}
	}
	sortedIndex++;
	
	return recursiveInsertionSort(array,howMany,sortedIndex);
}



int* selectSort(int array[], int howMany)
{
	int* temp = new int[howMany];
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