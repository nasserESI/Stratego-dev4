#include "board.h"


namespace model {
Board::Board()
{
    initBoard();
}

bool isParam(std::string line)
{
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}
Board::Board(std::string path,std::string path2):Board(){
    std::string line;
    char delem=' ';
    if(path2==""){
        std::ifstream myfile (path);
        unsigned row=0;
        if (myfile.is_open())
        {
          while ( getline (myfile,line) )
          {
            std::vector <std::string> out;
            tokenize(line,delem,out);
            for(unsigned i =0;i< out.size();i++){

                TypePiece typePiece;
                if(isParam(out.at(i))){
                    typePiece =static_cast<model::TypePiece>(std::stoi(out.at(i)));;
                }
                else{
                     typePiece =static_cast<model::TypePiece>(out.at(i)[0]);

                }

                Piece pred=Piece(typePiece,Color::Blue);
                this->board[i][row].setPiece(pred);
                Piece pblue=Piece(typePiece,Color::Red);
                this->board[i][9-row].setPiece(pblue);
            }
            row++;

          }
          myfile.close();
        }
        else
            throw std::invalid_argument("File does not exist");
    }
    else{
        std::ifstream myfile (path);
        std::ifstream myfile2 (path);
        unsigned row=0;
        if (myfile.is_open())
        {
          while ( getline (myfile,line) )
          {
            std::vector <std::string> out;
            tokenize(line,delem,out);
            for(unsigned i =0;i< out.size();i++){


                TypePiece typePiece;
                if(isParam(out.at(i))){
                    typePiece =static_cast<model::TypePiece>(std::stoi(out.at(i)));;
                }
                else{
                     typePiece =static_cast<model::TypePiece>(out.at(i)[0]);

                }
                Piece pblue= Piece(typePiece,Color::Blue);
                this->board[i][row].setPiece(pblue);
            }
            row++;

          }
          myfile.close();
        }
        else
            throw std::invalid_argument("File does not exist");
        row=0;
        if (myfile2.is_open())
        {
          while ( getline (myfile2,line) )
          {
            std::vector <std::string> out;
            tokenize(line,delem,out);
            for(unsigned i =0;i< out.size();i++){


                TypePiece typePiece;
                if(isParam(out.at(i))){
                    typePiece =static_cast<model::TypePiece>(std::stoi(out.at(i)));;
                }
                else{
                     typePiece =static_cast<model::TypePiece>(out.at(i)[0]);

                }
                Piece pred=Piece(typePiece,Color::Red);
                this->board[i][9-row].setPiece(pred);
            }
            row++;

          }
          myfile.close();
        }
        else
            throw std::invalid_argument("File does not exist");
    }
}
void Board::put( const Position & pos,Piece &piece){
     this->board[pos.getColumn()][pos.getRow()].setPiece(piece);
}
void Board::tokenize(std::string const &str, const char delim,
            std::vector<std::string> &out)const
{
    // construct a stream from the string
    std::stringstream ss(str);

    std::string s;
    while (std::getline(ss, s, delim)) {
        out.push_back(s);
    }
}
void Board::initBoard(){
    for(unsigned i = 0 ; i < this->board.size() ;i++){
        for(unsigned j=0; j < this->board[i].size();j++){
            if(checkWater(i,j)){
                this->board[i][j]=Square(TypeSquare::Water);
            }
            else{
                this->board[i][j]=Square(TypeSquare::Field);
            }
        }
    }


}
bool Board::checkWater(int column ,int row)const{
    if((row==4 && column==2) ||(row==4 &&column==3)||
           (row==5 && column==2) || (row==5 && column==3) )
        return true;

    if((row==4 && column==6) || (row==5 && column==6) ||
           (row==4 && column==7) || (row==5 && column==7))
        return true;
    return false;
}
bool Board::isPositionInBoard(const Position &position)const{
   if(position.getRow()>=0 && position.getRow()<10 && position.getColumn()>=0 && position.getColumn()<10)
       return true;
   return false;
}

bool Board::isSquareEmpty(const Position &position) const{
    if(!isPositionInBoard(position))
        throw std::invalid_argument("The given position is out of bound");
    return this->board[position.getColumn()][position.getRow()].isEmpty();
}
bool Board::isSameColor(const Position &position,Color color) const{
    if(!isPositionInBoard(position))
        throw std::invalid_argument("The given position is out of bound");
    return this->board[position.getColumn()][position.getRow()].isPieceColor(color);
}
void Board::move(const Move &move){




    board[move.getStart().getColumn()][move.getStart().getRow()].swapPiece(getPiece(move.getEnd()));
    getPiece(move.getStart())->addMove(move);






}
 std::optional<Piece>& Board::getPiece(const Position &position){
    if(!isPositionInBoard(position))
        throw std::invalid_argument("The given position is out of bound");
    return this->board[position.getColumn()][position.getRow()].getPieceToSwap();
}

bool Board::pieceCanMove(const std::optional<Piece>& piece)const {
    if(piece->getType()==TypePiece::Bombe)
        return false;
    if(piece->getType()==TypePiece::Flag)
        return false;
    return true;

}
void Board::setVisiblityPiece(const Position &position,bool value){
    this->board[position.getColumn()][position.getRow()].getPieceToSwap()->setVisiblity(value);
}
void Board::attack(const Move &move){


          if(this->board[move.getStart().getColumn()][move.getStart().getRow()].isSameValue(this->board[move.getEnd().getColumn()][move.getEnd().getRow()].getPiece().value())){
                this->board[move.getStart().getColumn()][move.getStart().getRow()].getPieceToSwap().reset();
                this->board[move.getEnd().getColumn()][move.getEnd().getRow()].getPieceToSwap().reset();
                return;

            }
            if(this->board[move.getStart().getColumn()][move.getStart().getRow()].isHigherValue(this->board[move.getEnd().getColumn()][move.getEnd().getRow()].getPiece().value())){

                board[move.getStart().getColumn()][move.getStart().getRow()].swapPiece(getPiece(move.getEnd()));
                this->board[move.getStart().getColumn()][move.getStart().getRow()].getPieceToSwap().reset();


            }else{
                this->board[move.getStart().getColumn()][move.getStart().getRow()].getPieceToSwap().reset();

            }



}


Color Board::checkWiner(){
    bool red=false;
    bool blue=false;
    unsigned nbPieceRed=0;
    unsigned nbPieceBlue=0;
    for(unsigned i=0;i<10;i++){
        for(unsigned j = 0;j<10;j++){
            if( this->board[i][j].getPiece().has_value()){
                if(this->board[i][j].getPiece()->getType()==TypePiece::Flag && this->board[i][j].getPiece()->getColor()==Color::Blue)
                    blue=true;
                if(this->board[i][j].getPiece()->getType()==TypePiece::Flag && this->board[i][j].getPiece()->getColor()==Color::Red)
                    red=true;
                if(this->board[i][j].getPiece()->getColor()==Color::Red && this->board[i][j].getPiece()->getType()!= TypePiece::Bombe)
                    nbPieceRed++;
                if(this->board[i][j].getPiece()->getColor()==Color::Blue && this->board[i][j].getPiece()->getType()!= TypePiece::Bombe)
                    nbPieceBlue++;
            }
        }
    }

    if(red && !blue)
        return Color::Red;
    if(blue && !red )
        return Color::Blue;

    if(nbPieceBlue==1 && nbPieceRed==1)
        return Color::Draw;
    if(nbPieceRed==1)
        return Color::Blue;
    if(nbPieceBlue==1)
        return Color::Red;

     if(red && blue)
        return Color::Null ;
     return Color::Null;
}
const std::array<std::array<Square,10>,10> Board::getBoard()const{
    return this->board;
}

bool Board::isItAttack(const Move &move,Color color) {
    if(checkMove(move,color))
    return !isSquareEmpty(move.getEnd());
    return false;
}

bool Board::checkMove(const Move &move, Color color)
{

    if(!isPositionInBoard(move.getStart()) || !isPositionInBoard(move.getEnd()))
        throw std::invalid_argument("The given position is out of bound");
    if(!isSquareEmpty(move.getEnd()) && getPiece(move.getEnd())->getColor()==color)
        throw std::invalid_argument("There is already your own piece at this position, you can't move here");
    if(isSquareEmpty(move.getStart()))
        throw std::invalid_argument("You don't have any piece at this position");
    if(this->board[move.getStart().getColumn()][move.getStart().getRow()].getType()==TypeSquare::Water || this->board[move.getEnd().getColumn()][move.getEnd().getRow()].getType()==TypeSquare::Water)
        throw std::invalid_argument("Atempt to walk over the water!!");
    if(!isSameColor(move.getStart(),color))
        throw std::invalid_argument("You can't move a piece who doesn't not belong to you ");
    if(!pieceCanMove(getPiece(move.getStart())))
        throw std::invalid_argument("This piece can't move");
    if(getPiece(move.getStart())->checkRoundTrip(move))
        throw std::invalid_argument("You can't do 3 round trips");
    if(getPiece(move.getStart())->getType()!= TypePiece::Eclaireur){
        if(abs(move.getStart()-move.getEnd())!=1)
            throw std::invalid_argument("Move unnacceptable");
    }else{

        if(move.getStart().getRow()== move.getEnd().getRow() && move.getStart().getColumn()!= move.getEnd().getColumn()){
                if(move.getStart().getColumn()>move.getEnd().getColumn()){

                    unsigned startCol=move.getStart().getColumn();
                    unsigned endCol=move.getEnd().getColumn();

                    while(startCol>endCol+1){
                        if(!this->board[startCol-1][move.getStart().getRow()].isEmpty())
                            throw std::invalid_argument("There is already a piece on the way where you want to move");
                        if(this->board[startCol-1][move.getStart().getRow()].getType()==TypeSquare::Water)
                            throw std::invalid_argument("There is water on the way where you want to move");


                        startCol--;
                    }

                }
                else if(move.getStart().getColumn()<move.getEnd().getColumn()){

                    unsigned startCol=move.getStart().getColumn();
                    unsigned endCol=move.getEnd().getColumn();

                    while(startCol<endCol-1){
                        if(!this->board[startCol+1][move.getStart().getRow()].isEmpty())
                            throw std::invalid_argument("There is already a piece on the way where you want to move");
                        if(this->board[startCol+1][move.getStart().getRow()].getType()==TypeSquare::Water)
                            throw std::invalid_argument("There is water on the way where you want to move");

                        startCol++;
                    }

                }
        }
        else if(move.getStart().getRow()!= move.getEnd().getRow() && move.getStart().getColumn()== move.getEnd().getColumn()){
            if(move.getStart().getRow()>move.getEnd().getRow()){

                unsigned startRow=move.getStart().getRow();
                unsigned endRow=move.getEnd().getRow();

                while(startRow>endRow+1){
                    if(!this->board[move.getStart().getColumn()][startRow-1].isEmpty())
                        throw std::invalid_argument("There is already a piece on the way where you want to move");
                    else if (this->board[move.getStart().getColumn()][startRow-1].getType()==TypeSquare::Water)
                        throw std::invalid_argument("There is water on the way where you want to move");
                    startRow--;
                }


            }
            else if(move.getStart().getRow()<move.getEnd().getRow()){

                    unsigned startRow=move.getStart().getRow();
                    unsigned endRow=move.getEnd().getRow();

                    while(startRow<endRow-1){

                        if(!this->board[move.getStart().getColumn()][startRow+1].isEmpty())
                            throw std::invalid_argument("There is already a piece on the way where you want to move");
                        else if(this->board[move.getStart().getColumn()][startRow+1].getType()==TypeSquare::Water){
                               throw std::invalid_argument("There is water on the way where you want to move");
                        }
                        startRow++;
                    }


    }
    }
        else{
            throw std::invalid_argument("Move unnacceptable");
        }


}
    return true;
}


}
