--Créé le 13/11/2019 par Sylvain Bourbousse

--Creation de la base de données

drop database if exists CRAB;
create database CRAB;
use CRAB;

--Création de tables

create table type_recharge(
    typeRechargeId smallint unsigned primary key,
    typeRechargeLibelle varchar(64),
    typeRechargePuissance mediumint unsigned 
)engine=innodb charset=utf8;
--en Kw --

create table borne(
    borneId int unsigned primary key,
    borneDateMiseEnService date,
    borneDateDerniereRevision date,
    borneEtat char(2),
    typeBorneId varchar(32) references type_borne(typeBorneId)
)engine=innodb charset=utf8;
 --ES pour En Service , HS pour Hors Service --

 create table type_borne(
     typeBorneId varchar(32) primary key,
     typeBorneDureeRevision smallint unsigned,
     typeBorneNbJourEntreRevision mediumint unsigned,
     typeBorneNbRechargementEntreRevision int unsigned
 )engine=innodb charset=utf8;

create table batterie(
    batterieRef varchar(64),
    batterieCapacite mediumint unsigned,
    batterieFabricant varchar(64)
)engine=innodb charset=utf8;

create table conducteur(
    conducteurId int unsigned primary key,
    conducteurNom varchar(64),
    conducteurPrenom varchar(64),
    conducteurTelPortable char(10),
    conducteurTelFixe char(10),
    conducteurAdresse varchar(128),
    conducteurCodePostale char(5),
    conducteurVille varchar(128)
)engine=innodb charset=utf8;

create table vehicule(
    vehiculeId int unsigned primary key,
    vehiculeImmat varchar(10),
    batterieRef varchar(64) references batterie(batterieRef),
    conducteurId int unsigned references conducteur(conducteurId)
)engine=innodb charset=utf8;

create table reglement(
    reglementId int unsigned primary key,
    dateDernierReglement date,
    reglementMontant float
)engine=innodb charset=utf8;

create table contrat(
    contratId int unsigned primary key,
    vehiculeId int unsigned references vehicule(vehiculeId),
    forfaitType char(1),
    reglementId int unsigned references reglement(reglementId)
)engine=innodb charset=utf8;
--A pour Abonnement, P pour Prepayé --

create table abonnement(
    abonnementDateDebut date,
    abonnementDateFin date,
    abonnementConsommation int unsigned,
    contratId int unsigned references contrat(contratId)
)engine=innodb charset=utf8;

create table prepaye(
    solde int unsigned,
    contratId int unsigned references contrat(contratId)
)engine=innodb charset=utf8;

create table rechargement(
    rechargementId int unsigned primary key,
    borneId int unsigned references borne(borneId),
    contratId int unsigned references contrat(contratId),
    dateHeureDebut datetime,
    dateHeureFin datetime,
    rechargementKiloWattServi smallint unsigned,
    echec bool
)engine=innodb charset=utf8;

create table echec(
    echecId int unsigned primary key,
    echecCauseLibelle varchar(256),
    rechargementId int unsigned references rechargement(rechargementId)
)engine=innodb charset=utf8;

create table station(
    stationId int unsigned primary key,
    stationAdresse varchar(128),
    stationCodePostal char(5),
    stationVille varchar(128),
    stationLongitude double,
    stationLatitude double
)engine=innodb charset=utf8;

create table possede(
    stationId int unsigned references station(stationId),
    borneId int unsigned references borne(borneId)
)engine=innodb charset=utf8;

create table offre(
    typeBorneId varchar(32) references type_borne(typeBorneId),
    typeRechargeId smallint unsigned references type_recharge(typeRechargeId)
)engine=innodb charset=utf8;

create table supporter(
    batterieRef varchar(64) references batterie(batterieRef),
    typeRechargeId smallint unsigned references type_recharge(typeRechargeId)
)engine=innodb charset=utf8;

create table technicien(
    technicienId mediumint unsigned primary key,
    technicienNom varchar(64),
    technicienPrenom varchar(64)
)engine=innodb charset=utf8;

create table type_incident(
    typeIncidentId smallint unsigned primary key,
    typeIncidentDescription varchar(256),
    typeIncidentTempsRepPrevu time
)engine=innodb charset=utf8;

create table incident(
    incidentId int unsigned primary key,
    incidentRemarque varchar(256),
    incidentDateHeureSignalement datetime,
    incidentDateHeureCloture datetime,
    borneId int unsigned references borne(borneId),
    typeIncidentId smallint unsigned references type_incident(typeIncidentId)
)engine=innodb charset=utf8;

create table intervention(
    interventionId int unsigned primary key,
    interventionDateHeureDebut datetime,
    interventionDateHeureFin datetime,
    incidentId int unsigned references incident(incidentId),
    technicienId mediumint unsigned references technicien(technicienId)
)engine=innodb charset=utf8;
