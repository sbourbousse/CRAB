#include "station.h"

/**
 * @brief Station::Station Constructeur de Station
 * @param unIdStation Entier(int) : Identifiant de la station
 * @param unLibelleEmplacement Chaine(QString) : Adresse de la station (rue, codePostale, Ville)
 * @param desBornes Classe personnalisée(QVector<Borne>) : Toutes les bornes de la station
 */
Station::Station(int unIdStation, QString unLibelleEmplacement, QVector<Borne> desBornes)
{
    idStation = unIdStation;
    libelleEmplacement = unLibelleEmplacement;
    lesBornes = desBornes;
}

/**
 * @brief Station::getId
 * @return Entier(int) : Identifiant de la station
 */
int Station::getId()
{
    return idStation;
}

/**
 * @brief Station::getLibelleEmplacement
 * @return Chaine(QString) : Adresse de la station
 */
QString Station::getLibelleEmplacement()
{
    return libelleEmplacement;
}

/**
 * @brief Station::getLesVisite Fonction qui renvoie une instance de la classe si au moins une borne est à réviser
 * @return Classe personnalisée(Visite) : pointeur de visite ou NULL
 * Verifie chaque borne de la station, est elle à reviser, memorise les bornes à reviser et la somme du temps necessaire à la revision
 * de toutes les bornes pour le mettre dans le constructeur
 */
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

