#ifndef HISTORICALMOVE_H
#define HISTORICALMOVE_H
#include "Move.h"
#include <array>
namespace model{
    /**
     * @brief this class define an object "historicalMove" as 
     *  an array of moves.
     * 
     */
class HistoricalMove{
private:
     std::array<Move,5> historicalMove;
    int length;
public:
    HistoricalMove();
    /**
    * @brief HistoricalMove::getLength
    * @return an integer shild represente the size of the list
    */
    int getLength()const;
    /**
     * @brief Get the Historical Move object
     * 
     * @return std::array<Move,5> which is the "story of the previous moves"
     */
    std::array<Move,5> getHistoricalMove() const;
    /**
     * @brief this methods add a move to a story
     * 
     * @param move the given move to add
     */
    void addMove(const Move &move);
};
}
#endif // HISTORICALMOVE_H
