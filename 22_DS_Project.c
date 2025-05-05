// Project on Student Marks

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    int rollNo;
    char name[50];
    float marks;
    struct Student *prev, *next;
} Student;

Student* head = NULL;

Student* createNode(int roll, const char* name, float marks) {
    Student* newNode = (Student*)malloc(sizeof(Student));
    newNode->rollNo = roll;
    strcpy(newNode->name, name);
    newNode->marks = marks;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void insert(int roll, const char* name, float marks) {
    Student* newNode = createNode(roll, name, marks);
    if (!head) {
        head = newNode;
        return;
    }
    Student* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteRecord(int roll) {
    Student* temp = head;
    while (temp && temp->rollNo != roll) temp = temp->next;
    if (!temp) {
        printf("Record not found.\n");
        return;
    }
    if (temp->prev) temp->prev->next = temp->next;
    else head = temp->next;
    if (temp->next) temp->next->prev = temp->prev;
    free(temp);
    printf("Record deleted successfully.\n");
}

void update(int roll, const char* name, float marks) {
    Student* temp = head;
    while (temp && temp->rollNo != roll) temp = temp->next;
    if (!temp) {
        printf("Record not found.\n");
        return;
    }
    strcpy(temp->name, name);
    temp->marks = marks;
    printf("Record updated successfully.\n");
}

void display() {
    Student* temp = head;
    printf("Student Records:\n");
    while (temp) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", temp->rollNo, temp->name, temp->marks);
        temp = temp->next;
    }
}

void sortByMarks() {
    if (!head) return;
    for (Student* i = head; i; i = i->next) {
        for (Student* j = i->next; j; j = j->next) {
            if (i->marks > j->marks) {
                int roll = i->rollNo; i->rollNo = j->rollNo; j->rollNo = roll;
                float m = i->marks; i->marks = j->marks; j->marks = m;
                char name[50]; strcpy(name, i->name); strcpy(i->name, j->name); strcpy(j->name, name);
            }
        }
    }
    printf("Sorted by marks.\n");
}

void sortByName() {
    if (!head) return;
    for (Student* i = head; i; i = i->next) {
        for (Student* j = i->next; j; j = j->next) {
            if (strcmp(i->name, j->name) > 0) {
                int roll = i->rollNo; i->rollNo = j->rollNo; j->rollNo = roll;
                float m = i->marks; i->marks = j->marks; j->marks = m;
                char name[50]; strcpy(name, i->name); strcpy(i->name, j->name); strcpy(j->name, name);
            }
        }
    }
    printf("Sorted by name.\n");
}

int main() {
    int choice, roll;
    char name[50];
    float marks;

    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Update\n4. Display\n5. Sort by Marks\n6. Sort by Name\n7. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter roll no, name, marks: ");
                scanf("%d %s %f", &roll, name, &marks);
                insert(roll, name, marks);
                break;
            case 2:
                printf("Enter roll no to delete: ");
                scanf("%d", &roll);
                deleteRecord(roll);
                break;
            case 3:
                printf("Enter roll no, new name, new marks: ");
                scanf("%d %s %f", &roll, name, &marks);
                update(roll, name, marks);
                break;
            case 4:
                display();
                break;
            case 5:
                sortByMarks();
                break;
            case 6:
                sortByName();
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice.\n");
        }
    }
}
