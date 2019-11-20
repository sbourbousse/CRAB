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
        tempsOccupe += lesVisites[i]->getDureeTotale();
    }

    return tempsOccupe;
}

void Technicien::affecterVisite(Visite* uneVisite)
{
    lesVisites.push_back(uneVisite);
}

QVector<Visite *> Technicien::getLesVisites()
{
    return lesVisites;
}

QString Technicien::getInfo()
{
    QString info = "Matricule : "+QString::number(matricule)+" \n"
            +"Nom : "+nom+"\n"
            +"Prenom : "+prenom+"\n"
            +"Temps occupé : "+QString::number(getTempsOccupe())
            +"PROCHAINE VISITES : ";

    for(int i = 0 ; i<lesVisites.size() ; i++)
    {
        info+= lesVisites[i]->getInfo()+"\n";
    }
    return info;
}


