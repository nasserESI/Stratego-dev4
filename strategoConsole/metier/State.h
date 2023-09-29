#ifndef STATE_H
#define STATE_H
namespace model {
    /**
     * @brief this enum is set to control the state of the game
     * 
     */
enum  State {
    CHECKMOVE,
    CHECKATTACK,
    SETVISIBILITY,
    ATTACK,
    MOVE,
    ENDGAME,



};
}

#endif // STATE_H

