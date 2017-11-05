#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "person.h"
#include "disease.h"
#include <vector>
#include <string>
#include <unordered_map>

using std::string;
using std::vector;
using std::unordered_map;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void filePeople(string a);
    void fileDisease(string a);
    vector<person> personVect;
    vector<string> personName;

    unordered_map<string,disease> diseases;
private slots:
    void on_pushButton_Login_clicked();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
