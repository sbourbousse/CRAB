#ifndef DATE_H
#define DATE_H

#include <QDate>

/**
 * @brief La classe Date
 * herite de la classe QDate
 */
class Date : public QDate
{
private:
    int p_annee;
    int p_mois;
    int p_jour;
public:
    Date();
    Date(int uneAnnee, int unMois, int unJour);
    static Date* aujourdhui();
    int annee();
    int mois();
    int jour();
    int difference(Date *uneDate);
};

#endif // DATE_H
