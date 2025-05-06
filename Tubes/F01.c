#include <stdio.h>
#include "user.h"

void login() {
    if (currentUser != NULL) {
        printf("Sudah login sebagai %s!\n", currentUser->username);
        return;
    }
    char uname[50], pw[50];
    printf("Username: "); scanf("%s", uname);
    printf("Password: "); scanf("%s", pw);

    User* user = findUser(uname);
    if (!user) {
        printf("Tidak ada Manager, Dokter, atau pun Pasien yang bernama %s!\n", uname);
        return;
    }
    if (strcmp(user->password, pw) != 0) {
        printf("Username atau password salah untuk pengguna yang bernama %s!\n", uname);
        return;
    }
    currentUser = user;
    if (user->role == ROLE_MANAGER) printf("Selamat pagi Manager %s!\n", uname);
    else if (user->role == ROLE_DOKTER) printf("Selamat pagi Dokter %s!\n", uname);
    else printf("Selamat pagi %s! Ada keluhan apa ?\n", uname);
}