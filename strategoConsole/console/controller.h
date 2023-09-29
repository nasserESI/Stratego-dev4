#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "stratego.h"
#include "view.h"
class Controller
{

private:
    View view;
    model::Stratego game;
    void initGame();
public:
    Controller(View view);
    void start();

};

#endif // CONTROLLER_H
