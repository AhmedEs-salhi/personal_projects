#include "main.h"

vehicule* chercher(vehicule *veh, int numPlace)
{
    while(veh)
    {
        if (numPlace == veh->numPlace)
            return (veh);

        veh = veh->suivant;
    }
    return (NULL);
}