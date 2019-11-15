#include "technicien.h"

Technicien::Technicien(int unMatricule, QString unNom, QString unPrenom)
{
    matricule = unMatricule;
    nom = unNom;
    prenom = unPrenom;
}

int Technicien::getTempsOccupe()
{
    int tempsOccupe = 0;
    for (int i = 0 ; i<lesVisites.size() ; i++)
    {
        tempsOccupe += tempslesVisites[i].getDureeTotale();
    }

    return tempsOccupe;
}

void Technicien::affecterVisite(Visite uneVisite)
{
    lesVisites.push_back(uneVisite);
}

QVector<Visite> Technicien::getLesVisites()
{
    return lesVisites;
}
