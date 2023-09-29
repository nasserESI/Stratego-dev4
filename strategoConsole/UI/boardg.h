#ifndef BOARDG_H
#define BOARDG_H
#include "../metier/stratego.h"
#include "QGridLayout"
#include "squareG.h"
#include "observer.h"

class BoardG : public QGridLayout,public nvs::Observer
{
    Q_OBJECT
private:
    model::Stratego & game;
    model::Position *start=nullptr;
    model::Position *end=nullptr;



public:
    BoardG(model::Stratego & game);
    void displayBoard();
    void updateBoard();
     virtual void update(const nvs::Subject * subject) override;
    void disconnectAll();

public slots:
    void select(SquareG &square);
    void move(SquareG & square);





};
#endif // BOARDG_H
