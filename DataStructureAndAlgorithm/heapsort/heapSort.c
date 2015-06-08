/* HEAP SORT
* 151008 Á¤½Â¹Ì
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int arr[], int i, int j){
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void max_heapify(int arr[], int i, int heapSize){
	int leftIndex = 2 * i;
	int rightIndex = 2 * i + 1;
	int maxIndex;
	if (leftIndex <= heapSize && arr[leftIndex-1] > arr[i-1])
		maxIndex = leftIndex;
	else
		maxIndex = i;
	if (rightIndex <= heapSize && arr[rightIndex-1] > arr[maxIndex-1])
		maxIndex = rightIndex;
	if (maxIndex != i){
		swap(arr, i - 1, maxIndex - 1);
		max_heapify(arr, maxIndex, heapSize);
	}		
}
void build_max_heap(int arr[], int arrLength){
	int i;
	for (i = arrLength / 2; i > 0; i--)
		max_heapify(arr, i, arrLength);
}
void heapSort(int arr[], int arrLength){
	int i;
	build_max_heap(arr, arrLength);
	for (i = arrLength; i > 1; i--){
		swap(arr, 0, i-1);
		arrLength = arrLength - 1;
		max_heapify(arr, 1, arrLength);
	}
}

void main(){
	int arr[20];
	int arrLength = sizeof(arr) / sizeof(int);
	int i;
	srand((unsigned)time(NULL));

	for (i = 0; i < arrLength; i++){
		arr[i] = rand() % 100;
	}
	puts("[original sequence]");
	for (i = 0; i < arrLength; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	puts("[after heapsort]");
	heapSort(arr, arrLength);
	for (i = 0; i < arrLength; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}




