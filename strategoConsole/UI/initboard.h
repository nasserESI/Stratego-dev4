#ifndef INITBOARD_H
#define INITBOARD_H
#include "../metier/stratego.h"
#include "ui_mainwindow.h"
#include "QHBoxLayout"
#include "QGridLayout"
#include "squareG.h"
#include <iostream>
#include "observer.h"
#include "mainwindow.h"
class initBoard : public  QHBoxLayout,public nvs::Observer
{
    Q_OBJECT
private:
      model::Stratego &game;
      QGridLayout *boardG=nullptr;
      QPushButton *startButton=nullptr;
      QGridLayout *playerPiece=nullptr;
      QWidget * window = nullptr;
      std::map<std::string, int> map ;
      const  std::array<std::string,12> symboles={"10","9","8","7","6","5","4","3","2","1","D","B"};
      model::Position *start=nullptr;
      model::Position *end=nullptr;
      bool redInit=false;
      bool blueInit=false;


public:
    initBoard(model::Stratego &game,QWidget * window = nullptr);
    void createBoard();
    void createPlayerPiece();
    virtual void update(const nvs::Subject * subject) override;
    int countPieces();
    void updateBoard();
    void updatePlayerPiece();


public slots:
    void select(SquareG &square);
    void move(SquareG & square);
    void on_startButton_clicked();
};

#endif // INITBOARD_H
