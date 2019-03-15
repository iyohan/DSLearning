/*
On my honour,  I pledge that I have neither received nor provided
improper assistance in the completion of this assignment.
Signed: John Lee    section: ECE20010 (02)  Student Number: 21800815
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <string>

using namespace std;

void swap(int&, int&, int&);
void selectionSort(int[], int);
int getSampleSize(int size = -1);
int* generateRandList(int);
void printList(int*, int);

int main(int argc, char* argv[])
{
	int i, size;
	int* list = NULL;

	srand(time(NULL));

	if(argc < 2)
		size = getSampleSize();
	else
	 	size = getSampleSize(stoi(argv[1]));

	cout << endl << "UnSorted array: " << endl;
	list = generateRandList(size);
	printList(list, size);

	selectionSort(list, size);

	cout << endl <<"Sorted array: " << endl;
	printList(list, size);

	delete(list);

	return 0;
}


// User-defined functions
void swap(int& x, int& y, int& temp)
{
	temp = x;
	x = y;
	y = temp;
}

void selectionSort(int list[], int n)
{
	int i, j, min, temp;

	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		swap(list[i], list[min], temp);
	}
}

int getSampleSize(int size)
{
	const int MAX_SIZE = 100;
	//아예 없애는 것은 오류의 가능성이 커지는 것 같아
	//symbolic integer로 만들어 const 처리함.
	string str_size = "";

	while(size < 1 || size > MAX_SIZE){
		if(size == 0)
			exit(1);
		cout << "Enter the number of samples: ";
		getline(cin, str_size);
		size = stoi(str_size);
	}

	return size;
}

int* generateRandList(int size)
{
	int* list = new int[size];
	assert(list != NULL);

	for(int i = 0; i < size; i++){
		list[i] = rand() % 1000;
	}

	return list;
}

void printList(int* list, int size)
{
	for(int i = 0; i < size; i++){
		cout << list[i] << "  ";
	}
	cout << endl;
}
