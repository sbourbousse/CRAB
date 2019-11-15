#ifndef STATION_H
#define STATION_H

#include <QString>
#include <QVector>
#include "borne.h"
#include "visite.h"

class Visite;

class Station
{
private:
    int idStation; // identifiant de la station
    QString libelleEmplacement; // libellé de l'emplacement de la station
    QVector<Borne*> lesBornes; // les bornes de la station

public:
    Station(int unIdStation, QString unLibelleEmplacement, QVector<Borne*>desBornes);
    int getId(); // retourne l'identifiant de la station
    QString getLibelleEmplacement(); // retourne le libellé de l'emplacement
    Visite* getLesVisite(); // retourne une instance de classe Visite recensant toutes les bornes de la station qui nécessitent d'être révisées, ou null s'il n'y a aucune borne à réviser
};

#endif // STATION_H
