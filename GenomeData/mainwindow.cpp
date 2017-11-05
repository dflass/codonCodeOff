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

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    ui->webView->load(QUrl("http://codoncodeoff.forumotion.com/t2-skin-aging"));

    fileDisease("../disease.csv");
    filePeople("../people.csv");



//    ui->webView->load(QUrl("public.tableau.com/profile/dave.lass3048#!/vizhome/Diseases_3/Sheet1"));

//    ui->webView_2->load(QUrl("http://public.tableau.com/profile/dave.lass3048"));

    string loginName = "Marie_Curie";
    string pic = loginName+".jpg";
    for(int i = 0; i < loginName.length(); i++){
        if(loginName[i] == '_')
            loginName[i] = ' ';
    }
    int loginPerson=0;
    for(int i = 0; i<personName.size(); i++){
        if(loginName==personName.at(i)){
            loginPerson = i;
            break;
        }
    }

    ui->label->setText(QString::fromStdString(loginName));
    QPixmap picture = QPixmap(QString::fromStdString(pic));
    ui->label_pic->setPixmap(picture);
    unordered_map<string, string>::iterator it = personVect[loginPerson].allelle.begin();
    while(it != personVect[loginPerson].allelle.end()){
        if(diseases.find(it->first)!=diseases.end()){
            disease temp = diseases.at(it->first);
             if(temp.riskAll==it->second){
                 vector<string> hold = personVect[loginPerson].confirmDis;
                 //Change to hash
                 if(!std::binary_search (hold.begin(), hold.end(), temp.diseaseNameA)){
                     personVect[loginPerson].confirmDis.push_back(temp.diseaseNameA);
                     std::sort(personVect[loginPerson].confirmDis.begin(), personVect[loginPerson].confirmDis.end());
                 }

             }
        }
        it ++;
    }

    cout << "number of diseases\n";
    cout << personVect[loginPerson].confirmDis.size();
    cout << "\n";


    for(int i=0; i<personVect[loginPerson].confirmDis.size();i++){
        ui->listWidget->addItem(QString::fromStdString(personVect[loginPerson].confirmDis[i]));
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

void MainWindow::on_listWidget_itemSelectionChanged()
{

}

void MainWindow::on_pushButton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://public.tableau.com/profile/dave.lass3048#!/vizhome/Diseases_3/Sheet1"));
}
