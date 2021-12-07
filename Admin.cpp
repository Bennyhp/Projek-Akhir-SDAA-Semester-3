#include<iostream>
#include<iomanip>
#include<conio.h>
#include<math.h>
#include"Structs.h"
#include"LoadSaveCSV.h"



using namespace std;

Sepatu *head = NULL, *tail = NULL, *del;
Antrian *ant_head = NULL, *ant_tail = NULL, *del1;

void tekanLanjut()
{
	cout<<"\n<<<< Tekan ENTER Untuk Melanjutkan >>>>";
	getch();
	fflush(stdin);
}


void freestyle(Sepatu **head, Sepatu **tail, int check)
{
	if(check == 0)
	{
		while(head != NULL)
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
		}
	}
	else
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
	}
}

void freestyle2(Antrian **ant_head, Antrian **ant_tail, int check)
{
	if(check == 0)
	{
		while(ant_head != NULL)
		{
			if((*ant_head)->next == NULL)
			{
				*ant_head = NULL;
				*ant_tail = NULL;
				return;
			}
			del1 = *ant_tail;
			*ant_tail = (*ant_tail)->prev;
			(*ant_tail)->next = NULL;
			delete del1;	
		}
	}
	else if(check == 2)
	{
		if((*ant_head)->next == NULL)
			{
				*ant_head = NULL;
				*ant_tail = NULL;
				return;
			}
			del1 = *ant_tail;
			*ant_tail = (*ant_tail)->prev;
			(*ant_tail)->next = NULL;
			delete del1;
	}
}

// Queue

void tampilAntrian(Antrian *ant_head)
{
	system("CLS");
	int width = 17;
	cout << "__________________ DAFTAR ANTRIAN ____________________\n" << endl;
	cout << "======================================================\n" << endl;
	cout 
	<<setw(width)<<left<< "No Antrian" 
	<<setw(width)<<left<< "Kode Sepatu"
	<<setw(width)<<left<< "Jumlah Beli"<< endl;
	cout << "------------------------------------------------------\n" << endl;
	Antrian *temp2 = ant_head;
	if(temp2 != NULL)
	{
		while(temp2 != NULL)
		{
			
			cout 
			<<setw(width)<<left<<temp2->no_antri
			<<setw(width)<<left<<temp2->kode_sepatu
			<<setw(width)<<left<<temp2->jumlah_sepatu<<endl;
			temp2 = temp2->next;
		}
	}
	else
	{
		cout<<"Data Kosong"<<endl;
	}
	cout << "======================================================\n" << endl;
}


void takeQueue(Antrian **ant_head, Antrian **ant_tail, Sepatu *head)
{
	int i;
	int width = 17;
	Antrian *temp = *ant_head;
	Antrian *dataOld = *ant_head;
	if(*ant_head == NULL)
	{
		cout<<"Tidak Ada Antrian"<<endl;
		return;
	}
	Sepatu *temp2 = head;
	while(temp2->kode_sep != temp->kode_sepatu)
	{
		temp2 = temp2->next;
	}
	system("CLS");
	cout << "___________________________________ AMBIL ANTRIAN ___________________________________\n" << endl;
	cout << "=====================================================================================\n" << endl;
	cout 
	<<setw(width)<<left<< "No Antrian" 
	<<setw(width)<<left<< "Kode Sepatu"
	<<setw(width)<<left<< "Nama Sepatu"
	<<setw(width)<<left<< "Jumlah Beli"
	<<setw(width)<<left<< "Harga Per Pasang"<< endl;
	cout << "-------------------------------------------------------------------------------------\n" << endl;
	cout
	<<setw(width)<<left<<temp->no_antri
	<<setw(width)<<left<<temp->kode_sepatu
	<<setw(width)<<left<<temp2->nama_sep
	<<setw(width)<<left<<temp->jumlah_sepatu
	<<setw(width)<<left<<temp2->harga_sep<<endl;
	cout << "=====================================================================================\n" << endl;
	int total;
	int uang;
	int sisa;
	total = temp2->harga_sep * temp->jumlah_sepatu;
	cout << "Total harga yang perlu dibayar : Rp."<< total << endl;
	cout << "Masukkan Uang Yang Diberikan : Rp.";cin >> uang;
	sisa = uang - total;
	while(true)
	{
		if(sisa == 0)
		{
			cout << "Uang Pas";
			if((*ant_head)->next == NULL)
			{
				*ant_head = NULL;
				*ant_tail = NULL;
				return;
			}
			del1 = *ant_head;
			*ant_head = dataOld->next;
			(*ant_head)->prev = NULL;
			delete del1;
			saveQueue(ant_head);
			return;
		}
		else if(uang < total)
		{
			cout << "Uang Yang Diberikan Kurang Silahkan Masukkan Uang Lagi"<<endl;
			return;
		}
		else if(sisa != 0)
		{
			cout << "Kembalian : "<< sisa;
			if((*ant_head)->next == NULL)
			{
				*ant_head = NULL;
				*ant_tail = NULL;
				return;
			}
			del1 = *ant_head;
			*ant_head = dataOld->next;
			(*ant_head)->prev = NULL;
			delete del1;
			saveQueue(ant_head);
			return;
		}
	}
}


// CRUD

void tambahData(Sepatu **head, Sepatu **tail)
{
	Sepatu *sptBaru = new Sepatu();
	Sepatu *temp = *head;
	int pilihTambahData;
	
	system("CLS");
	cout
	<<"======================\n"
	<<"|  MENU TAMBAH DATA  |\n"
	<<"|--------------------|\n"
	<<"| (1). Tambah Awal   |\n"
	<<"| (2). Tambah Akhir  |\n"
	<<"======================\n"
	<<"Masukkan Pilihan : ";cin >> pilihTambahData;
	switch(pilihTambahData)
	{
		case 1:
			cout<<"Kode Barang : ";cin >> sptBaru->kode_sep;
			fflush(stdin);
			cout<<"Nama Sepatu : ";getline(std::cin >> std::ws, sptBaru->nama_sep);
			cout<<"Merk Sepatu : ";getline(std::cin >> std::ws, sptBaru->merk_sep);
			cout<<"Ukuran Sepatu : ";cin >> sptBaru->ukuran_sep;
			fflush(stdin);
			cout<<"Warna Sepatu : ";getline(std::cin >> std::ws, sptBaru->warna_sep);
			cout<<"Jumlah Sepatu : ";cin >> sptBaru->jumlah_sep;
			fflush(stdin);
			cout<<"Harga Sepatu : ";cin >> sptBaru->harga_sep;
			fflush(stdin);	
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
			cout<<"Kode Barang : ";cin >> sptBaru->kode_sep;
			fflush(stdin);
			cout<<"Nama Sepatu : ";getline(std::cin >> std::ws, sptBaru->nama_sep);
			cout<<"Merk Sepatu : ";getline(std::cin >> std::ws, sptBaru->merk_sep);
			cout<<"Ukuran Sepatu : ";cin >> sptBaru->ukuran_sep;
			fflush(stdin);
			cout<<"Warna Sepatu : ";getline(std::cin >> std::ws, sptBaru->warna_sep);
			cout<<"Jumlah Sepatu : ";cin >> sptBaru->jumlah_sep;
			fflush(stdin);
			cout<<"Harga Sepatu : ";cin >> sptBaru->harga_sep;
			fflush(stdin);
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
										
void tampil(Sepatu *head)
{
	system("CLS");
	int width = 17;
	cout << "_____________________________________________ INVENTORI TOKO SEPATU _____________________________________________\n" << endl;
	cout << "=================================================================================================================\n" << endl;
	cout 
	<<setw(width)<<left<< "Kode" 
	<<setw(width)<<left<< "Nama"
	<<setw(width)<<left<< "Merk" 
	<<setw(width)<<left<< "Ukuran" 
	<<setw(width)<<left<< "Warna" 
	<<setw(width)<<left<< "Jumlah" 
	<<setw(width)<<left<< "Harga"<< endl;
	cout << "=================================================================================================================\n" << endl;
	Sepatu *temp = head;
	if(temp != NULL)
	{
		while(temp != NULL)
		{
			cout 
			<<setw(width)<<left<<temp->kode_sep
			<<setw(width)<<left<<temp->nama_sep
			<<setw(width)<<left<<temp->merk_sep
			<<setw(width)<<left<<temp->ukuran_sep
			<<setw(width)<<left<<temp->warna_sep
			<<setw(width)<<left<<temp->jumlah_sep
			<<setw(width)<<left<<temp->harga_sep<<endl;
			temp = temp->next;
		}
	}
	else
	{
		cout<<"Data Kosong"<<endl;
	}
	cout << "=================================================================================================================\n" << endl;
}

void hapusData(Sepatu **head, Sepatu **tail)
{
	system("CLS");
	int pilihHapusData;
	int cariKode;
	if(*head == NULL)
	{
		cout<<"!!!! Data Masih Kosong !!!!"<<endl;
		tekanLanjut();
		return;
	}
	
	Sepatu *dataOld = *head;
	Sepatu *dataNew = *head;
	
	cout
	<<"===========================\n"
	<<"|     MENU HAPUS DATA     |\n"
	<<"|-------------------------|\n"
	<<"| (1). Hapus Awal         |\n"
	<<"| (2). Hapus Akhir        |\n"
	<<"| (3). Hapus Sesuai Kode  |\n"
	<<"===========================\n"
	<<"Masukkan Pilihan : ";cin >> pilihHapusData;
	switch(pilihHapusData)
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
			fflush(stdin);
			if((*head)->kode_sep == cariKode)
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
			else if((*tail)->kode_sep == cariKode)
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
					if(dataNew->kode_sep == cariKode)
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

void editData(Sepatu *head)
{
	int cariKode;
	Sepatu *temp = head;

	
	if(head == NULL)
	{
		system("CLS");
		cout<<"!!!! Data Masih Kosong !!!!"<<endl;
		tekanLanjut();
		return;
	}
	cout
	<<"=============================================\n"
	<<"|              MENU EDIT DATA               |\n"
	<<"---------------------------------------------\n"
	<<"Masukkan Kode Sepatu Yang Ingin Diupdate : ";cin>>cariKode;
	cin.ignore();
	while(temp->kode_sep != cariKode)
	{
		temp = temp->next;
	}
	if(temp->kode_sep == cariKode)
	{
		cout<<"Kode Sepatu : "<<cariKode<<endl;
		fflush(stdin);
		cout <<"\nvvvvvvv Masukkan Data Baru vvvvvvv"<<endl;
		cout<<"Nama Baru   : ";getline(std::cin >> std::ws, temp->nama_sep);
		cout<<"Merk Baru   : ";getline(std::cin >> std::ws, temp->merk_sep);
		cout<<"Ukuran Baru : ";cin >> temp->ukuran_sep;
		fflush(stdin);
		cout<<"Warna Baru  : ";getline(std::cin >> std::ws, temp->warna_sep);
		cout<<"Jumlah Baru : ";cin >> temp->jumlah_sep;
		fflush(stdin);
		cout<<"Harga Baru  : ";cin >> temp->harga_sep;
		fflush(stdin);
		tekanLanjut();
		return;
	}
	else
	{
		system("CLS");
		cout<<"!!!! Kode Tidak Ada !!!!"<<endl;
		tekanLanjut();
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
void sortData(Sepatu *head)
{
	Sepatu *temp = head;
	Sepatu spta[100];
	if(head == NULL)
	{
		system("CLS");
		cout<<"!!!! Data Masih Kosong !!!!"<<endl;
		tekanLanjut();
		return;
	}
	int i;
	// ubah jadi array
	while(head != NULL)
	{
		spta[i].kode_sep = head->kode_sep;
		spta[i].nama_sep = head->nama_sep;
		spta[i].merk_sep = head->merk_sep;
		spta[i].ukuran_sep = head->ukuran_sep;
		spta[i].warna_sep = head->warna_sep;
		spta[i].jumlah_sep = head->jumlah_sep;
		spta[i].harga_sep = head->harga_sep;
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
	// Masukkan ke struct dari array
	while(temp != NULL)
	{
		temp->kode_sep = spta[i].kode_sep;
		temp->nama_sep = spta[i].nama_sep;
		temp->merk_sep = spta[i].merk_sep;
		temp->ukuran_sep = spta[i].ukuran_sep;
		temp->warna_sep = spta[i].warna_sep;
		temp->jumlah_sep = spta[i].jumlah_sep;
		temp->harga_sep = spta[i].harga_sep;
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
void searchData(Sepatu *head)
{
	int i;
	int kode;
	Sepatu *temp = head;
	Sepatu spta[100];
	// Ubah jadi array
	while(head != NULL)
	{
		spta[i].kode_sep = head->kode_sep;
		spta[i].nama_sep = head->nama_sep;
		spta[i].merk_sep = head->merk_sep;
		spta[i].ukuran_sep = head->ukuran_sep;
		spta[i].warna_sep = head->warna_sep;
		spta[i].jumlah_sep = head->jumlah_sep;
		spta[i].harga_sep = head->harga_sep;
		head = head->next;
		i++;
	}
	shellSort(&spta[0], i, 1, 1);
	i = 0;
	// Masukkan ke struct dari array
	while(temp != NULL)
	{
		temp->kode_sep = spta[i].kode_sep;
		temp->nama_sep = spta[i].nama_sep;
		temp->merk_sep = spta[i].merk_sep;
		temp->ukuran_sep = spta[i].ukuran_sep;
		temp->warna_sep = spta[i].warna_sep;
		temp->jumlah_sep = spta[i].jumlah_sep;
		temp->harga_sep = spta[i].harga_sep;
		temp = temp->next;
		i++;
	}
	system("CLS");
	cout
	<<"=============================\n"
	<<"|     MENU SEARCH DATA      |\n"
	<<"-----------------------------\n"
	<<"Masukkan Kode : ";cin>>kode;
	fflush(stdin);
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
		tampilAntrian(ant_head);
		cout<<"======= MENU ADMIN TOKO SEPATU ======="<<endl;
		cout<<"|(1). Menambah Data Barang           |"<<endl;
		cout<<"|(2). Menampilkan Data Barang        |"<<endl;
		cout<<"|(3). Mengupdate Data Barang         |"<<endl;
		cout<<"|(4). Menghapus Data Barang          |"<<endl;
		cout<<"|(5). Sorting Data Barang            |"<<endl;
		cout<<"|(6). Searching Data Barang          |"<<endl;
		cout<<"|(7). Terima Antrian                 |"<<endl;
		cout<<"|(8). Save Data                      |"<<endl;
		cout<<"|(9). Keluar                         |"<<endl;
		cout<<"======================================"<<endl;
		cout<<"Silahkan Pilih Menu Yang ingin Di Pilih? : ";cin>>menu;
		fflush(stdin);
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
			case 7:
				takeQueue(&ant_head, &ant_tail, head);
				tekanLanjut();
				break;
			case 8:
				saveCSV(&head);
				cout<<"<<<< Berhasil Disimpan >>>>"<<endl;
				tekanLanjut();
				break;
			case 9:
				continue;
			default:
				cout<<"INVALID INPUT"<<endl;
		}
	}
}


// =================== Login Admin ===================

void LogAdmin()
{
	string login_username = "admin";
	string login_password = "admin";
	std::string username,password;
	system("cls");
	cout
	<<"\n\n=============================================\n"
	<<"|                     Login                  |\n"
	<<"---------------------------------------------\n";
	cout<<"Masukan Username : ";
	getline(std::cin >> std::ws, username);
	cout<<"Masukan Password : ";
    getline(std::cin >> std::ws, password);
	if (login_username == username && login_password == password){
		cout<<"LOGIN ANDA BERHASIL......"<<endl;
		tekanLanjut();
		menuAdmin();
	}else{
		cout<<"Password atau Username Salah "<<endl;
		tekanLanjut();
		LogAdmin();
	}
	
}
