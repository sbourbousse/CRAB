#include "typeborne.h"

/**
 * @brief TypeBorne::TypeBorne Constructeur vide de TypeBorne
 * ne pas utiliser
 */
TypeBorne::TypeBorne()
{

}

/**
 * @brief TypeBorne::TypeBorne Constructeur de TypeBorne
 * @param unCodeTypeBorne Chaine(QString) : Code du modele
 * @param uneDureeRevision Entier(int) : Duree en heures de la révision
 * @param unNbJoursEntreRevisions Entier(int) : Nombre de jour entre 2 révisions, une fois de nombre atteint, la borne doit etre révisé
 * @param unNbUnitesEntreRevisions Entier(int) : Nombre de rechargement entre 2 révisions, une fois ce nombre atteint, la borne doit être révisé
 */
TypeBorne::TypeBorne(QString unCodeTypeBorne, int uneDureeRevision, int unNbJoursEntreRevisions, int unNbUnitesEntreRevisions)
{
    codeTypeBorne = unCodeTypeBorne;
    dureeRevision = uneDureeRevision;
    nbJoursEntreRevisions = unNbJoursEntreRevisions;
    nbUnitesEntreRevisions = unNbUnitesEntreRevisions;
}

/**
 * @brief TypeBorne::getDureeRevision
 * @return Entier(int) : duree en heure de la revision de ce type de borne
 */
int TypeBorne::getDureeRevision()
{
    return dureeRevision;
}

/**
 * @brief TypeBorne::getNbJoursEntreRevisions
 * @return Entier(int) : Nombre de jour entre 2 révisions, une fois de nombre atteint, la borne doit etre révisé
 */
int TypeBorne::getNbJoursEntreRevisions()
{
    return nbJoursEntreRevisions;
}

/**
 * @brief TypeBorne::getNbUnitesEntreRevisions
 * @return  Entier(int) : Nombre de rechargement entre 2 révisions, une fois ce nombre atteint, la borne doit être révisé
 */
int TypeBorne::getNbUnitesEntreRevisions()
{
    return nbUnitesEntreRevisions;
}
