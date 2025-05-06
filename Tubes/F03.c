#include <stdio.h>
#include "user.h"

void logout() {
    if (!currentUser) {
        printf("Logout gagal!\nAnda belum login, silahkan login terlebih dahulu sebelum melakukan logout\n");
    } else {
        printf("Sampai jumpa!\n");
        currentUser = NULL;
    }
}
