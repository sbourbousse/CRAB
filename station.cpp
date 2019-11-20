#include "station.h"

Station::Station(int unIdStation, QString unLibelleEmplacement, QVector<Borne> desBornes)
{
    idStation = unIdStation;
    libelleEmplacement = unLibelleEmplacement;
    lesBornes = desBornes;
}

int Station::getId()
{
    return idStation;
}

QString Station::getLibelleEmplacement()
{
    return libelleEmplacement;
}

Visite * Station::getLesVisite()
{
    QVector<Borne> bornesAReviser;

    bool aucuneRevision = true;
    int dureeTotalRevision = 0;

    for (int i = 0 ; i<lesBornes.size() ; i++)
    {
        if(lesBornes[i].estARevisier())
        {
            dureeTotalRevision += lesBornes[i].getDureeRevision();
            bornesAReviser.push_back(lesBornes[i].getBorne());
            aucuneRevision=false;
        }
    }

    Visite *maVisite = new Visite('p',dureeTotalRevision,this,bornesAReviser);
            //maVisite('p',dureeTotalRevision,this,bornesAReviser);

    if(!aucuneRevision)
        return maVisite;
    else
        return NULL;

}

