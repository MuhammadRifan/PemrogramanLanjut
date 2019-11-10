#include <stdio.h>
#include <stdlib.h>

int recur(int bil, int pang)
{
	if(pang == 1){
		return bil;
	}else{
		return bil*recur(bil, pang-1);
	}
}

int itera(int bil, int pang)
{
	int x, hasil=1;
	for(x=0; x<pang; x++){
		hasil = hasil*bil;
	}

	return hasil;
}

int main(int argc, char *argv[]) {
	
	int bil, pang, menu;
	
	int z=0;
	while(z == 0){
		printf("Masukkan bilangan: ");
		scanf("%d", &bil);
		printf("Masukkan pangkat: ");
		scanf("%d", &pang);
		
		printf("\n1. Rekursif \n2. Iteratif \nPilih metode penyelesaiannya: ");
		scanf("%d", &menu);
		switch(menu){
			case 1:
				printf("Hasil rekursif = %d\n", recur(bil, pang));
				break;
			case 2:
				printf("Hasil iteratif = %d\n", itera(bil, pang));
				break;
			default:
				printf("Pilih menu dengan benar");
				break;
		}
		
		printf("\n1. Kembali ke awal \n2. Keluar \nPilih: ");
		scanf("%d", &menu);
		(menu == 1) ? system("cls") : (z=1);
	}

	return 0;
}

