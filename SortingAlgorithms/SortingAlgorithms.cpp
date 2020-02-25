#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <iterator>
using namespace std;

//Function Defintions ---------------------------------------
void printVector(vector<int> tVec, int size);

//Sorting algorithm functions must be pass-by-reference to
//properly sort the vectors
void bubbleSort(vector<int>& tVec, int size, int& count, int& compCount);
void insertionSort(vector<int>& tVec, int size, int& count, int& compCount);
void selectionSort(vector<int>& tVec, int size, int& count, int& compCount);
void swap(int* x, int* y);
int partition(vector<int>& tVec, int low, int high, int& count, int& compCount);
void quickSort(vector<int>& tVec, int low, int high, int& count, int& compCount);
void shellShort(vector<int>& tVec, int size, int& count, int& compCount);

int main() {

	//Variable Declarations ---------------------------------
	vector<int> bubVector;
	srand(time(NULL));
	for (int i = 0; i < 10000; i++)
	{
		int temp = rand() % 100;
		bubVector.push_back(temp);
	}

	//Creating deep copies of initial vector to ensure all
	//sorting algorithms perform on the same vector
	vector<int> insertVector(bubVector);
	vector<int> selectVector(bubVector);
	vector<int> quickVector(bubVector);
	vector<int> shellVector(bubVector);
	int size = bubVector.size();
	int bubbleCount = 0, selectCount = 0, insertCount = 0,
		quickCount = 0, shellCount = 0, bubbleComp = 0, selectComp = 0,
		insertComp = 0, quickComp = 0, shellComp = 0;

	bubbleSort(bubVector, size, bubbleCount, bubbleComp);
	//printVector(bubVector, size);
	insertionSort(insertVector, size, insertCount, insertComp);
	//printVector(insertVector, size);
	selectionSort(selectVector, size, selectCount, selectComp);
	//printVector(selectVector, size);
	quickSort(quickVector, 0, (size - 1), quickCount, quickComp);
	//printVector(quickVector, size);
	shellShort(shellVector, size, shellCount, shellComp);
	//printVector(shellVector, size);
	cout << endl;

	cout << "             Swaps    Comparisons" << endl;
	cout << "Bubble:    " << bubbleCount << "  " << bubbleComp << endl;
	cout << "Insertion: " << insertCount << "  " << insertComp << endl;
	cout << "Selection: " << selectCount << "     " << selectComp << endl;
	cout << "Shell:     " << shellCount <<  "     " << shellComp << endl;
	cout << "Quicksort: " << quickCount <<  "     " << quickComp << endl;

	return 0;
}

//Function Implementations ----------------------------------

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void printVector(vector<int> tVec, int size) {
	for (vector<int>::iterator iter = tVec.begin(); iter != tVec.end(); iter++)
		cout << *iter << " ";
}

void bubbleSort(vector<int>& tVec, int size, int& count, int& compCount) {
	int i, j;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < (size - i - 1); j++)
		{
			if (tVec[j] > tVec[j + 1])
			{
				//Swapping adjacent elements
				swap(&tVec[j], &tVec[j + 1]);
				count++;
				compCount++;
			}
			compCount++;
		}
	}
}

void insertionSort(vector<int>& tVec, int size, int& count, int& compCount) {
	int i = 1, j = 0, key = 0;
	for (i; i < size; i++)
	{
		key = tVec[i];
		j = i - 1;
		while (j >= 0 && tVec[j] > key)
		{
			tVec[j + 1] = tVec[j];
			j = j - 1;
			count++;
			compCount++;
		}
		tVec[j + 1] = key;
		compCount++;
	}
}

void selectionSort(vector<int>& tVec, int size, int& count, int& compCount) {
	int minVal = 0;
	for (int i = 0; i < size - 1; i++)
	{
		minVal = i;
		for (int j = i + 1; j < size; j++)
		{
			//keeps minimum value updated
			if (tVec[j] < tVec[minVal]) {
				minVal = j;
				count++;
				compCount++;
			}
		}
		if (minVal != i) {
			swap(&tVec[i], &tVec[minVal]);
			count++;
			compCount++;
		}
	}
}

int partition(vector<int>& tVec, int low, int high, int& count, int& compCount) {
	int pivot = tVec[high];//setting the pivot for the sort
	int i = (low - 1); //finds index of smaller element
	for (int j = low; j <= high - 1; j++)
	{
		if (tVec[j] < pivot)
		{
			i++;
			swap(&tVec[i], &tVec[j]);
			count++;
			compCount++;
		}
	}
	swap(&tVec[i + 1], &tVec[high]);
	compCount++;
	return (i + 1);
}

void quickSort(vector<int>& tVec, int low, int high, int& count, int& compCount) {
	if (low < high)
	{
		int pi = partition(tVec, low, high, count, compCount);
		quickSort(tVec, low, (pi - 1), count, compCount);
		quickSort(tVec, (pi + 1), high, count, compCount);
	}
}

void shellShort(vector<int>& tVec, int size, int& count, int& compCount) {
	int gap;
	for (gap = (size / 2); gap > 0; gap /= 2)
	{

		for (int i = 0; i < size; i++)
		{
			//Saving i value 
			int temp = tVec[i];
			int j = i;
			//This for loop is in place to shift the already sorted data up 
			for (j; j >= gap && tVec[j - gap] > temp; j -= gap) {
				tVec[j] = tVec[j - gap];
				count++;
				compCount++;
			}
			tVec[j] = temp;
			compCount++;
		}
	}
}
