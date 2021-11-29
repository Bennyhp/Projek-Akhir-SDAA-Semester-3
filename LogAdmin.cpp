#include<iostream>
#include<conio.h>
#include<iomanip>
#include"Admin.cpp"

using namespace std;

struct Admin
{
	string username;
	string password;
};

struct Nodes
{
	Admin adm;
	struct Nodes* next;
	struct Nodes* prev;
};

Nodes *head2 = NULL, *tail2 = NULL;


void regis(Nodes **head2, Nodes **tail2)
{
	Nodes *admBaru = new Nodes();
	Nodes *temp = *head2;
	int pilih;
	
	cout
	<<"\n\n=============================================\n"
	<<"|                     Regis                  |\n"
	<<"---------------------------------------------\n";
	cout<<"username : ";cin >> admBaru->adm.username;
	cin.ignore();
	cout<<"password : ";cin >> admBaru->adm.password;
	admBaru->next = *head2;
	if(*head2 == NULL)	{
		*head2 = admBaru;
		*tail2 = admBaru;
	}
	else
	{
		admBaru->prev = NULL;
		admBaru->next = *head2;
		(*head2)->prev = admBaru;
		(*head2) = admBaru;
	}
	tekanLanjut();	
}



void LogAdmin(Nodes *head2)
{
	string usn;
	string pass;
	Nodes *temp = head2;

	
	if(head2 == NULL)
	{
		system("CLS");
		cout<<"!!!! Data Masih Kosong !!!!"<<endl;
		tekanLanjut();
		return;
	}
	system("CLS");
	cout
	<<"\n\n=============================================\n"
	<<"|                     Login                  |\n"
	<<"---------------------------------------------\n";
	cout<<"Masukkan username : ";cin>>usn;
	cout<<"Masukkan password : ";cin>>pass;
	
	while(temp != NULL)
	{
		if(temp->adm.username == usn && temp->adm.password == pass)
		{
			cout <<"Anda Berhasil Login"<<endl;
			tekanLanjut();
			menuAdmin();
			return;
		}
		else
		{
			system("CLS");
			cout<<"!!!! USER DAN PASSWORD SALAH COBA LAGI !!!!"<<endl;
			tekanLanjut();
			LogAdmin(head2);
		}
		temp = temp->next;
	}
	
}


void inAdmin(){
	int pilih;
	int admin;
	while(pilih !=3){
		system("CLS");
		cout
		<<"\n=============================================\n"
		<<"|            Masuk Sebagai Admin              |\n"
		<<"---------------------------------------------\n"
		<<" 1. Daftar\n"
		<<" 2. Masuk\n"
		<<" 3. Kembali\n"
		<<"Masukkan Pilihan : ";cin >> pilih;
		switch(pilih){
		
			case 1:
				regis(&head2, &tail2);
				inAdmin();
			case 2:
				LogAdmin(head2);	
				continue;
			case 3:
				break;
			default:
				cout<<"Pilihan tidak ada"<<endl;
				tekanLanjut();
		}
	}			
}
