#include <QCoreApplication>
#include <QTimer>
#include <iostream>
#include <QNetworkRequest>
#include <QNetworkAddressEntry>
#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QSqlDatabase ASD() ;
    QNetworkRequest qw;
    QNetworkAddressEntry asd;
    QCoreApplication a(argc, argv);

    std::cout << "Application started.\n";

    QTimer::singleShot(5000, &a, &QCoreApplication::quit);

     return a.exec();
}
