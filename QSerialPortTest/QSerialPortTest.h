#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QSerialPortTest.h"
#include <qtcpsocket.h>
#include <qtcpserver.h>
#include <QSerialPort>
#include <QSerialPortInfo>

class QSerialPortTest : public QMainWindow
{
    Q_OBJECT

public:
    QSerialPortTest(QWidget *parent = nullptr);
    ~QSerialPortTest();

private:
    Ui::QSerialPortTestClass ui;
    QSerialPort* port;

public slots:
    void onOpenPortButtonClicked();
    void onSerialPortReadyRead();
    void onSendMessageButtonClicked();
};
