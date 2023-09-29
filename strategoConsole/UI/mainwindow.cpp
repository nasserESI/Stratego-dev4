#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->startButton, SIGNAL(clicked()),this,SLOT(on_startButton_clicked()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_startButton_clicked()
{
    if(ui->inputPB->text()!="" && ui->inputPR->text()!=""){
    if(ui->fileRadio->isChecked()){


    auto central = new QWidget;
    this->label = new QLabel();
    this->game = model::Stratego(true,"example.txt");

    game.addPlayer(ui->inputPR->text().toStdString(),model::Color::Red);
    game.addPlayer(ui->inputPB->text().toStdString(),model::Color::Blue);
    game.initCurrentPlayer();
    game.registerObserver(this);
    this->board= new BoardG(game);
    QVBoxLayout * vbox = new QVBoxLayout;
    QHBoxLayout * box = new QHBoxLayout;
    QString currentPlayer= QString::fromStdString("It's the turn of "+game.getCurrentPlayer().getName()+" to play");
    label->setText(currentPlayer);
     box->addItem(board);
     vbox->addWidget(label);
     label->setAlignment(Qt::AlignCenter);
     label->setStyleSheet("font-family: arial; font-weight : bold; font-size: 24px; background-color: #87CEFA;");
    vbox->addItem(box);
    central->setLayout(vbox);
    this->setCentralWidget(central);
     }else{
         auto central = new QWidget;
         this->game = model::Stratego(true);
         game.addPlayer(ui->inputPR->text().toStdString(),model::Color::Red);
         game.addPlayer(ui->inputPB->text().toStdString(),model::Color::Blue);
         game.initCurrentPlayer();
         initBoard *vbox=  new initBoard(game,this);
         central->setLayout(vbox);
         this->setCentralWidget(central);

    }

    }


    else{
        ui->errorLabel->setText("Veulliez entrer les deux noms");
        ui->errorLabel->setStyleSheet("color:red;");
    }


}

void MainWindow::update(const nvs::Subject * subject) {
    if(subject != &this->game)return;
    QString currentPlayer= QString::fromStdString("It's the turn of "+game.getCurrentPlayer().getName()+" to play");

    if(label!=nullptr)
        this->label->setText(currentPlayer);
    if(game.checkWinner()!=model::Color::Null){
        QString currentPlayer= QString::fromStdString(game.getNamePlayer(game.checkWinner())+" won the game");
        this->label->setText(currentPlayer);
        this->board->disconnect();
        this->board->disconnectAll();
    }


}

