#ifndef MAINTENANCE_H
#define MAINTENANCE_H

#include <QVector>
#include "passerelle.h"
#include "station.h"
#include "technicien.h"
#include "visite.h"

class Maintenance
{
private:
    QVector<Station> lesStations; // l'ensemble des stations
    QVector<Technicien> lesTechniciens; // l'ensemble des techniciens
    QVector<Visite> lesVisites; // l'ensemble des visites à réaliser
public:
    Maintenance();
    void reviser(); // Etablit l'ensemble des visites à réaliser sur les stations
    void affecterVisites();// Affecte les visites à réaliser aux techniciens, en répartissant équitablement le travail
    // entre les techniciens. Chaque visite est affectée au technicien le moins occupé en temps
    // total de maintenance préventive. L'état de chaque visite doit alors être mis à jour.


};

#endif // MAINTENANCE_H
