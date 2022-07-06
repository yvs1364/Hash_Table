#include <stdlib.h>
#include <stdio.h>

typedef struct Student Student;
typedef struct List List;

#define PRESENT(list, student)({        \
 if(list == NULL || student == NULL){   \
        exit(EXIT_FAILURE);             \
    }                                   \
})                                      \

struct Student{
    char *name;
    int age;
    Student *next;
};

struct List{
    Student *first;
};


List *init();
int sizeOfList(List *list);
int hash(char *list);
void insert(List *list, char* newName, int newAge);
void showList(List *list);



int main() {
    List *myList = init();


    printf("------------------------------------\n");
    showList(myList);
    printf("------------------------------------\n");
    insert(myList, "Luc Doncieux", 25);
    showList(myList);
    printf("------------------------------------\n");
    sizeOfList(myList);
    printf("------------------------------------\n");


    return 0;
}

List *init() {
    // Initiliase la liste chainee
    List *list = malloc(sizeof(*list));
    Student *student = malloc(sizeof(*student));

    PRESENT(list,student);
    student->name = "Jean-eude";
    student->age  = 26;
    student->next = NULL;
    list->first   = student;

    return list;
}

void insert(List *list, char* newName, int newAge){
    Student *new = malloc(sizeof(*new));
    PRESENT(list,new);
    new->name = newName;
    new->age = newAge;
    new->next = list->first;
    list->first = new;

}


void showList(List *list) {
    if(list == NULL) {
        exit(EXIT_FAILURE);
    }

    Student *current = list->first;

    while (current != NULL){
        printf("[ Nom -> %s, ", current->name);
        printf("age -> %d ", current->age);
        printf("{ Hash du nom = %i }]", hash(current->name));
        current = current->next;
        printf(" -> ");
    }
    printf(" [ NULL ]\n");

}

int sizeOfList(List *list) {
    int sizeList = 0;
    if(list == NULL) {
        exit(EXIT_FAILURE);
    }

    Student *current = list->first;
    while (current != NULL){
       ++sizeList;
        current = current->next;
    }

    return sizeList;
}

int hash(char *list){
  int numbHash = 0;

    for (int i=0; list[i] != '\0'; i++){
        numbHash += list[i];
    }
    numbHash %= 100;

    return numbHash;
}