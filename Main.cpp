#include<iostream>
#include"LogAdmin.cpp"
#include"Pembeli.cpp"


using namespace std;


int pilihan;

int main()
{
	while(pilihan != 3)
	{
		system("CLS");
		cout<<"==================================="<<endl;
		cout<<"|  Selamat Datang Di Toko Sepatu  |"<<endl;
		cout<<"|---------------------------------|"<<endl;
		cout<<"| (1). Masuk Sebagai Admin        |"<<endl;
		cout<<"| (2). Masuk Sebagai Pembeli      |"<<endl;
		cout<<"| (3). Keluar                     |"<<endl;
		cout<<"==================================="<<endl;
		cout<<"Masukan Pilihan Anda :";cin>>pilihan;
		switch(pilihan)
		{
			case 1:
				inAdmin();
				break;
			case 2:
				menuPembeli();
				break;
			case 3:
				continue;
			default :
				cout<<"Pilihan tidak ada"<<endl;
				tekanLanjut();
		}
	}
}
