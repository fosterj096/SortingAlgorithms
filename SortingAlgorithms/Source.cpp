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
void bubbleSort(vector<int>& tVec, int size, int& count);
void insertionSort(vector<int>& tVec, int size, int& count);
void selectionSort(vector<int>& tVec, int size, int& count);
void swap(int* x, int* y);
int partition(vector<int>& tVec, int low, int high, int& count);
void quickSort(vector<int>& tVec, int low, int high, int& count);

int main() {

	//Variable Declarations ---------------------------------
	vector<int> bubVector;
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		int temp = rand() % 100;
		bubVector.push_back(temp);
	}

	//Creating deep copies of initial vector to ensure all
	//sorting algorithms perform on the same vector
	vector<int> insertVector(bubVector);
	vector<int> selectVector(bubVector);
	vector<int> quickVector(bubVector);
	int size = bubVector.size();
	int bubbleCount = 0, selectCount = 0, insertCount = 0,
		quickCount = 0;

	bubbleSort(bubVector, size, bubbleCount);
	printVector(bubVector, size);
	cout << endl;
	insertionSort(insertVector, size, insertCount);
	printVector(insertVector, size);
	cout << endl;
	selectionSort(selectVector, size, selectCount);
	printVector(selectVector, size);
	cout << endl;
	quickSort(quickVector, 0, (size - 1), quickCount);
	printVector(quickVector, size);
	cout << endl;

	cout << "Bubble sort swaps performed: " << bubbleCount << endl;
	cout << "Insertion sort swaps performed: " << insertCount << endl;
	cout << "Selection sort swaps performed: " << selectCount << endl;
	cout << "Quick sort swaps performed: " << quickCount << endl;

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

void bubbleSort(vector<int>& tVec, int size, int& count) {
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
			}
		}
	}
}

void insertionSort(vector<int>& tVec, int size, int& count) {
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
		}
		tVec[j + 1] = key;
	}
}

void selectionSort(vector<int>& tVec, int size, int& count) {
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
			}
		}
		if (minVal != i) {
			swap(&tVec[i], &tVec[minVal]);
			count++;
		}
	}
}

int partition(vector<int>& tVec, int low, int high, int& count) {
	int pivot = tVec[high];//setting the pivot for the sort
	int i = (low - 1); //finds index of smaller element
	for (int j = low; j <= high - 1; j++)
	{
		if (tVec[j] < pivot)
		{
			i++;
			swap(&tVec[i], &tVec[j]);
			count++;
		}
	}
	swap(&tVec[i + 1], &tVec[high]);
	return (i + 1);
}

void quickSort(vector<int>& tVec, int low, int high, int& count) {
	if (low < high)
	{
		int pi = partition(tVec, low, high, count);
		quickSort(tVec, low, (pi - 1), count);
		quickSort(tVec, (pi + 1), high, count);
	}
}