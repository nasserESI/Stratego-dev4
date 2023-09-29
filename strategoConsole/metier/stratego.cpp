#include "stratego.h"
namespace model
{
Stratego::Stratego(){

}
    Stratego::Stratego(bool modeVisible,std::string path1,std::string path2):modeVisible(modeVisible){

    if(path1=="")
        this->board=Board();
    else
        this->board=Board(path1,path2);
    state=State::CHECKMOVE;
}

    void Stratego::addPlayer(std::string name,Color color){
        this->players.push_back(Player(name,color));
    }

    void Stratego::setCurrenPlayer(){


        if(currentPlayer==nullptr)
            currentPlayer=&players.at(0);
        else if(currentPlayer==&players.at(0))
            currentPlayer=&players.at(1);
        else
            currentPlayer=&players.at(0);




    }

    void Stratego::move(){
        if(state==State::MOVE){
            this->board.move(*moveSelected);

             setCurrenPlayer();

             state=State::CHECKMOVE;
             notifyObservers();
        }
        else{
            throw Access_exception("You can't acces to this function");
        }


    }
    bool Stratego::getMode()const{
        return  this->modeVisible;
    }
    bool Stratego::isItAttack(){

        if(state==State::CHECKATTACK){
            bool value =this->board.isItAttack(*moveSelected,this->currentPlayer->getColor());

            if(value){
                state=State::SETVISIBILITY;
                return value;
            }
            else{
                state=State::MOVE;
                return value;
            }

        }
        else{
            throw Access_exception("You can't acces to this function");
        }

    }
    void Stratego::initCurrentPlayer(){
        if(this->currentPlayer==nullptr)
            this->currentPlayer=&players.at(0);
      }
    void Stratego::attack(){
        if(this->state==State::ATTACK){
            this->board.attack(*moveSelected);
            setCurrenPlayer();
            state=State::CHECKMOVE;
            notifyObservers();
        }
        else{
            throw Access_exception("You can't acces to this function");
        }

    }

    const Player& Stratego::getCurrentPlayer()const{
        return *currentPlayer;
    }
    void Stratego::setVisibilityPiece(){
        if(this->state==State::SETVISIBILITY){

            board.setVisiblityPiece(moveSelected->getStart(),true);
            board.setVisiblityPiece(moveSelected->getEnd(),true);
            state=State::ATTACK;
            notifyObservers();
    }
        else{
            throw Access_exception("You can't acces to this function");
        }
    }
    void Stratego::resetVisibilityPiece(){
        if(board.isSquareEmpty(moveSelected->getStart()))
            board.setVisiblityPiece(moveSelected->getStart(),false);
        if(board.isSquareEmpty(moveSelected->getEnd()))
            board.setVisiblityPiece(moveSelected->getEnd(),false);

        notifyObservers();



    }
    const Board & Stratego::getBoard()const {
        return this->board;
    }
   const std::vector<Position> Stratego::getPositions(const Position &position) const {
        std::vector<Position> positions;
         std::vector<std::pair<unsigned,unsigned>> checkPositions;
         std::pair<unsigned,unsigned> check1= std::make_pair(-1,0);
         std::pair<unsigned,unsigned> check2= std::make_pair(1,0);
         std::pair<unsigned,unsigned> check3= std::make_pair(0,1);
         std::pair<unsigned,unsigned> check4= std::make_pair(0,-1);
         checkPositions.push_back(check1);
         checkPositions.push_back(check2);
         checkPositions.push_back(check3);
         checkPositions.push_back(check4);




         if(getBoard().getBoard()[position.getColumn()][position.getRow()].isEmpty()
                || getBoard().getBoard()[position.getColumn()][position.getRow()].getPiece()->getType() == model::TypePiece::Bombe
                || getBoard().getBoard()[position.getColumn()][position.getRow()].getPiece()->getType() == model::TypePiece::Flag ||
                 getBoard().getBoard()[position.getColumn()][position.getRow()].getPiece()->getColor()!=this->currentPlayer->getColor())
                    return positions;


        if(getBoard().getBoard()[position.getColumn()][position.getRow()].getPiece()->getType() != model::TypePiece::Eclaireur){
                for(unsigned i=0;i<checkPositions.size();i++){
                    Position tmp=Position(position.getColumn()+checkPositions.at(i).first,position.getRow()+checkPositions.at(i).second);
                    if(getBoard().isPositionInBoard(tmp)
                            && board.getBoard()[tmp.getColumn()][tmp.getRow()].getType()!=TypeSquare::Water

                            && (board.isSquareEmpty(tmp) || !board.isSameColor(tmp,this->currentPlayer->getColor())))
                            positions.push_back(tmp);

                }

        }
        else{
            for(unsigned i=0;i<checkPositions.size();i++){
                unsigned column = checkPositions.at(i).first;
                unsigned row =checkPositions.at(i).second;
                while(board.isPositionInBoard(Position(position.getColumn()+column,position.getRow()+row))) {
                     if(!board.isSquareEmpty(Position(position.getColumn()+column,position.getRow()+row))){
                         if(!board.isSameColor(Position(position.getColumn()+column,position.getRow()+row),currentPlayer->getColor()))
                              positions.push_back(Position(position.getColumn()+column,position.getRow()+row));
                         break;
                     }
                     if(board.getBoard()[position.getColumn()+column][position.getRow()+row].getType()==TypeSquare::Water)
                         break;
                     positions.push_back(Position(position.getColumn()+column,position.getRow()+row));
                     column=column+checkPositions.at(i).first;
                     row=row+checkPositions.at(i).second;
            }


            }
        }
        return positions;
    }
   bool Stratego::validateMove(const Move& move){
       if(state==CHECKMOVE){
           if(board.checkMove(move,this->currentPlayer->getColor())){

               this->moveSelected=&move;
               this->state=CHECKATTACK;

               return true;
           }
       }else{
           throw Access_exception("You can't acces to this function");
       }

    return false;
   }


   void Stratego::put(const Position &position,Piece &piece){
       if(!board.isPositionInBoard(position))
            throw std::invalid_argument("position not in board");
       if(board.getBoard()[position.getColumn()][position.getRow()].getType()==TypeSquare::Water)
            throw std::invalid_argument("You can't walk on water");
       if(position.getRow()<=3 && piece.getColor()!=Color::Blue)
           throw std::invalid_argument("You can't put a piece here, it's the place of the other player");
       if(position.getRow()>3 && piece.getColor()==Color::Blue)
           throw std::invalid_argument("You can't put a piece here");
       if(position.getRow()>5 && piece.getColor()!=Color::Red)
           throw std::invalid_argument("You can't put a piece here, it's the place of the other player");
       if(position.getRow()<6 && piece.getColor()==Color::Red)
           throw std::invalid_argument("You can't put a piece here");
       if(!board.isSquareEmpty(position))
            throw std::invalid_argument("You have already a piece here");

        board.put(position,piece);
        notifyObservers();

   }
   const Move &Stratego::getMoveSelected() const{
       return *moveSelected;
   }
   Color Stratego::checkWinner(){
       return this->board.checkWiner();
   }
   std::string Stratego::getNamePlayer(Color color){
       for(unsigned i = 0 ; i<players.size();i++){
           if(players[i].getColor()==color)
               return players[i].getName();
       }
       return "Player not found";
   }


}

