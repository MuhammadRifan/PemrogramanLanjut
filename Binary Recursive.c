#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int binary(int arr[], int awal, int tengah, int akhir, int cari, int loop) {
	if (arr[tengah] == cari) 
		return printf("\n\nHasil pencarian %d setelah loop %d kali = Ada\n", cari, loop);
	else if (awal >= akhir) 
		return printf("\n\nHasil pencarian %d setelah loop %d kali = Tidak Ada\n", cari, loop);
	else if (arr[tengah] < cari) 
		return binary(arr, (tengah + 1), ((awal + akhir) / 2), akhir, cari, loop+1);
	else if (arr[tengah] > cari) 
		return binary(arr, awal, ((awal + akhir) / 2), (tengah - 1), cari, loop+1);
}

int main()
{	
	
	int jml; printf("Masukkan jumlah data : "); scanf("%d", &jml);
	int arr[jml];
	int cari, x, f=0, temp, z, a=0, b, c=jml;
	
	srand(time(NULL));
	
	temp=jml+100;
	
	printf("\nData: ");
	for (x=0; x<jml; x++) {
		arr[x] = rand() % temp;
		printf("%d ", arr[x]);
	}
	
	printf("\n\nCari : "); scanf("%d", &cari);
	
//	Binary Search
	
	for(x=1; x<jml; x++) {
		if (arr[x] < arr[x-1]) {
			temp = arr[x];
			for (z=x-1; z>=0; z--) {
				if (arr[z] > temp) {
					arr[z+1] = arr[z];
					arr[z] = temp;
				} else break;
			}
		}
	}
	
	printf("\nSorted Data: ");
	for (x=0; x<jml; x++) {
		printf("%d ", arr[x]);
	}
	
	x=1;
	
	b = (a + c) / 2;
	
	binary(arr, a, b, c, cari, 1);
	
	return 0;
}
