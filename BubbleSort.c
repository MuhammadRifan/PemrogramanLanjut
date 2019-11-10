#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Bubble(int arr[], int jml, int swap, int jump, int sort){
	int temp = arr[jump+1];
	
	if (swap == 0 && jump == jml) return printf("\n\nSorting selesai!\n");
	else if (jump == jml) return Bubble(arr, jml, 0, 0, sort);
	else if (sort == 0 && temp < arr[jump]) {
		arr[jump+1] = arr[jump];
		arr[jump] = temp;
		return Bubble(arr, jml, swap+1, jump+1, sort);
	}
	else if (sort == 1 && temp > arr[jump]) {
		arr[jump+1] = arr[jump];
		arr[jump] = temp;
		return Bubble(arr, jml, swap+1, jump+1, sort);
	} 
	else return Bubble(arr, jml, swap, jump+1, sort);
	
}

int main()
{
	int jml; printf("Masukkan jumlah data : "); scanf("%d", &jml);
	int arr[jml];
	int cari, x, temp;
	
	srand(time(NULL));
	
	temp=jml*2;
	
	printf("\nData: ");
	for (x=0; x<jml; x++) {
		arr[x] = rand() % temp + 1;
		printf("%d ", arr[x]);
	}
	
	Bubble(arr, jml-1, 0, 0, 0);
	
	printf("\nSorted Data (Ascending): ");
	
	for (x=0; x<jml; x++) {
		printf("%d ", arr[x]);
	}
	
	Bubble(arr, jml-1, 0, 0, 1);
	
	printf("\nSorted Data (Descending): ");
	
	for (x=0; x<jml; x++) {
		printf("%d ", arr[x]);
	}
}
