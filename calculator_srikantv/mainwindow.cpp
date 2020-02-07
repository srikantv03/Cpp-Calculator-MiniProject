#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QPushButton>
#include <iostream>
using namespace std;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->zero, SIGNAL(released()),this, SLOT(number_pressed()));
    connect(ui->one, SIGNAL(released()),this, SLOT(number_pressed()));
    connect(ui->two, SIGNAL(released()),this, SLOT(number_pressed()));
    connect(ui->three, SIGNAL(released()),this, SLOT(number_pressed()));
    connect(ui->four, SIGNAL(released()),this, SLOT(number_pressed()));
    connect(ui->five, SIGNAL(released()),this, SLOT(number_pressed()));
    connect(ui->six, SIGNAL(released()),this, SLOT(number_pressed()));
    connect(ui->seven, SIGNAL(released()),this, SLOT(number_pressed()));
    connect(ui->eight, SIGNAL(released()),this, SLOT(number_pressed()));
    connect(ui->nine, SIGNAL(released()),this, SLOT(number_pressed()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::number_pressed(){
    QPushButton * button = (QPushButton*)sender();
    double number;
    QString renameLabel;
    number = (ui->label->text() + button->text()).toDouble();
    renameLabel = QString::number(number, 'g', 15);
    ui->label->setText(ui->label->text() + renameLabel);
}


void MainWindow::on_decimal_released()
{
    string teststring;
    teststring = (ui->label->text()).toStdString();
    int index = teststring.find_first_of(".");
    if(index < 0){
        ui->label->setText(ui->label->text() + ".");
    }
    else{
        ui->label->setText(ui->label->text() + "");
    }
}

void MainWindow::on_clear_pressed()
{
    ui->label->setText("");
}

void MainWindow::on_multiply_pressed()
{
    string teststring;
    teststring = (ui->label->text()).toStdString();
    int index = teststring.find_first_of("*");
    if(index < 0){
        ui->label->setText(ui->label->text() + "*");
    }
    else{
        ui->label->setText(ui->label->text() + "");
    }
}

void MainWindow::on_divide_released()
{
    string teststring;
    teststring = (ui->label->text()).toStdString();
    int index = teststring.find_first_of("/");
    if(index < 0){
        ui->label->setText(ui->label->text() + "/");
    }
    else{
        ui->label->setText(ui->label->text() + "");
    }
}
