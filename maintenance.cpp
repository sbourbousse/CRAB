#include "maintenance.h"

/**
 * @brief Maintenance::Maintenance Constructeur de Maintenance
 */
Maintenance::Maintenance()
{
    lesStations = Passerelle::chargerLesStations();
    lesTechniciens = Passerelle::chargerLesTechniciens();
    //Rempli le vecteur de visites lesVisites
    reviser();
}

/**
 * @brief Maintenance::reviser Procédure qui rempli le vecteur de Visite
 * Rempli l'ensemble des visites à réaliser selon si dans chaque station, il ya une ou plusieurs bornes à réviser
 */
void Maintenance::reviser()
{
    // Etablit l'ensemble des visites à réaliser sur les stations
    for(int i = 0 ; i<lesStations.size() ; i++)
    {
        if(!(lesStations[i]->getLesVisite()==NULL))
            lesVisites.push_back(lesStations[i]->getLesVisite());
    }
}

/**
 * @brief Maintenance::affecterVisites Procédure qui repartie equitablement les visites au techniciens
 * Chaque visite est affectée au technicien le moins occupé en temps total de maintenance préventive.
 * L'état de chaque visite doit alors être mis à jour.
 */
void Maintenance::affecterVisites()
{
    // Affecte les visites à réaliser aux techniciens, en répartissant équitablement le travail
    // entre les techniciens. Chaque visite est affectée au technicien le moins occupé en temps
    // total de maintenance préventive. L'état de chaque visite doit alors être mis à jour.

    bool permutation;

    for(int i = 0 ; i<lesVisites.size() ; i++)
    {
        //Trie des Techniciens
        do
        {
            permutation=false;
            for(int noCase=0 ; noCase<lesTechniciens.size()-1 ; noCase++)
            {
                if(lesTechniciens[noCase]->getTempsOccupe()>lesTechniciens[noCase+1]->getTempsOccupe())
                {
                    Technicien *permutationTemp;
                    permutationTemp=lesTechniciens[noCase];
                    lesTechniciens[noCase]=lesTechniciens[noCase+1];
                    lesTechniciens[noCase+1]=permutationTemp;
                    permutation=true;
                }
            }
        }
        while(permutation);

        //On attribut la visite au technicien en bas du tableau (avec le moins d'heure)
        lesTechniciens[0]->affecterVisite(lesVisites[i]);
        lesVisites[i]->changerEtat();

        //Enregistrer la visite dans la base de donées
        Passerelle::enregistrerVisite(lesVisites[i],lesTechniciens[0]->getMatricule());
    }

}

/**
 * @brief Maintenance::afficherTout
 */
void Maintenance::afficherTout()
{
    for (int i = 0 ; i<lesTechniciens.size() ; i++)
    {
        qDebug()<<lesTechniciens[i]->getInfo();
    }
}


