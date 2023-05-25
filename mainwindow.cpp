#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <qstring.h>
#include <QFileDialog>
#include <fstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      _synonymTable(),
      category("CppTask_4")
{
    qDebug(category) << "Init main window";
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    qDebug(category) << "Destroy main window";
    delete ui;
}


void MainWindow::on_chooseTextBtn_clicked()
{
    qDebug(category) << "ChooseTextBtn clicked";
    QString filename = QFileDialog::getOpenFileName(
                this, tr("Open text"), "../CppTask_4/data", tr("Text files (*.txt)"));
    fstream file;
    file.open(filename.toStdString());
    qDebug(category) << "File text opened";
    if(file.is_open())
    {
        QString temp;
        string line;
        while (getline(file, line))
        {
            temp = ui->textLabel->text();
            temp.append(QString::fromStdString(line));
            ui->textLabel->setText(temp);
        }
    }
    file.close();
    qDebug(category) << "File text closed";
}

void MainWindow::on_selectTableBtn_clicked()
{
    qDebug(category) << "SelectTableBtn clicked";
    QString filename = QFileDialog::getOpenFileName(
                this, tr("Open synonym table"), "../CppTask_4/data", tr("Text files (*.txt)"));
    fstream file;
    file.open(filename.toStdString());
    qDebug(category) << "File table opened";
    if(file.is_open())
    {
        string line;
        while(getline(file, line))
        {
            _synonymTable.addSynonyms(line);
        }
    }
    file.close();
    qDebug(category) << "File table closed";
}


void MainWindow::on_resultBtn_clicked()
{
    qDebug(category) << "ResultBtn clicked";
    QString oldText = ui->textLabel->text();
    stringstream ss(oldText.toStdString());
    string word, newText;
    while(ss>>word)
    {
        newText += _synonymTable.getRndSynonym(word) + " ";
    }
    ui->textLabel->setText(QString::fromStdString(newText));
    qDebug(category) << "Text changed on label";
    //save to file
    QString filename = QFileDialog::getOpenFileName(
                this, tr("Choose result file"), "../CppTask_4/data", tr("Text files (*.txt)"));
    fstream file;
    file.open(filename.toStdString());
    qDebug(category) << "File result opened";
    if(file.is_open())
    {
        file << newText;
    }
    file.close();
    qDebug(category) << "File result closed";
}

