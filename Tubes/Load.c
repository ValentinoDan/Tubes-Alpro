#include <stdio.h>
#include "user.h"

void loadUsersFromCSV(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Gagal membuka file %s\n", filename);
        return;
    }

    char line[128];
    while (fgets(line, sizeof(line), file)) {
        // Hilangkan newline
        line[strcspn(line, "\n")] = 0;

        User user;
        sscanf(line, "%[^,],%[^,],%s", user.username, user.password, user.role);
        users[userCount++] = user;
        setAdd(&usernameSet, user.username);
    }

    fclose(file);
}

int main(){
    
}