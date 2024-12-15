#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>
#include "mamir.h"

int main_menu(){

    printf(" \n ========================================\n");
    printf("  = SELAMAT DATANG DI MARMIR RESERVATION =\n");
    printf("  ========================================\n");
    printf(" ========================================\n");
    printf(" =                MENU UTAMA            =\n");
    printf(" ========================================\n");

    char pilihan;

    while (1) {
        printf("\nPilihan Menu:\n");
        printf("[A] Admin \n");
        printf("[U] User \n");
        printf("[K] Keluar \n");
        printf("Silahkan pilih: ");

        
        
		while (pilihan !='a' || pilihan !='A' || pilihan !='u' || pilihan !='U' || pilihan !='k' || pilihan !='K' ){
		pilihan=getch();
    switch (pilihan) {
            case 'A': case 'a':
                admin_menu();
                break;
            case 'U': case 'u':
                user_menu();
                break;
            case 'K': case 'k':
                printf("Terima kasih telah menggunakan aplikasi kami!\n");
                exit(0);
        }
    }
}

}


void admin_menu() {
    const char username[] = "admin";
    const char password[] = "pass123";
    char usr[20], pass[20];
    int attempts = 0;

    printf("\nSelamat datang Admin, masukkan username dan password.\n");

    while (attempts < 3) {
        printf("Masukkan username: ");
        scanf("%s", usr);
        printf("Masukkan password: ");
        scanf("%s", pass);

        if (strcmp(usr, username) == 0 && strcmp(pass, password) == 0) {
            printf("Akses diterima. Selamat Datang Admin!\n");
            char pilihan;

            while (1) {
                printf("\nMenu Admin:\n");
                printf("[T] Tambah fasilitas tambahan\n");
                printf("[K] Kembali ke menu utama\n");
                printf("Silahkan pilih: ");
                pilihan = getch();

                switch (pilihan) {
                    case 'T': case 't':
                        tambah_fasilitas();
                        break;
                    case 'K': case 'k':
                        printf("Kembali ke menu utama.\n");
                        system("cls");
                        main_menu();
                    default:
                        printf("Pilihan tidak valid. Silahkan coba lagi.\n");
                }
            }
        } else {
            printf("Akun tidak sesuai. Coba lagi.\n");
            attempts++;
        }
    }

    printf("Akses ditolak setelah 3 percobaan.\n");
    system("cls");
    main_menu();
}

void tambah_fasilitas() {
    char fasilitas_baru[50];

    fasil = fopen("fasil.txt", "a");
    if (fasil == NULL) {
        printf("Gagal membuka file fasilitas.\n");
        return;
    }

    printf("Masukkan nama fasilitas tambahan: ");
    getchar(); // Membersihkan newline dari buffer
    fgets(fasilitas_baru, sizeof(fasilitas_baru), stdin);
    fasilitas_baru[strcspn(fasilitas_baru, "\n")] = '\0';

    fprintf(fasil, "%s\n", fasilitas_baru);
    fclose(fasil);
    printf("Fasilitas '%s' berhasil ditambahkan.\n", fasilitas_baru);

}


void tampilkan_fasilitas() {
    char fasilitas[50];

    fasil = fopen("fasil.txt", "r");
    if (fasil == NULL) {
        printf("Tidak ada fasilitas tambahan yang tersedia.\n");
        return;
    }

    printf("\nFasilitas tambahan yang tersedia:\n");
    int i = 1;
    while (fgets(fasilitas, sizeof(fasilitas), fasil)) {
        fasilitas[strcspn(fasilitas, "\n")] = '\0';
        printf("[%d] %s\n", i++, fasilitas);
        printf("[?]tidak memesan fasilitas\n");
    }
    fclose(fasil);
}



void user_menu() {
    printf(" \n========================================\n");
    printf(" =            PILIHAN RESTORAN          =\n");
    printf(" ========================================\n");
    char pilihanuser;

    while (1) {
        printf("\nPilihan Restoran:\n");
        printf(" [A] Nasi Padang\n");
        printf(" [B] kfc\n");
        printf(" [C] burger king\n");
        printf(" [K] Kembali ke menu utama\n");
        printf("Silahkan pilih: ");

       pilihanuser=getch();

        switch (pilihanuser) {
            case 'A': case 'a':
            	system("cls");
                printf("Nasi Padang Sahara dipilih.\n");
                 strcpy(bd111.restoran,"nasi padang sahara");
                 printf(" \n========================================\n");
                 printf(" =            Nasi Padang Sahara          =\n");
                 printf(" ========================================\n"); 
                buat_reservasi(&bd111);
                return;
            case 'B': case 'b':
            	system("cls");
                printf("kfc dipilih.\n");
                 strcpy(bd111.restoran,"kfc");
                 printf(" \n=======================================\n");
                 printf(" =                   KFC                 =\n");
                 printf(" ========================================\n");
                buat_reservasi(&bd111);
                return;
            case 'C': case 'c':
            	system("cls");
                printf("burger king dipilih.\n");
                  strcpy(bd111.restoran,"burger_king");
                 printf(" \n========================================\n");
                 printf(" =                burger king             =\n");
                 printf(" ========================================\n");
                buat_reservasi(&bd111);
                return;
            case 'K': case 'k':
            	system("cls");
            	main_menu();
               
            default:
                printf("Pilihan tidak valid. Silahkan coba lagi.\n");
        }
    }
}

// Menulis data struct ke file
void buat_reservasi(DataBuatRes *bd) {
    int harga_per_kursi = 5000;
    int biaya_vip = 0; 
    printf("Masukkan nama: ");
    fgets(bd->nama, sizeof(bd->nama), stdin);
    bd->nama[strcspn(bd->nama, "\n")] = '\0';
	 printf("[1] January\n");
	 printf("[2] February\n");
	 printf("[3] March\n");
	 printf("[4] April\n");
	 printf("[5] May\n");
	 printf("[6] June\n");
	 printf("[7] July\n");
	 printf("[8] August\n");
	 printf("[9] September\n");
	 printf("[10] October\n");
	 printf("[11] Novembery\n");
	 printf("[12] December\n");
	  printf("pilih bulan reservasi memilih sesuai nomor bulan: ");
	scanf("%d",&bd->bulan);
	
while(bd->bulan>12){
    printf("lakukan yang benar pintar\n");
	 printf("[1] January[2] February[3] March[4] April[5] May[6] June[7] July[8] August[9] September[10] October[11] November[12] December\n");
       printf("pilih bulan reservasi memilih sesuai nomor bulan: ");
	scanf("%d",&bd->bulan);
}

	if(bd->bulan==1 || bd->bulan==3 || bd->bulan==5 || bd->bulan==7 || bd->bulan==8 || bd->bulan==10 || bd->bulan==12)
{
	 printf("Masukkan tanggal reservasi: ");
	scanf("%d", &bd->tanggalres);
	while(bd->tanggalres > 31){
	
		printf("tanggal tidak boleh lebih dari 31\n");
	   printf("Masukkan tanggal reservasi: ");
    scanf("%d", &bd->tanggalres);
}
}
    	if(bd->bulan==4 || bd->bulan==6 || bd->bulan==9 || bd->bulan==11 )
{
	 printf("Masukkan tanggal reservasi: ");
	scanf("%d", &bd->tanggalres);
	while(bd->tanggalres > 30){
		printf("tanggal tidak boleh lebih dari 30\n");
	   printf("Masukkan tanggal reservasi: ");
    scanf("%d", &bd->tanggalres);
}
}
    
    	if(bd->bulan==2){
    		 printf("Masukkan tanggal reservasi: ");
	scanf("%d", &bd->tanggalres);
	while(bd->tanggalres > 28){
		printf("yang benar");
	   printf("Masukkan tanggal reservasi: ");
    scanf("%d", &bd->tanggalres);
}
		}
    
    
        // Meminta waktu reservasi
    printf("Masukkan waktu reservasi jam format (HH) ): ");
    scanf("%d", &bd->jam);
    
 while (bd->jam < 0 || bd->jam > 23) {
        printf("Waktu tidak valid! Harap masukkan jam antara 0-23.\n");
         printf("Masukkan waktu reservasi jam ");
 		   scanf("%d", &bd->jam);
}

printf("Masukkan waktu reservasi menit, antar 0-59 menit format (MM): ");
 		   scanf("%d",&bd->menit);
     while (bd->menit < 0 || bd->menit > 59){
     printf("Waktu tidak valid! Harap masukkan menit antara 0-59.\n");
         printf("Masukkan waktu reservasi menit, antar 0-59 menit: ");
 		   scanf("%d",&bd->menit);
    
}
    
    
    printf("Untuk berapa orang? (minimal 2): ");
    scanf("%d", &bd->org);
    while (bd->org < 2){
            printf("Jumlah orang minimal 2.\n");
            printf("Untuk berapa orang? (minimal 2): ");
   			scanf("%d", &bd->org);
	}

    printf("Pilih indoor atau outdoor:\n");
    printf("[I] Indoor\n");
    printf("[O] Outdoor\n");
    printf("Silahkan pilih: ");
    
    while(bd->inout != 'i' && bd->inout != 'I' && bd->inout !='o' && bd->inout != 'O'){
		 bd->inout=getch();
	}

    printf("Apakah ingin ruangan VIP? (biaya tambahan 50,000):\n");
    printf("[Y] Ya\n");
    printf("[T] Tidak\n");
    printf("Silahkan pilih: ");
    while(bd->vip!='y' && bd->vip!='Y' && bd->vip!='t' && bd->vip!='T'){
    	bd->vip=getch();
	}
    
    if (bd->vip == 'Y' || bd->vip == 'y') {
        biaya_vip = 50000;
    }
	system("cls");
	 printf("\n========================================\n");
    printf("=      PILIH FASILITAS TAMBAHAN       =\n");
    printf("========================================\n");
    tampilkan_fasilitas();
     printf("\n=================================================================================\n");
        printf("!!NOTE untuk harga dari fasilitas bayarnya tidak tercatat karena bayar ofline!!");
       printf("\n===============================================================================\n");   
    printf("Masukkan fasilitas yang dipilih (pisahkan dengan koma jika lebih dari satu): ");
    getchar(); // Membersihkan newline dari buffer
    fgets(bd->fasilitas, sizeof(bd->fasilitas), stdin);
    bd->fasilitas[strcspn(bd->fasilitas, "\n")] = '\0';
     printf("apabila tidak ingin memesan ketikan simbol ? ");

    int total_bayar = (bd->org * harga_per_kursi) + biaya_vip;

    printf("\n========================================\n");
    printf("=              TOTAL HARGA             =\n");
    printf("========================================\n");
    printf("Nama: %s\n", bd->nama);
    printf("Tanggal: %d\n", bd->tanggalres);
    printf("Waktu: %02d:%02d\n", bd->jam, bd->menit);
    printf("Jumlah kursi: %d\n", bd->org);
    printf("Indoor/Outdoor: %c\n", bd->inout);
    printf("Harga per kursi: %d\n", harga_per_kursi);
    printf("Biaya VIP: %d\n", biaya_vip);
    printf("Fasilitas: %s\n", bd->fasilitas);
    printf("Total bayar: %d\n", total_bayar);
    printf("========================================\n");
    printf("reservasi anda terdaftar\n");

    proses_pembayaran(&bd111);
    
}

void via_pembayaran(DataBuatRes *bd) {
    int total_bayar = (bd->org * 5000) + ((bd->vip == 'Y' || bd->vip == 'y') ? 50000 : 0);
    int jumlah_uang;
    char pilihan;

    printf("\n========================================\n");
    printf("=                VIA BAYAR             =\n");
    printf("========================================\n");
    printf("[L] Langsung\n");
    printf("[T] Transfer\n");
    printf("Silahkan pilih cara pembayaran: ");
    scanf(" %c", &pilihan);

    switch (pilihan) {
        case 'L': case 'l':
            printf("\nSilahkan scan barcode berikut saat pembayaran di restoran:\n");
            printf("  =======================================  \n");
            printf("  |  |  ||  ||  | |  | || ||  ||  | |   |\n");
            printf("  |  |  | |||  |  ||  |  |  |  |  | |  |\n");
            printf("  | |  | || |  |  | ||| | ||  || | || |  |\n");
            printf("  =======================================  \n");
            printf("  Nama Pelanggan: %s\n", bd->nama); 
            printf("  Harap tunjukkan barcode ini saat pembayaran.\n");
            printf("  Jika melebihi 30 menit, reservasi hangus.\n");
            break;

        case 'T': case 't':
            printf("\nSilahkan transfer ke rekening berikut:\n");
            printf("Nomor rekening: 987-654-321\n");
            printf("Total yang harus dibayar: %d\n", total_bayar);

            printf("Masukkan jumlah uang yang akan ditransfer: ");
            scanf("%d", &jumlah_uang);

            if (jumlah_uang < total_bayar) {
                printf("Jumlah uang kurang. Transfer gagal.\n");
                return;
            } else if (jumlah_uang > total_bayar) {
                printf("Transfer berhasil! Kembalian Anda: %d\n", jumlah_uang - total_bayar);
            } else {
                printf("Transfer berhasil! Pembayaran selesai.\n");
            }
            break;

        default:
            printf("Pilihan tidak valid. Silahkan coba lagi.\n");
            return;
    }

    // Simpan data ke file
    FILE *data_base = fopen("kfc.txt", "a");
    if (data_base == NULL) {
        printf("Gagal membuka file untuk menyimpan data.\n");
        return;
    }

    fprintf(data_base, "%s %s %d %d %d %d %d %c %c %c %s\n",
            bd->restoran,
            bd->nama,
            bd->bulan,
            bd->tanggalres,
            bd->jam,
            bd->menit,
            bd->org,
            bd->inout,
            bd->vip,
            bd->pilihan,
            bd->fasilitas);
    fclose(data_base);

    printf("\nReservasi Anda telah terdaftar. Terima kasih!\n");
    printf("Kembali ke menu utama.\n");
    main_menu();


    if (bd->pilihan == 'T' || bd->pilihan == 't') {
        printf("\nSilahkan transfer ke rekening berikut:\n");
        printf("Nomor rekening: 987-654-321\n");
        printf("Total yang harus dibayar: %d\n", total_bayar);

        printf("Masukkan jumlah uang yang akan ditransfer: ");
        scanf("%d", &jumlah_uang);

        // Validasi jumlah uang
        if (jumlah_uang < total_bayar) {
            printf("Jumlah uang kurang. Transfer gagal.\n");
            system("cls");
            printf("kembali ke main menu");
            sleep(0.5);
            main_menu();
        } else if (jumlah_uang > total_bayar) {
        	jumlah_uang=jumlah_uang-total_bayar;
            printf("Jumlah uang berlebih kembalian= %d\n",jumlah_uang);
            printf("restoran anda berhasil terdaftar ke data base serta jangan lupa hadir di reservasi tepat waktu");
            printf("kembali ke main menu atau keluar");
            	system("cls");
                main_menu();
     
        } 
}
		else {
            printf("Transfer berhasil! Pembayaran selesai.\n");
            printf("Terima kasih atas reservasinya.\n");
              printf("ceritanya berhasil\n");
      		  printf("data anda disimpan di data base\n");
      		   data_base = fopen("kfc.txt", "a");
           fprintf(data_base, "%s %s %d %d %d %d %d %c %c %c %s\n",
    		bd->restoran,
            bd->nama,
            bd->bulan,
            bd->tanggalres,
            bd->jam,
            bd->menit,
            bd->org,
            bd->inout,
            bd->vip,
            bd->pilihan,
			bd->fasilitas);
    fclose(data_base);
     printf("program akan dihentikan");
        }
}


void proses_pembayaran(DataBuatRes *bd) {
    char pilihan;

    while (1) {
        printf("\nApakah Anda yakin untuk reservasi?\n");
        printf("[Y] Ya\n");
        printf("[T] Tidak\n");
        printf("[K] Kembali ke menu utama\n");
        printf("Silahkan pilih: ");
		pilihan=getch();
        switch (pilihan) {
            case 'Y': case 'y':
                via_pembayaran(&bd111);
                return;
            case 'T': case 't':
                printf("Kembali ke menu reservasi.\n");
                sleep(0.2);
                system("cls");
                main_menu();
                return;
            case 'K': case 'k':
            	system("cls");
                printf("Kembali ke menu utama.\n");
                main_menu();
                return;
            default:
                printf("Pilihan tidak valid. Silahkan coba lagi.\n");
        }
    }
}

int main() {
main_menu();
	
}
