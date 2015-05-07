#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtNetwork>
#include<QTimer>
#include"qcustomplot.h"
#include <QList>
#include "mytcpsocket.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    MyTcpSocket socket;
    Q_OBJECT
    QVector<double>  MemoryHistory,MemoryHistory2;
    int Escale = 9;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setupRealtimeDataDemo(QCustomPlot *customPlot);

    void realtimeData(double value0);
private:
    Ui::MainWindow *ui;
    QTimer dataTimer;
    double rx_value, key_x;
    bool start = false;
    QTcpSocket *client;

private slots:    
    void realtimeDataSlot();
signals:

};

#endif // MAINWINDOW_H
