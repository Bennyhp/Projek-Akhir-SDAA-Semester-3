#ifndef TOKOSEPATU_ADMIN_H
#define TOKOSEPATU_ADMIN_H
#include"Structs.h"

void intoStructSepatu(Sepatu **head, Sepatu **tail, string kode, string nama, string merk, string ukuran, string warna, string jumlah, string harga);
void loadCSV(Sepatu **head, Sepatu **tail);
void saveCSV(Sepatu **head);
void intoStructQueue(Antrian **head, Antrian **tail, string no_antri, string jumlah_sep_antri, string kode_sep_antri);
void loadQueue(Antrian **head, Antrian **tail);
void saveQueue(Antrian **head);
int checkingQueue();
int checkingCSV();



#endif
