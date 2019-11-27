#include "date.h"
#include <QDebug>

/**
 * @brief Date::Date Constructeur vide de Date
 * ne pas utiliser
 */
Date::Date()
{

}

/**
 * @brief Date::Date Constructeur de Date
 * @param uneAnnee Entier(int) : année au format YYYY
 * @param unMois Entier(int) : mois au format MM
 * @param unJour Entier(int) : jour au format DD
 */
Date::Date(int uneAnnee, int unMois, int unJour) : QDate(uneAnnee,unMois,unJour)
{
    p_annee=uneAnnee;
    p_mois=unMois;
    p_jour=unJour;
}

/**
 * @brief Date::aujourdhui Fonction qui renvoie la date d'aujourd'hui
 * @return Classe personnalisée(Date) : la date d'aujourd'hui
 */
Date *Date::aujourdhui()
{
    return new Date(currentDate().year(),currentDate().month(),currentDate().day());
}

/**
 * @brief Date::annee
 * @return Entier(int) : l'année de la date
 */
int Date::annee()
{
    return p_annee;
}

/**
 * @brief Date::mois
 * @return Entier(int) : le mois de la date
 */
int Date::mois()
{
    return p_mois;
}

/**
 * @brief Date::jour
 * @return Entier(int) : le jour de la date
 */
int Date::jour()
{
    return p_jour;
}

/**
 * @brief Date::difference Fonction qui renvoie la différence entre 2 dates
 * @param uneDate Classe personnalisée(Date) : deuxième date à comparer
 * @return Entier relatif(int) : nombre de jours qui sépare deux dates
 */
int Date::difference(Date* uneDate)
{
    //Différence en jours entre 2 dates
    //Si l'objet est une date plus récente que le parametre , le résultat est positif
    qDebug()<<uneDate->daysTo(*this);
    return uneDate->daysTo(*this);
    //return (- daysTo(uneDate));
}
