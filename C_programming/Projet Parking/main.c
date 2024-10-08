#include "main.h"

int main()
{
    parking* par = initNode();
    vehicule* veh = par->premierVeh, *tmp;

    int choix;

    do {
        printf("\n------------------MENU---------------------\n");
        printf("Entrer votre choix: \n");
        printf(" 0 - Afficher le contenue du parking.\n");
        printf(" 1 - Ajouter une vehicule.\n");
        printf(" 2 - Suprimmer une vehicule.\n");
        /*A feature that it's not working for now*/
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