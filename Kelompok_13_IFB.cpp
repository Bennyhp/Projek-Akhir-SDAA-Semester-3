#include<iostream>
#include<stdio.h>
#include"Structs.h"
#include"Admin.cpp"
#include"Pembeli.cpp"
#include"LoadSaveCSV.cpp"

using namespace std;


int pilihan;


int main()
{
	loadCSV(&head, &tail);
	loadQueue(&ant_head, &ant_tail);
	int checkQueue = checkingQueue();
	int checkCSV = checkingCSV();
	freestyle2(&ant_head, &ant_tail, checkQueue);
	freestyle(&head, &tail, checkCSV);

	while(pilihan != 9)
	{
		system("CLS");
		cout<<"==================================="<<endl;
		cout<<"|  Selamat Datang Di Toko Sepatu  |"<<endl;
		cout<<"|---------------------------------|"<<endl;
		cout<<"| (1). Masuk Sebagai Admin        |"<<endl;
		cout<<"| (2). Masuk Sebagai Pembeli      |"<<endl;
		cout<<"| (9). Keluar                     |"<<endl;
		cout<<"==================================="<<endl;
		cout<<"Masukan Pilihan Anda : ";cin>>pilihan;
		cin.ignore();
		switch(pilihan)
		{
			case 1:
				LogAdmin();
				break;
			case 2:
				menuPembeli();
				break;
			case 9:
				continue;
			default :
				cout<<"Pilihan tidak ada"<<endl;
				tekanLanjut();
		}
	}
}
