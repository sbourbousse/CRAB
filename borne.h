#ifndef BORNE_H
#define BORNE_H

#include "date.h"
#include "typeborne.h"

class Borne
{
private:
    int idBorne; // identifiant de la borne
    Date dateDerniereRevision; // date de la dernière révision effectuée sur la borne
    int indiceCompteurUnites; // nombre d'unités de recharge délivrées depuis la dernière révision, ce compteur étant remis à zéro suite à chaque révision
    TypeBorne* leType; // type de la borne

public:
    Borne(int unIdBorne, Date uneDateDerniereRevision, int unIndiceCompteurUnites, TypeBorne *unType);
    int getDureeRevision(); // retourne la durée en minutes requise pour réaliser la révision sur la borne, cette durée étant fonction du type de la borne
    bool estARevisier();

};

#endif // BORNE_H
