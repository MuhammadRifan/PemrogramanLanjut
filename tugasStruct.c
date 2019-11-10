#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct tanggalLahir{
	int tgl;
	int bln;
	int thn;
};

struct alamat{
	char jalan[30];
	char kota[15];
	char provinsi[20];
};

struct bank{
	int noRek;
	char bank[10];
	char nama[50];
	
	struct tanggalLahir tl;
	
	float saldo;
	
	struct alamat al;
};

typedef struct bank bankurt;

int main(int argc, char *argv[]) {
	
	time_t s;
    struct tm* current_time;
    s = time(NULL);
    current_time = localtime(&s);
    
    srand(time(NULL));
    
	int x, loop = 0, menu, sum = 0, umin, umax, year, found;
	float min, max, totalSaldo;
	char kovin[20];
	
	bankurt bank[20];
	
	while (loop == 0) {
		system("cls");
		printf("+------------------------------+-----------------------------+\n");
		printf("+---------------------+ Selamat Datang +---------------------+\n");
		printf("+------------------------------+-----------------------------+\n");
		printf("+-----  1. Tambah nasabah                               -----+\n");
		printf("+-----  2. Tampilkan total saldo                        -----+\n");
		printf("+-----  3. Tampilkan semua nasabah                      -----+\n");
		printf("+-----  4. Tampilkan saldo terbanyak dan tersedikit     -----+\n");
		printf("+-----  5. Cari saldo dalam range tertentu              -----+\n");
		printf("+-----  6. Cari nasabah dalam range umur tertentu       -----+\n");
		printf("+-----  7. Cari nasabah berdasarkan kota atau provinsi  -----+\n");
		printf("+-----  8. Keluar                                       -----+\n");
		printf("+---------------------------+--+--+--------------------------+\n");
		printf(" Silahkan pilih: ");
		scanf("%d", &menu);
		system("cls");
		fflush(stdin);
		
		switch(menu) {
			case 1: // Insert nasabah
				printf("+------------------------------+-----------------------------+\n");
				printf("+---------------------+ Tambah Nasabah +---------------------+\n");
				
				if (sum < 20) {
					printf(" Nasabah ke-%d:\n", sum+1);
					printf(" Masukkan nama nasabah: ");
					gets(bank[sum].nama);
					
					printf(" Masukkan tanggal nasabah lahir: ");
					scanf("%d", &bank[sum].tl.tgl);
					printf(" Masukkan bulan nasabah lahir: ");
					scanf("%d", &bank[sum].tl.bln);
					printf(" Masukkan tahun nasabah lahir: ");
					scanf("%d", &bank[sum].tl.thn);
					fflush(stdin);
					
					printf(" Masukkan alamat nasabah: ");
					gets(bank[sum].al.jalan);
					printf(" Masukkan kota nasabah: ");
					gets(bank[sum].al.kota);
					printf(" Masukkan provinsi nasabah: ");
					gets(bank[sum].al.provinsi);
					
					printf(" Masukkan bank nasabah: ");
					gets(bank[sum].bank);
					printf(" Masukkan jumlah saldo nasabah: ");
					scanf("%f", &bank[sum].saldo);
					
					bank[sum].noRek = rand() % 9876543210 + 1234567890;
					sum ++;
					
					printf("\n+----------------------+ Data disimpan +---------------------+\n");
				} else {
					printf(" Penyimpanan penuh\n");
				}
				
				printf("+---------------------------+--+--+--------------------------+\n");
								
				system("pause");
				break;
			case 2: // Total saldo
				printf("+----------------------------+----------------------------+\n");
				printf("+---------------------+ Total saldo +---------------------+\n");
				
				if (sum < 1) {
					printf(" Data kosong\n");
				} else {
					totalSaldo = 0;
					for (x=0; x<sum; x++) {
						printf("- Nasabah %s dengan saldo %.2f\n", bank[x].nama, bank[x].saldo);
						totalSaldo = totalSaldo + bank[x].saldo;
					}
					printf("\n #Total saldo: Rp %.2f\n", totalSaldo);	
				}
				
				printf("+-------------------------+--+--+-------------------------+\n");
				system("pause");
				break;
			case 3: // Tampil semua
				printf("+------------------------------+-----------------------------+\n");
				printf("+--------------------+ Data semua nasabah +------------------+\n");
				
				if (sum < 1) {
					printf(" Data kosong\n");
				} else {
					for (x=0; x<sum; x++) {
						printf(" Data nasabah ke #%d: \n", x+1);
						printf(" - Nama nasabah\t\t: %s\n", bank[x].nama);
						printf(" - No rekening\t\t: %d\n", bank[x].noRek);
						
						printf(" - Tanggal lahir nasabah: %d-%d-%d\n", bank[x].tl.tgl, bank[x].tl.bln, bank[x].tl.thn);
						
						printf(" - Alamat nasabah\t: %s, %s, %s\n", bank[x].al.jalan, bank[x].al.kota, bank[x].al.provinsi);
						
						printf(" - Bank nasabah\t\t: %s\n", bank[x].bank);
						printf(" - Jumlah saldo nasabah\t: Rp %.2f\n", bank[x].saldo);
						
						printf("\n");
					}	
				}
				
				printf("+---------------------------+--+--+--------------------------+\n");
				system("pause");
				break;
			case 4: // Terbanyak dan tersedikit
				printf("+------------------------------+-----------------------------+\n");
				printf("+----------------------+ Filter saldo +----------------------+\n");
				
				if (sum < 1) {
					printf(" Data kosong\n");
				} else {
					umax = 0, umin = 0;
					for (x=0; x<sum; x++) {
						if (bank[umax].saldo <= bank[x].saldo) {
							umax = x;
						}
						if (bank[umin].saldo >= bank[x].saldo) {
							umin = x;
						}
					}
					
					printf("\n Saldo terbanyak dimiliki nasabah %s senilai %.2f\n", bank[umax].nama, bank[umax].saldo);
					printf("\n Saldo tersedikit dimiliki nasabah %s senilai %.2f\n\n", bank[umin].nama, bank[umin].saldo);	
				}
				
				printf("+---------------------------+--+--+--------------------------+\n");
				system("pause");
				break;
			case 5: // saldo range tertentu
				printf("+------------------------------+-----------------------------+\n");
				printf("+----------------------+ Filter saldo +----------------------+\n");
				
				if (sum < 1) {
					printf(" Data kosong\n");
				} else {
					found = 0;
					printf(" Masukkan minimum saldo: ");
					scanf("%f", &min);
					printf(" Masukkan maximum saldo: ");
					scanf("%f", &max);
					
					printf("\n Hasil: \n");
					
					for (x=0; x<sum; x++) {
						if(bank[x].saldo >= min && bank[x].saldo <= max) {
							printf("- Nasabah %s dengan saldo: %.2f\n", bank[x].nama, bank[x].saldo);
							found++;
						};
					}
					
					if (found == 0) printf(" Data tidak ditemukan\n");	
				}
				
				printf("+---------------------------+--+--+--------------------------+\n");
				system("pause");
				break;
			case 6: // umur range tertentu
				printf("+------------------------------+-----------------------------+\n");
				printf("+--------------------+ Cari dengan umur +--------------------+\n");
				
				if (sum < 1) {
					printf(" Data kosong\n");
				} else {
					found = 0;
					printf(" Masukkan minimum umur: ");
					scanf("%d", &umin);
					printf(" Masukkan maximum umur: ");
					scanf("%d", &umax);
					
					printf("\n Hasil: \n");
					
					for (x=0; x<sum; x++) {
						year = (current_time->tm_year + 1900) - bank[x].tl.thn;
						if (year >= umin && year <= umax) {
							printf("- Nasabah %s berumur %d tahun\n", bank[x].nama, year);
							found++;
						}	
					}
					
					if (found == 0) printf(" Data tidak ditemukan\n");
				}
				
				printf("+---------------------------+--+--+--------------------------+\n");
				system("pause");
				break;
			case 7: // search kota / provinsi
				printf("+------------------------------+-----------------------------+\n");
				printf("+---------------+ Cari dengan kota / provinsi +--------------+\n");
				
				if (sum < 1) {
					printf(" Data kosong\n");
				} else {
					found = 0;
					printf(" Masukkan kota/provinsi: ");
					gets(kovin);
					
					printf("\n Hasil: \n");
					
					for (x=0; x<sum; x++) {
						
						if (strcmp(bank[x].al.kota, kovin) == 0) {
							printf("- Nasabah %s tinggal di kota %s\n", bank[x].nama, bank[x].al.kota);
							found++;
						} else if (strcmp(bank[x].al.provinsi, kovin) == 0) {
							printf("- Nasabah %s tinggal di provinsi %s\n", bank[x].nama, bank[x].al.provinsi);
							found++;
						}
					}
					
					if (found == 0) printf(" Data tidak ditemukan\n");	
				}
				
				printf("+---------------------------+--+--+--------------------------+\n");
				system("pause");
				break;
			case 8:
				printf("+------------------------------+-----------------------------+\n");
				printf("+----------------------+ Terima kasih +----------------------+\n");
				printf("+------------------------------+-----------------------------+\n");
				system("pause");
				loop = 1;
				break;
			default:
				printf("Mohon masukkan sesuai menu\n");
				system("pause");
				break;
		}
	}	
	
	return 0;
}
