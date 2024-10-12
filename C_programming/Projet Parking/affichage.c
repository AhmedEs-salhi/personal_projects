#include "main.h"

void affichageParkingVehicules(parking list)
{
    vehicule *veh;
    int i;
    veh = list.premierVeh;

    i = 0;
    while(veh)
    {
        printf("\nVehicule numero %d\n", i + 1);
        printf("-------------------\n");
        afficherSeulVehicule(veh);
        veh = veh->suivant;
        i++;
    }
}

void formaterHeure(int minutes)
{
    int h = 0;
    while(minutes >= 60)
    {
        h++;
        minutes -= 60;
    }
    printf("%.2dh%.2dmin\n", h, minutes);
}