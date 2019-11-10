#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct NilaiMahasiswa{
	int NPM;
	float IPK;
};

struct ipkmhs{
	char npm[11];
	char nama[30];
	float ipk;
};

typedef struct ipkmhs ipms;

typedef struct NilaiMahasiswa nilai;

int main(int argc, char *argv[]) {
	
	/// Tugas 1 ///
	
	int bla[20], x, y, sum;
	
	sum = 0;
	for(x=0; x<20; x++){
		printf("Masukkan array ke %d: ", x);
		scanf("%d",&bla[x]);
		sum++;
	}
	
	printf("\n");
	
	for(x=0; x<sum; x++){
		printf("Array ke %d = %d\n", x,bla[x]);
	}
	
	printf("\n");
	
	for(x=sum-1; x>=0; x--){
		printf("Array ke %d = %d\n", x,bla[x]);
	}
	
	printf("\n");
	
	int input, found = 0;
	printf("Masukkan data : ");
	scanf("%d", &input);
	
	for(x=0; x<sum; x++){
		if(bla[x] == input) {
			printf("Data %d ditemukan pada array ke %d\n", input, x);
			found++;
			break;	
		}
	}
	
	if(found == 0) printf("Data tidak ditemukan\n");
	
	/// Nilai Array ///
	
	int npm[10];
	float ipk[10];
	
	sum = 5;
	for(x=0; x<2; x++){
		for(y=0; y<sum; y++){
			if(x == 0){
				printf("Masukkan NPM ke %d: ", y);
				scanf("%d",&npm[y]);
			} else {
				printf("Masukkan IPK ke %d: ", y);
				scanf("%f",&ipk[y]);
			}
		}
		printf("\n");
	}
	
	for(x=0; x<sum; x++){
		printf("NPM ke %d = %d, IPK = %.2f\n", x,npm[x],ipk[x]);
	}
	
	printf("\n");

	/// Struct Nilai ///
	
	nilai nla[5];
	
	sum = 5;
	for(y=0; y<sum; y++){
		printf("Masukkan NPM ke %d: ", y);
		scanf("%d",&nla[y].NPM);
		printf("Masukkan IPK ke %d: ", y);
		scanf("%f",&nla[y].IPK);
		printf("\n");
	}
	
	for(x=0; x<sum; x++){
		printf("NPM ke %d = %d, IPK = %.2f\n", x, nla[x].NPM, nla[x].IPK);
	}
	
	printf("\n");
	
	/// Struct IPK MHS ///
	
	ipms ims[5];
	
	sum = 5;
	fflush(stdin);
	for(x=0; x<sum; x++){
		printf("Masukkan NPM ke %d: ", x);
		gets(ims[x].npm);
		printf("Masukkan Nama ke %d: ", x);
		gets(ims[x].nama);
		printf("Masukkan IPK ke %d: ", x);
		scanf("%f", &ims[x].ipk);
		fflush(stdin);
		printf("\n");
	}
	
	printf("Mahasiswa ipk >= 3:\n");
	for(x=0; x<sum; x++) if (ims[x].ipk >= 3) printf("%s\n", ims[x].nama);
	
	printf("Mahasiswa ipk < 3:\n");
	for(x=0; x<sum; x++) if (ims[x].ipk < 3) printf("%s\n", ims[x].nama);
	
	printf("\n");
	
	return 0;
}
