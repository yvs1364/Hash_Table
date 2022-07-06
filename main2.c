#include <stdio.h>
#include <stdlib.h>

typedef struct Student Student;
struct Student{
    char *name;
    int age;
};

struct H_item{
    char *key;
    char *value;
};

int hash(char *chaine){
  int numbHash = 0;

    for (int i=0; chaine[i] != '\0'; i++){
        numbHash += chaine[i];
    }
    numbHash %= 100;

    return numbHash;
}
void *searchInHash(Student *arr, char *name){
    printf("Value du nom : %i\n", hash(name));
}
/******************************************************************************
// Grâce à cette fonction de hash, vous savez donc dans quelle case de votre tableau vous devez placer vos données ! Lorsque vous voudrez y accéder plus tard pour en récupérer les données,
il suffira de hacher à nouveau le nom de la personne pour retrouver l'indice de la case du tableau où sont stockées les informations !

//Je vous recommande de créer une fonction de recherche qui se chargera de hacher la clé (le nom) et de vous renvoyer un pointeur vers les données que vous recherchiez.

//Cela donnerait par exemple :
//infosSurLuc = rechercheTablehash(tableau, "Luc Doncieux");
*******************************************************************************/
int main(){
    Student student1, student2;
    student1.name = "Luc Doncieux";
    student1.age = 26;
    student2.name = "Jean eude";
    student2.age = 25;
    searchInHash(Student, "Luc Doncieux");

    // printf("Value du nom : %i\n", hash(student1.name));
    // printf("Value du nom : %i\n", hash(student2.name));
    // infos = searchInHash(student1, "Luc Doncieux");

    return 0;
}
