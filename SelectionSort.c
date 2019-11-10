#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Selection(int arr[], int jml, int temp, int loop1, int loop2, int sort){
	
	if (loop1 == jml) return printf("\n\nSorting Selesai");
	
	if (loop2 == jml) {
		loop2 = arr[temp];
		arr[temp] = arr[loop1];
		arr[loop1] = loop2;
		return Selection(arr, jml, loop1+1, loop1+1, loop1+1, sort);
	}
	
	if (sort == 0 && arr[temp] > arr[loop2]) temp = loop2;
	else if (sort == 1 && arr[temp] < arr[loop2]) temp = loop2;
	
	return Selection(arr, jml, temp, loop1, loop2+1, sort);
}

int main() 
{
	int jml; printf("Masukkan jumlah data : "); scanf("%d", &jml);
	int arr[jml];
	int x, temp, z;
	
	srand(time(NULL));
	
	temp=jml*2;
	
	printf("\nData: ");
	for (x=0; x<jml; x++) {
		arr[x] = rand() % temp + 1;
		printf("%d ", arr[x]);
	}
	
	Selection(arr, jml, 0, 0, 1, 0);
	
	printf("\n\nSorted Data (Ascending): ");
	for (x=0; x<jml; x++) {
		printf("%d ", arr[x]);
	}
	
	Selection(arr, jml, 0, 0, 1, 1);
	
	printf("\n\nSorted Data (Descending): ");
	for (x=0; x<jml; x++) {
		printf("%d ", arr[x]);
	}
	
	return 0;
}
