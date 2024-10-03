#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nom[20];
    char prenom[20];
    char tele[20]; 
    int age;
    char statut[20]; // statut (validé, reporté, annulé, traité)
    int reference;   // Référence unique générée automatiquement
    char date_reserv[20]; 
} RESERV;

RESERV R[200];
int NV = 0; 

void Ajouter_Reserv() {       // 1111  
    if (NV < 200) {
        printf("Veuillez entrer le nom : ");
        scanf("%s", R[NV].nom);
        printf("Veuillez entrer le prenom : ");
        scanf("%s", R[NV].prenom);
        printf("Veuillez entrer le telephone : ");
        scanf("%s", R[NV].tele);
        printf("Veuillez entrer l'age : ");
        scanf("%d", &R[NV].age);
        printf("Veuillez entrer le statut (validé, reporté, annulé, traité) : ");
        scanf("%s", R[NV].statut);
        
        R[NV].reference = NV + 1; 
        printf("Référence est automatique : %d\n", R[NV].reference);

        printf("Veuillez entrer la date de reservation (jj/mm/aaaa) : ");
        scanf("%s", R[NV].date_reserv);
        NV++; 
        printf("Réservation ajoutée avec succès.\n");
    } else {
        printf("La capacité maximale de réservations est atteinte.\n");
    }
}

// 2.1 // 2.2

void modifier_ou_supprimer(){     
    int reference, found = 0;
    printf("Entrez la référence de la réservation à modifier ou supprimer : ");
    scanf("%d", &reference);
    
    for (int i = 0; i < NV; i++) {
        if (R[i].reference == reference) {
            found = 1;
            int choix;
            printf("Réservation trouvée. Que voulez-vous faire ?\n");
            printf("1. Modifier\n2. Supprimer\n");
            scanf("%d", &choix);
            
            if (choix == 1) {
                printf("Modifier la réservation : \n");
                printf("Nouveau nom : ");
                scanf("%s", R[i].nom);
                printf("Nouveau prénom : ");
                scanf("%s", R[i].prenom);
                // Continue les modifications nécessaires...
            } else if (choix == 2) {
                for (int j = i; j < NV - 1; j++) {
                    R[j] = R[j + 1];  // Décaler les éléments pour supprimer
                }
                NV--;
                printf("Réservation supprime.\n");
            } else {
                printf("Choix invalide.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Aucun reservation trouve with this reference.\n");
    }
}

// 3333 

void afficher_reservation() {  
    int ref, found = 0;
    printf("Entrez référence de la réservation : ");
    scanf("%d", &ref);

    for (int i = 0; i < NV; i++) {
        if (R[i].reference == ref) {
            found = 1;
            printf("Les info de reservation :\n");
            printf("Nom : %s\n", R[i].nom);
            printf("Prénom : %s\n", R[i].prenom);
            printf("Tele : %s\n", R[i].tele);
            printf("Âge : %d\n", R[i].age);
            printf("Statut : %s\n", R[i].statut);
            printf("Référence : %d\n", R[i].reference);
            printf("Date de reserv : %s\n", R[i].date_reserv);
            break;
        }
    }else{
        printf("Aucun reservation trouve with this reference.\n");
    }
}

// 4444
void trier_par_nom() {
    RESERV temp;
    for (int i = 0; i < NV - 1; i++) {
        for (int j = 0; j < NV - i - 1; j++) {
            if (strcmp(R[j].nom, R[j + 1].nom) > 0) {
                temp = R[j];
                R[j] = R[j + 1];
                R[j + 1] = temp;
            }
        }
    }
    printf("Réservations triées par nom.\n");
}

