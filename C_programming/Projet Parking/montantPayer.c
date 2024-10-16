#include "main.h"

int montantPayer(vehicule v)
{
    int montant;
    montant = 0;

    while(v.hrMin.minutes > 60){
        if(v.veType == 0)
            montant += 5;
        else if(v.veType == 1)
            montant += 10;
        v.hrMin.minutes -= 60;
    }
    if(v.hrMin.minutes / 30 >= 1){
        if (v.veType == 0)
            montant += 5;
        else if (v.veType == 1)
            montant += 10;
    }

    return montant;
}