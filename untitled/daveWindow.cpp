#include "daveWindow.h"
#include "ui_davewindow.h"

DaveWindow::DaveWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DaveWindow)
{
    ui->setupUi(this);
}

DaveWindow::~DaveWindow()
{
    delete ui;
}

