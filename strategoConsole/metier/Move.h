#ifndef MOVE_H
#define MOVE_H
#include "Position.h"
#include <stddef.h>
namespace model{
    /**
     * @brief thise class define a move has a pair of two positions
     * with the getters
     * 
     */
class Move{
private:
    Position start;
    Position end;
public:
    Move();
     /**
     * @brief Move : define a move as a paire of positions
     * @param start : source position
     * @param end : destination
     */
    Move(Position &start,Position &end);
    /**
    * @brief Move::getStart : define the first position
    * @return a move.
    */
    Position getStart()const;
    /**
    * @brief Move::getEnd : define the second move because a move is defined by two position
    * @return  a move
    */
    Position getEnd()const;

};
/**
 * @brief operator == : check if two moves are equals
 * @param move
 * @param move2
 * @return gives true if move and move2 are equals. false in the opposite way.
 */
inline bool operator==(const Move &move,const Move &move2){
    return move.getStart() == move2.getStart() && move.getEnd() == move2.getEnd();
}
/**
 * @brief the result of the calculation of the moves should be equal to one in order to 
 * be good.
 * 
 * @param move depature 
 * @param move2 arrival
 * @return int the result of the operation should be 1
 */
inline int operator-(Move &move,Move &move2){
    return (move.getStart().getRow()+move.getStart().getColumn())-(move2.getEnd().getRow()+move2.getEnd().getColumn());
}
}
#endif // MOVE_H
