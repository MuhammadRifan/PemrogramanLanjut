#include <stdio.h>
#include <stdlib.h>

struct mahasiswa{
	char npm[15];
	char nama[25];
	char fakultas[15];
	char jurusan[20];
	int semester;
};

typedef struct mahasiswa mhs;

int main(int argc, char *argv[]) {
	
	mhs rifan;
	strcpy(rifan.npm, "18081010067");
	strcpy(rifan.nama, "Muhammad Rif'an");
	strcpy(rifan.fakultas, "Ilmu Komputer");
	strcpy(rifan.jurusan, "Teknik Informatika");
	rifan.semester = 3;
	
	printf("NPM: %s\n", rifan.npm);
	printf("Nama: %s\n", rifan.nama);
	printf("Fakultas: %s\n", rifan.fakultas);
	printf("Jurusan: %s\n", rifan.jurusan);
	printf("Semester: %d\n", rifan.semester);
	
	int nilai = 10;
	printf("Value nilai: %d \n", nilai);
	printf("Alamat memori nilai: %d \n", &nilai);
	
	int *pnil = &nilai;
	int tes = &nilai;
	
	printf("Alamat nilai dari pointer nilai: %d + %d + %d \n", *pnil, tes, &pnil);
	
	int *a; // a = 68, *a = ?
	// a = nilai; ?
	// *a = &nilai; // a = 6487572, *a = 6487572
	a = &nilai; // a = 6487572, *a = nilai
	
	printf("%d %d %d", nilai, a, *a);
	
	return 0;
}
