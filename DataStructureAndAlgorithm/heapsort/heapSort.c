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
	int arr[10];
	int arrLength = sizeof(arr) / sizeof(int);
	int i;
	srand(time(NULL));

	for (i = 0; i < arrLength; i++){
		arr[i] = rand() % 30;
	}

	for (i = 0; i < arrLength; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	heapSort(arr, arrLength);
	for (i = 0; i < arrLength; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}




// ver. ±³¼ö´Ô
//void manage(int *, int);
//void heapsort(int *, int, int);
//
//void manage(int *arr, int i)
//{
//	int tmp;
//	tmp = arr[i];
//	while ((i>1) && (arr[i / 2]<tmp))
//	{
//		arr[i] = arr[i / 2];
//		i = i / 2;
//	}
//	arr[i] = tmp;
//}
//
//
//void heapsort(int *arr, int i, int size)
//{
//	int tmp, j;
//	tmp = arr[i];
//	j = i * 2;
//	while (j <= size)
//	{
//		if ((j < size) && (arr[j] < arr[j + 1]))
//			j++;
//		if (arr[j] < arr[j / 2])
//			break;
//		arr[j / 2] = arr[j];
//		j = j * 2;
//	}
//	arr[j / 2] = tmp;
//}
//
//#define NDATA 20
//
//int main()
//{
//	int arr[NDATA + 1];
//	int i, j, size, tmp, k;
//	size = NDATA;
//	j = size;
//	for (i = 1; i <= NDATA; i++) {
//		arr[i] = rand() % 100;
//	}
//	for (i = 1; i <= j; i++) {
//		tmp = arr[1];
//		arr[1] = arr[size];
//		arr[size] = tmp;
//		size--;
//		heapsort(arr, 1, size);
//	}
//	size = j;
//	for (i = 1; i <= size; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}