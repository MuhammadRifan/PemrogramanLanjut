#include <stdio.h>
#include <stdlib.h>

struct ipkmhs{
	char npm[11];
	char nama[30];
	float ipk;
};

typedef struct ipkmhs ipms;

int main(int argc, char *argv[]) {
	
	ipms ims[3];

	int x,sum = 3;
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
	for(x=0; x<sum; x++) if (ims[x].ipk >= 3.0) printf("%s\n", ims[x].nama);
	
	printf("Mahasiswa ipk < 3:\n");
	for(x=0; x<sum; x++) if (ims[x].ipk < 3.0) printf("%s\n", ims[x].nama);
	
	printf("\n");
	
	return 0;
}
