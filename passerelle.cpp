#include "passerelle.h"

QVector<Technicien> Passerelle::chargerLesTechniciens()
{
    QVector<Technicien> toutLesTechniciens;

    QString recupererLesTechniciens = "select technicienId, technicienNom, technicienPrenom from technicien";
    qDebug()<<recupererLesTechniciens;
    QSqlQuery requeteTechniciens(recupererLesTechniciens);

    while(requeteTechniciens.next())
    {
        toutLesTechniciens.push_back(Technicien(requeteTechniciens.value("technicienId").toInt(),
                                                requeteTechniciens.value("technicienNom").toString(),
                                                requeteTechniciens.value("technicienPrenom").toString()
                                                ));
    }
    requeteTechniciens.clear();

    return toutLesTechniciens;
}

QVector<Station> Passerelle::chargerLesStations()
{
    QVector<Station> touteLesStations;

    QString recupererLesStations = "select stationId, stationAdresse, stationCodePostale, stationVille from station";
    qDebug()<<recupererLesStations;
    QSqlQuery requeteStations(recupererLesStations);

    QString adresseDeStation;
    while(requeteStations.next())
    {
        //Les champs d'adresse de la station sont regroupés en une seul propriété dans la classe station
        adresseDeStation = recupererLesStations.value("stationAdresse").toString()+" ,"
                           +recupererLesStations.value("stationCodePostale").toString()+" ,"
                           +recupererLesStations.value("stationVille").toString();

        //Recuperer toutes les bornes de la station
        QVector<Borne> borneDeLaStation;

        QString recupererLesBornes = "select borne.borneId, borneDateDerniereRevision, count(rechargement.borneId) as nbUnite from possede natural join borne natural join rechargement where possede.stationId="+requeteStations.value("stationId").toString();
        qDebug()<<recupererLesBornes;
        QSqlQuery requeteBornes(recupererLesBornes);

        while(requeteBornes.next)
        {
            //Recuperer le type de la borne
            QString recupererLeType = "select typeBorneId, typeBorneDureeRevision, typeBorneNbJourEntreRevision, typeBorneNbRechargementEntreRevision from borne natural join type_borne where borneId="+requeteBornes.value("borne.borneId").toString();
            qDebug()<<recupererLeType;
            QSqlQuery requeteType(recupererLeType);

            requeteType.first();

            borneDeLaStation.push_back(Borne(requeteBornes.value("borne.borneId").toInt(),
                                             Date(requeteBornes.value("borneDateDerniereRevision").toDate().year(),
                                                  requeteBornes.value("borneDateDerniereRevision").toDate().month(),
                                                  requeteBornes.value("borneDateDerniereRevision").toDate().day()),
                                             requeteBornes.value("nbUnite").toInt(),
                                             TypeBorne(requeteLeType.value("typeBorneId").toString(),
                                                       requeteLeType.value("typeBorneDureeRevision").toInt(),
                                                       requeteLeType.value("typeBorneNbJourEntreRevision").toInt(),
                                                       requeteLeType.value("typeBorneNbRechargementEntreRevision").toInt()),
                                             ));

        }

        touteLesStations.push_back(Station(requeteStation.value("stationId").toInt(),
                                           adresseDeStation,
                                           borneDeLaStation));

    }
    requeteStations.clear();

    return touteLesStations;
}

