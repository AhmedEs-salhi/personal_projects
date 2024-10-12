#include "main.h"

void afficherSeulVehicule(vehicule* veh)
{
    int montant;

    if(veh->veType == 0)
        printf("Type de vehicule: Voiture\n");
    else if(veh->veType == 1)
        printf("Type de vehicule: Camion\n");
    printf("Numero d'immatriculation: %s\n", veh->numMat);
    printf("Nombre du place dans le parking: %.2d\n", veh->numPlace);
    printf("Temps du stationnement: ");
    formaterHeure(veh->hrMin.minutes);
    montant = montantPayer(*veh);
    printf("Montant a payer: %.2d Dhs\n", montant);    
}