#ifndef PLAYER_H
#define PLAYER_H
#include "Color.h"
#include <string>
namespace model {
    /**
     * @brief this class define the identity of a player and his/her behaviour in the game
     * 
     */
class Player
{
private:
    Color color;
    std::string name;
public:
/**
 * @brief Construct a new Player object defined by his/her name
 * and his/her color
 * @param name : name of the player
 * @param color : color of the piece of the player
 */
    Player(std::string name,Color color);
    /**
     * @brief Get the Name object
     * 
     * @return the name of the player
     */
    std::string getName() const;
    /**
     * @brief Get the Color 
     * 
     * @return Color of the player
     */
    Color getColor() const;
};
}


#endif // PLAYER_H
