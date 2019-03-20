#include <iostream>
#include <cmath>
#include <ctime>
#include <cassert>
#include "nowic.h"
#include "sort.h"
using namespace std;

/*
extern void bubbleSort(int* , int, int (*)(int, int));
extern void insertionSort(int*, int, int (*)(int, int));
extern void selectionSort(int*, int, int (*)(int, int));
extern void quickSort(int*, int, int (*)(int, int));
*/

int getSampleSize(int arg, char* argv[]);
int* generateRandList(int N);
void print_list(int *list, int n);
void testCase(int* list, int N, int test_option);
int acscending(int a, int b);
int descending(int a, int b);

#if 1
int main(int argc, char* argv[])
{
	int N, test_option;
	int* list;
	srand(time(NULL));

	N = getSampleSize(argc, argv);
	list = generateRandList(N);
	for(test_option = 0; test_option < 4; test_option++)
		testCase(list, N, test_option);

	delete[] list;
	cout << "Happy Coding~~\n";
}
#endif


//User-defined Functions
int getSampleSize(int argc, char* argv[])
{
	int N;

	if(argc < 2){
		N = GetInt("Enter a number of samples to sort: ");
	}
	else{
		N =  atoi(argv[1]);
		if(N < 1){
			cout << "Your input (" << N << ") cannot be processed." << endl;
			N = GetInt("Enter a number of samples to sort: ");
		}
	}

	return N;
}

int* generateRandList(int N)
{
	int *list = new (nothrow) int[N];
	assert(list != nullptr);

	for (int i = 0; i < N; i++)
		list[i] = rand() % N;
	return list;
}

void print_list(int *list, int n)
{
	for (int i = 0; i < n; i++)
		cout << list[i] << " ";
	cout << endl;
}

void testCase(int* list, int N, int test_option)
{
	int i, j;
	clock_t start, end;
	string algorithm_list[4] = {"Bubble", "Insert", "Quick", "Select"};
	string option[] = {"Not passing a default argument: quickSort(list, N)",
	"Passing a function pointer: quickSort(list, N, up)",
	"Passing a function pointer: quickSort(list, N, dn)",
	"Using an array of function pointers "};
	string sorted[] = {"NOT", "Up ", "Dn ", "  "};
	int (*compOption[])(int, int) = {acscending, descending};
	void (*sortFn[])(int*, int, int (*)(int, int)) = {bubbleSort, insertionSort, selectionSort, quickSort};
	const int WIDTH = 6;

	cout << "Test Case: " << option[test_option] << endl;
	for(i = 0; i < 30; i++) cout << "-";
	cout << endl;
	//cout.width[WIDTH];
	//cout.fill(" ");

	switch (test_option){
		case 0:
			start = clock();
			cout << sorted[0] <<"sorted: ";
			print_list(list, N);
			cout << sorted[3] << "sorted: ";
			quickSort(list, N);
			end = clock();
			print_list(list, N);
			cout << "\t\tDuration: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds\n";
			cout << endl;
			break;

		case 1:
			start = clock();
		 	for(i = 0; i < 2; i++){
				cout << sorted[i] << "sorted: ";
				if(i > 0){
					quickSort(list, N, acscending);
					end = clock();
				}
				print_list(list, N);
				if(i > 0)
					cout << "\t\tDuration: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds\n";
			}
			cout << endl;
			break;

		case 2:
			start = clock();
			for(i = 0; i < 2; i++){
				cout << sorted[i] << "sorted: ";
				if(i > 0){
					quickSort(list, N, descending);
					end = clock();
				}
				print_list(list, N);
				if(i > 0)
					cout << "\t\tDuration: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds\n";
			}
			cout << endl;
			break;

		case 3:
			for(i = 0; i < 4; i++){
				for(j = 0; j <3; j++){
					start = clock();
					cout << sorted[j] << "sorted[";
					cout.width(WIDTH);
					cout.fill(' ');
					cout << algorithm_list[i];
					cout << "]: ";
					if(j > 0){
						sortFn[i](list, N, compOption[j - 1]);
						end = clock();
					}
					print_list(list, N);
					if(j > 0)
						cout << "\t\tDuration: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds\n";
				}
				cout << endl;
			}
			break;
	}
}

int acscending(int a, int b){ return a - b; }
int descending(int a, int b){ return b - a; }
