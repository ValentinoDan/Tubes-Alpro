#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "user.h"

User users[MAX_USERS];
int userCount = 0;
User* currentUser = NULL;

char usernameSet[MAX_USERS][50];
int usernameSetSize = 0;

char* roleToStr(Role r) {
    switch (r) {
        case ROLE_MANAGER: return "Manager";
        case ROLE_DOKTER: return "Dokter";
        case ROLE_PASIEN: return "Pasien";
        default: return "Unknown";
    }
}

void toLowerCase(char* dest, const char* src) {
    int i = 0;
    while (src[i]) {
        dest[i] = tolower((unsigned char)src[i]);
        i++;
    }
    dest[i] = '\0';
}

bool isUsernameExists(char* username) {
    char unameLower[50];
    toLowerCase(unameLower, username);
    for (int i = 0; i < usernameSetSize; i++) {
        char existingLower[50];
        toLowerCase(existingLower, usernameSet[i]);
        if (strcmp(existingLower, unameLower) == 0) return true;
    }
    return false;
}

void addUser(const char* username, const char* password, Role role) {
    strcpy(users[userCount].username, username);
    strcpy(users[userCount].password, password);
    users[userCount].id = userCount + 1;
    users[userCount].role = role;
    strcpy(users[userCount].penyakit, role == ROLE_PASIEN ? "" : "-");

    strcpy(usernameSet[usernameSetSize++], username);
    userCount++;
}

User* findUser(const char* username) {
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0) {
            return &users[i];
        }
    }
    return NULL;
}
