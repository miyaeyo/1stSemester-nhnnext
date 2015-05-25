#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int comp(const void* x, const void*y){
	int* xx = (int*)x;
	int* yy = (int*)y;
	return *xx - *yy;
} // float  ÀÏ¶§´Â  float

void swap(int v[], int i, int j){
	int temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
void myqsort(int v[], int start, int end){
	int x = v[start];
	int p = start + 1;
	int q = end;
	if (start < end){
		while (p < q){
			while (v[p] <= x && p < end)
				p++;
			while (v[q] > x)
				q--;
			if (p < q)
				swap(v, p, q);
		}
		if (v[start]>v[q])
			swap(v, start, q);
		myqsort(v, start, q - 1);
		myqsort(v, q + 1, end);
	}
}

int main(){
	//int v[] = {83, 86, 77, 15, 93, 35, 86, 92, 49, 21};
	int v[20];
	int n = sizeof(v) / sizeof(v[0]);
	int i;
	srand(time);
	//qsort(v, sizeof(v) / sizeof(v[0]), sizeof(v[0]), &comp);
	for (i = 0; i < n; i++){
		v[i] = rand() % 200;
	}
	for (i = 0; i < n; i++){
		printf("%d ", v[i]);
	}
	myqsort(v, 0, n-1);
	printf("\n");
	for (i = 0; i < n; i++){
		printf("%d ", v[i]);
	}
	printf("\n");
}