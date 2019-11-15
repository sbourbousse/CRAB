#include "date.h"

Date::Date()
{

}

Date::Date(int uneAnnee, int unMois, int unJour)
{
    p_annee=uneAnnee;
    p_mois=unMois;
    p_jour=unJour;
}

Date Date::aujourdhui()
{
    return Date(currentDate().year(),currentDate().month(),currentDate.day());
}

int Date::annee()
{
    return p_annee;
}

int Date::mois()
{
    return p_mois;
}

int Date::jour()
{
    return p_jour;
}

int Date::difference(Date uneDate)
{
    //Différence en jours entre 2 dates

    //Si l'objet est une date plus récente que le parametre , le résultat est positif
    return uneDate.daysTo(Date);
}
