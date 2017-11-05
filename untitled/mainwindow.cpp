#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include "daveywindow.h"
#include <vector>
#include <stdio.h>
#include <QUrl>
#include <QDesktopServices>
#include "daveywindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //ui->webView->load(QUrl("http://codoncodeoff.forumotion.com/t2-skin-aging"));

    fileDisease("C:/Users/Maddie/Documents/untitled/disease.csv");
    filePeople("C:/Users/Maddie/Documents/untitled/people.csv");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Login_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    string name = username.toStdString();
    if(username ==  "Marie_Curie" && password == "test") {
        //QMessageBox::information(this, "Login", "Username and password is correct");
        DaveyWindow* daveyWindow = new DaveyWindow(this, name, this);
        daveyWindow->show();
    }
    else {
        QMessageBox::warning(this,"Login", "Username and password is not correct");
    }
}

void MainWindow::filePeople(string a){
    string  line, name, snpID, allelel;
    std::ifstream file;
    file.open(a);
    int i = 0;
    getline(file,line);

    while(!file.eof()){
        getline(file,line);
        int j = line.find(",");
        name = line.substr(0,j);
        int k = line.find(",",j+1);
        snpID = line.substr(j+1,k-(j+1));
        allelel = line.substr(k+1);
        if(std::find(personName.begin(),personName.end(),name)!=personName.end()){
            personVect[i-1].push(snpID,allelel);
        }
        else{
            personName.push_back(name);
            person temp = person(name,snpID,allelel);
            personVect.push_back(temp);
            i++;
        }

    }
}

void MainWindow::fileDisease(string a){
    string line, diseaseName, snpID, allelel;
    std::ifstream file;
    file.open(a);
    int i = 0;
    getline(file,line);
    while(!file.eof()){
        getline(file,line);
        int j = line.find(",");
        diseaseName = line.substr(0,j);
        int k = line.find(",",j+1);
        snpID = line.substr(j+1,k-(j+1));
        allelel = line.substr(k+1);
        disease temp = disease(diseaseName, allelel);
        //hashmaps
        diseases.insert(std::make_pair(snpID,temp));

    }

}
