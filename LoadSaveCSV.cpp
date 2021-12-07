#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include"Structs.h"

using namespace std;

void intoStructSepatu(Sepatu **head, Sepatu **tail, string kode, string nama, string merk, string ukuran, string warna, string jumlah, string harga)
{
	Sepatu *sptBaru = new Sepatu();
	Sepatu *temp = *head;
	int Ikode;
	int Iukuran;
	int Ijumlah;
	int Iharga;

	istringstream iss;
	istringstream iss2;
	istringstream iss3;
	istringstream iss4;
	iss.str(kode);
	iss >> Ikode;

	
	iss2.str(ukuran);
	iss2 >> Iukuran;

	iss3.str(jumlah);
	iss3 >> Ijumlah;

	iss4.str(harga);
	iss4 >> Iharga;
	
	
	sptBaru->kode_sep = Ikode;
	sptBaru->nama_sep = nama;
	sptBaru->merk_sep = merk;
	sptBaru->ukuran_sep = Iukuran;
	sptBaru->warna_sep = warna;
	sptBaru->jumlah_sep = Ijumlah;
	sptBaru->harga_sep = Iharga;

	if(*head == NULL)
	{
		*head = sptBaru;
		*tail = sptBaru;
	}
	else
	{
		sptBaru->prev = *tail;
		sptBaru->next = NULL;
		(*tail)->next = sptBaru;
		*tail = sptBaru;
	}
}

int checkingCSV()
{
	int masuk1 = 1;

	ifstream fileDataIn("data_sepatu.csv");
	
	if(!fileDataIn)
	{
		return 0;
	}
	bool isEmpty = fileDataIn.peek() == EOF;
	if(isEmpty == true)
	{
		masuk1 -= 1;
	}
	else
	{
		masuk1 += 1;
	}
	fileDataIn.close();
	return masuk1;
}


void loadCSV(Sepatu **head, Sepatu **tail)
{
	string nama;
	string merk;
	string warna;
	string temp;
	string Skode, Sukuran, Sjumlah, Sharga;

	ifstream fileDataIn("data_sepatu.csv");
	if(fileDataIn.is_open())
	{
       	while(!fileDataIn.eof())
		{
			getline(fileDataIn, Skode, ',');
			getline(fileDataIn, nama, ',');
			getline(fileDataIn, merk, ',');
			getline(fileDataIn, Sukuran, ',');
			getline(fileDataIn, warna, ',');
			getline(fileDataIn, Sjumlah, ',');
			getline(fileDataIn, Sharga, '\n');

			intoStructSepatu(head, tail, Skode, nama, merk, Sukuran, warna, Sjumlah, Sharga);
		}		
	}
	else
	{
		cout<<"Error Occured"<<endl;
	}
	fileDataIn.close();

}

void saveCSV(Sepatu **head)
{
	Sepatu *temp = *head;
	ofstream fileDataOut("data_sepatu.csv");
	while(temp != NULL)
	{
		fileDataOut << temp->kode_sep << "," 
					<< temp->nama_sep << "," 
					<< temp->merk_sep << "," 
					<< temp->ukuran_sep << "," 
					<< temp->warna_sep << "," 
					<< temp->jumlah_sep << "," 
					<< temp->harga_sep << "\n";
		temp = temp->next;
	}
	fileDataOut.close();
}



void intoStructQueue(Antrian **ant_head, Antrian **ant_tail, string no_antri, string kode_sep_antri, string jumlah_sep_antri)
{
	Antrian *antBaru = new Antrian();
	Antrian *temp = *ant_head;
	int Ino_antri;
	int Ijumlah_sep_antri;
	int Ikode_sep_antri;

	istringstream iss;
	istringstream iss2;
	istringstream iss3;

	iss.str(no_antri);
	iss >> Ino_antri;

	iss2.str(jumlah_sep_antri);
	iss2 >> Ijumlah_sep_antri;

	iss3.str(kode_sep_antri);
	iss3 >> Ikode_sep_antri;

	

	antBaru->no_antri = Ino_antri;
	antBaru->kode_sepatu = Ikode_sep_antri;
	antBaru->jumlah_sepatu = Ijumlah_sep_antri;
	

	if(*ant_head == NULL)
	{
		*ant_head = antBaru;
		*ant_tail = antBaru;
	}
	else
	{
		antBaru->prev = *ant_tail;
		antBaru->next = NULL;
		(*ant_tail)->next = antBaru;
		*ant_tail = antBaru;
	}
}


int checkingQueue()
{
	int masuk = 1;

	ifstream fileQueueIn("queue.csv");
	
	if(!fileQueueIn)
	{
		return 0;
	}
	bool isEmpty = fileQueueIn.peek() == EOF;
	if(isEmpty == true)
	{
		masuk -= 1;
	}
	else
	{
		masuk += 1;
	}
	fileQueueIn.close();
	return masuk;
}

void loadQueue(Antrian **ant_head, Antrian **ant_tail)
{
	string Sno_antri, Sjumlah_sepatu, Skode_sepatu;

	ifstream fileQueueIn("queue.csv");
	if(fileQueueIn.is_open())
	{
		while(!fileQueueIn.eof())
		{
			getline(fileQueueIn, Sno_antri, ',');
			getline(fileQueueIn, Skode_sepatu, ',');
			getline(fileQueueIn, Sjumlah_sepatu, '\n');

			intoStructQueue(ant_head, ant_tail, Sno_antri, Skode_sepatu, Sjumlah_sepatu);
		}
	}
	else
	{
		cout<<"Error Occured"<<endl;
	}
	fileQueueIn.close();
}

void saveQueue(Antrian **head)
{
	Antrian *temp = *head;
	ofstream fileQueueOut("queue.csv");
	while(temp != NULL)
	{
		fileQueueOut << temp->no_antri << ","
					 << temp->kode_sepatu << ","
					 << temp->jumlah_sepatu << "\n";
	 	temp = temp->next;
	}
	fileQueueOut.close();
}



