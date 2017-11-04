#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    fileDisease("../disease.csv");
    filePeople("../people.csv");

    for(int i = 0; i<1; i++){

    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::filePeople(string a){
    string  line, name, snpID, allelel;
    ifstream file;
    file.open(a);
    int i = 0;
    getline(file,line);
    person curPersonPoint;
    while(!file.eof() && i < 2){
        getline(file,line);
        int j = line.find(",");
        name = line.substr(0,j);
        int k = line.find(",",j+1);
        snpID = line.substr(j+1,k);
        allelel = line.substr(k+1);
        if(std::find(personName.begin(),personName.end(),name)!=personName.end()){
            curPersonPoint->push(snpID,allelel);
        }
        else{
            personName.push_back(name);
            curPersonPoint = new person(name, snpID,allelel);

            cout << (name) + "\n";
            ui->comboBox->addItem(QString::fromStdString(name));
            i++;
        }

    }
}

void MainWindow::fileDisease(string a){
    string line, diseaseName, snpID, allelel;
    ifstream file;
    file.open(a);
    int i = 0;
    getline(file,line);
    while(!file.eof()){
        getline(file,line);
        int j = line.find(",");
        diseaseName = line.substr(0,j);
        int k = line.find(",",j+1);
        snpID = line.substr(j+1,k);
        allelel = line.substr(k+1);

        //hashmaps
//        diseases.insert(snpID,allelel);

    }

}


void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{

}
