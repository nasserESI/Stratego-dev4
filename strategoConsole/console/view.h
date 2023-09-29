#ifndef VIEW_H
#define VIEW_H
#include <string>
#include "square.h"
#include <vector>
#include <array>

class View
{
private:

public:
    View();
    void initialize();
    void quit();
    void displayError(std::string error);
    void displayBoard( std::array<std::array<model::Square,10>,10>,model::Color color=model::Color::Null);
    void displayWinner(std::string name);
    void displayEndGame();
    void displayPositionsPossible(const std::vector<model::Position>& position);
    void displayCurrentPlayer(std::string);
    void welcomeGame();
    void askWhichModeForInit();
    void askPathFile();
    void askNbOfFile();
    void askPlayerName1();
    void askPlayerName2();
    void askToChoseSourceMove();
    void askToChoseDestinationMove();
    void askToChoseSymboleToPut();
    void askWherePutPiece();
    void askPlayerRedPutPiece();
     void askPlayerBluePutPiece();
     void printDraw();
};

#endif // VIEW_H
