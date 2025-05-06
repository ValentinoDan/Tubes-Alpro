#ifndef USER_H
#define USER_H

#include <stdbool.h>

#define MAX_USERS 100

typedef enum {
    ROLE_NONE,
    ROLE_MANAGER,
    ROLE_DOKTER,
    ROLE_PASIEN
} Role;

typedef struct {
    int id;
    char username[50];
    char password[50];
    char penyakit[50];
    Role role;
} User;

// Variabel global
extern User users[MAX_USERS];
extern int userCount;
extern User* currentUser;

// Set of usernames untuk validasi REGISTER
extern char usernameSet[MAX_USERS][50];
extern int usernameSetSize;

/* Utility */
char* roleToStr(Role r);
void toLowerCase(char* dest, const char* src);
bool isUsernameExists(char* username);
void addUser(const char* username, const char* password, Role role);
User* findUser(const char* username);
void login();

#endif
