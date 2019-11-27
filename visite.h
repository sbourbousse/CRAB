#ifndef VISITE_H
#define VISITE_H

#include <QChar>
#include "borne.h"
#include "station.h"

class Station;
/**
 * @brief La classe Visite
 */
class Visite
{
private:
    QChar etat; // état de la visite : 'p' pour programmée, 'a' pour affectée, 'r' pour réalisée
    int dureeTotale; // durée totale en minutes requise pour réaliser l'ensemble des révisions prévues sur les bornes de la station
    Station *laStation; // la station concernée par la visite
    QVector<Borne> lesBornes; // la collection des bornes de laStation concernées par la visite
public:
    Visite();
    Visite(QChar unEtat, int uneDureeTotale, Station *uneStation, QVector<Borne> desBornes);// ce constructeur valorise tous les attributs privés de la classe Visite, y compris l'état et la durée totale de la visite
    int getDureeTotale(); // retourne la durée totale en minutes requise pour réaliser l'ensemble des révisions prévues sur les bornes de la station
    QChar getEtat(); // retourne l'état de la visite
    void changerEtat(); // modifie l'état de la visite, de 'p' programmée à 'a' affectée, ou de 'a' affectée à 'r' réalisée
    QString getInfo();
    Station *getStation();
    QVector<Borne> getBornes();
};

#endif // VISITE_H
