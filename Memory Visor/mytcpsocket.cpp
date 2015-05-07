#include "mytcpsocket.h"

MyTcpSocket::MyTcpSocket(QObject *parent) : QObject(parent)
{

}

MyTcpSocket::~MyTcpSocket()
{

}
void MyTcpSocket::doConnect(QString ip){
     socket = new QTcpSocket(this);
     connect(socket, SIGNAL(connected()),this, SLOT(connected()));
     connect(socket, SIGNAL(disconnected()),this, SLOT(disconnected()));
     connect(socket, SIGNAL(bytesWritten(qint64)),this, SLOT(bytesWritten(qint64)));
     connect(socket, SIGNAL(readyRead()),this, SLOT(readyRead()));
     qDebug() << "connecting...";
     bool use = true;
     while(use){
         try{
                socket->connectToHost(ip,9500);

                if(!socket->waitForConnected(5000))
                    {
                        //qDebug() << "Error: " << socket->errorString();
                        }
                else{
                     use = false;
                }
         }
         catch(int e){
             qDebug()<<"cannot connect";
         }
     }

}
double MyTcpSocket::getData(){

    socket->write("HEAD / HTTP/1.0\r\n\r\n\r\n\r\n");
    data =QString::fromUtf8(socket->readAll());
    QJsonDocument d = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject sett2 = d.object();
    QJsonValue value = sett2.value(QString("UseSize"));
    double pos = value.toDouble();

    return pos/1000;

}
double MyTcpSocket::getToatalSize(){
    QJsonDocument da = QJsonDocument::fromJson(data.toUtf8());
    QJsonObject sett1 = da.object();
    QJsonValue value = sett1.value(QString("TotalSize"));
    double pos =value.toDouble()/1024/1024;



    return pos;
}


void MyTcpSocket::connected()
{
    qDebug() << "connected...";

    // Hey server, tell me about you.
    socket->write("HEAD / HTTP/1.0\r\n\r\n\r\n\r\n");
}
void MyTcpSocket::disconnected()
{
    //qDebug() << "disconnected...";
}

void MyTcpSocket::bytesWritten(qint64 bytes)
{
   // qDebug() << bytes << " bytes written...";
}

void MyTcpSocket::readyRead()
{
   // qDebug() << "reading...";

    // read the data from the socket
   // qDebug() << socket->readAll();
   // QString data = QString::fromUtf8(socket->readAll());
    //return data;
}
