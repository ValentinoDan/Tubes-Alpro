#include <stdio.h>
#include "user.h"

void runLengthEncode(char* result, const char* input) {
    int len = strlen(input);
    int count = 1;
    char buffer[10];
    result[0] = '\0';
    for (int i = 1; i <= len; i++) {
        if (i < len && input[i] == input[i - 1]) {
            count++;
        } else {
            if (count > 1) {
                sprintf(buffer, "%d%c", count, input[i - 1]);
            } else {
                sprintf(buffer, "%c", input[i - 1]);
            }
            strcat(result, buffer);
            count = 1;
        }
    }
}

void lupaPassword() {
    char uname[50], kode[100], kodeCek[100];
    printf("Username: "); scanf("%s", uname);
    printf("Kode Unik: "); scanf("%s", kode);

    User* user = findUser(uname);
    if (!user) {
        printf("Username tidak terdaftar!\n");
        return;
    }
    runLengthEncode(kodeCek, uname);
    if (strcmp(kodeCek, kode) != 0) {
        printf("Kode unik salah!\n");
        return;
    }
    printf("Halo %s %s, silakan daftarkan ulang password anda!\n", roleToStr(user->role), uname);
    printf("Password Baru: "); scanf("%s", user->password);
}