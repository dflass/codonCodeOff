#include "daveywindow.h"
#include "ui_daveywindow.h"
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
DaveyWindow::DaveyWindow(QWidget *parent, std::string name, MainWindow* m) :
    QDialog(parent),
    ui(new Ui::DaveyWindow)
{
    ui->setupUi(this);
    std::cout << "Before Load URL" <<std::endl;

    ui->webView->load(QUrl("http://codoncodeoff.forumotion.com/t2-skin-aging"));
    std::cout<<"After Load URL" << std::endl;
    win = parent;
    username = name;
    mainy = m;
    ui->label->setText(QString::fromStdString(name));

        for(int i = 0; i < name.length();i++){
            if(name[i] == '_')
                name[i] = ' ';
        }
        int loginPerson = 0;

        for(int i = 0; i< mainy->personName.size(); i++){
            if(name==mainy->personName.at(i)){
                loginPerson = i;
                break;
            }
        }
        unordered_map<string, string>::iterator it = mainy->personVect[loginPerson].allelle.begin();
        while(it != mainy->personVect[loginPerson].allelle.end()){
            if(mainy->diseases.find(it->first)!=mainy->diseases.end()){
                disease temp = mainy->diseases.at(it->first);
                 if(temp.riskAll==it->second){
                     vector<string> hold = mainy->personVect[loginPerson].confirmDis;
                     //Change to hash
                     if(!std::binary_search (hold.begin(), hold.end(), temp.diseaseNameA)){
                         mainy->personVect[loginPerson].confirmDis.push_back(temp.diseaseNameA);
                         std::sort(mainy->personVect[loginPerson].confirmDis.begin(), mainy->personVect[loginPerson].confirmDis.end());
                     }

                 }
            }
            it ++;
        }

        std::cout << "number of diseases\n";
        std::cout << mainy->personVect[loginPerson].confirmDis.size();
        std::cout << "\n";

        for(int i=0; i<mainy->personVect[loginPerson].confirmDis.size();i++){
            ui->listWidget->addItem(QString::fromStdString(mainy->personVect[loginPerson].confirmDis[i]));
        }

}


DaveyWindow::~DaveyWindow()
{
    delete ui;
}



void DaveyWindow::on_pushButton_clicked()
{


   QDesktopServices::openUrl(QUrl("https://public.tableau.com/profile/dave.lass3048#!/vizhome/Diseases_3/Sheet1"));

}
