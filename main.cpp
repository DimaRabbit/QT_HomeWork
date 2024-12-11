#include <QCoreApplication>
#include <QTcpSocket>
#include <QSqlDatabase>

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    // Экземпляр класса для работы с сетью
    QTcpSocket socket;
    socket.connectToHost("example.com", 80);
    if (socket.waitForConnected(3000)) {
        qDebug("Connected to server!");
    } else {
        qDebug("Failed to connect.");
    }


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("example.db");
    if (db.open()) {
        qDebug("Database connected!");
    } else {
        qDebug("Failed to connect to database.");
    }

    return a.exec();
}
