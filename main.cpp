#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include "maintenance.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();

    /*
     * CONNEXION A LA BASE DE DONNEE
     */
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("CRAB");
    db.setUserName("root");
    db.setPassword("");
    bool ok = db.open();

    Maintenance *m = new Maintenance;
    m->affecterVisites();
    m->afficherTout();


    return a.exec();
}
