#include <QApplication>
#include <QSqlDatabase>
#include "maintenance.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*
     * CONNEXION A LA BASE DE DONNEE
     */
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("CRAB");
    db.setUserName("root");
    db.setPassword("");
    bool ok = db.open();

    //Creer l'instance Maintenance
    Maintenance *m = new Maintenance;
    //J'affecte les visites au techniciens
    m->affecterVisites();
    //J'affiche les visites avec des qDebug
    m->afficherTout();


    return a.exec();
}
