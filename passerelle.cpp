#include "passerelle.h"

/**
 * @brief Passerelle::chargerLesTechniciens Fonction qui renvoie un vecteur de tout les techniciens de la base de données
 * @return Vecteur de classe personnalisée(QVector<Technicien>) : Tout les techniciens
 */
QVector<Technicien *> Passerelle::chargerLesTechniciens()
{
    QVector<Technicien*> toutLesTechniciens;

    QString recupererLesTechniciens = "select technicienId, technicienNom, technicienPrenom from technicien";
    qDebug()<<recupererLesTechniciens;
    QSqlQuery requeteTechniciens(recupererLesTechniciens);

    while(requeteTechniciens.next())
    {
        toutLesTechniciens.push_back(new Technicien(requeteTechniciens.value("technicienId").toInt(),
                                                requeteTechniciens.value("technicienNom").toString(),
                                                requeteTechniciens.value("technicienPrenom").toString()
                                                ));
    }
    requeteTechniciens.clear();

    return toutLesTechniciens;
}

/**
 * @brief Passerelle::chargerLesStations Fonction qui renvoie toutes les stations
 * @return Vecteur de classe personnalisée(QVector<Station>) : Toutes les stations
 * Récupère toute les station, toute les bornes de chaques station, chaque Type de chaque borne
 */
QVector<Station *> Passerelle::chargerLesStations()
{
    QVector<Station*> touteLesStations;

    QString recupererLesStations = "select stationId, stationAdresse, stationCodePostal, stationVille from station";
    qDebug()<<recupererLesStations;
    QSqlQuery requeteStations(recupererLesStations);

    QString adresseDeStation;
    while(requeteStations.next())
    {
        //Les champs d'adresse de la station sont regroupés en une seul propriété dans la classe station
        adresseDeStation = requeteStations.value("stationAdresse").toString()+" ,"
                           +requeteStations.value("stationCodePostal").toString()+" ,"
                           +requeteStations.value("stationVille").toString();

        //Recuperer toutes les bornes de la station
        QVector<Borne> borneDeLaStation;

        QString recupererLesBornes = "select borne.borneId as borneId, borneDateDerniereRevision, count(*) as nbUnite from possede natural join borne natural join rechargement where possede.stationId="+requeteStations.value("stationId").toString()+" group by borneId";
        qDebug()<<recupererLesBornes;
        QSqlQuery requeteBornes(recupererLesBornes);

        while(requeteBornes.next())
        {
            //Recuperer le type de la borne
            QString recupererLeType = "select typeBorneId, typeBorneDureeRevision, typeBorneNbJourEntreRevision, typeBorneNbRechargementEntreRevision "
                                      "from borne natural join type_borne where borneId="+requeteBornes.value("borneId").toString();
            qDebug()<<recupererLeType;
            QSqlQuery requeteType(recupererLeType);

            requeteType.first();

            borneDeLaStation.push_back(Borne(requeteBornes.value("borneId").toInt(),
                                             new Date(requeteBornes.value("borneDateDerniereRevision").toDate().year(),
                                                  requeteBornes.value("borneDateDerniereRevision").toDate().month(),
                                                  requeteBornes.value("borneDateDerniereRevision").toDate().day()),
                                             requeteBornes.value("nbUnite").toInt(),
                                             TypeBorne(requeteType.value("typeBorneId").toString(),
                                                       requeteType.value("typeBorneDureeRevision").toInt(),
                                                       requeteType.value("typeBorneNbJourEntreRevision").toInt(),
                                                       requeteType.value("typeBorneNbRechargementEntreRevision").toInt())
                                             ));

        }

        touteLesStations.push_back(new Station(requeteStations.value("stationId").toInt(),
                                           adresseDeStation,
                                           borneDeLaStation));

    }
    requeteStations.clear();

    return touteLesStations;
}

/**
 * @brief Passerelle::enregistrerVisite Procédure qui insere une visite et les bornes à reviser dans la base de données
 * @param uneVisite Classe personnalisée(Visite) : la visite à inserer
 * @param unMatricule Entier(int) : matricule du technicien affecté à la visite
 * Enregistre une visite dans la table visite et une ou plusieurs bornes dans la table concerne
 */
void Passerelle::enregistrerVisite(Visite *uneVisite, int unMatricule)
{
    QString etat(uneVisite->getEtat());
    QString date = QString::number(Date::aujourdhui()->year())+"-"+QString::number(Date::aujourdhui()->month())+"-"+QString::number(Date::aujourdhui()->day());
    QString insertVisite = "insert into visite (visiteEtat, visiteDate, stationId, technicienId) "
                           "values (\""+etat+"\",\""+date+"\","+QString::number(uneVisite->getStation()->getId())+","+QString::number(unMatricule)+")";
    qDebug()<<insertVisite;

    QSqlQuery requeteVisite(insertVisite);



    for(int i = 0 ; i<uneVisite->getBornes().size() ; i++)
    {
        QString insertConcerne = "insert into concerne (visiteId,borneId) "
                                 "values ( LAST_INSERT_ID(),"+QString::number(uneVisite->getBornes()[i].getId())+")";

        qDebug()<<insertConcerne;

        QSqlQuery requeteConcerne(insertConcerne);
    }

}

