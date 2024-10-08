#include "main.h"

void affichageParkingVehicules(parking list)
{
    vehicule *veh;
    int montant, i;
    veh = list.premierVeh;

    i = 0;
    while(veh)
    {
        printf("\nVehicule numero %d\n", i + 1);
        printf("-------------------\n");
        if(veh->veType == 0)
            printf("Type de vehicule: Voiture\n");
        else if(veh->veType == 1)
            printf("Type de vehicule: Camion\n");
        printf("Numero d'immatriculation: %s\n", veh->numMat);
        printf("Nombre du place dans le parking: %.2d\n", veh->numPlace);
        printf("Temps du stationnement: ");
        formaterHeure(veh->hrMin.hrs, veh->hrMin.minutes);
        montant = montantPayer(*veh);
        printf("Montant a payer: %.2d Dhs\n", montant);
        veh = veh->suivant;
        i++;
    }
}

void formaterHeure(int h, int minutes)
{
    while(minutes >= 60)
    {
        h++;
        minutes -= 60;
    }
    printf("%.2dh%.2dmin\n", h, minutes);
}