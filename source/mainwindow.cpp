#include "mainwindow.h"
#include "ui_mainwindow.h"
//------------------------------------------------------------------
MainWindow::MainWindow(QObject *obj, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("GxxCryptoTool"));

    connect(ui->pushButton_encrypt, SIGNAL(clicked()), this, SLOT(slot_pushButton_clicked()));
    connect(ui->pushButton_decrypt, SIGNAL(clicked()), this, SLOT(slot_pushButton_clicked()));

    connect(this, SIGNAL(SignalGetCipher(QString, QString&)), obj, SLOT(SlotGetCipher(QString, QString&)));
    connect(this, SIGNAL(SignalGetPlain(QString, QString&)), obj, SLOT(SlotGetPlain(QString, QString&)));
}
//------------------------------------------------------------------
MainWindow::~MainWindow()
{
    delete ui;
}
//------------------------------------------------------------------
void MainWindow::slot_pushButton_clicked()
{
    if(sender() == ui->pushButton_encrypt)
    {
        QString tPlain  = ui->lineEdit_plain->text();
        QString tCipher = "";
        emit SignalGetCipher(tPlain, tCipher);

        ui->plainTextEdit_cipher->clear();
        ui->plainTextEdit_cipher->appendPlainText(tCipher);
        return;
    }

    if(sender() == ui->pushButton_decrypt)
    {
        QString tCipher = ui->plainTextEdit_cipher->toPlainText();
        QString tPlain  = "";
        emit SignalGetPlain(tCipher, tPlain);

        ui->lineEdit_plain->clear();
        ui->lineEdit_plain->setText(tPlain);
        return;
    }
}
//------------------------------------------------------------------
