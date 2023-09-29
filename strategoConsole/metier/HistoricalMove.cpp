#include "HistoricalMove.h"
namespace model{
HistoricalMove::HistoricalMove(){}


 std::array<Move,5> HistoricalMove::getHistoricalMove() const{
    return this->historicalMove;
}


void HistoricalMove::addMove(const Move &move){
    this->historicalMove[length%5]=move;
    length++;
}
int HistoricalMove::getLength()const{
    return this->length;
}

}
