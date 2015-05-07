    #ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QObject>
#include <QTcpSocket>
#include <QAbstractSocket>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

class MyTcpSocket : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpSocket(QObject *parent = 0);
    ~MyTcpSocket();
     void doConnect(QString);
     QString data;

signals:


public slots:
     double getToatalSize();
     void connected();
     void disconnected();
     void bytesWritten(qint64 bytes);
     double getData();
     void readyRead();
private:
     QTcpSocket *socket;
};

#endif // MYTCPSOCKET_H
