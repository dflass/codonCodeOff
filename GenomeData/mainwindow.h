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

private slots:

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_listWidget_itemSelectionChanged();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    void filePeople(string a);
    void fileDisease(string a);
    vector<person> personVect;
    vector<string> personName;

    unordered_map<string,disease> diseases;
};

#endif // MAINWINDOW_H
