#ifndef PASSERELLE_H
#define PASSERELLE_H

#include <QSqlQuery>
#include <QString>
#include <QDebug>
#include <QVector>
#include "technicien.h"
#include "station.h"
#include "visite.h"


class Passerelle
{
public:
    static QVector<Technicien *> chargerLesTechniciens();
    static QVector<Station*> chargerLesStations();
};

#endif // PASSERELLE_H
