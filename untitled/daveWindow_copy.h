#ifndef DaveWindow_H
#define DaveWindow_H

#include <QMainWindow>

#include "person.h"
#include "disease.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <QDialog>

using std::string;
using std::vector;
using std::unordered_map;

namespace Ui {
class DaveWindow;
}

class DaveWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DaveWindow(QWidget *parent = 0);
    ~DaveWindow();

private slots:


private:
    Ui::DaveWindow *ui;
    void filePeople(string a);
    void fileDisease(string a);
    vector<person> personVect;
    vector<string> personName;

    unordered_map<string,disease> diseases;
};

#endif // DaveWindow_H
