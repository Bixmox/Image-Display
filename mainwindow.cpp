#include "mainwindow.h"
#include "ui_mainwindow.h"

void mainwindow::onfinish(QNetworkReply *reply)
{
    ui->label->setText(reply->readAll());
    qDebug() << reply->errorString();
    if (reply->errorString() == "Unknown error")
    {
        ui->label_2->setText("Success!");
    } else {
        ui->label_2->setText("Output: " + reply->errorString());
    }
}

mainwindow::mainwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::mainwindow)
{
    ui->setupUi(this);
    qDebug() << QSslSocket::sslLibraryBuildVersionString();
    qDebug() << QSslSocket::supportsSsl();
}

mainwindow::~mainwindow()
{
    delete ui;
}


void mainwindow::on_pushButton_clicked()
{
    QUrl url(ui->lineEdit->text());
    QNetworkAccessManager *mgr = new QNetworkAccessManager(this);
    connect(mgr,&QNetworkAccessManager::finished,this, &mainwindow::onfinish);
    mgr->get(QNetworkRequest(url));
}
