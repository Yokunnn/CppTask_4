#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "synonymtable.h"

#include <QMainWindow>
#include <QLoggingCategory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_chooseTextBtn_clicked();

    void on_selectTableBtn_clicked();

    void on_resultBtn_clicked();

private:
    SynonymTable _synonymTable;
    Ui::MainWindow *ui;
    QLoggingCategory category;
};
#endif // MAINWINDOW_H
