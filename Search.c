#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{	
	int jml; printf("Masukkan jumlah data : "); scanf("%d", &jml);
	int arr[jml];
	int cari, x, f=0, temp, z, a=0, b, c=jml;
	
	srand(time(NULL));
	
	temp = jml+100;
	
	printf("\nData: ");
	for (x=0; x<jml; x++) {
		arr[x] = rand() % temp;
		printf("%d ", arr[x]);
	}
	
	printf("\n\nCari : "); scanf("%d", &cari);
	
//	Sequential Search
	printf("\n+-----+ Sequential +-----+\n\n");
	
	for(x=0; x<jml; x++){
		if (arr[x] == cari) {
			f++; break;
		}
	}
	
	if (f != 0) printf("Hasil pencarian %d setelah loop %d kali = Ada", cari, x);
	else printf("Hasil pencarian %d setelah loop %d kali = Tidak ada", cari, x);
	
//	Sentinel Search
	printf("\n\n+------+ Sentinel +------+\n\n");
	
	x=0;
	arr[jml+1] = cari;
	
	while(x <= jml+1){
		if (x == jml+1) printf("Hasil pencarian %d setelah loop %d kali = Tidak Ada", cari, x);
		else if (arr[x] == cari) {
			printf("Hasil pencarian %d setelah loop %d kali = Ada", cari, x);
			x = jml+1;
		} 
		x++;
	}
	
//	Binary Search
	printf("\n\n+-------+ Binary +-------+\n\n");
	
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
	
	printf("Sorted Data: ");
	for (x=0; x<jml; x++) {
		printf("%d ", arr[x]);
	}
	
	x=1;
	
	while (x != 0){
		b = (a + c) / 2;
		
		if (arr[b] == cari) {
			printf("\n\nHasil pencarian %d setelah loop %d kali = Ada\n", cari, x);
			x = 0;
		} else if (a >= c) {
			printf("\n\nHasil pencarian %d setelah loop %d kali = Tidak Ada\n", cari, x);
			x = 0;
		} else if (arr[b] < cari) {
			a = b + 1;
			x++;
		} else if (arr[b] > cari) {
			c = b - 1;
			x++;
		}
	}
	
	return 0;
}
