#include "player.h"
namespace  model{

Player::Player(std::string name,Color color):color(color),name(name)
{

}
Color Player::getColor()const{
    return this->color;
}

std::string Player::getName() const{
    return this->name;
}
}
