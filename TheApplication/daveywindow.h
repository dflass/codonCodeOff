#ifndef DAVEYWINDOW_H
#define DAVEYWINDOW_H

#include <QDialog>
#include "person.h"
#include "disease.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <QMainWindow>
#include <mainwindow.h>

using std::string;
using std::vector;
using std::unordered_map;

namespace Ui {
class DaveyWindow;
}

class DaveyWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DaveyWindow(QWidget *parent = 0, std::string name = "Marie_Curie", MainWindow *mainy = 0);
    ~DaveyWindow();
    QWidget* win;
    std::string username;
    MainWindow* mainy;
private slots:
    void on_pushButton_clicked();

private:
    Ui::DaveyWindow *ui;

};

#endif // DAVEYWINDOW_H
