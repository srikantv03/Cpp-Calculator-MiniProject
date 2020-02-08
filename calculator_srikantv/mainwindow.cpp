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
    QString renameLabel;
    renameLabel = (button->text());
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


void MainWindow::on_minus_released()
{
    string teststring;
    teststring = (ui->label->text()).toStdString();
    int index = teststring.find_first_of("-");
    if(index < 0){
        ui->label->setText(ui->label->text() + "-");
    }
    else{
        ui->label->setText(ui->label->text() + "");
    }
}



void MainWindow::on_plus_released()
{
    string teststring;
    teststring = (ui->label->text()).toStdString();
    int index = teststring.find_first_of("+");
    if(index < 0){
        ui->label->setText(ui->label->text() + "+");
    }
    else{
        ui->label->setText(ui->label->text() + "");
    }
}

void MainWindow::on_equals_released()
{
    string teststring;
    teststring = (ui->label->text()).toStdString();
    int if_divide = teststring.find_first_of("/");
    int if_multiply = teststring.find_first_of("*");
    int if_add = teststring.find_first_of("+");
    int if_subtract = teststring.find_first_of("-");

    if(if_divide>0){
        string number[] = {"", ""};
        int i=0;
        for(auto x: teststring){
            if(x=='/'){
                i=1;
            }
            else{
                number[i] = number[i] + x;
            }
        }

        double num1 = std::stod(number[0]);
        double num2 = std::stod(number[1]);
        double output = num1/num2;
        QString textoutput = QString::number(output);
        ui->label->setText(textoutput);
    }
    else if (if_multiply>0){
        string number[] = {"", ""};
        int i=0;
        for(auto x: teststring){
            if(x=='*'){
                i=1;
            }
            else{
                number[i] = number[i] + x;
            }
        }

        double num1 = std::stod(number[0]);
        double num2 = std::stod(number[1]);
        double output = num1 * num2;
        QString textoutput = QString::number(output);
        ui->label->setText(textoutput);
    }
    else if (if_add>0){
        string number[] = {"", ""};
        int i=0;
        for(auto x: teststring){
            if(x=='+'){
                i=1;
            }
            else{
                number[i] = number[i] + x;
            }
        }

        double num1 = std::stod(number[0]);
        double num2 = std::stod(number[1]);
        double output = num1+num2;
        QString textoutput = QString::number(output);
        ui->label->setText(textoutput);
    }
    else if (if_subtract>0){
        string number[] = {"", ""};
        int i=0;
        for(auto x: teststring){
            if(x=='-'){
                i=1;
            }
            else{
                number[i] = number[i] + x;
            }
        }

        double num1 = std::stod(number[0]);
        double num2 = std::stod(number[1]);
        double output = num1-num2;
        QString textoutput = QString::number(output);
        ui->label->setText(textoutput);
    }
    else {

    }
}

