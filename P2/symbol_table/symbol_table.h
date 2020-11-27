#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdint.h>


struct keyValuePair {
    char* key;
    uint32_t value;
    struct keyValuePair* next;
    struct keyValuePair* prev;
};

typedef struct keyValuePair pair;

typedef struct {
    pair *header;
    pair *footer;
} symbol_table;

pair* allocate_pair(void);

void free_pair(pair *pair_to_free);

void init_table(symbol_table *t);

typedef pair *tabl_iter;

tabl_iter table_begin(symbol_table *t);

tabl_iter table_end(symbol_table *t);

void table_insert(symbol_table *t, tabl_iter iter, char *key, int32_t value);

void insert_front(symbol_table *t, char *key, int32_t value);


void insert_back(symbol_table *t, char *key, int32_t value);

void destroy_table(symbol_table *t);

int32_t table_lookup(symbol_table *t, char *key);

#endif
