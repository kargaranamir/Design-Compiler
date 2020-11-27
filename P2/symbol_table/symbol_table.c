#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "symbol_table.h"

//symbol table by linked list 

//Allocate
pair *allocate_pair(void) {
    pair *newpair = malloc(sizeof(pair));

    if (newpair == NULL) {
        perror("allocate_pair");
        exit(EXIT_FAILURE);
    }

    return newpair;
}

//Free
void free_pair(pair *pair_to_free) {
    free(pair_to_free);
}

//Initialise
void init_table(symbol_table *t) {
    t -> header = allocate_pair();
    t -> footer = allocate_pair();
    t -> header -> prev = NULL;
    t -> footer -> next = NULL;
    t -> header -> next = t -> footer;
    t -> footer -> prev = t -> header;
}

tabl_iter table_begin(symbol_table *t) {
    return t -> header -> next;
}

tabl_iter table_end(symbol_table *t) {
    return t -> footer;
}

//Insert
void table_insert(symbol_table *t, tabl_iter iter, char *key, int32_t value) {
    pair *new_pair = allocate_pair();
    new_pair -> value = value;
    new_pair -> key = malloc((strlen(key) + 1) * sizeof(char));
    strcpy(new_pair -> key, key);

    new_pair -> prev = iter -> prev;
    new_pair -> next = iter;

    iter -> prev -> next = new_pair;
    iter -> prev = new_pair;
}


void insert_front(symbol_table *t, char *key, int32_t value) {
    table_insert(t, table_begin(t), key, value);
}


void insert_back(symbol_table *t, char *key, int32_t value) {
    table_insert(t, table_end(t), key, value);
}

void destroy_table(symbol_table *t) {
    pair *p = t -> header;
    while (p != NULL) {
        pair *next = p -> next;
        free_pair(p);
        p = next;
    }
}

//Lookup 
int32_t table_lookup(symbol_table *t, char *key) {
    for (tabl_iter iter = table_begin(t); iter != table_end(t); iter = iter -> next) {
        if (strcmp(iter -> key, key) == 0) {
            return iter -> value;
        }
    }
    return 0;
}
