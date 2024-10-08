#include "main.h"

void statVehicule(parking* p)
{
    vehicule* v, *pourStationer;
    pourStationer = malloc(sizeof(vehicule));

    v = p->premierVeh;
    while(v->suivant)
    {
        v = v->suivant;
    }

    printf("Entrer le type de votre vehicule\n");
    printf("0 pour voiture, 1 pour camion: ");
    scanf("%u", &pourStationer->veType);

    if(v->veType == 0){
        if (p->nbVoiture == VOITURE_MAX && p->nbCamion <= CAMION_MAX / 2){
            v->suivant = pourStationer;
            printf("Entrer le numero d'immatriculation de votre vehicule: ");
            scanf("%s", pourStationer->numMat);
            printf("Entrer le numero dans le parking: ");
            scanf("%d", &pourStationer->numPlace);
            printf("Entrer le temps du stationnement (en minutes): ");
            scanf("%d", &pourStationer->hrMin.minutes);
            printf("Une nouvelle voiture a etait stationnee.\n");
        }
        else
            printf("Tu peut pas stationer votre voiture.\n");
    }
    else if(v->veType == 1){
        if(p->nbCamion < CAMION_MAX){
            v->suivant = pourStationer;
            printf("Entrer le numero d'immatriculation de votre vehicule: ");
            scanf("%s", pourStationer->numMat);
            printf("Entrer le numero dans le parking: ");
            scanf("%d", &pourStationer->numPlace);
            printf("Entrer le temps du stationnement (en minutes): ");
            scanf("%d", &pourStationer->hrMin.minutes);
            printf("Une nouveau camion a etait stationnee.\n");
        }
        else
            printf("Tu peut pas stationer votre camion\n");
    }
    pourStationer->suivant = NULL;
}