#ifndef TOKOSEPATU_STRUCTS_H
#define TOKOSEPATU_STRUCTS_H

using namespace std;

typedef struct Sepatu
{
	int kode_sep;
	std::string nama_sep;
	std::string merk_sep;
	int ukuran_sep;
	std::string warna_sep;
	int jumlah_sep;
	int harga_sep;
	Sepatu* next;
	Sepatu* prev;
} Sepatu;

typedef struct Antrian {
   int no_antri;
   int jumlah_sepatu;
   int kode_sepatu;
   Antrian *next;
   Antrian *prev;
} Antrian;

#endif
