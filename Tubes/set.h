#ifndef SET_H
#define SET_H

#define MAX_SET_SIZE 100
#define MAX_ELEMENT_LENGTH 50

typedef struct {
    char elements[MAX_SET_SIZE][MAX_ELEMENT_LENGTH];
    int size;
} Set;

// Inisialisasi set kosong
void createSet(Set* s);

// Mengecek apakah elemen ada di dalam set
int isInSet(Set* s, const char* element);

// Menambahkan elemen ke set (jika belum ada)
void insertSet(Set* s, const char* element);

#endif
