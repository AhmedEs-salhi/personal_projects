#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#define MAT_MAX 10
#define PARK_MAX 8
#define VOITURE_MAX 5
#define CAMION_MAX 3

typedef struct heure heure;
typedef struct vehicule vehicule;
typedef struct Parking parking;

typedef enum Type
{
    VOITURE = 0,
    CAMION = 1
}type;

struct heure
{
    int hrs;
    int minutes;
};

struct vehicule
{
    type veType;
    heure hrMin;
    char numMat[MAT_MAX];
    int numPlace;
    int payement;
    vehicule *suivant;
};

struct Parking
{
    vehicule *premierVeh;
    int nbCamion;
    int nbVoiture;
};

void saisieVehicule(parking*);
parking* initNode();
void affichageParkingVehicules(parking);
void formaterHeure(int, int);
int estPlaine(parking*);
void statVehicule(parking*);
int montantPayer(vehicule);
void quiterParking(parking*);
int chercher(int);
void afficherSeulVehicule(vehicule *veh);

#endif