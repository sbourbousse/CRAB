#include "visite.h"

/**
 * @brief Visite::Visite Constructeur vide de Visite
 */
Visite::Visite()
{

}

/**
 * @brief Visite::Visite Constructeur de Visite
 * @param unEtat Caractere(QChar) : etat de la visite (p=programmé, a=affecté, r=realisée)
 * @param uneDureeTotale Entier(int) : Duree totale en heure de la visite
 * @param uneStation Classe personnalisée(Station) : Station concerné par la visite
 * @param desBornes Classe personalisée(QVector<Bornes>) : Vecteur de bornes qui necessite une révision (borne(s) de la station)
 */
Visite::Visite(QChar unEtat, int uneDureeTotale, Station *uneStation, QVector<Borne> desBornes)
{
    etat=unEtat;
    dureeTotale=uneDureeTotale;
    laStation=uneStation;
    lesBornes=desBornes;
}

/**
 * @brief Visite::getDureeTotale
 * @return Entier(int) : Duree totale en heure de la visite
 */
int Visite::getDureeTotale()
{
    return dureeTotale;
}

/**
 * @brief Visite::getEtat
 * @return Caractere(QChar) : etat de la visite (p=programmé, a=affecté, r=realisée)
 */
QChar Visite::getEtat()
{
    return etat;
}

/**
 * @brief Visite::changerEtat Procédure qui change l'etat de la visite
 * Passe la visite à l'etat suivant (programmé vers affecté ou affecté vers réalisé)
 */
void Visite::changerEtat()
{
    if(etat=='p')
        etat='a';
    else if(etat=='a')
        etat='r';
}

/**
 * @brief Visite::getInfo Fonction qui renvoie les informations d'une visite
 * @return Chaine(QString) : information au format texte de la visite (Etat,Durée,Station)
 */
QString Visite::getInfo()
{
    QString info = "Etat : \n Durée : "+QString::number(dureeTotale)+"\n Station : "+laStation->getLibelleEmplacement();

    return info;
}

Station *Visite::getStation()
{
    return laStation;
}

QVector<Borne> Visite::getBornes()
{
    return lesBornes;
}
