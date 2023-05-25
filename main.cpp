#include "mainwindow.h"

#include <QApplication>
#include <QDateTime>
#include <QFile>

QScopedPointer<QFile> logFile;

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    logFile.reset(new QFile("log.txt"));
    logFile.data()->open(QFile::Append | QFile::Text);
    qInstallMessageHandler(messageHandler);

    MainWindow w;
    w.show();
    return a.exec();
}

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QTextStream out(logFile.data());
    out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz ");
    switch(type)
    {
    case QtInfoMsg: out << "INFO "; break;
    case QtDebugMsg: out << "DEBUG "; break;
    case QtWarningMsg: out << "WARNING "; break;
    case QtCriticalMsg: out << "CRIT "; break;
    case QtFatalMsg: out << "FATAL "; break;
    }
    out << context.category << ": " << msg << '\n';
    out.flush();
}
