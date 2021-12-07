#include<iostream>
#include"Structs.h"
#include"Admin.h"

using namespace std;

int sesAntri = 0;

void beliSepatu(Sepatu *p_head, Antrian **arr_head, Antrian **arr_tail, int *sesAntri)
{
	Sepatu *temp = p_head;
	int kodeB;
	int jumlahB;
	int i;
	if(p_head == NULL)
	{
		cout<<"!!!! Data Kosong !!!!"<<endl;
		tekanLanjut();
	}
	cout<<"Masukkan Kode Sepatu Yang Ingin Dibeli : ";cin >> kodeB;
	fflush(stdin);
	cout<<"Masukkan Jumlah Pasang Sepatu Yang Ingin Dibeli : ";cin >> jumlahB;
	fflush(stdin);

	while(temp->kode_sep != kodeB)
	{
		temp = temp->next;
	}
	if(temp->kode_sep == kodeB)
	{
		if(jumlahB < temp->jumlah_sep)
		{
			temp->jumlah_sep -= jumlahB;
		}
		else
		{
			cout<<"Stok Tidak Mencukupi"<<endl;
			tekanLanjut();
			return;
		}
	}
	Antrian *antri = new Antrian();
	antri->jumlah_sepatu = jumlahB;
	antri->kode_sepatu = kodeB;
	antri->no_antri = ++*sesAntri;
	Antrian *temp2 = *arr_head;
	if(*arr_head == NULL)
	{
		*arr_head = antri;
	}
	else
	{
		while(temp2->next != NULL)
		{
			temp2 = temp2->next;
		}
		temp2->next = antri;
		antri->prev = temp2;
	}
	cout<<"Pembelian Selesai"<<endl;
	cout<<"No Antrian = "<< *sesAntri <<endl;
	saveCSV(&head);
	tekanLanjut();
}


void menuPembeli()
{
	int pilihPembeli;
	while(pilihPembeli != 9)
	{
		int check;
		system("CLS");
		cout<<"============ TOKO SEPATU ============="<<endl;
		cout<<"| (1). Beli Sepatu                   |"<<endl;
		cout<<"| (2). Menampilkan Data Sepatu       |"<<endl;
		cout<<"| (3). Urutkan Sepatu                |"<<endl;
		cout<<"| (4). Cari Sepatu                   |"<<endl;
		cout<<"| (9). Keluar & Simpan               |"<<endl;
		cout<<"======================================"<<endl;
		cout<<"Silahkan Pilih Menu Yang ingin Di Pilih? : ";cin>>pilihPembeli;
		fflush(stdin);
		switch(pilihPembeli)
		{
			case 1:
				tampil(head);
				beliSepatu(head, &ant_head, &ant_tail, &sesAntri);
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
			case 9:
				saveQueue(&ant_head);
				continue;
			default:
				cout<<"INVALID INPUT"<<endl;
				tekanLanjut();
		}
	}
}
