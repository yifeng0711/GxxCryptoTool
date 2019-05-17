#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//------------------------------------------------------------------
#include <QMainWindow>
#include <Windows.h>
#include <QDebug>

#include "mc_log.h"
//------------------------------------------------------------------
namespace Ui {
class MainWindow;
}
//------------------------------------------------------------------
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QObject *obj, QWidget *parent = 0);
    ~MainWindow();

private:
    

private:
    Ui::MainWindow *ui;


signals:
    void    SignalGetCipher             (QString vPlain,  QString& vCipher);
    void    SignalGetSHA256             (QString vPlain,  QString& vCipher);
    void    SignalGetPlain              (QString vCipher, QString& vPlain);

private slots:
    void 	slot_pushButton_clicked     (void);

};
//------------------------------------------------------------------
#endif // MAINWINDOW_H
//------------------------------------------------------------------
