#include <QCoreApplication>
#include <QTimer>
#include <iostream>
#include <QNetworkRequest>
#include <QNetworkAddressEntry>

int main(int argc, char *argv[])
{
    QNetworkRequest qw;
    QNetworkAddressEntry asd;
    QCoreApplication a(argc, argv);

    std::cout << "Application started.\n";

    QTimer::singleShot(5000, &a, &QCoreApplication::quit);

     return a.exec();
}
