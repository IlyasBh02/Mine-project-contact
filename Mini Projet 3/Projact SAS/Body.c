#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef stuct {
    char nom [20];
    char prenom [20];
    int tele [20];
    int age [10];
    char statut [20];
    int referance [20];
    int date_reserv [10]

} RESERV;

RESERV R [200];
int NV = 0;

void Ajouter_Reserv(){
    if (count<max_reservation){
        printf("Veuillez entrer le nom : ");
        scanf("%s",R[NV].nom);
        printf("Veuillez entrer le prenom : ");
        scanf("%s",R[NV].prenom);
        printf("Veuillez entrer le telephone : ");
        scanf("%d",R[NV].tele);
        printf("Veuillez entrer l'age : ");
        scanf("%d",R[NV].age);
        printf("Veuillez entrer le statut : ");
        scanf("%s",R[NV].statut);
        printf("Veuillez entrer le referance : ");
        scanf("%d",R[NV].referance);
        printf("Veuillez entrer la date de reservation : ");
        scanf("%d",R[NV].date_reserv);
        NV++;
        printf("Reservation est ajouter . \n");
    }else{
        printf("Reservation est plein");
    }
}

void modifier (){
    int referance, found = 0;
    printf("Entrer le referance du reservation : ");
    scanf("%d")
}