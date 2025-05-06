#include <string.h>
#include "set.h"

void createSet(Set* s) {
    s->size = 0;
}

int isInSet(Set* s, const char* element) {
    for (int i = 0; i < s->size; i++) {
        if (strcmp(s->elements[i], element) == 0) {
            return 1; // true
        }
    }
    return 0; // false
}

void insertSet(Set* s, const char* element) {
    if (!isInSet(s, element) && s->size < MAX_SET_SIZE) {
        strncpy(s->elements[s->size], element, MAX_ELEMENT_LENGTH - 1);
        s->elements[s->size][MAX_ELEMENT_LENGTH - 1] = '\0'; // null terminator
        s->size++;
    }
}
