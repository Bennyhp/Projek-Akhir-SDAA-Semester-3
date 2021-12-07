#ifndef TOKOSEPATU_ADMIN_H
#define TOKOSEPATU_ADMIN_H
#include"Structs.h"

void tekanLanjut();
void tambahData(Sepatu **head, Sepatu **tail);
void tampil(Sepatu *head);
void hapusData(Sepatu **head, Sepatu **tail);
void editData(Sepatu *head);
void shellSort(Sepatu *spta, int a, int kategori, int asdc);
void sortData(Sepatu *head);
int jumpSearch(Sepatu *spta, int x, int n);
void searchData(Sepatu *head);
void menuAdmin();
void LogAdmin();
void tampilAntrian(Antrian* arr_head);
void freestyle(Sepatu **head, Sepatu **tail);
void freestyle2(Antrian **ant_head, Antrian **ant_tail, int check);
void takeQueue(Antrian **ant_head, Sepatu **head);

#endif
