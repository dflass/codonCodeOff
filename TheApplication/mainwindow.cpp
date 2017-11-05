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
#include <QtWebKitWidgets/QWebView>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <QtWebKitWidgets/QWebView>
#include <QUrl>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    std::cout << "Before Setup \n";
    ui->setupUi(this);
    std::cout << "Dave scks 3" << std::endl;
    std::cout << "After Setup \n";
    std::cout << "Dave scks 3" << std::endl;
    //ui->webView->load(QUrl("http://codoncodeoff.forumotion.com/t2-skin-aging"));

    fileDisease("C:/Users/David/Documents/untitled/disease.csv");
    std::cout << "Dave scks disease" << std::endl;
    filePeople("C:/Users/David/Documents/untitled/people.csv");
std::cout << "Dave scks people" << std::endl;
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
    std::cout << "Dave scks 3" << std::endl;
    string  line, name, snpID, allelel;
    std::ifstream file;
    file.open(a);
    int i = 0;
    getline(file,line);
    std::cout << "Dave scks 4" << std::endl;
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
    std::cout << "Dave people sorted" << std::endl;
}

void MainWindow::fileDisease(string a){
    std::cout << "Dave scks 3" << std::endl;
    string line, diseaseName, snpID, allelel;
    std::ifstream file;
    file.open(a);
    std::cout << "Dave scks 3" << std::endl;
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
std::cout << "Dave scks 3" << std::endl;
    }

}
