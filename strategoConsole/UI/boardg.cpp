#include "boardg.h"
#include <QDebug>
#include <unistd.h>

void BoardG::displayBoard()
{

    for(unsigned i=0;i<game.getBoard().getBoard().size();i++){
         for(unsigned j=0;j<game.getBoard().getBoard().size();j++){
             model::Position pos = model::Position(i,j);
             SquareG *s1= new SquareG(game.getBoard().getBoard()[i][j],pos);
             QObject::connect(s1,SIGNAL(clicked()),s1,SLOT(mouseClick()));
             QObject::connect(s1,SIGNAL(click(SquareG&)),this,SLOT(select(SquareG&)));
             QLayoutItem* item =itemAtPosition(j,i);
             removeItem(item);

             addWidget(s1,j,i);



         }


    }
    updateBoard();
     setContentsMargins(0,0,0,0);
     setSpacing(0);
     // alternatively
     setHorizontalSpacing(0);
     setVerticalSpacing(0);
}
void BoardG::select(SquareG & square){
    if(game.checkWinner()==model::Color::Null){
        if(start!=nullptr){
            QLayoutItem * item = this->itemAtPosition(start->getRow(),start->getColumn());
            QWidget * widget = item->widget();
            SquareG * square = dynamic_cast<SquareG*>(widget);
            square->setStyleSheet("");
            std::vector<model::Position> positions=game.getPositions(*start);
            for(auto & p : positions){

                QLayoutItem * item = this->itemAtPosition(p.getRow(),p.getColumn());
                QWidget * widget = item->widget();
                SquareG * square = dynamic_cast<SquareG*>(widget);
                square->setStyleSheet("");
                QObject::connect(square,SIGNAL(click(SquareG&)),this,SLOT(select(SquareG&)));
                QObject::disconnect(square,SIGNAL(click(SquareG&)),this,SLOT(move(SquareG&)));

            }

        }

    square.setStyleSheet("background-color: green;");
    qDebug().nospace()<<square.getPosition().getColumn()<<"," << square.getPosition().getRow();
    model::Position pos1=square.getPosition();
    qDebug().nospace()<<"Je suis apres la création de position";
    std::vector<model::Position> positions=game.getPositions(pos1);
    qDebug().nospace()<<game.getBoard().getBoard()[square.getPosition().getColumn()][square.getPosition().getRow()].getPiece()->getType();
    if(positions.size()==0)
           qDebug().nospace()<<"positions empty bru";
    this->start=&square.getPosition();
    for(auto & p : positions){

        QLayoutItem * item = this->itemAtPosition(p.getRow(),p.getColumn());
        QWidget * widget = item->widget();
        SquareG * square = dynamic_cast<SquareG*>(widget);
        square->setStyleSheet("background-color: blue;");
        QObject::disconnect(square,SIGNAL(click(SquareG&)),this,SLOT(select(SquareG&)));
        QObject::connect(square,SIGNAL(click(SquareG&)),this,SLOT(move(SquareG&)));

    }
    }

}

void BoardG::move(SquareG & square){
    if(game.checkWinner()==model::Color::Null){

    this->end=&square.getPosition();
    QLayoutItem * item = this->itemAtPosition(square.getPosition().getRow(),square.getPosition().getColumn());
    QWidget * widget = item->widget();
    SquareG * sq = dynamic_cast<SquareG*>(widget);

    qDebug().nospace()<<"I'm in move"<<square.getPosition().getColumn()<<"," << square.getPosition().getRow();
    qDebug().nospace()<<"source"<<start->getColumn()<<"," << start->getRow();
    qDebug().nospace()<<"destination"<<end->getColumn()<<"," << end->getRow();    
    model::Move move=model::Move(*start,*end);
    if(game.validateMove(move)){
            if(game.isItAttack()){
                qDebug().nospace()<<"Position column " << game.getMoveSelected().getEnd().getColumn();
                qDebug().nospace()<<"Position row " << game.getMoveSelected().getEnd().getRow();

                game.setVisibilityPiece();

                qDebug().nospace()<<"visiblity start " << game.getBoard().getBoard()[start->getColumn()][start->getRow()].getPiece()->getVisible();
                qDebug().nospace()<<"visiblity end " << game.getBoard().getBoard()[end->getColumn()][end->getRow()].getPiece()->getVisible();
                sleep(1);
                game.attack();
                if(!game.getMode())
                    game.resetVisibilityPiece();
                QObject::disconnect(sq,SIGNAL(click(SquareG&)),this,SLOT(move(SquareG&)));
                QObject::connect(sq,SIGNAL(click(SquareG&)),this,SLOT(select(SquareG&)));
            }else{
                QObject::disconnect(sq,SIGNAL(click(SquareG&)),this,SLOT(move(SquareG&)));
                QObject::connect(sq,SIGNAL(click(SquareG&)),this,SLOT(select(SquareG&)));
                game.move();

            }


    }
    }
    //displayBoard();




}
BoardG::BoardG(model::Stratego & game):game(game)
{
    this->game=game;
    game.registerObserver(this);
    displayBoard();
    setHorizontalSpacing(0);
    setVerticalSpacing(0);

}
void BoardG::updateBoard(){
    for(unsigned i=0;i<game.getBoard().getBoard().size();i++){
         for(unsigned j=0;j<game.getBoard().getBoard().size();j++){
                      QLayoutItem * item = this->itemAtPosition(j,i);
                      QWidget * widget = item->widget();
                      SquareG * square = dynamic_cast<SquareG*>(widget);
                      model::Position pos=model::Position(i,j);
                      model::Square sq = game.getBoard().getBoard()[i][j];


                      square->updateSquare(sq,pos,game.getCurrentPlayer().getColor());


                      square->disconnect();
                      QObject::connect(square,SIGNAL(clicked()),square,SLOT(mouseClick()));
                      QObject::connect(square,SIGNAL(click(SquareG&)),this,SLOT(select(SquareG&)));

         }

    }
}

void BoardG::update(const nvs::Subject *subject){
     if(subject != &this->game)return;
     updateBoard();


}
void BoardG::disconnectAll(){
    for(unsigned i=0;i<game.getBoard().getBoard().size();i++){
         for(unsigned j=0;j<game.getBoard().getBoard().size();j++){
                      QLayoutItem * item = this->itemAtPosition(j,i);
                      QWidget * widget = item->widget();
                      SquareG * square = dynamic_cast<SquareG*>(widget);
                      square->disconnect();


         }

    }
}

