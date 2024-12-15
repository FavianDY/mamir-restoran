#ifndef MAMIR_H
#define MAMIR_H
#include "boolean.h"

// Struktur data untuk reservasi
typedef struct {
	char restoran[30];
    char nama[50];
    int bulan;
    int tanggalres;
    int jam;
	int menit;
    int org;
    char inout;
    char vip;
    char pilihan;
    char fasilitas[100];
} DataBuatRes;

DataBuatRes bd111;

FILE *data_base;
FILE *fasil;

// Deklarasi fungsi
int main_menu();
void user_menu();
void admin_menu();
void buat_reservasi(DataBuatRes *bd);
void proses_pembayaran(DataBuatRes *bd);
void via_pembayaran(DataBuatRes *bd);
void tambah_fasilitas();
void tampilkan_fasilitas();


