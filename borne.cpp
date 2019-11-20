#include "borne.h"

Borne::Borne()
{

}

Borne::Borne(int unIdBorne, Date* uneDateDerniereRevision, int unIndiceCompteurUnites, TypeBorne unType)
{
    idBorne = unIdBorne;
    dateDerniereRevision = uneDateDerniereRevision;
    indiceCompteurUnites = unIndiceCompteurUnites;
    leType = unType;
}

int Borne::getDureeRevision()
{
    leType.getDureeRevision();
}

bool Borne::estARevisier()
{
    /*
     * retourne vrai lorsque la borne doit être révisée, soit parce que le temps qui sépare
     * deux révisions pour ce type de borne s'est écoulé depuis la date de la dernière révision,
     * soit parce que le nombre d'unités de recharge délivrées par la borne
     * depuis la dernière révision a atteint le seuil établi pour ce type de borne ;
     * retourne faux sinon
     */
    bool aReviser = false;

    if(Date::aujourdhui()->difference(dateDerniereRevision)>=leType.getNbJoursEntreRevisions())
        aReviser = true;
    else if (indiceCompteurUnites>=leType.getNbUnitesEntreRevisions())
        aReviser = true;

    return aReviser;
}

Borne Borne::getBorne()
{
    return *this;
}
