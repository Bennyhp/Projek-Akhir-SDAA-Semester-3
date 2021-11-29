#include<iostream>
#include<iomanip>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string>

using namespace std;


struct Sepatu
{
	int kode_sep;
	string nama_sep;
	string merk_sep;
	int ukuran_sep;
	string warna_sep;
	int jumlah_sep;
	int harga_sep;
};

struct Node
{
	Sepatu spt;
	struct Node* next;
	struct Node* prev;
};

Node *head = NULL, *tail = NULL, *del;

void tekanLanjut()
{
	cout<<"\n<<<< Tekan ENTER Untuk Melanjutkan >>>>";
	getch();
}


// CRUD

void tambahData(Node **head, Node **tail)
{
	Node *sptBaru = new Node();
	Node *temp = *head;
	int pilih;
	
	system("CLS");
	cout
	<<"======================\n"
	<<"|  MENU TAMBAH DATA  |\n"
	<<"|--------------------|\n"
	<<"| (1). Tambah Awal   |\n"
	<<"| (2). Tambah Akhir  |\n"
	<<"======================\n"
	<<"Masukkan Pilihan : ";cin >> pilih;
	switch(pilih)
	{
		case 1:
			cout<<"Kode Barang : ";cin >> sptBaru->spt.kode_sep;
			cin.ignore();
			cout<<"Nama Sepatu : ";cin >> sptBaru->spt.nama_sep;
			cout<<"Merk Sepatu : ";cin >> sptBaru->spt.merk_sep;
			cout<<"Ukuran Sepatu : ";cin >> sptBaru->spt.ukuran_sep;
			cout<<"Warna Sepatu : ";cin >> sptBaru->spt.warna_sep;
			cout<<"Jumlah Sepatu : ";cin >> sptBaru->spt.jumlah_sep;
			cout<<"Harga Sepatu : ";cin >> sptBaru->spt.harga_sep;
			sptBaru->next = *head;
			if(*head == NULL) 
			{
				*head = sptBaru;
				*tail = sptBaru;
			}
			else
			{
				sptBaru->prev = NULL;
				sptBaru->next = *head;
				(*head)->prev = sptBaru;
				(*head) = sptBaru;
			}
			tekanLanjut();
			break;
		case 2:
			cout<<"Kode Barang : ";cin >> sptBaru->spt.kode_sep;
			cin.ignore();
			cout<<"Nama Sepatu : ";cin >> sptBaru->spt.nama_sep;
			cout<<"Merk Sepatu : ";cin >> sptBaru->spt.merk_sep;
			cout<<"Ukuran Sepatu : ";cin >> sptBaru->spt.ukuran_sep;
			cout<<"Warna Sepatu : ";cin >> sptBaru->spt.warna_sep;
			cout<<"Jumlah Sepatu : ";cin >> sptBaru->spt.jumlah_sep;
			cout<<"Harga Sepatu : ";cin >> sptBaru->spt.harga_sep;
			sptBaru->next = NULL;
			if(*head == NULL) 
			{
				*head = sptBaru;
				*tail = sptBaru;
				return;
			}
			else
			{
				sptBaru->prev = *tail;
				sptBaru->next = NULL;
				(*tail)->next = sptBaru;
				*tail = sptBaru;
			}
			tekanLanjut();
			break;
		default:
			cout<<"INVALID INPUT"<<endl;
			return;
	}	
}

void tampil(Node *head)
{
	system("CLS");
	int width = 17;
	cout << "========================================================================================================================" << endl;
	cout 
	<<setw(width)<<left<< "Kode" 
	<<setw(width)<<left<< "Nama"
	<<setw(width)<<left<< "Merk" 
	<<setw(width)<<left<< "Ukuran" 
	<<setw(width)<<left<< "Warna" 
	<<setw(width)<<left<< "Jumlah" 
	<<setw(width)<<left<< "Harga"<< endl;
	cout << "========================================================================================================================" << endl;
	if(head != NULL)
	{
		while(head != NULL)
		{
			cout 
			<<setw(width)<<left<<head->spt.kode_sep
			<<setw(width)<<left<<head->spt.nama_sep
			<<setw(width)<<left<<head->spt.merk_sep
			<<setw(width)<<left<<head->spt.ukuran_sep
			<<setw(width)<<left<<head->spt.warna_sep
			<<setw(width)<<left<<head->spt.jumlah_sep
			<<setw(width)<<left<<head->spt.harga_sep<<endl;
			head = head->next;
		}
	}
	else
	{
		cout<<"Data Kosong"<<endl;
	}
	cout << "========================================================================================================================" << endl;
}

void hapusData(Node **head, Node **tail)
{
	system("CLS");
	int pilih;
	int cariKode;
	if(*head == NULL)
	{
		cout<<"!!!! Data Masih Kosong !!!!"<<endl;
		tekanLanjut();
		return;
	}
	
	Node *dataOld = *head;
	Node *dataNew = *head;
	
	cout
	<<"===========================\n"
	<<"|     MENU HAPUS DATA     |\n"
	<<"|-------------------------|\n"
	<<"| (1). Hapus Awal         |\n"
	<<"| (2). Hapus Akhir        |\n"
	<<"| (3). Hapus Sesuai Kode  |\n"
	<<"===========================\n"
	<<"Masukkan Pilihan : ";cin >> pilih;
	switch(pilih)
	{
		case 1:
			if((*head)->next == NULL)
			{
				*head = NULL;
				*tail = NULL;
				return;
			}
			del = *head;
			*head = dataOld->next;
			(*head)->prev = NULL;
			delete del;
			tekanLanjut();
			break;
		case 2:
			if((*head)->next == NULL)
			{
				*head = NULL;
				*tail = NULL;
				return;
			}
			del = *tail;
			*tail = (*tail)->prev;
			(*tail)->next = NULL;
			delete del;
			tekanLanjut();
			break;
		case 3:
			cout<<"Masukkan Kode Sepatu Yang Ingin Dihapus : ";cin >> cariKode;
			cin.ignore();
			if((*head)->spt.kode_sep == cariKode)
			{
				if((*head)->next == NULL)
				{
					*head = NULL;
					*tail = NULL;
					return;
				}
				del = *head;
				*head = dataOld->next;
				(*head)->prev = NULL;
				delete del;
				tekanLanjut();
			}
			else if((*tail)->spt.kode_sep == cariKode)
			{
				if((*head)->next == NULL)
				{
					*head = NULL;
					*tail = NULL;
					return;
				}
				del = *tail;
				*tail = (*tail)->prev;
				(*tail)->next = NULL;
				delete del;
				tekanLanjut();
			}
			else
			{
				while(dataNew != NULL)
				{
					if(dataNew->spt.kode_sep == cariKode)
					{
						(dataNew->prev)->next = dataNew->next;
						(dataNew->next)->prev = dataNew->prev;
						return;
					}
					dataNew = dataNew->next;
				}
				cout<<"!!!! Data Tidak Ada !!!!"<<endl;
				tekanLanjut();
				return;	
			}
			break;
		default:
			cout<<"INVALID INPUT"<<endl;
			tekanLanjut();
			return;
	}
}

void editData(Node *head)
{
	int cariKode;
	Node *temp = head;

	
	if(head == NULL)
	{
		system("CLS");
		cout<<"!!!! Data Masih Kosong !!!!"<<endl;
		tekanLanjut();
		return;
	}
	cout
	<<"\n\n=============================================\n"
	<<"|              MENU EDIT DATA               |\n"
	<<"---------------------------------------------\n"
	<<"Masukkan Kode Sepatu Yang Ingin Diupdate : ";cin>>cariKode;
	while(temp != NULL)
	{
		if(temp->spt.kode_sep == cariKode)
		{
			cout<<"Kode Sepatu : "<<cariKode<<endl;
			cout <<"\nvvvvvvv Masukkan Data Baru vvvvvvv"<<endl;
			cout<<"Nama Baru   : ";cin >> temp->spt.nama_sep;
			cout<<"Merk Baru   : ";cin >> temp->spt.merk_sep;
			cout<<"Ukuran Baru : ";cin >> temp->spt.ukuran_sep;
			cout<<"Warna Baru  : ";cin >> temp->spt.warna_sep;
			cout<<"Jumlah Baru : ";cin >> temp->spt.jumlah_sep;
			cout<<"Harga Baru  : ";cin >> temp->spt.harga_sep;
			tekanLanjut();
			return;
		}
		else
		{
			system("CLS");
			cout<<"!!!! Kode Tidak Ada !!!!"<<endl;
			tekanLanjut();
		}
		temp = temp->next;
	}
}


// SORT AND SEARCH

// =================== Fungsi Sort ===================
void shellSort(Sepatu *spta, int a, int kategori, int asdc)
{
	for(int gap = a / 2; gap >0; gap /=2)
	{
		for(int i = gap; i<a; i += 1)
		{
			Sepatu temp = spta[i];
			int j;
			// Sorting Kode Barang 
			if(kategori == 1 and asdc == 1)
			{
				for(j = i; j >= gap && spta[j-gap].kode_sep > temp.kode_sep; j -= gap)
					spta[j] = spta[j - gap];
			}
			else if(kategori == 1 and asdc == 2)
			{
				for(j = i; j >= gap && spta[j-gap].kode_sep < temp.kode_sep; j -= gap)
					spta[j] = spta[j - gap];							
			}
			// Sorting Nama Barang
			else if(kategori == 2 and asdc == 1)
			{
				for(j = i; j >= gap && spta[j-gap].nama_sep > temp.nama_sep; j -= gap)
					spta[j] = spta[j - gap];
			}
			else if(kategori == 2 and asdc == 2)
			{
				for(j = i; j >= gap && spta[j-gap].nama_sep < temp.nama_sep; j -= gap)
					spta[j] = spta[j - gap];
			}
			spta[j] = temp;
		}		
	}
}

// =================== Jalankan Sorting ===================
void sortData(Node *head)
{
	Node *temp = head;
	Sepatu spta[100];
	if(head == NULL)
	{
		system("CLS");
		cout<<"!!!! Data Masih Kosong !!!!"<<endl;
		tekanLanjut();
		return;
	}
	int i;
	while(head != NULL)
	{
		spta[i].kode_sep = head->spt.kode_sep;
		spta[i].nama_sep = head->spt.nama_sep;
		spta[i].merk_sep = head->spt.merk_sep;
		spta[i].ukuran_sep = head->spt.ukuran_sep;
		spta[i].warna_sep = head->spt.warna_sep;
		spta[i].jumlah_sep = head->spt.jumlah_sep;
		spta[i].harga_sep = head->spt.harga_sep;
		head = head->next;
		i++;
	}
	int pilih_kategori;
	system("CLS");
	cout
	<<"===========================\n"
	<<"|     MENU SORT DATA      |\n"
	<<"|-------------------------|\n"
	<<"| (1). Kode Sepatu        |\n"
	<<"| (2). Nama Sepatu        |\n"
	<<"===========================\n"
	<<"Sort Data Berdasarkan : ";cin>>pilih_kategori;
	
	int pilih_urutan;
	system("CLS");
	cout
	<<"===========================\n"
	<<"|     MENU SORT DATA      |\n"
	<<"|-------------------------|\n"
	<<"| (1). Ascending          |\n"
	<<"| (2). Descending         |\n"
	<<"===========================\n"
	<<"Sort Secara : ";cin>>pilih_urutan;
	
	shellSort(&spta[0], i, pilih_kategori, pilih_urutan);
	i = 0;
	while(temp != NULL)
	{
		temp->spt.kode_sep = spta[i].kode_sep;
		temp->spt.nama_sep = spta[i].nama_sep;
		temp->spt.merk_sep = spta[i].merk_sep;
		temp->spt.ukuran_sep = spta[i].ukuran_sep;
		temp->spt.warna_sep = spta[i].warna_sep;
		temp->spt.jumlah_sep = spta[i].jumlah_sep;
		temp->spt.harga_sep = spta[i].harga_sep;
		temp = temp->next;
		i++;
	}
	tekanLanjut();
}

// =================== Fungsi Search ===================
int jumpSearch(Sepatu *spta, int x, int n)
{
	int step = sqrt(n);

	int prev = 0;
	while(spta[min(step, n)-1].kode_sep < x){
		prev = step;
		step += sqrt(n);
		if(prev >= n)
			return -1;
	}

	while (spta[prev].kode_sep < x){
		prev++;

		if(prev == min(step, n))
			return -1;
	}

	if(spta[prev].kode_sep == x)
		return prev;

	return -1;
}

// =================== Jalankan Search ===================
void searchData(Node *head)
{
	int i;
	int kode;
	Node *temp = head;
	Sepatu spta[100];
	while(head != NULL)
	{
		spta[i].kode_sep = head->spt.kode_sep;
		spta[i].nama_sep = head->spt.nama_sep;
		spta[i].merk_sep = head->spt.merk_sep;
		spta[i].ukuran_sep = head->spt.ukuran_sep;
		spta[i].warna_sep = head->spt.warna_sep;
		spta[i].jumlah_sep = head->spt.jumlah_sep;
		spta[i].harga_sep = head->spt.harga_sep;
		head = head->next;
		i++;
	}
	shellSort(&spta[0], i, 1, 1);
	i = 0;
	while(temp != NULL)
	{
		temp->spt.kode_sep = spta[i].kode_sep;
		temp->spt.nama_sep = spta[i].nama_sep;
		temp->spt.merk_sep = spta[i].merk_sep;
		temp->spt.ukuran_sep = spta[i].ukuran_sep;
		temp->spt.warna_sep = spta[i].warna_sep;
		temp->spt.jumlah_sep = spta[i].jumlah_sep;
		temp->spt.harga_sep = spta[i].harga_sep;
		temp = temp->next;
		i++;
	}
	system("CLS");
	cout
	<<"=============================\n"
	<<"|     MENU SEARCH DATA      |\n"
	<<"-----------------------------\n"
	<<"Masukkan Kode : ";cin>>kode;
	int index = jumpSearch(&spta[0], kode, i);
	if(index != -1)
	{
		cout<<"<<<<<< DATA DITEMUKAN >>>>>>"<<endl;
		cout<<"Kode Sepatu   : "<<kode<<endl;
		cout<<"Nama Sepatu   : "<<spta[index].nama_sep<<endl;
		cout<<"Merk Sepatu   : "<<spta[index].merk_sep<<endl;
		cout<<"Ukuran Sepatu : "<<spta[index].ukuran_sep<<endl;
		cout<<"Warna Sepatu  : "<<spta[index].warna_sep<<endl;
		cout<<"Jumlah Sepatu : "<<spta[index].jumlah_sep<<endl;
		cout<<"Harga Sepatu  : "<<spta[index].harga_sep<<endl;
		tekanLanjut();
	}
	else
	{
		cout<<"!!!! Data Tidak Ditemukan !!!!"<<endl;
		tekanLanjut();
	}
}


// MENU

// =================== Admin ===================
void menuAdmin()
{
	int menu;
	while(menu != 9)
	{
		system("CLS");
		cout<<"======= MENU ADMIN TOKO SEPATU ======="<<endl;
		cout<<"|(1). Menambah Data Barang           |"<<endl;
		cout<<"|(2). Menampilkan Data Barang        |"<<endl;
		cout<<"|(3). Mengupdate Data Barang         |"<<endl;
		cout<<"|(4). Menghapus Data Barang          |"<<endl;
		cout<<"|(5). Sorting Data Barang            |"<<endl;
		cout<<"|(6). Searching Data Barang          |"<<endl;
		cout<<"|(9). Keluar                         |"<<endl;
		cout<<"======================================"<<endl;
		cout<<"Silahkan Pilih Menu Yang ingin Di Pilih? : ";cin>>menu;
		switch(menu)
		{
			case 1:
				tambahData(&head, &tail);
				break;
			case 2:
				tampil(head);
				tekanLanjut();
				break;
			case 3:
				system("CLS");
				tampil(head);
				editData(head);
				break;
			case 4:
				hapusData(&head, &tail);
				break;
			case 5:
				system("CLS");
				sortData(head);
				break;
			case 6:
				searchData(head);
				break;
			case 9:
				continue;
			default:
				cout<<"INVALID INPUT"<<endl;
		}
	}
}
