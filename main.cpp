#include <QCoreApplication>
#include <QSqlDatabase>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QUrl>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("database.db");

    if (!db.open())
    {
        qDebug() << "Не удалось открыть базу данных!";
    }
    else
    {
        qDebug() << "База данных успешно открыта.";
    }

    QNetworkAccessManager networkManager;

    QUrl url("https://www.gdtfgr.ru");
    QNetworkRequest request(url);
    networkManager.get(request);

    qDebug() << "Запрос отправлен на:" << url.toString();

    return a.exec();
}
