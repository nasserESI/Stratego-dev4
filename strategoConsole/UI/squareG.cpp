#include "squareG.h"
#include <QString>
#include <QDebug>

void SquareG::setIconSquare(const model::Square &square,model::Position & pos,model::Color colorCurrentPlayer)
{
    setFixedSize(QSize(90,100));

        if(square.getType()==model::TypeSquare::Water){
            if((pos.getRow()==4 && pos.getColumn()==2) ||(pos.getRow()==4 && pos.getColumn()==6)){
                QIcon water(QPixmap("img/W1.png"));
                setIcon(water);
             }
            if((pos.getRow()==4 &&pos.getColumn()==3) ||(pos.getRow()==4 && pos.getColumn()==7)){
                QIcon water(QPixmap("img/W2.png"));
                setIcon(water);
            }
            if((pos.getRow()==5 && pos.getColumn()==2) ||(pos.getRow()==5 && pos.getColumn()==6)){
                QIcon water(QPixmap("img/W3.png"));
                setIcon(water);
             }
            if((pos.getRow()==5 && pos.getColumn()==3) ||(pos.getRow()==5 && pos.getColumn()==7)){
                QIcon water(QPixmap("img/W4.png"));
                setIcon(water);
            }
        }else{
            if(square.isEmpty()){
                QIcon empty=QPixmap("img/E.png");
                setIcon(empty);
            }else{

                if(square.getPiece()->getColor()==model::Color::Blue ){

                    if( !square.getPiece()->getVisible() and square.getPiece()->getColor()!=colorCurrentPlayer){
                        //qDebug().nospace()<<"visibilité : "<<square.getPiece()->getVisible()<< " Position " << pos.getColumn() << " , " << pos.getRow();

                        QIcon bc=QPixmap("img/BC.png");
                        this->setIcon(bc);
                    }
                    else{
                        qDebug().nospace()<<"visibilité : "<<square.getPiece()->getVisible()<< " Position " << pos.getColumn() << " , " << pos.getRow();

                         QString nameImg="img/";
                        if(square.getPiece()->getType()<=10)
                             nameImg=nameImg+QString::number(square.getPiece()->getType());
                        else
                             nameImg=nameImg+char(square.getPiece()->getType());
                        nameImg=nameImg+"B.png";
                        if(pos.getColumn()==5 && pos.getRow() == 4)
                            qDebug().nospace()<<nameImg;
                        QIcon piee=QPixmap(nameImg);
                        this->setIcon(piee);
                    }

                }
                else{

                    if( !square.getPiece()->getVisible() and  square.getPiece()->getColor()!=colorCurrentPlayer){
                        //qDebug().nospace()<<"visibilité : "<<square.getPiece()->getVisible()<< " Position " << pos.getColumn() << " , " << pos.getRow();

                        QIcon bc=QPixmap("img/RC.png");
                        this->setIcon(bc);
                    }
                    else{
                        qDebug().nospace()<<"visibilité : "<<square.getPiece()->getVisible()<< " Position " << pos.getColumn() << " , " << pos.getRow();

                         QString nameImg="img/";
                        if(square.getPiece()->getType()<=10)
                             nameImg=nameImg+QString::number(square.getPiece()->getType());
                        else{
                             QChar tmp=square.getPiece()->getType();
                             nameImg=nameImg+tmp;
                        }
                        nameImg=nameImg+"R.png";
                        if(pos.getColumn()==5 && pos.getRow() == 5)
                            qDebug().nospace()<<nameImg;


                        QIcon piee=QPixmap(nameImg);
                        this->setIcon(piee);

                    }
                }

            }
            }
        setStyleSheet("");
        setIconSize(QSize(80,90));
}

SquareG::SquareG(const model::Square &square,model::Position & pos):square(square),position(pos)
{
    //setFixedSize(QSize(90,133));

    setIconSquare(square,pos);
}


model::Position & SquareG::getPosition(){
    return this->position;
}

void SquareG::mouseClick(){
    emit click(*this);
}
void SquareG::updateSquare(const model::Square & square,model::Position  &pos,model::Color currentPlayerColor){
    this->square=square;
    this->position=pos;
    this->setIconSquare(this->square,this->position,currentPlayerColor);
}
const model::Square &  SquareG::getSquare(){
    return this->square;
}


