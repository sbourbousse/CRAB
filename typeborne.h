#ifndef TYPEBORNE_H
#define TYPEBORNE_H

#include <QString>

/**
 * @brief La classe TypeBorne
 */
class TypeBorne
{
private:
    QString codeTypeBorne; // code du type de borne
    int dureeRevision; // durée en minutes requise pour réaliser la révision sur les bornes de ce type
    int nbJoursEntreRevisions; // nombre de jours qui séparent deux révisions successives d'une borne de ce type
    int nbUnitesEntreRevisions;     // nombre d'unités de recharge au-delà duquel il faut envisager une nouvelle révision


public:
    TypeBorne();
    TypeBorne(QString unCodeTypeBorne, int uneDureeRevision, int unNbJoursEntreRevisions, int unNbUnitesEntreRevisions);
    int getDureeRevision();    // retourne la durée en minutes requise pour réaliser la révision sur les bornes de ce type
    int getNbJoursEntreRevisions(); // retourne le nombre de jours au-delà duquel il faut envisager une révision sur les bornes de ce type
    int getNbUnitesEntreRevisions(); // retourne le nombre d'unités de recharge au-delà duquel il faut envisager une révision sur les bornes de ce type


};

#endif // TYPEBORNE_H
