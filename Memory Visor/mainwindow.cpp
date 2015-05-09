#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupRealtimeDataDemo(ui->customPlot);

    foreach (const QHostAddress &address, QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress(QHostAddress::LocalHost))

             socket.doConnect(address.toString());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setupRealtimeDataDemo(QCustomPlot *customPlot){
    customPlot->addGraph(); // blue line
    customPlot->graph(0)->setPen(QPen(Qt::blue));
    customPlot->graph(0)->setBrush(QBrush(QColor(240, 255, 200)));
    customPlot->graph(0)->setAntialiasedFill(false);


    customPlot->addGraph(); // blue dot
    customPlot->graph(1)->setPen(QPen(Qt::blue));
    customPlot->graph(1)->setLineStyle(QCPGraph::lsNone);
    customPlot->graph(1)->setScatterStyle(QCPScatterStyle::ssDisc);


    customPlot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    customPlot->xAxis->setDateTimeFormat("ss");
    customPlot->xAxis->setAutoTickStep(true);
  //  customPlot->xAxis->setTickStep(2);
    customPlot->axisRect()->setupFullAxesBox();

    // make left and bottom axes transfer their ranges to right and top axes:
      connect(customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->xAxis2, SLOT(setRange(QCPRange)));
    connect(customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), customPlot->yAxis2, SLOT(setRange(QCPRange)));

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    dataTimer.start(50); // Interval 0 means to refresh as fast as possible
}






void MainWindow::realtimeDataSlot(){

    // calculate two new data points:
    #if QT_VERSION < QT_VERSION_CHECK(4, 7, 0)
     // double key = 0;

    #else
      double key = QDateTime::currentDateTime().toMSecsSinceEpoch()/1000.0;
         double data = socket.getData();
         ui->label_2->setText("Total Memory: "+QString::number(socket.getToatalSize())+"KB");
         ui->label_3->setText("Actual memory use: "+QString::number(data)+"KB");
         double totalSize = socket.getToatalSize();

         //ui->label->setText("Total Memory in Vheap: "<< totalSize << "Mb");


    #endif
      //static double lastPointKey = 0;
   //   if (key-lastPointKey > 0.01) // at most add point every 10 ms
    //  {
        //double value0 = qSqrt(key_x); //qSin(key*1.6+qCos(key*1.7)*2)*10 + qSin(key*1.2+0.56)*20 + 26;
        //key_x = qSqrt(key_x);
        // add data to lines:
        ui->customPlot->graph(0)->addData(key, data);

        // set data of dots:
        ui->customPlot->graph(1)->clearData();
        ui->customPlot->graph(1)->addData(key, data);

        // remove data of lines that's outside visible range:
        ui->customPlot->graph(0)->removeDataBefore(key-8);
        ui->customPlot->graph(1)->removeDataBefore(key-8);
        // rescale value (vertical) axis to fit the current data:
        ui->customPlot->graph(0)->rescaleValueAxis();
        ui->customPlot->graph(1)->rescaleValueAxis();
      //  lastPointKey = key;
    //  }
      // make key axis range scroll with the data (at a constant range size of 8):
      ui->customPlot->xAxis->setRange(key+0.25, 8, Qt::AlignRight);
      ui->customPlot->replot();



      }


