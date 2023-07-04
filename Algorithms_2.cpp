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
// Time Complexity : O(n^2)
// Space Coplexity : O(n)
void InsertionSort(int input[],int size)
{
	for (int i = 1;i < size; i++)
	{
		int j = i;
		int target = input[i];

		while (--j >= 0&&target<input[j])
		{
			input[j + 1] = input[j];
			input[j] = target;
		}
	}
}

/////////////////////////////////////////////////////////////////

// Merge Sort
// Time Complexity : O(n log n)
// Space Coplexity : O(n)
void Merge(int input[], int start, int half, int end, int temp[])
{
	int i{ start };
	int j{ half + 1 };
	int tempIndex{};

	while (i <= half && j <= end)
	{
		if (input[i] < input[j])
		{
			temp[tempIndex++] = input[i++];
		}
		else
		{
			temp[tempIndex++] = input[j++];
		}
	}

	//남아 있는 것 병합
	while (i <= half)
	{
		temp[tempIndex++] = input[i++];
	}
	while (j <= half)
	{
		temp[tempIndex++] = input[j++];
	}

	// 임시 배열 -> 원래 배열로 복사
	tempIndex = 0;
	for (int i = start; i <= end; i++)
	{
		input[i] = temp[tempIndex++];
	}
}

void MergeSort(int input[],int start, int end, int temp[])
{
	//base case
	if (start >= end)
	{
		return;
	}

	// recursuve case
	int half = (start + end) / 2;
	MergeSort(input, start, half, temp);
	MergeSort(input, half + 1, end, temp);

	Merge(input, start, half, end, temp);
}

// Quicksort
// Time Complexity : O(n log n)
// Space Coplexity : O(n)
void QuickSort(int input[], int left, int right)
{
	int i = left;
	int j = right;
	int pivot = input[(left + right) / 2];

	do
	{
		while (input[i] < pivot)
		{
			i++;
		}
		while (input[j] > pivot)
		{
			j--;
		}
		if (i <= j)
		{
			Swap(input[i], input[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j)
	{
		QuickSort(input, left, j);
	}
	if (i < right)
	{
		QuickSort(input, i, right);
	}
}


int main()
{
	const int ARRAY_SIZE{ 5 };
	int array[ARRAY_SIZE]{ 8,7,2,3,1, };

	//SequentialSort(array, ARRAY_SIZE);
	//SelectionSort(array, ARRAY_SIZE);
	//BubbleSort(array, ARRAY_SIZE);
	/*InsertionSort(array, ARRAY_SIZE);*/

	/*int tempArray[ARRAY_SIZE]{};
	MergeSort(array, 0, ARRAY_SIZE - 1, tempArray);*/

	QuickSort(array, 0, ARRAY_SIZE - 1);


	Print(array, ARRAY_SIZE);
}
