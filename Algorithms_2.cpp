#include <iostream>

//속도
//O(1) - Constant pattern
//O(log n) - Logarithmic Pattern
// void Log(int n)
// { 
// while(x>=1)
// { 
// x /= 2;
// }
// }

// void Log(int n)
// {
// for(int i = 1; i<n; i*=2)
// {// 
// }
// }

// void Log(int n);
// {
// if(n<1)
// {
//	return;
// }
// Log(n/2);
// }

//O(n) - Linear Pattern
//O(n*log n) - Linear Logarithmic Pattern
//--------------------------------------------
//O(n^2) - Quadratic Polynomial
//O(2^n) - Exponential Pattern
// void f(int n)
// {
// if(n <=0)
// {
// return;
// }
// f(n-1);
// f(n-1);
// }
//O(n!) - Factorial Pattern

void Print(int input[], int count)
{
	for (int i = 0; i < count; i++)
	{
		std::cout << input[i] << " ";
	}
	std::cout << std::endl;
}

void Swap(int& value, int& value2)
{
	int temp = value;
	value = value2;
	value2 = temp;
}


// Sequential Sort
// Time Complexity : O(n^2)
// Space Complexity : O(n)
void SequentialSort(int input[], int size)
{
	for (int i = 0;i < size - 1;i++)
	{
		for (int j = i + 1;j < size;j++)
		{
			if (input[i] > input[j])
			{
				Swap(input[i], input[j]);
			}
		}
	}
}

//Selection Sort
//Time Complexity : O(n^2)
//Space Complexity : O(n)
void SelectionSort(int input[], int size)
{
	for (int i = 0; i < size;i++)
	{
		int minIndex = i;
		for (int j = i; j < size; j++)
		{
			if (input[minIndex] > input[j])
			{
				minIndex = j;
			}
		}

		Swap(input[i], input[minIndex]);
	}
}


// Bubble Sort
// Time Complexity : O(n^2)
// Space Complextiy : O(n)

void BubbleSort(int input[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1;j++)
		{
			if (input[j] > input[j + 1])
			{
				Swap(input[j], input[j + 1]);
			}
		}
	}
}


// Insertion Sort
void InsertionSort()
{

}

int main()
{
	const int ARRAY_SIZE{ 5 };
	int array[ARRAY_SIZE]{ 8,7,2,3,1, };

	//SequentialSort(array, ARRAY_SIZE);
	//SelectionSort(array, ARRAY_SIZE);
	//BubbleSort(array, ARRAY_SIZE);

	Print(array, ARRAY_SIZE);
}
