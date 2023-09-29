#ifndef BOARD_H
#define BOARD_H
#include "array"
#include "square.h"
#include <stdexcept>
#include <stdlib.h>
#include <fstream>
#include <bits/stdc++.h>
namespace model {
    /**
     * @brief this class deal with the control of the pieces
     *
     * 
     */
class Board
{
private:
    std::array<std::array<Square,10>,10> board;
    std::optional<Piece>& getPiece(const Position &position) ;
    void tokenize(std::string const &str, const char delim,
                  std::vector<std::string> &out) const ;
    bool checkFile(std::string path)const;
    void initBoard();
    bool checkWater(int column , int row)const;
public:
    Board();
    /**
     * @brief Construct a new Board object
     * defined by two string path.
     * @param path 
     * @param path2 
     */
    Board(std::string path,std::string path2="");
    /**
     * @brief this methods add a move
     * 
     * @param move this move is composed by 
     */
    void move(const Move &move);
    /**
     * @brief check if the position is in the board
     * 
     * @param position is the given position by one of the users
     * @return true if it is inside 
     * otherwise it is false
     */
    bool isPositionInBoard(const Position &position)const;
    /**
     * @brief check if the square is empty
     * @param position is the given one by the user
     * @return true return true if the square is really empty
     * otherwise it return false.
     */
    bool isSquareEmpty(const Position &position) const;
    /**
     * @brief check if it is the same color as the player.
     * 
     * @param position is given position by the user
     * @param color is given color by the user
     * @return true if it is the same color. 
     * @return false if it the color is not the same.
     */
    bool isSameColor(const Position &position,Color color) const;
    /**
     * @brief this methods check how is the winner.
     * 
     * @return Color the color of the winner
     */
    Color checkWiner();
    /**
     * @brief this methods is set to attach the opponent.
     * @param move the given move by the user
     */
    void attack(const Move &move);
    /**
     * @brief check if the piece is a flag or a bombe because thoses pieces can't move.
     * 
     * @param piece the chosen piece by the user
     * @return true if it can move 
     * @return false if it can't move
     */
    bool pieceCanMove(const std::optional<Piece>& piece)const ;
    /**
     * @brief Set the Visiblity Piece object to true  
     * 
     * @param position given position by the user
     * @param value changed in case of attack
     */
    void setVisiblityPiece(const Position &position,bool value);
    /**
     *
     * @brief gives the data of the board
     * 
     * @return an array 10x10 
     */
    const std::array<std::array<Square,10>,10> getBoard()const;
    /**
     * @brief thhis methods is set to check if the moves is an attempte to attack
     * 
     * @param move is given by the user
     * @param color is the color of the user
     * @return true return true if there is defenetely an attack
     * @return false return false if it is a simple move
     */
    bool isItAttack(const Move &move,Color color)  ;
    /**
     * @brief  to check if a move is possible
     * 
     * @param move the given move by the user
     * @return true if it can move
     * @return false if can't
     */
    bool checkMove(const Move & move , Color);
    /**
     * @brief this methods is set to put a piece
     * 
     * @param pos the position is given by the user
     * @param piece is chosen by the user
     */
    void put(const Position & pos,Piece &piece);
};
}


#endif // BOARD_H
