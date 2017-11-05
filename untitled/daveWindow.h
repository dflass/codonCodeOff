#ifndef DAVEWINDOW_H
#define DAVEWINDOW_H

#include <QDialog>

namespace Ui {
class DaveWindow;
}

class DaveWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DaveWindow(QWidget *parent = 0);
    ~DaveWindow();

private:
    Ui::DaveWindow *ui;
};

#endif // DAVEWINDOW_H
