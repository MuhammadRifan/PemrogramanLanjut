#include <stdio.h>
#include <stdlib.h>

// Buat baru, namun dengan acuan dari kodingan pak Fawwas

struct node {
	int data;
	struct node *next;
};
typedef struct node node;

void printList(node *head) {
	node *nJumper;
				
	printf("Data :");
	nJumper = head;
	while(nJumper != NULL){
		printf(" %d ->", nJumper->data);
		nJumper = nJumper->next;
	}
	printf(" NULL\n");
}

void tambahExec(node **head, node *nPost, node *nNew) {
	if (nPost == NULL) {
		nNew->next = *head;
		*head = nNew;
	} else {
		nNew->next = nPost->next;
		nPost->next = nNew;
	}
}

void tambahNode(node **head, int sec) {
	int bil;
	node *nTemp, *nSeek;
	
	printf("\n");
	printList(*head);
	
	printf("\nMasukkan bilangan: ");
	scanf("%d", &bil);
	
	nTemp = (node *)malloc(sizeof(node));
	
	nTemp->data = bil;
	nTemp->next = NULL;
	
	if(sec == 1) tambahExec(head, NULL, nTemp);
	else if (sec == 2){
		printf("\nPilih data sebelum data baru: ");
		scanf("%d", &bil);
		
		nSeek = *head;
		while(nSeek != NULL && nSeek->data != bil){
			nSeek = nSeek->next;
		}
		
		if (nSeek == NULL) {
			printf("\nData tidak ditemukan\n");
			system("pause");
		} 
		else tambahExec(head, nSeek, nTemp);
	}else if(sec == 3){
		if(*head == NULL) tambahExec(head, NULL, nTemp);
		else {
			nSeek = *head;
			while(nSeek->next != NULL){
				nSeek = nSeek->next;
			}
			tambahExec(head, nSeek, nTemp);	
		}
	}
}

void hapusExec(node **head, node *nPre, node *nPos) {
	if(nPre == NULL){
		*head = nPos->next;
	}else{
		nPre->next = nPos->next;
	}
	free(nPos);
}

void hapusNode(node **head, int sec) {
	int bil;
	node *nPre, *nSeek;
	
	nPre = NULL;
	nSeek = *head;
	
	if(nSeek == NULL){
		printf("\nData Kosong\n");
		system("pause");	
	}
	else if(sec == 1) hapusExec(head, NULL, *head);
	else if(sec == 2){
		printList(*head);
		
		printf("Pilih data yang dihapus: ");
		scanf("%d", &bil);
		
		while(nSeek != NULL && nSeek->data != bil){
			nPre = nSeek;
			nSeek = nSeek->next;
		}
		
		if(nSeek == NULL) {
			printf("Data tidak ditemukan");
		} 
		else hapusExec(head, nPre, nSeek);
	}else if(sec == 3){
		while(nSeek->next != NULL){
			nPre = nSeek;
			nSeek = nSeek->next;
		}
		
		hapusExec(head, nPre, nSeek);
	}
}

int main()
{
	node *head;
	int menu = 1;
	
	head = NULL;
	
	while(menu != 0){
		system("cls");
		printf("+----------------+--------------+\n");
		printf("+-------+ Selamat Datang +------+\n");
		printf("+----------------+--------------+\n");
		printf("+-----  1. Tambah data     -----+\n");
		printf("+-----  2. Hapus data      -----+\n");
		printf("+-----  3. Tampilkan data  -----+\n");
		printf("+-----  4. Keluar          -----+\n");
		printf("+-------------+--+--+-----------+\n");
		printf(" Silahkan pilih: ");
		scanf("%d", &menu);
		fflush(stdin);
		
		switch(menu) {
			case 1:
				menu = 0;
				system("cls");
				
				printf("+------------------+------------------+\n");
				printf("+-----------+ Tambah Data +-----------+\n");
				printf("+-----  1. Tambah data diawal    -----+\n");
				printf("+-----  2. Tambah data ditengah  -----+\n");
				printf("+-----  3. Tambah data diakhir   -----+\n");
				printf("+-----  4. Kembali               -----+\n");
				printf("+---------------+--+--+---------------+\n");		
				printf(" Silahkan pilih: ");
				scanf("%d", &menu);
				
				if(menu == 1){
					tambahNode(&head, 1);
				}else if(menu == 2){
					tambahNode(&head, 2);
				}else if(menu == 3){
					tambahNode(&head, 3);
				}else{
					menu = 4;
				}
				break;
			case 2:
				menu = 0;
				system("cls");
				
				printf("+-----------------+------------------+\n");
				printf("+-----------+ Hapus Data +-----------+\n");
				printf("+-----  1. Hapus data diawal    -----+\n");
				printf("+-----  2. Hapus data ditengah  -----+\n");
				printf("+-----  3. Hapus data diakhir   -----+\n");
				printf("+-----  4. Kembali              -----+\n");
				printf("+--------------+--+--+---------------+\n");
				printf(" Silahkan pilih: ");
				scanf("%d", &menu);
				
				if(menu == 1){
					hapusNode(&head, 1);
				}else if(menu == 2){
					hapusNode(&head, 2);
				}else if(menu == 3){
					hapusNode(&head, 3);
				}else{
					menu = 4;
				}
				break;
			case 3:
				system("cls");
				
				int jml = 0;
				node *nJumper;
				
				printf("Data :");
				nJumper = head;
				while(nJumper != NULL){
					printf(" %d ->", nJumper->data);
					jml = jml + nJumper->data;
					nJumper = nJumper->next;
				}
				printf(" NULL\n\n");
				
				printf("Jumlah dari seluruh data: %d\n\n", jml);
				
				system("pause");
				break;
			case 4:
				printf("\nTerima Kasih ^^");
				menu = 0;
				break;
			default:
				printf("Mohon masukkan dengan benar ^^\n");
				system("pause");
				break;
		}
	}
}
