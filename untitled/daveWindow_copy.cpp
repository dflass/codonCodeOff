#include "daveWindow.h"
#include "ui_davewindow.h"
#include <vector>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;
DaveWindow::DaveWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DaveWindow)
{
    ui->setupUi(this);

    fileDisease("../disease.csv");
    filePeople("../people.csv");

    for(int i = 0; i<2; i++){
        cout << personVect[i].name;
        cout << "\n";
        cout << personVect[i].allelle[0][0];
        cout << "\n";
        cout << personVect[i].allelle[0][1];
        cout << "\n";


    }


}

DaveWindow::~DaveWindow()
{
    delete ui;
}

void DaveWindow::filePeople(string a){
    string  line, name, snpID, allelel;
    ifstream file;
    file.open(a);
    int i = 0;
    getline(file,line);

    while(!file.eof() && i < 2){
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

void DaveWindow::fileDisease(string a){
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
//        diseases.insert(snpID,a);

    }

}


