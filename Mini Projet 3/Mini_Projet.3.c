#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nom[20];
    char prenom[20];
    char tele[20]; 
    int age;
    char statut[20];            // validé, reporté, annulé, traité
    int ref;                    // Rfrnc / auto.
    char date_reserv[20]; 
} RESERV;

RESERV R[200];
int NV = 0; 

void Ajouter_Reserv() {       // P.1.  
    if (NV < 200) {
        printf("Veuillez entrer le nom : ");
        scanf("%s", R[NV].nom);
        printf("Veuillez entrer le prenom : ");
        scanf("%s", R[NV].prenom);
        printf("Veuillez entrer le telephone : ");
        scanf("%s", R[NV].tele);
        printf("Veuillez entrer l'age : ");
        scanf("%d", &R[NV].age);

        printf("Veuillez choissir le statut  : \n");
        printf("1.Valide .\n");
        printf("2.Reporte .\n");
        printf("3.Annule .\n");
        printf("4.Traite .\n");
        int CX ;
        scanf("%d",&CX);
        switch (CX){
            case 1 :
              strcpy(R[NV].statut, "validé");
            break;
            case 2 :
              strcpy(R[NV].statut, "reporté");
            break;
            case 3 :
              strcpy(R[NV].statut, "annulé");
            break;
            case 4 :
              strcpy(R[NV].statut, "traité");
            break;
            default:
              printf("Choix invalide !");

        }

        R[NV].ref = NV + 1; 
        printf("Référence est automatique : %d\n", R[NV].ref);

        printf("Veuillez entrer la date de reservation (jj/mm/aaaa) : ");
        scanf("%s", R[NV].date_reserv);
        NV++; 
        printf("Réservation ajoutée avec succès.\n");
    } else {
        printf("La capacité maximale de réservations est atteinte.\n");
    }
}


// P.2.1 // P.2.2
void modifier_ou_supprimer(){     
    int ref, found = 0;
    printf("Entrez la référence de la réservation pour modifier ou supprimer : ");
    scanf("%d", &ref);
    
    for (int i = 0; i < NV; i++) {
        if (R[i].ref == ref) {
            found = 1;
            int choix;
            printf("Réservation trouvée. votre choix ? \n");
            printf("1. Modifier\n");
            printf("2. Supprimer\n");
            scanf("%d", &choix);
            
            if (choix == 1) {
                printf("Modifier : \n");
                printf("Nouveau nom : ");
                scanf("%s", R[i].nom);
                printf("Nouveau prénom : ");
                scanf("%s", R[i].prenom);
              
            } else if (choix == 2) {
                for (int j = i; j < NV - 1; j++) {
                    R[j] = R[j + 1];  
                }
                NV--;
                printf("Réservation supprimer .\n");
            } else {
                printf("Choix invalid ! \n");
            }
            break;
        }
    }
    if (!found) {
        printf("Aucun reservation trouve avec se reference. \n");
    }
}


// P.3 
void afficher_reservation() {  
    int ref, found = 0;
    printf("Entrez référence de la réservation : ");
    scanf("%d", &ref);

    for (int i = 0; i < NV; i++) {
        if (R[i].ref == ref) {
            found = 1;
            printf("Les info de reservation :\n");
            printf("Nom : %s\n", R[i].nom);
            printf("Prénom : %s\n", R[i].prenom);
            printf("Tele : %s\n", R[i].tele);
            printf("Age : %d\n", R[i].age);
            printf("Statut : %s\n", R[i].statut);
            printf("Reference : %d\n", R[i].ref);
            printf("Date de reserv : %s\n", R[i].date_reserv);
            break;
        }
    }
    if (!found){
        printf("Aucun reservation trouve avec se reference.\n");
    }
}


// 4.1
void trier_nom() {
    RESERV N;
    for (int i = 0; i < NV - 1; i++) {
        for (int j = 0; j < NV - i - 1; j++) {
            if (strcmp(R[j].nom, R[j + 1].nom) > 0) {
                N = R[j];
                R[j] = R[j + 1];
                R[j + 1] = N;
            }
        }
    }
    printf("Réservations triées par nom.\n");
}


// P.4.2 
void trier_statut(){
    RESERV S;
    for (int i = 0; i < NV - 1 ; i++){
        for(int j = 0; j < NV -1 ; i++){
            if (strcmp(R[j].statut,R[j+1].statut) > 0){
                S = R[j];
                R[j] = R[j+1];
                R[j+1] = S ;
            }
        }
    }
    printf("Reservation trie par statut : \n");
}


// 5.1
void recherche_ref(){
    int ref, found = 0;
    printf("Veuillez entrer le referance de reservation : ");
    scanf("%d",&ref);

    for (int i=0;i<NV;i++){
        if(R[i].ref == ref){
            found = 1 ;
            printf("Voilla la reservation : \n");
            printf("Nom : %s\n",R[i].nom);
            printf("Prenom : %s\n",R[i].prenom);
            printf("Tele : %s\n",R[i].tele);
            printf("Age : %d\n",R[i].age);
            printf("Statut : %s\n",R[i].statut);
            printf("Date de reservation : %s\n",R[i].date_reserv);
            break;
        }
    }
    if (!found)
    printf("Aucune reservation trouve !");
}


// 5.2
void recherche_nom(){
    char nom[20];
    int found =0;

    printf("Veuillez entrer le nom de reservation : ");
    scanf("%s",nom);

    for (int i=0;i<NV;i++){
        if(strcmp(R[i].nom,nom)==0){
            found = 1 ;
            printf("Found reservation : ");
            printf("Nom : %s\n",R[i].nom);
            printf("Prenom : %s\n",R[i].prenom);
            printf("Tele : %s\n",R[i].tele);
            printf("Age : %d\n",R[i].age);
            printf("Statue : %s\n",R[i].statut);
            printf("Date de reservation : %s\n",R[i].date_reserv);
        }
    }
    if (!found)
    printf("Aucune reservation trouve !");
}


// 6.1 
float calculer_moyen_age(){
    if ( NV == 0 ){
        printf("Aucune reservation pour traiter ! ");
        return 0;
    }
    int total_age = 0 ;
    for (int i = 0 ; i < NV ; i++){
        total_age = total_age + R[i].age;
    }
    float moyen_age = total_age / NV ;
    printf("La moyennne d'age est : %.2f ans ", &moyen_age);
}


//6.2
void affichage_tranche_age (){
    if ( NV = 0){
        printf("Aucune nombre a afficher ! ");
    }
    int Tr1 = 0 ;    //0-18
    int Tr2 = 0 ;     //19-35  
    int Tr3 = 0 ;    //36++

    for (int i = 0 ; i < NV ; i++){
        if( R[i].age >= 0 && R[i].age <= 18){
            Tr1++;
        }
        else if (R[i].age >= 19 && R[i].age <= 35){
            Tr2++;
        }
        else if (R[i].age >= 36 ){
            Tr3++;
        }
    }
    printf("Nombre de pations pour chaque tranche : \n");
    printf("Pour la tranche entre 0 et 18 : %d ",&Tr1);
    printf("Pour la tranche entre 19 et 35 : %d ",&Tr2);
    printf("Pour la tranche 36+ : %d ",&Tr3);

}


//6.3
void affichage_statut(){
    if ( NV = 0){
        printf("Aucune reservation a traitter ! ");
        return ;
    }
    
    int valide = 0 ;
    int reporte = 0 ;
    int annule = 0 ;
    int traite = 0 ;

    for (int i = 0 ; i < NV ; i++){
        if (strcmp(R[i].statut,"reporte") == 0 ){
            reporte++;
        }else if (strcmp(R[i].statut,"valide") == 0 ){
            valide++;
        }else if (strcmp(R[i].statut,"annule") == 0 ){
            annule++;
        }else if (strcmp(R[i].statut,"traite") == 0 ){
            traite++;
        }
    }

    printf("Nombre total de resrvations par statut : \n");
    printf("Pour reporte : %d .\n",&reporte);
    printf("Pour valide : %d .\n",&valide);
    printf("Pour annule : %d .\n",&annule);
    printf("Pour Traite : %d .\n",&traite);
}



// AFFG_PT2: !!!!!!!!
int main() {

    int choix;
    do {
        printf(" Menu Principal:\n");
        printf("1. Ajouter une reservation .\n");
        printf("2. Modifier ou supprimer une réservation .\n");
        printf("3. Afficher les details de réservation .\n");
        printf("4. Trier les réservations .\n");
        printf("5. Rechercher les réservations .\n");
        printf("6. Statistiques .\n");
        printf("7. Quitter.. !\n");

        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        
        switch (choix) {
            case 1: 
              Ajouter_Reserv(); 
            break;

            case 2: 
              modifier_ou_supprimer(); 
            break;

            case 3: 
              afficher_reservation(); 
            break;

            case 4: {
                int S_choix;
                printf("1. Trier par nom\n");
                printf("2. Trier par statut\n");
                printf("Entrez votre choix : ");
                scanf("%d", &S_choix);

                switch (S_choix) {
                    case 1: 
                      trier_nom(); 
                    break;
                    
                    case 2: 
                      trier_statut(); 
                    break;

                    default: 
                      printf("Choix invalide.\n");
                }
                break;
            }
            case 5: {
                int S_choix;
                printf("1. Recherche par référence\n");
                printf("2. Recherche par nom\n");
                printf("Entrez votre choix : ");
                scanf("%d", &S_choix);

                switch (S_choix) {
                    case 1: 
                      recherche_ref(); 
                    break;

                    case 2: 
                      recherche_nom(); 
                    break;

                    default: 
                      printf("Choix invalide.\n");
                }
                break;
            }
            case 6 : 
              int S_choix ;
              printf("1.Calculer la moyenne d'age de pationts.\n");
              printf("2.Afficher le nombre de patients par tranche d'age.\n");
              printf("3.Le nombre total de reservation par statut.\n");
              scanf("%d",&S_choix);
              switch (S_choix){
                case 1 : 
                  calculer_moyen_age();
                break;
                case 2 :
                  affichage_tranche_age ();
                break;
                case 3 :
                  affichage_statut();
                break;
                default : 
                  printf("Choix invalide !");
              }
            break;

            case 7 : 
              printf("Au revoir!\n"); 
            break;

            default : printf("Choix invalide ! \n");
        }
    } while (choix != 0);

    return 0;
}
