#include "typeborne.h"

TypeBorne::TypeBorne()
{

}

TypeBorne::TypeBorne(QString unCodeTypeBorne, int uneDureeRevision, int unNbJoursEntreRevisions, int unNbUnitesEntreRevisions)
{
    codeTypeBorne = unCodeTypeBorne;
    dureeRevision = uneDureeRevision;
    nbJoursEntreRevisions = unNbJoursEntreRevisions;
    nbUnitesEntreRevisions = unNbUnitesEntreRevisions;
}

int TypeBorne::getDureeRevision()
{
    return dureeRevision;
}

int TypeBorne::getNbJoursEntreRevisions()
{
    return nbJoursEntreRevisions;
}

int TypeBorne::getNbUnitesEntreRevisions()
{
    return nbUnitesEntreRevisions;
}
