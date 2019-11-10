#include <iostream>
using namespace std;

void biodata(string nama, string alamat, string ttl, int umur, string telp, string email, string pekerjaan, string status, string kelamin, string agama);

int main() {

	string nama, alamat, ttl, telp, email, pekerjaan, status, kelamin, agama;
	int umur;

	cout << "Hai, Selamat datang. Mohon perkenalkan diri anda :D" << endl;

	cout << "Nama: ";
	getline(cin, nama);

	cout << "Alamat: ";
	getline(cin, alamat);

	cout << "Tempat Tanggal Lahir: ";
	getline(cin, ttl);

	cout << "Umur: ";
	cin >> umur;
	cin.ignore();

	cout << "Email: ";
	getline(cin, email);

	cout << "No Telp: ";
	getline(cin, telp);

	cout << "Kelamin: ";
	getline(cin, kelamin);

	cout << "Agama: ";
	getline(cin, agama);

	cout << "Pekerjaan: ";
	getline(cin, pekerjaan);

	cout << "Status: ";
	getline(cin, status);
	
	cout << endl;
	
	biodata(nama, alamat, ttl, umur, telp, email, pekerjaan, status, kelamin, agama);

	return 0;
}

void biodata(string nama, string alamat, string ttl, int umur, string telp, string email, string pekerjaan, string status, string kelamin, string agama)
{
	cout << "Nama: " << nama << endl;
	cout << "Alamat rumah: " << alamat << endl;
	cout << "Tempat tanggal lahir: " << ttl << endl;
	cout << "Umur: " << umur << " Tahun" << endl;
	cout << "Email: " << email << endl;
	cout << "Telp: " << telp << endl;
	cout << "Kelamin: " << kelamin << endl;
	cout << "Agama: " << agama << endl;
	cout << "Pekerjaan: " << pekerjaan << endl;
	cout << "Status: " << status << endl;
}
