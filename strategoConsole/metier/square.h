#ifndef SQUARE_H
#define SQUARE_H
#include "piece.h"
#include "TypeSquare.h"
#include "optional"
namespace model {
  /**
   * @brief this methods gives everything to build and use a square in a board
   * 
   */
class Square
{
private:
  std::optional<Piece> piece;
  TypeSquare type;
public:
    Square();
    /**
     * @brief Square the square is defined by a type and a piece of a player
     * but the piece might be absent. thus, it has been defined as optional.
     * the piece are initialized afterward.
     * @param type the type of the square.
     */
    Square(TypeSquare type);
    /**
     * @brief this method check if the square has a piece
     * 
     * @return true if the square is "null". it means empty
     * @return false if the square has a piece.
     */
    bool isEmpty() const;
    /**
     * @brief help to check if the piece of the opponent is 
     * "stronger or not" in order to beat his/her piece up.
     * 
     * @param piece this opponent piece
     * @return true true if it is "stronger"
     * @return false if it is "weaker"
     */
    bool isHigherValue(const Piece &piece)const;
    /**
     * @brief check if the piece has the same value.
     * we mean by "value", the rank
     * @param piece the opponent piece.
     * @return true if it is the same value 
     * @return false if it is not the same
     */
    bool isSameValue(const Piece &piece)const;
    /**
     * @brief check if the color of the piece is the same as the player
     * when we get the color in parameter, then we can compare.
     * @param color the given color.
     * @return true if the player can use it.
     * @return false if the player can't use it.
     */
    bool isPieceColor(Color color)const;
    /**
     * @brief Set the Piece Visible or invisible
     * 
     * @param value given to update the visibility of the piece.
     */
    void setPieceVisible(bool value);
    /**
     * @brief update the piece. 
     * @param piece the piece given by the user
     */
    void setPiece(Piece &piece);
    /**
     * @brief this method swap the pieces
     * even if the square is empty. then, it means that the piece
     * that the empty value 
     * @param piece the piece of the other square.
     */
    void swapPiece(std::optional<Piece> &piece);
    /**
     * @brief this methode is used at the beginning of the game to 
     * setup the board with "field" or "water"
     * 
     * @param type that might be "water" or "field"
     */
    void setType(TypeSquare type);
    /**
     * @brief Get the Type of the square to not fall in the water.
     * 
     * @return TypeSquare 
     */
    TypeSquare getType()const;
    /**
     * @brief Get the Piece To Swap 
     * 
     * @return std::optional<Piece>& 
     */
    std::optional<Piece>& getPieceToSwap();
    /**
     * @brief gives the reference of the piece
     * 
     * @return const std::optional<Piece>& 
     */
    const std::optional<Piece>& getPiece() const;

};
}


#endif // SQUARE_H
