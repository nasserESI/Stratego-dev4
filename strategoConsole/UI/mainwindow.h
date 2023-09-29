#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "../metier/stratego.h"
#include "ui_mainwindow.h"
#include "observer.h"
#include <QMainWindow>
#include "boardg.h"
#include "initboard.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow,public nvs::Observer
{
    Q_OBJECT
private:
    QLabel *label=nullptr;
    BoardG *board=nullptr;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    model::Stratego game;
    virtual void update(const nvs::Subject * subject) override;

private slots:
    void on_startButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
