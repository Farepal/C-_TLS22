#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//ngedit uang, nambah uang, ngurangin uang, nukar bak ke uang asli dan sebaliknya
struct tabungan
{
	int uangAsli;
	int uangBank;
};

int main()
{
	fstream uang;
	uang.open("data.bin", ios::binary | ios::in | ios::out);

	tabungan tabunganFarrel;
	if (!uang.is_open())
	{
		uang.close();
		uang.open("data.bin", ios::binary | ios::in | ios::out | ios::trunc);
	}

	int pilihan = 1;

	cout << "===================UANG MILIK ANDA================" << endl;
	cout << "1. Mengubah 	Uang Asli" << endl;
	cout << "2. Mengubah 	Uang Bank" << endl;
	cout << "3. Menambah 	Uang Asli" << endl;
	cout << "4. Menambah 	Uang Bank" << endl;
	cout << "5. Mengambil 	Uang Asli" << endl;
	cout << "6. Mengambil 	Uang Bank" << endl;
	cout << "7. Menukar 	Uang dari Uang Bank ke Uang Asli" << endl;
	cout << "8. Menukar 	Uang dari Uang Asli ke Uang Bank" << endl;
	cout << "==================================================" << endl;

	tabungan hasilKeluaran;
	uang.read(reinterpret_cast<char*>(&hasilKeluaran), sizeof(tabungan));
	cout << "UANG TOTAL	: " << hasilKeluaran.uangAsli + hasilKeluaran.uangBank << endl;
	cout << "UANG ASLI 	: " << hasilKeluaran.uangAsli << endl;
	cout << "UANG BANK 	: " << hasilKeluaran.uangBank << endl;
	
	uang.close();

	cout << "==================================================" << endl;
	cout << "Masukkan Pilihan : ";
	cin >> pilihan;


	if (pilihan == 1)//Mengubah 	Uang Asli
	{
		uang.open("data.bin", ios::binary | ios::in | ios::out);
		cout << "Masukkan Uang Asli : ";
		cin >> tabunganFarrel.uangAsli;
		tabunganFarrel.uangBank = hasilKeluaran.uangBank;
		uang.write(reinterpret_cast<char*>(&tabunganFarrel), sizeof(tabungan));
	}
	else if (pilihan == 2)//Mengubah 	Uang Bank
	{
		uang.open("data.bin", ios::binary | ios::in | ios::out);
		cout << "Masukkan Uang Bank : ";
		cin >> tabunganFarrel.uangBank;
		tabunganFarrel.uangAsli = hasilKeluaran.uangAsli;
		uang.write(reinterpret_cast<char*>(&tabunganFarrel), sizeof(tabungan));
	}
	else if (pilihan == 3)//Menambah 	Uang Asli
	{
		int temp;
		uang.open("data.bin", ios::binary | ios::in | ios::out);
		cout << "Masukkan Uang Asli yang ditambah : ";
		cin >> temp;
		tabunganFarrel.uangAsli = hasilKeluaran.uangAsli;
		tabunganFarrel.uangAsli = tabunganFarrel.uangAsli + temp;
		tabunganFarrel.uangBank = hasilKeluaran.uangBank;
		uang.write(reinterpret_cast<char*>(&tabunganFarrel), sizeof(tabungan));
	}
	else if (pilihan == 4)//Menambah 	Uang Bank
	{
		int temp;
		uang.open("data.bin", ios::binary | ios::in | ios::out);
		cout << "Masukkan Uang Bank yang ditambah : ";
		cin >> temp;
		tabunganFarrel.uangBank = hasilKeluaran.uangBank;
		tabunganFarrel.uangBank = tabunganFarrel.uangBank + temp;
		tabunganFarrel.uangAsli = hasilKeluaran.uangAsli;
		uang.write(reinterpret_cast<char*>(&tabunganFarrel), sizeof(tabungan));
	}
	else if (pilihan == 5)//Mengambil 	Uang Asli
	{
		int temp;
		uang.open("data.bin", ios::binary | ios::in | ios::out);
		cout << "Masukkan Uang Asli yang diambil : ";
		cin >> temp;
		tabunganFarrel.uangAsli = hasilKeluaran.uangAsli;
		tabunganFarrel.uangAsli = tabunganFarrel.uangAsli - temp;
		tabunganFarrel.uangBank = hasilKeluaran.uangBank;
		uang.write(reinterpret_cast<char*>(&tabunganFarrel), sizeof(tabungan));
	}
	else if (pilihan == 6)//Mengambil 	Uang Bank
	{
		int temp;
		uang.open("data.bin", ios::binary | ios::in | ios::out);
		cout << "Masukkan Uang Bank yang diambil : ";
		cin >> temp;
		tabunganFarrel.uangBank = hasilKeluaran.uangBank;
		tabunganFarrel.uangBank = tabunganFarrel.uangBank - temp;
		tabunganFarrel.uangAsli = hasilKeluaran.uangAsli;
		uang.write(reinterpret_cast<char*>(&tabunganFarrel), sizeof(tabungan));
	}
	else if (pilihan == 7)//Menukar 	Uang dari Uang Bank ke Uang Asli
	{
		int temp;
		uang.open("data.bin", ios::binary | ios::in | ios::out);
		cout << "Masukkan uang Bank yang diambil dari Bank : ";
		cin >> temp;
		tabunganFarrel.uangBank = hasilKeluaran.uangBank - temp;
		tabunganFarrel.uangAsli = hasilKeluaran.uangAsli + temp;
		uang.write(reinterpret_cast<char*>(&tabunganFarrel), sizeof(tabungan));
	}
	else if (pilihan == 8)//Menukar 	Uang dari Uang Asli ke Uang Bank
	{
		int temp;
		uang.open("data.bin", ios::binary | ios::in | ios::out);
		cout << "Masukkan uang Asli yang ditaro di Bank : ";
		cin >> temp;
		tabunganFarrel.uangAsli = hasilKeluaran.uangAsli - temp;
		tabunganFarrel.uangBank = hasilKeluaran.uangBank + temp;
		uang.write(reinterpret_cast<char*>(&tabunganFarrel), sizeof(tabungan));
	}

	uang.close();
	return 0;
}
