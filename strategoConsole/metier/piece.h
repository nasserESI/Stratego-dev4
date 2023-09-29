#ifndef PIECE_H
#define PIECE_H
#include "TypePiece.h"
#include "Color.h"
#include "HistoricalMove.h"
#include <iostream>
namespace model {
    /**
     * @brief this class define a piece with a color,a type,
     * the visibility, a story of move.
     */
class Piece
{
private:
    TypePiece type;
    Color color;
    bool visible=false;
    HistoricalMove historical;
    int countDistinct(std::array<Move ,6> arr) const;
public:
    Piece();
     /**
     * @brief Piece is defined by the color which mean the team and
     * the type which means the hierarchy in the team.this will help us to allow or forbbid certains
     * moves.
     * @param type : element of an enumeration in order to see how is the piece ranked
     * so that we can determine if this one is stronger than another one.
     * @param color :element of an enumeration in order to determine the team.
     */
    Piece(TypePiece type,Color color);
    /**
     * @brief isHigherValue
     * @param piece : the piece of the opposite team
     * @return return true if the current piece is "stronger than the other one."
     * return false in the opposite case.
     */
    bool isHigherValue(const Piece &piece) const;
    /**
     * @brief hasSameRank tells us if the pieces of both teams have the same rank.
     * @param piece : the opposite team's piece.
     * @return true if the pieces have the same rank or false in the opposite case
     */
    bool hasSameRank(const Piece &piece) const;
    /**
     * @brief addMove : the pieces have moves. and in the rules the piece cannot
     * moves tree times from two same places.
     * that's why we have set a list of moves to update each turn.
     * @param move the move that we need to put in the list of move for each piece.
     */
    void addMove(const Move &move);
    /**
     * @brief isMyColor
     * @param color : the given color for certain pieces
     * @return return true if the piece has the same color or false in the opposite case.
     */
    bool isMyColor(Color color)const;
    /**
     * @brief getColor
     * @return the given color for a given piece.
     */
    Color getColor()const;
    /**
     * @brief getVisible
     * @return true if the given piece is visible or false in the opposite case.
     */
    bool getVisible()const;
    /**
     * @brief getType
     * @return gives the type for a givens piece.
     */
    TypePiece getType()const;
    /**
     * @brief getHistoricalMove
     * @return gives the array of the 3 latest moves.
     */
    const HistoricalMove& getHistoricalMove() const;
    /**
     * @brief getLenghtHistorical
     * @return gives the limit bound of the array
     */
    int getLenghtHistorical() const;
    /**
      * @brief setVisiblity : change the visibility with the boolean variable 
      * passed in parameter.
      * @param value the boolean to update the visibility
      */
     void setVisiblity(bool value);
     /**
      * @brief 
      * 
      * @param move 
      * @return true 
      * @return false 
      */
     bool checkRoundTrip(const Move &move)const;

};

}

#endif // PIECE_H
