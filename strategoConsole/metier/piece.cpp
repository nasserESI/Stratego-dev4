#include "piece.h"
namespace model {
Piece::Piece(){}

Piece::Piece(TypePiece type,Color color) :type(type),color(color){}


bool Piece::isHigherValue(const Piece &piece) const{
    if(piece.getType()==TypePiece::Flag)
        return true;
    if(piece.getType()==TypePiece::Bombe && this->type!=TypePiece::Demineur)
        return false;
    if(piece.getType()==TypePiece::Demineur && this->type==TypePiece::Bombe)
        return false;
    if( this->type==TypePiece::Demineur  && piece.getType()==TypePiece::Bombe)
        return true;
    if(piece.getType()==TypePiece::Marechal && this->type==TypePiece::Espionne)
        return true;
    return static_cast<int>(this->type) > static_cast<int>(piece.getType());
}

bool Piece::hasSameRank(const Piece &piece) const{
    return static_cast<int>(this->type) == static_cast<int>(piece.getType());
}

void Piece::addMove(const Move &move){

    this->historical.addMove(move);

}
bool Piece::isMyColor(Color color)const{
    return this->color==color;

}
Color Piece::getColor()const{
    return this->color;
}
bool Piece::getVisible()const{
    return this->visible;
}
const HistoricalMove&  Piece::getHistoricalMove() const{
   return this->historical;
}
TypePiece Piece::getType()const{
    return this->type;
}
int Piece::getLenghtHistorical() const{
    return this->historical.getLength();
}
void Piece::setVisiblity(bool value){
    this->visible=value;
}
bool Piece::checkRoundTrip(const Move &move)const{




    if(this->getLenghtHistorical()<5)
        return false;
     std::array<Move ,6> cp;
     for(unsigned i = 0 ; i < 5;i++){
         cp[i]=historical.getHistoricalMove()[i];
     }
     cp[5]=move;
     int count = countDistinct(cp);
     if(count==2)
         return true;
     else return false;
   return false;
}

int Piece::countDistinct(std::array<Move ,6> arr) const
{
    int res = 1;

    // Pick all elements one by one
    for (int i = 1; i < 6; i++) {
        int j = 0;
        for (j = 0; j < i; j++)
            if (arr[i] == arr[j])
                break;

        // If not printed earlier, then print it
        if (i == j)
            res++;
    }
    return res;
}
}

