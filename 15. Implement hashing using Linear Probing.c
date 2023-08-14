#include <stdlib.h>
#define SIZE 10 
typedef struct {
    int key;
    int value;
} KeyValuePair;
KeyValuePair* createKeyValuePair(int key, int value) {
    KeyValuePair* pair = (KeyValuePair*)malloc(sizeof(KeyValuePair));
    pair->key = key;
    pair->value = value;
    return pair;
}
KeyValuePair** createHashTable() {
    KeyValuePair** hashTable = (KeyValuePair**)malloc(SIZE * sizeof(KeyValuePair*));
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
    return hashTable;
}
int getHashIndex(int key) {
    return key % SIZE;
}
void insert(KeyValuePair** hashTable, int key, int value) {
    int index = getHashIndex(key);
    int i = index;
    do {
        if (hashTable[i] == NULL) {
            hashTable[i] = createKeyValuePair(key, value);
            printf("Inserted (%d, %d) at index %d\n", key, value, i);
            return;
        }
        i = (i + 1) % SIZE;
    } while (i != index);
    printf("Hash table is full. Cannot insert (%d, %d)\n", key, value);
}
int search(KeyValuePair** hashTable, int key) {
    int index = getHashIndex(key);
    int i = index;
    do {
        if (hashTable[i] != NULL && hashTable[i]->key == key) {
            return hashTable[i]->value;
        }
        i = (i + 1) % SIZE;
    } while (hashTable[i] != NULL && i != index);
    return -1; 
}
void display(KeyValuePair** hashTable) {
    printf("Hash Table Contents:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] != NULL) {
            printf("Index %d: (%d, %d)\n", i, hashTable[i]->key, hashTable[i]->value);
        }
    }
}
int main() {
    KeyValuePair** hashTable = createHashTable();
    insert(hashTable, 1, 10);
    insert(hashTable, 2, 20);
    insert(hashTable, 3, 30);
    insert(hashTable, 4, 40);
    insert(hashTable, 12, 120); 
    display(hashTable);
    int keyToSearch = 2;
    int result = search(hashTable, keyToSearch);
    if (result != -1) {
        printf("Value for key %d: %d\n", keyToSearch, result);
    } else {
        printf("Key %d not found in the hash table.\n", keyToSearch);
    }
    free(hashTable);
    return 0;
}
