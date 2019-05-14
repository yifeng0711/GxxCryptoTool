#include "mc_kernelwork.h"
#include <QApplication>

#include "GxxGmCryptoEx/include/libGxxGmCryptoEx.h"
#ifdef _DEBUG
#pragma comment(lib, "GxxGmCryptoEx/bin/debug/libGxxGmCryptoExd.lib")
#else
#pragma comment(lib, "GxxGmCryptoEx/bin/release/libGxxGmCryptoEx.lib")
#endif
//------------------------------------------------------------------
MC_KernelWork::MC_KernelWork(QObject *parent) :
    QObject(parent)
{
    m_Avalible = false;
    m_MainWindow = NULL;
}
//------------------------------------------------------------------
MC_KernelWork::~MC_KernelWork()
{
    UnInit();
}
//------------------------------------------------------------------
bool MC_KernelWork::Init()
{
    if(true == m_Avalible)
        return true;

    //�������������Ӧ�ۺ���
    //�������������init����

    m_MainWindow    = new MainWindow(this, 0);
//    if(false == connect(this, SIGNAL(SignalStatus(QString)), m_MainWindow, SLOT(slotInfo(QString))))
//    {
//        LOG_ERROR("connect signal SignalStatus fail");
//        return false;
//    }



    m_Avalible = true;
    return true;
}
//------------------------------------------------------------------
bool MC_KernelWork::UnInit()
{
    if(false == m_Avalible)
        return true;

    Stop();

    if(NULL != m_MainWindow)
        delete m_MainWindow;

    m_Avalible = false;
    return true;
}
//------------------------------------------------------------------
bool MC_KernelWork::Start()
{
    if(false == m_Avalible)
        return false;

    //����UI����ʼִ�в���
    m_MainWindow->show();


    return true;
}
//------------------------------------------------------------------
bool MC_KernelWork::Stop()
{
    if(false == m_Avalible)
        return false;

    //���̵߳�

    return true;
}
//------------------------------------------------------------------
bool MC_KernelWork::MyTest(void)
{
    //���Խӿ�

    return true;
}
//------------------------------------------------------------------
void MC_KernelWork::SlotGetCipher(QString vPlain, QString &vCipher)
{
    QString tCertPath   = QApplication::applicationDirPath() + "\\libGxxGmCryptoHelper.dll";
    QString tCertPin    = "123456";

    libGxxGmCryptoEx tCrypto;
    std::string tCipher = "";
    tCrypto.EncryptPin_v1(vPlain.toStdString(), tCipher, tCertPath.toStdString(), tCertPin.toStdString());

    vCipher = QString::fromStdString(tCipher);
}
//------------------------------------------------------------------
void MC_KernelWork::SlotGetPlain(QString vCipher, QString &vPlain)
{
    QString tCertPath   = QApplication::applicationDirPath() + "\\libGxxGmCryptoHelper.dll";
    QString tCertPin    = "123456";

    libGxxGmCryptoEx tCrypto;
    std::string tPlain = "";
    tCrypto.DecryptPin_v1(vCipher.toStdString(), tPlain, tCertPath.toStdString(), tCertPin.toStdString());

    vPlain = QString::fromStdString(tPlain);
}
//------------------------------------------------------------------

