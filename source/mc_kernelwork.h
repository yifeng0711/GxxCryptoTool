#ifndef MC_KERNELWORK_H
#define MC_KERNELWORK_H
//------------------------------------------------------------------
#include <QObject>

#include "mainwindow.h"
//------------------------------------------------------------------
class MC_KernelWork : public QObject
{
    Q_OBJECT
public:
    explicit MC_KernelWork(QObject *parent = 0);
    ~MC_KernelWork();

public:
    bool    Init        (void);
    bool    UnInit      (void);
    bool    Start       (void);
    bool    Stop        (void);

private:
    //function
    bool    MyTest      (void);

private:
    bool            m_Avalible;
    MainWindow*     m_MainWindow;



signals:

private slots:
    void    SlotGetCipher   (QString vPlain,  QString& vCipher);
    void    SlotGetSHA256   (QString vPlain,  QString& vCipher);
    void    SlotGetPlain    (QString vCipher, QString& vPlain);
    
};
//------------------------------------------------------------------
MC_KernelWork* GetKernelWork();
//------------------------------------------------------------------
#endif // MC_KERNELWORK_H
//------------------------------------------------------------------
