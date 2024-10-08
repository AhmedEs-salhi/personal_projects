#include "main.h"

int estPlaine(parking* list)
{
    vehicule* v;
    int i = 0;

    v = list->premierVeh;
    while(v){
        i++;
        if(i == PARK_MAX)
            return 1;
        v = v->suivant;
    }
    return 0;
}