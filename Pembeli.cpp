#include<iostream>

using namespace std;


void menuPembeli()
{
	int menu;
	while(menu != 5)
	{
		system("CLS");
		cout<<"============ TOKO SEPATU ============="<<endl;
		cout<<"|(1). Beli Sepatu                    |"<<endl;
		cout<<"|(2). Menampilkan Data Sepatu        |"<<endl;
		cout<<"|(3). Urutkan Sepatu                 |"<<endl;
		cout<<"|(4). Cari Sepatu                    |"<<endl;
		cout<<"|(5). Keluar                         |"<<endl;
		cout<<"======================================"<<endl;
		cout<<"Silahkan Pilih Menu Yang ingin Di Pilih? : ";cin>>menu;
		switch(menu)
		{
			case 1:
				menuPembeli();
				break;
			case 2:
				tampil(head);
				tekanLanjut();
				menuPembeli();
				break;
			case 3:
				system("CLS");
				sortData(head);
				menuPembeli();
				break;
			case 4:
				searchData(head);
				menuPembeli();
				break;
			case 5:
				continue;
			default:
				cout<<"INVALID INPUT"<<endl;
		}
	}
}
