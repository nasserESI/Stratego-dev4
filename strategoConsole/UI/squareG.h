#ifndef SQUAREG_H
#define SQUAREG_H
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>
#include <../metier/square.h>
class SquareG : public QPushButton
{
    Q_OBJECT
private:
     model::Square square ;
     model::Position position;


public:

    SquareG(const model::Square &square,model::Position & );
    void updateSquare(const model::Square  &square,model::Position & pos,model::Color currentPlayerColor);
    model::Position &  getPosition();

    void setIconSquare(const model::Square &square,model::Position & pos,model::Color currentPlayerColor=model::Color::Null);
    const model::Square &  getSquare();

signals:
   void click(SquareG& s);
public slots:
   void mouseClick();
};
#endif
