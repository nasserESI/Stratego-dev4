#ifndef STRATEGO_H
#define STRATEGO_H
#include "board.h"
#include "player.h"
#include "State.h"
#include "access_exception.h"
#include <utility>
#include "subject.h"
namespace  model{
    /**
     * @brief this class is set as the "facade class" to represent the whole model
     * 
     */
class Stratego : public nvs::Subject
{
private:
    Board board;
    std::vector<Player> players;
    bool modeVisible;
    Player *currentPlayer=nullptr;
    State state;
    const Move *moveSelected=nullptr;
    void setCurrenPlayer();
public:
    Stratego();
    /**
     * @brief Construct a new Stratego Object
     * 
     * @param modeVisible 
     * @param path1 
     * @param path2 
     */
    Stratego(bool modeVisible,std::string path1="",std::string path2="");
    /**
     * @brief this methods add a player
     * 
     * @param name the name of a player 
     * @param color the color chosen by this player
     */
    void addPlayer(std::string name,Color color);
    /**
     * @brief this methods is set to move
     * 
     */
    void move();
    /**
     * @brief this methods is set for the attack
     * 
     */
    void attack();
    /**
     * @brief Get the Mode object 
     * 
     * @return true if it is in debug mode
     * @return false if it is in normal mode
     */
    bool getMode() const;
    /**
     * @brief this methode check if one of the player is attacking the other
     * 
     * @return true true if one of them is attacking the other
     * @return false if it is not the case 
     */
    bool isItAttack() ;
    /**
     * @brief this method is used to put pieces somewhere
     * 
     * @param position the position given by the user
     * @param piece the piece chosen by the user
     */
    void put(const Position &position,Piece &piece);
    /**
     * @brief update the Visibility of a Piece 
     * 
     */
    void setVisibilityPiece();
    /**
     * @brief put the visibility back to false
     * 
     */
    void resetVisibilityPiece();
    /**
     * @brief Get the Current Player object
     * 
     * @return const Player& the reference to the current player object
     */
    const Player& getCurrentPlayer()const ;
    /**
     * @brief gives the board
     * 
     * @return const Board& 
     */
    const Board & getBoard()const ;
    /**
     * @brief this methods gives to priority to begin to the first player
     * 
     */
    void initCurrentPlayer();

    /**
     * @brief Gives all the possible moves for a piece in a certain position.
     * 
     * @param postion the givens position by the user
     * @return const std::vector<Position> which is all the possible move found
     */
    const std::vector<Position> getPositions(const Position &postion) const;
    /**
     * @brief this methods is given to validate the move
     * 
     * @param move the move given by the user
     * @return true if the move is good
     * @return false if the move is not good
     */
    bool validateMove(const Move & move);
    /**
     * @brief this methods gives the color of the winner
     * 
     * @return Color 
     */
    Color checkWinner();
    /**
     * @brief Get the Name of the Player 
     * 
     * @param color : the color the any concerned player
     * @return std::string 
     */
    std::string getNamePlayer(Color color);
    const Move& getMoveSelected() const;

};
}


#endif // STRATEGO_H
