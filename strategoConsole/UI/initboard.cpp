#include "initboard.h"
#include "QDebug"
initBoard::initBoard(model::Stratego &game,QWidget * window ):game(game),window(window)
{
    game.registerObserver(this);
    createBoard();
    this->startButton=new QPushButton("start");
    this->addWidget(startButton);
    QObject::connect(startButton, SIGNAL(clicked()),this,SLOT(on_startButton_clicked()));
    this->addItem(this->boardG);
    map["10"]=1;
    map["9"]=1;
    map["8"]=2;
    map["7"]=3;
    map["6"]=4;
    map["5"]=4;
    map["4"]=4;
    map["3"]=5;
    map["2"]=8;
    map["1"]=1;
    map["D"]=1;
    map["B"]=6;
    createPlayerPiece();




}


void initBoard::createBoard(){
 this->boardG=new QGridLayout();
    for(unsigned i=0;i<game.getBoard().getBoard().size();i++){
         for(unsigned j=0;j<game.getBoard().getBoard().size();j++){
             model::Position pos = model::Position(i,j);
             SquareG *s1= new SquareG(game.getBoard().getBoard()[i][j],pos);

             this->boardG->addWidget(s1,j,i);



         }


    }
}

void initBoard::createPlayerPiece(){

    this->playerPiece=new QGridLayout();
    for(unsigned i = 0 ; i < this->symboles.size();i++){
        for(int j = 0 ; j< map[symboles[i]];j++){
            model::Square square=model::Square();
            int x = 0;
            try {
                x = std::stoi(symboles[i]);

            }  catch (...) {
                x=int(symboles[i].at(0));
            }
            qDebug().nospace()<< static_cast<model::TypePiece>(x);
            model::Piece piece = model::Piece(static_cast<model::TypePiece>(x),model::Color::Red);
            piece.setVisiblity(true);
            square.setPiece(piece);
            model::Position pos=model::Position(i,j);
            SquareG *s1= new SquareG(square,pos);
            QObject::connect(s1,SIGNAL(clicked()),s1,SLOT(mouseClick()));
            QObject::connect(s1,SIGNAL(click(SquareG&)),this,SLOT(select(SquareG&)));
            this->playerPiece->addWidget(s1,i,j);

        }

    }
    this->addItem(this->playerPiece);

}


int initBoard::countPieces(){
    int nbPieces=0;
    for(unsigned i = 0 ; i < this->symboles.size();i++){
        nbPieces=nbPieces+map[symboles[i]];
    }

    return nbPieces;
}


void initBoard::select(SquareG & squareG){
        if(start!=nullptr){
            QLayoutItem * item = playerPiece->itemAtPosition(start->getColumn(),start->getRow());
            QWidget * widget = item->widget();
            SquareG * square = dynamic_cast<SquareG*>(widget);
            square->setStyleSheet("");
        }


      squareG.setStyleSheet("background-color: green;");

    this->start=&squareG.getPosition();
    for(unsigned i=0;i<game.getBoard().getBoard().size();i++){
         for(unsigned j=0;j<game.getBoard().getBoard().size();j++){
             QLayoutItem * item = boardG->itemAtPosition(i,j);
             QWidget * widget = item->widget();
             SquareG * s1 = dynamic_cast<SquareG*>(widget);
             QObject::connect(s1,SIGNAL(clicked()),s1,SLOT(mouseClick()));
             QObject::connect(s1,SIGNAL(click(SquareG&)),this,SLOT(move(SquareG&)));
         }

}
}
void initBoard::move(SquareG & square){
    QLayoutItem * item = playerPiece->itemAtPosition(this->start->getColumn(),this->start->getRow());
    QWidget * widget = item->widget();
    SquareG * s1 = dynamic_cast<SquareG*>(widget);

    try{

         model::Piece piece = s1->getSquare().getPiece().value();
         qDebug().nospace() << square.getPosition().getRow() << " , "<<square.getPosition().getColumn();
        game.put(model::Position(square.getPosition().getColumn(),square.getPosition().getRow()),piece);
        for(unsigned i=0;i<game.getBoard().getBoard().size();i++){
             for(unsigned j=0;j<game.getBoard().getBoard().size();j++){
                 QLayoutItem * item = boardG->itemAtPosition(i,j);
                 QWidget * widget = item->widget();
                 SquareG * s2 = dynamic_cast<SquareG*>(widget);
                 QObject::disconnect(s2,SIGNAL(clicked()),s1,SLOT(mouseClick()));
                 QObject::disconnect(s2,SIGNAL(click(SquareG&)),this,SLOT(move(SquareG&)));
             }


    }
        std::string symboleD="";
        if(piece.getType()>10){

            symboleD = char(piece.getType());
             qDebug().nospace() << "symbole dans > 10 : " << QString::fromStdString(symboleD);


        }else{
            symboleD = std::to_string(piece.getType());
            qDebug().nospace() << "symbole dans < 10 : " << QString::fromStdString(symboleD);
        }

        qDebug().nospace() << "symbole : " << QString::fromStdString(symboleD);
        qDebug().nospace() << "seconde" << map.find(symboleD)->second;

        //map.find(symboleD)->second--;
         qDebug().nospace() << "seconde" << map.find(symboleD)->second;


    }
    catch(std::invalid_argument e){
        qDebug().nospace() << e.what();
    }
}

void initBoard::update(const nvs::Subject *subject){
     if(subject != &this->game)return;
     updateBoard();
     QLayoutItem * item = playerPiece->itemAtPosition(this->start->getColumn(),this->start->getRow());
     QWidget * widget = item->widget();
     SquareG * s1 = dynamic_cast<SquareG*>(widget);
     model::Piece piece = s1->getSquare().getPiece().value();
     std::string symboleD="";
     if(piece.getType()>10){

         symboleD = char(piece.getType());


     }else{
         symboleD = std::to_string(piece.getType());
     }
     QObject::disconnect(s1,SIGNAL(clicked()),s1,SLOT(mouseClick()));
     QObject::disconnect(s1,SIGNAL(click(SquareG&)),this,SLOT(select(SquareG&)));
     if(s1->getSquare().getPiece()->getColor()==model::Color::Red){
         QIcon bc=QPixmap("img/RC.png");
         s1->setIcon(bc);
     }else{
         QIcon bc=QPixmap("img/BC.png");
         s1->setIcon(bc);
     }
      s1->setStyleSheet("");



     map.find(symboleD)->second--;

     qDebug().nospace() << "nb Piece" <<countPieces() ;

     if(countPieces()==0 && redInit==false){
         qDebug().nospace() << "je dois change de pieces de joueurs";


         redInit=true;
         updatePlayerPiece();
     }


}
void initBoard::updateBoard(){
    for(unsigned i=0;i<game.getBoard().getBoard().size();i++){
         for(unsigned j=0;j<game.getBoard().getBoard().size();j++){
                      QLayoutItem * item = this->boardG->itemAtPosition(j,i);
                      QWidget * widget = item->widget();
                      SquareG * square = dynamic_cast<SquareG*>(widget);
                      model::Position pos=model::Position(i,j);
                      model::Square sq = game.getBoard().getBoard()[i][j];


                      square->updateSquare(sq,pos,game.getCurrentPlayer().getColor());


         }

    }



}
void initBoard::updatePlayerPiece(){
    map["10"]=1;
    map["9"]=1;
    map["8"]=2;
    map["7"]=3;
    map["6"]=4;
    map["5"]=4;
    map["4"]=4;
    map["3"]=5;
    map["2"]=8;
    map["1"]=1;
    map["D"]=1;
    map["B"]=6;
    for(unsigned i = 0 ; i < this->symboles.size();i++){
        for(int j = 0 ; j< map[symboles[i]];j++){
            model::Square square=model::Square();
            int x = 0;
            try {
                x = std::stoi(symboles[i]);

            }  catch (...) {
                x=int(symboles[i].at(0));
            }
            QLayoutItem * item = playerPiece->itemAtPosition(i,j);
            QWidget * widget = item->widget();
            SquareG * s1 = dynamic_cast<SquareG*>(widget);
            model::Piece piece = model::Piece(static_cast<model::TypePiece>(x),model::Color::Blue);
            piece.setVisiblity(true);
            square.setPiece(piece);
            model::Position pos=model::Position(i,j);
            s1->updateSquare(square,pos,model::Color::Blue);
            QObject::connect(s1,SIGNAL(clicked()),s1,SLOT(mouseClick()));
            QObject::connect(s1,SIGNAL(click(SquareG&)),this,SLOT(select(SquareG&)));
            this->playerPiece->addWidget(s1,i,j);

        }

    }
}
void initBoard::on_startButton_clicked(){

}



