#include <stdio.h>
#include <string.h>

typedef struct {
    char nom[100];
    char email[100];
    char num[20];
    char nationality[50];
} contacts;

contacts CT[100];
int NV = 0;

void Ajout_Simple() {

    printf("Veuillez entrer le nom : ");
    scanf("%s", CT[NV].nom);
    printf("Veuillez entrer l'adresse email : ");
    scanf("%s", CT[NV].email);
    printf("Veuillez entrer le numéro : ");
    scanf("%s", CT[NV].num);
    printf("Veuillez entrer la nationalité : ");
    scanf("%s", CT[NV].nationality);
    NV++; 

    printf("--- Contact ajouté avec succès ---\n");
}

void Ajout_Multiple() {
    char choix;
    do {
        Ajout_Simple();

        printf("Voulez-vous ajouter un autre contact ? (a/z) : ");
        scanf(" %c", &choix);

    } while (choix == 'a' && NV < 100);
}

void Affichage_Simple() {

    for (int i = 0; i < NV; i++) {

        printf("Nom Contact %d : %s\n", i + 1, CT[i].nom);
        printf("Le numéro : %s\n", CT[i].num);
        printf("L'adresse email : %s\n", CT[i].email);
        printf("La nationalité : %s\n", CT[i].nationality);
    }
}

void Affichage_Order_asc() {

    for (int i = 0; i < NV - 1; i++) {

        for (int j = i + 1; j < NV; j++) {

            if (strcmp(CT[i].nom, CT[j].nom) > 0) {
                contacts temp = CT[i];
                CT[i] = CT[j];
                CT[j] = temp;
            }
        }
    }
}

void Affichage_Order_Desc() {

    for (int i = 0; i < NV - 1; i++) {

        for (int j = i + 1; j < NV; j++) {

            if (strcmp(CT[i].nom, CT[j].nom) < 0) {
                contacts temp = CT[i];
                CT[i] = CT[j];
                CT[j] = temp;
            }
        }
    }
}

void Modification_Email_Num() {

    char nom[100];
    int contact_found = -1;

    printf("Veuillez entrer le nom du contact que vouller modifier : ");
    scanf("%s", nom);

    for (int i = 0; i < NV; i++) {
        if (strcmp(CT[i].nom, nom) == 0) {
            contact_found = i;
            break;
        }
    }

    if (contact_found == -1) {
        printf("Contact invalide.\n");
    } 
    else {

        printf("Modifier le nom : ", CT[contact_found].nom);
        scanf("%s", CT[contact_found].nom);

        printf("Modifier l'adresse email : ", CT[contact_found].email);
        scanf("%s", CT[contact_found].email);

        printf("Modifier le num : ", CT[contact_found].num);
        scanf("%s", CT[contact_found].num);

        printf("Modifier la nationalité : ", CT[contact_found].nationality);
        scanf("%s", CT[contact_found].nationality);

        printf("Contact modifié avec succès.\n");
    }
}