#include <stdio.h>
#include "user.h"

void help() {
    printf("=========== HELP ===========\n\n");
    if (!currentUser) {
        printf("Kamu belum login sebagai role apapun. Silahkan login terlebih dahulu.\n\nLOGIN: Masuk ke dalam akun yang sudah terdaftar\nREGISTER: Membuat akun baru\n");
    } else if (currentUser->role == ROLE_MANAGER) {
        printf("Halo Manager %s. Kenapa kamu memanggil command HELP? Berikut fitur yang bisa kamu pakai:\n\nLOGOUT\nTAMBAH_DOKTER\n", currentUser->username);
    } else if (currentUser->role == ROLE_DOKTER) {
        printf("Halo Dokter %s. Berikut fitur yang bisa kamu pakai:\n\nLOGOUT\nDIAGNOSIS\n", currentUser->username);
    } else if (currentUser->role == ROLE_PASIEN) {
        printf("Selamat datang, %s. Berikut fitur yang bisa kamu pakai:\n\nLOGOUT\nDAFTAR_CHECKUP\n", currentUser->username);
    }
    printf("\nFootnote:\nUntuk menggunakan aplikasi, silahkan masukkan nama fungsi yang terdaftar\nJangan lupa untuk memasukkan input yang valid\n");
}