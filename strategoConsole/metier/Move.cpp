#include "Move.h"
namespace model{
Move::Move(){

}
Move::Move(Position& start,Position& end):start(start),end(end){

}

Position Move::getStart()const{
    return this->start;
}
Position Move::getEnd()const{
    return this->end;
}

}

