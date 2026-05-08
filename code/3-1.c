#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    int score;
    struct Node* next;
};

struct Node* head = NULL;

void add(char* name, int score) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* tmp = head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
}

void delete_node(char* name) {
    struct Node* tmp = head;
    struct Node* prev = NULL;

    if (tmp != NULL && strcmp(tmp->name, name) == 0) {
        head = tmp->next;
        free(tmp);
        return;
    }

    while (tmp != NULL && strcmp(tmp->name, name) != 0) {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL) return;

    prev->next = tmp->next;
    free(tmp);
}

void print_list() {
    struct Node* tmp = head;
    while (tmp != NULL) {
        printf("%s %d\n", tmp->name, tmp->score);
        tmp = tmp->next;
    }
}

void free_all() {
    struct Node* tmp = head;
    while (tmp != NULL) {
        struct Node* next = tmp->next;
        free(tmp);
        tmp = next;
    }
    head = NULL;
}

int main() {
    char cmd[20];
    char name[50];
    int score;

    while (1) {
        scanf("%s", cmd);

        if (strcmp(cmd, "add") == 0) {
            scanf("%s %d", name, &score);
            add(name, score);
        } 
        else if (strcmp(cmd, "delete") == 0) {
            scanf("%s", name);
            delete_node(name);
        } 
        else if (strcmp(cmd, "print") == 0) {
            print_list();
        } 
        else if (strcmp(cmd, "quit") == 0) {
            free_all();
            break;
        }
    }

    return 0;
}
