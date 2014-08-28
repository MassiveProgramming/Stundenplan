#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "timeClass.h"
#include "fileparser.h"

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
    void on_buttonWeek_clicked();

    void on_buttonMonday_clicked(bool checked);

    void on_buttonTuesday_pressed();

    void on_buttonMonday_pressed();

    void on_buttonWednesday_pressed();

    void on_buttonThursday_pressed();

    void on_buttonFriday_pressed();

private:
    Ui::MainWindow *ui;
    Time *time;
    FileParser *fp;
    int day;
    int week;

    void setWeekButton( int e );
    void selectedDayButton( int day );
    void toggleWeek();
    void displayData( struct tag data );
    void clearData();
};

#endif // MAINWINDOW_H
