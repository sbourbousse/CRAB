#include "borne.h"

/**
 * @brief Borne::Borne Constructeur vide de Borne
 * ne pas utiliser
 */
Borne::Borne()
{

}

/**
 * @brief Borne::Borne Constructeur de Borne
 * @param unIdBorne Entier(int) : Identifiant de la borne
 * @param uneDateDerniereRevision Classe personnalisée(Date) : Date de la dernière révision de la borne
 * @param unIndiceCompteurUnites Entier(int) : Nombre de recharge offert par la borne depuis sa dernière révision
 * @param unType Classe personnalisée(typeBorne) : Instance de la classe du type de la borne
 */
Borne::Borne(int unIdBorne, Date* uneDateDerniereRevision, int unIndiceCompteurUnites, TypeBorne unType)
{
    idBorne = unIdBorne;
    dateDerniereRevision = uneDateDerniereRevision;
    indiceCompteurUnites = unIndiceCompteurUnites;
    leType = unType;
}

/**
 * @brief Borne::getDureeRevision
 * @return Entier(int) : Duree en heures de la révision préconisé par le type de la borne
 */
int Borne::getDureeRevision()
{
    leType.getDureeRevision();
}

/**
 * @brief Borne::estARevisier Fonction booleenne, la borne doit elle être révisé
 * @return Booleen(bool) : Vrai si la borne est à réviser , faux si la borne n'a pas à être révisé
 */
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

    //Si la borne n'a pas été révisé depuis un nombre de jours superieur ou égal au nombre de jour préconisé par son type
    if(Date::aujourdhui()->difference(dateDerniereRevision)>=leType.getNbJoursEntreRevisions())
        aReviser = true;
    //Si la borne a été utilisé un nombre de fois superieur ou égal au nombre de jour préconisé par son type
    else if (indiceCompteurUnites>=leType.getNbUnitesEntreRevisions())
        aReviser = true;

    return aReviser;
}

/**
 * @brief Borne::getBorne
 * @return Classe personnalisée(Borne) : la Borne courant
 */
Borne Borne::getBorne()
{
    return *this;
}

int Borne::getId()
{
    return idBorne;
}
