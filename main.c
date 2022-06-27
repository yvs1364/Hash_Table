#include <stdio.h>
#include <stdlib.h>

typedef struct Student Student;
struct Student{
    char *name;
};

int hachage(char *chaine){
    int i = 0, nombreHache = 0;

    for (i = 0 ; chaine[i] != '\0' ; i++){
        nombreHache += chaine[i];
    }
    nombreHache %= 100;

    return nombreHache;
}
/******************************************************************************
// Grâce à cette fonction de hachage, vous savez donc dans quelle case de votre tableau vous devez placer vos données ! Lorsque vous voudrez y accéder plus tard pour en récupérer les données, il suffira de hacher à nouveau le nom de la personne pour retrouver l'indice de la case du tableau où sont stockées les informations !

//Je vous recommande de créer une fonction de recherche qui se chargera de hacher la clé (le nom) et de vous renvoyer un pointeur vers les données que vous recherchiez.

//Cela donnerait par exemple :
//infosSurLuc = rechercheTableHachage(tableau, "Luc Doncieux");
*******************************************************************************/
int main(){
    Student student1, student2;
    student1.name = "Luc Doncieux";
    student2.name = "Julien Lefebvre";

    printf("Value du nom : %i\n", hachage(student1.name));
    printf("Value du nom : %i\n", hachage(student2.name));

    return 0;
}
