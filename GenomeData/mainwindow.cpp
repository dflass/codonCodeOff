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

    for(int i = 0; i<personVect.size(); i++){
        cout << personVect[i].name << std::endl;
        cout << personVect[i].allelle.size()<< std::endl;
        unordered_map<string, string>::iterator it = personVect[i].allelle.begin();
        while(it != personVect[i].allelle.end()){
            if(diseases.find(it->first)!=diseases.end()){
                disease temp = diseases.at(it->first);
                 if(temp.riskAll==it->second){
                     vector<string> hold = personVect[i].confirmDis;
                     //Change to hash
                     if(!std::binary_search (hold.begin(), hold.end(), temp.diseaseNameA)){
                         personVect[i].confirmDis.push_back(temp.diseaseNameA);
                         std::sort(personVect[i].confirmDis.begin(), personVect[i].confirmDis.end());
                     }

                 }
            }
            it ++;
        }

        cout << "number of diseases\n";
        cout << personVect[i].confirmDis.size();
        cout << "\n";
    }

    for(int i=0; i<personVect[0].confirmDis.size();i++){
        ui->listWidget->addItem(QString::fromStdString(personVect[0].confirmDis[i]));
    }
    //Shove into listView



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
        snpID = line.substr(j+1,k-(j+1));
        allelel = line.substr(k+1);
        disease temp = disease(diseaseName, allelel);
        //hashmaps
        diseases.insert(std::make_pair(snpID,temp));

    }

}


void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{

}
