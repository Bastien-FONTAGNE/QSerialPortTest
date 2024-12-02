#include "QSerialPortTest.h"
#include <qlistview.h>
QSerialPortTest::QSerialPortTest(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();

    for (int i = 0; i < availablePorts.size(); i++)
    {
        QSerialPortInfo info = availablePorts[i];
        ui.portComboBox->addItem(info.portName(), QVariant(info.portName()));
    }

}

QSerialPortTest::~QSerialPortTest()
{}

void QSerialPortTest::onOpenPortButtonClicked()
{
    if (ui.portComboBox->currentIndex() >= 0)
    {
        port = new QSerialPort(ui.portComboBox->currentText());
        QObject::connect(port, SIGNAL(readyRead()), this, SLOT(onSerialPortReadyRead()));
        port->setBaudRate(9600);
        port->setDataBits(QSerialPort::DataBits::Data8);
        port->setParity(QSerialPort::Parity::NoParity);
        port->setStopBits(QSerialPort::StopBits::OneStop);
        if (port->open(QIODevice::OpenModeFlag::ExistingOnly | QIODevice::OpenModeFlag::ReadWrite));
        {
            ui.portStatusLabel->setText("Status port: Ouvert");
        }
    }
}

void QSerialPortTest::onSerialPortReadyRead()
{
    QByteArray data = port->read(port->bytesAvailable());
    QString str(data);
    ui.receivedDataText->insertPlainText(str);
    
}

void QSerialPortTest::onSendMessageButtonClicked()
{
    if (port->isOpen())
    {
        QString messageClient = ui.lineEdit->text();
        port->write(messageClient.toStdString().c_str());

        ui.receivedDataText->insertPlainText(messageClient);
    }

    

}
