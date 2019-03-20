#ifndef SORT_H
#define SORT_H

int acscending(int a, int b);
int descending(int a, int b);
void bubbleSort(int* , int, int (*)(int, int));
void insertionSort(int*, int, int (*)(int, int));
void selectionSort(int*, int, int (*)(int, int));
void quickSort(int*, int, int (*)(int, int) = acscending);

//sort.h가 sort.cpp와 quicksort.cpp 두개에 동시에 영향을 주므로, 여기에 디폴트 파리미터를 선언한다.

#endif
