#include <QtGui/QApplication>
#include <QTextCodec>
#include "mc_kernelwork.h"

#include <QPlastiqueStyle>
//------------------------------------------------------------------
MC_KernelWork* g_KernelWork = 0;
//------------------------------------------------------------------
int main(int argc, char *argv[])
{
    QTextCodec* tCodec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(tCodec);

    qApp->setStyle(new QPlastiqueStyle);    //�����ı��߿�

    //��ʵ��
    HANDLE tMutex = CreateMutexA(0, FALSE, "Global\\{C060D808-103E-4ba9-BB71-D189F8170FC7}");
    if (GetLastError() == ERROR_ALREADY_EXISTS)
    {
        CloseHandle(tMutex);
        tMutex = NULL;
        LOG_ERROR("the instance has already exist");
        return -1;
    }

    QApplication a(argc, argv);

    MC_KernelWork* tKernelWork = GetKernelWork();;

    if(false == tKernelWork->Init())
        return -1;

    if(false == tKernelWork->Start())
        return -1;

    int tRet = a.exec();
    CloseHandle(tMutex);
    tMutex = NULL;

    return tRet;
}
//------------------------------------------------------------------
MC_KernelWork* GetKernelWork()
{
    if(0 == g_KernelWork)
        g_KernelWork = new MC_KernelWork(0);
    return g_KernelWork;
}
//------------------------------------------------------------------