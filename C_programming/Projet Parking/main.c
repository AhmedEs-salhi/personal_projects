#include "main.h"

int main()
{
    parking* par = initNode();
    vehicule* veh = par->premierVeh, *tmp;
    vehicule *vehAChercher;

    int choix, numPlaceSaisie;

    do {
        /**
         * work to do the next time you implement on this project:
         * 
         * >> YOU MUST WORK ON THE SEARCH FUNCTION THAT WILL SHOW
         * YOU WETHER THE VEHICULE EXISTS OR NOT AND SHOW ITS
         * INFOS IF IT EXISTED
         */
        

        printf("\n------------------MENU---------------------\n");
        printf("Entrer votre choix: \n");
        printf(" 0 - Afficher le contenue du parking.\n");
        printf(" 1 - Ajouter une vehicule.\n");
        printf(" 2 - Suprimmer une vehicule.\n");
        /**
         * -> 3rd choice working just fine
         * **/
        printf(" 3 - Chercher une vehicule.\n");
        printf("-1 - Exit.\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        if(choix == 0)
        {
            if (par->premierVeh == NULL)
            {
                printf("\n------------------VIDE---------------------\n");
                printf("Le parking est deja vide\n");
            }
            else
                affichageParkingVehicules(*par);
        }

        if(choix == 1)
            saisieVehicule(par);

        if(choix == 2)
        {
            if (par->premierVeh == NULL)
            {
                printf("\n------------------VIDE---------------------\n");
                printf("Le parking est deja vide\n");                
            }
            else
                quiterParking(par);
        }

        if (choix == 3)
        {
            printf("\n------------------SAISIE---------------------\n");
            printf("Entrer le nombre de place de votre vehicule: ");
            scanf("%d", &numPlaceSaisie);
            if (numPlaceSaisie > PARK_MAX)
            {
                printf("\n------------------ERREUR---------------------\n");
                printf("Tu depasser la taille maximale du parking\n\n"); 
                continue;
            }
            vehAChercher = chercher(par->premierVeh, numPlaceSaisie);
            if (vehAChercher)
            {
                printf("\n------------------EXIST---------------------\n");
                printf("Votre vehicule exist dans le parking\n");
                printf("\n------------------VEHICULE INFOS---------------------\n");
                afficherSeulVehicule(vehAChercher);
            }
            else if(!vehAChercher)
            {
                printf("\n------------------N'EXIST PAS---------------------\n");
                printf("votre vehicule n'existe pas dans le parking\n");
            }
        }

        /*Ending the tests shit*/

        else if((choix != 0) && (choix != 1) && (choix != 2) && (choix != 3) && (choix != -1))
        {
            printf("\n------------------ERREUR---------------------\n");
            printf("Ce choix n'existe pas\n\n");
        }

    }while(choix != -1);
    printf("\n------------------AU REVOIR---------------------\n");
    printf("Merci pour votre visite\n");

    while(veh)
    {
        tmp = veh;
        veh = veh->suivant;
        free(tmp);
    }
    free(par);

    return 0;
}