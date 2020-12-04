#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QPixmap>
#include <iostream>

QT_BEGIN_NAMESPACE
namespace Ui { class mainwindow; }
QT_END_NAMESPACE

class mainwindow : public QWidget
{
    Q_OBJECT

public:
    mainwindow(QWidget *parent = nullptr);
    ~mainwindow();

private:
    Ui::mainwindow *ui;

private slots:
    void onfinish(QNetworkReply*);
    void on_pushButton_clicked();
};
#endif // MAINWINDOW_H
