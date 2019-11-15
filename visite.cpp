#include "visite.h"

Visite::Visite()
{

}

Visite::Visite(QChar unEtat, int uneDureeTotale, Station uneStation, QVector<Borne> desBornes)
{
    etat=unEtat;
    dureeTotale=uneDureeTotale;
    laStation=uneStation;
    lesBornes=desBornes;
}

int Visite::getDureeTotale()
{
    return dureeTotale;
}

QChar Visite::getEtat()
{
    return etat;
}

void Visite::changerEtat()
{
    if(etat=='p')
        etat='a';
    else if(etat=='a')
        etat='r';
}
