#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
using namespace std;

void selectionSort(int *list, int n);
void printList(int* list, int n);
int* generateRandList(int n);

#if 1
int main() {
	//int list[] = { 3, 4, 1, 7, 9, 6, 5, 2, 8, 0 };
	//const int N = sizeof(list) / sizeof(list[0]);	// Task1
	int *list = NULL;
	const int N = 50;

	srand(time(NULL));
	list = generateRandList(N);

	cout << "UNSORTED: " << endl;
	printList(list, N);

	selectionSort(list, N);

	cout << "SORTED: " << endl;
	printList(list, N);

	delete[] list;
	// system("pause");
	cout << "Happy Coding~~" << endl;
}
#endif


void selectionSort(int *list, int n)
{
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		// Swap min found with the first one of unsorted
		temp = list[i];
		list[i] = list[min];
		list[min] = temp;
	}
}

int* generateRandList(int n)
{
	int i, j;
    int* randList = NULL;

	randList = new (nothrow) int[n];
    assert(randList != NULL);

	for(i = 0; i < n; i++){
        randList[i] = rand() % n;

        j = 0;
        while(j < i){
            if(randList[i] == randList[j]){
                randList[i] = rand() % n;
                j = 0;
                continue;
            }
            j++;
        }
    }

    return randList;
}

void printList(int* list, int n)
{
	for(int i = 0; i < n; i++){
		cout << list[i] << " ";
	}
	cout << endl;
}
