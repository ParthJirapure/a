/*Write a menu-driven program that implements a circular linked list for the following operations:

Create
Insert
Delete
Reverse*/

#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
typedef struct Node* NODE;

NODE insertAtPositionInCLL(NODE last, int position, int data) {
    NODE newNode = (NODE)malloc(sizeof(struct Node));
    newNode->data = data;

    if (last == NULL) {
        if (position != 1) {
            printf("Position not found\n");
            free(newNode);
            return NULL;
        }
        newNode->next = newNode;
        return newNode;
    }
    NODE temp = last->next;
    if (position == 1) {
        newNode->next = last->next;
        last->next = newNode;
        return last;
    }

    int count = 1;
    while (temp != last && count < position - 1) {
        temp = temp->next;
        count++;
    }

    if (count != position - 1) {
        printf("Position not found\n");
        free(newNode);
        return last;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    if (temp == last) {
        return newNode;
    }
    return last;
}

NODE deleteAtPositionInCLL(NODE last, int position) {
    if (last == NULL) {
        printf("CLL is empty\n");
        return NULL;
    }

    NODE temp = last->next;
    if (position == 1) {
        if (last->next == last) {
            printf("Deleted element: %d\n", last->data);
            free(last);
            return NULL;
        }
        last->next = temp->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return last;
    }

    NODE prev = NULL;
    int count = 1;
    while (temp != last && count < position) {
        prev = temp;
        temp = temp->next;
        count++;
    }
    if (count != position) {
        printf("Position not found\n");
        return last;
    }

    prev->next = temp->next;
    if (temp == last) last = prev;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
    return last;
}

void traverseListInCLL(NODE last) {
    if (last == NULL) {
        printf("CLL is empty\n");
        return;
    }

    NODE temp = last->next;
    do {
        printf("%d --> ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}
NODE reverseCLL(NODE last) {
    if (!last || last->next == last) return last;

    NODE prev = last, curr = last->next, next;
    NODE first = last->next;

    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (prev != last);

    first->next = prev;
    last = first;
    return last;
}
void main() {
    NODE first = NULL;
    int x, pos, op;
    while (1) {
        printf("1.Insert 2.Delete 3.Display 4.Reverse 5.Exit\n");
        printf("choice: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                printf("Position: ");
                scanf("%d", &pos);
                if (pos <= 0) {
                    printf("Position not found\n");
                } else {
                    printf("Element: ");
                    scanf("%d", &x);
                    first = insertAtPositionInCLL(first, pos, x);
                }
                break;
            case 2:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Position: ");
                    scanf("%d", &pos);
                    first = deleteAtPositionInCLL(first, pos);
                }
                break;
            case 3:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    printf("Elements in CLL are: ");
                    traverseListInCLL(first);
                }
                break;
            case 4:
                if (first == NULL) {
                    printf("CLL is empty\n");
                } else {
                    first = reverseCLL(first);
                    printf("CLL reversed\n");
                }
                break;
            case 5:
                exit(0);
        }
    }
}