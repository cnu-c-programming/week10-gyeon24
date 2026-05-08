#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 노드 구조체 정의
struct Node {
    char name[50];
    int score;
    struct Node* next;
};

// 리스트의 시작(head)
struct Node* head = NULL;

// add <name> <score>: 리스트의 맨 뒤에 추가
void add(char* name, int score) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    newNode->score = score;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// delete <name>: 해당 이름을 가진 학생 제거
void delete_node(char* name) {
    struct Node* temp = head;
    struct Node* prev = NULL;

    if (temp != NULL && strcmp(temp->name, name) == 0) {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return; [span_27](start_span)// 예외 처리는 생략[span_27](end_span)

    prev->next = temp->next;
    free(temp);
}

// print: 리스트 전체 출력
void print_list() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%s %d\n", temp->name, temp->score);
        temp = temp->next;
    }
}

// quit: 할당된 모든 메모리 해제
void free_all() {
    struct Node* temp = head;
    while (temp != NULL) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
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
