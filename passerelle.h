#ifndef PASSERELLE_H
#define PASSERELLE_H

#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QVector>
#include "technicien.h"
#include "station.h"
#include "visite.h"

/**
 * @brief La classe Passerelle
 * récupère les données de la base
 */
class Passerelle
{
public:
    static QVector<Technicien *> chargerLesTechniciens();
    static QVector<Station*> chargerLesStations();
    static void enregistrerVisite(Visite* uneVisite, int unMatricule);
};

#endif // PASSERELLE_H
