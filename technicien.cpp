#include "technicien.h"

/**
 * @brief Technicien::Technicien Constructeur de technicien
 * @param unMatricule Entier(int) : Matricule du technicien
 * @param unNom Chaine(QStirng) : Nom du technicien
 * @param unPrenom Chaine(QString) : Prenom du technicien
 */
Technicien::Technicien(int unMatricule, QString unNom, QString unPrenom)
{
    matricule = unMatricule;
    nom = unNom;
    prenom = unPrenom;
}

/**
 * @brief Technicien::getTempsOccupe Fonction qui renvoie le temps que prends toute les visites à faire du technicien
 * @return Entier(int) : Somme en heure du temps que prendra toute les visites à faire du technicien
 */
int Technicien::getTempsOccupe()
{
    int tempsOccupe = 0;
    for (int i = 0 ; i<lesVisites.size() ; i++)
    {
        tempsOccupe += lesVisites[i]->getDureeTotale();
    }

    return tempsOccupe;
}

/**
 * @brief Technicien::affecterVisite Procédure qui affecte un visite
 * @param uneVisite Classe personnalisée(Visite) : Ajoute une visite au vecteur de visites du Technicien
 */
void Technicien::affecterVisite(Visite* uneVisite)
{
    lesVisites.push_back(uneVisite);
}

/**
 * @brief Technicien::getLesVisites Fonction qui renvoie les visite à faire du technicien
 * @return Classe personnalisée(QVector<Visite>) : Vecteur de visite lesVisites du technicien
 */
QVector<Visite *> Technicien::getLesVisites()
{
    return lesVisites;
}

/**
 * @brief Technicien::getInfo Renvoie au format texte les informations relatives au  technicien
 * @return Chaine(QString) : information du technicien (Matricule,nom,prenom,temps occupé, liste des visites),
 * pour etre utilisé dans un document texte
 */
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

/**
 * @brief Technicien::getMatricule Fonction qui renvoie le matricule du technicien
 * @return Entier(int) : matricule/identifiant du technicien
 */
int Technicien::getMatricule()
{
    return matricule;
}


