#include "main.h"

parking* initNode()
{
    parking* l = malloc(sizeof(parking));
    l->premierVeh = NULL;

    return l;
}

void saisieVehicule(parking* list)
{
    vehicule* veh = malloc(sizeof(vehicule));

    printf("\nVehicule numero \n");
    printf("-------------------\n");
    printf("Entrer le type de votre vehicule\n");
    printf("0 pour voiture, 1 pour camion: ");
    scanf("%u", &veh->veType);
    printf("Entrer le numero d'immatriculation de votre vehicule: ");
    scanf("%s", veh->numMat);
    printf("Entrer le numero dans le parking: ");
    scanf("%d", &veh->numPlace);
    printf("Entrer le temps du stationnement (en minutes): ");
    scanf("%d", &veh->hrMin.minutes);
    veh->suivant = NULL;

    if(veh->veType == 0)
        list->nbVoiture++;
    else if(veh->veType == 1)
        list->nbCamion++;

    if(list->premierVeh == NULL)
        list->premierVeh = veh;
    else
    {
        vehicule* current = list->premierVeh;
        while(current->suivant)
        {
            current = current->suivant;
        }
        current->suivant = veh;
    }
}