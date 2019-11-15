#include "maintenance.h"

Maintenance::Maintenance()
{
    lesStations = Passerelle::chargerLesStations();
    lesTechniciens = Passerelle::chargerLesTechniciens();
    reviser();
}

void Maintenance::reviser()
{
    // Etablit l'ensemble des visites à réaliser sur les stations
    for(int i = 0 ; i<lesStations.size() ; i++)
    {
        lesVisites.push_back(lesStations[i].getLesVisite());
    }
}

void Maintenance::affecterVisites()
{
    // Affecte les visites à réaliser aux techniciens, en répartissant équitablement le travail
    // entre les techniciens. Chaque visite est affectée au technicien le moins occupé en temps
    // total de maintenance préventive. L'état de chaque visite doit alors être mis à jour.

    for(int i = 0 ; i<lesVisites.size() ; i++)
    {
        //Trie des Techniciens
        do
        {
            permutation=false;
            for(int noCase=0 ; noCase<lesTechniciens.size()-1 ; noCase++)
            {
                if(lesTechniciens[noCase].getTempsOccupe()>lesTechniciens[noCase+1].getTempsOccupe())
                {
                    Technicien permutationTemp;
                    permutationTemp=lesTechniciens[noCase];
                    lesTechniciens[noCase]=lesTechniciens[noCase+1];
                    lesTechniciens[noCase+1]=permutationTemp;
                    permutation=true;
                }
            }
        }
        while(permutation);

        //On attribut la visite au technicien en bas du tableau (avec le moins d'heure)
        lesTechniciens[0].affecterVisite(lesVisites[i]);
        lesVisites[i].changerEtat();
    }

}


