#ifndef TECHNICIEN_H
#define TECHNICIEN_H

#include <QString>
#include <QVector>
#include "visite.h"

class Technicien
{
private:
    int matricule; // matricule du technicien
    QString nom; // nom du technicien
    QString prenom; // prénom du technicien
    QVector<Visite*> lesVisites; // ensemble des visites affectées au technicien
public:
    Technicien(int unMatricule, QString unNom, QString unPrenom);
    int getTempsOccupe(); // retourne la durée totale en minutes des visites affectées au technicien
    void affecterVisite(Visite* uneVisite); // ajoute la visite uneVisite dans les visites affectées au technicien
    QVector<Visite*> getLesVisites(); // retourne l'ensemble des visites affectées au technicien
    QString getInfo();

};

#endif // TECHNICIEN_H
