#include "main.h"

vehicule* chercher(vehicule *veh, int numPlace)
{
    while(veh)
    {
        if(numPlace == veh->numPlace)
            return (veh);

        veh = veh->suivant;
    }
    return (NULL);
}

void quiterHeadParking(parking *head, vehicule* vehASupp)
{     
    head->premierVeh = vehASupp->suivant;
    vehASupp->suivant = NULL;
    free(vehASupp);
}

void quiterHeadTailParking(parking* head, vehicule *vehASupp)
{
    vehicule *prevVeh;

    prevVeh = head->premierVeh;
    while(prevVeh->suivant->numPlace != vehASupp->numPlace)
        prevVeh = prevVeh->suivant;

    if (vehASupp->suivant == NULL)
    {
        prevVeh->suivant = NULL;
        free(vehASupp);
    }
    else if (vehASupp->suivant != NULL)
    {
        prevVeh->suivant = vehASupp->suivant;
        vehASupp->suivant = NULL;
        free(vehASupp);
    }
}