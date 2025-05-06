#include <stdio.h>
#include "user.h"

void registerPasien() {
    if (currentUser != NULL) {
        printf("Logout terlebih dahulu sebelum register.\n");
        return;
    }
    char uname[50], pw[50];
    printf("Username: "); scanf("%s", uname);
    printf("Password: "); scanf("%s", pw);

    if (isUsernameExists(uname)) {
        printf("Registrasi gagal! Pasien dengan nama %s sudah terdaftar.\n", uname);
        return;
    }
    addUser(uname, pw, ROLE_PASIEN);
    printf("Pasien %s berhasil ditambahkan!\n", uname);
}