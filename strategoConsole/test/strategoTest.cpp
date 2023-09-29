#include "catch.hpp"
#include "stratego.h"
using namespace model;
TEST_CASE("Testing methods of the Stratego class")
{
    Stratego game = Stratego(true);
    game.addPlayer("Younes",Color::Blue);
    game.addPlayer("Younes",Color::Red);

    game.initCurrentPlayer();



    SECTION("Test of method move Game state not good ")
    {


        REQUIRE_THROWS_AS(game.move(),Access_exception);


    }
    SECTION("Test of method move Game state  good ")
    {

        Piece p = Piece(TypePiece::Colonel,Color::Blue);
        Position pos = Position(0,0);

        game.put(pos,p);
        Position pos2=Position(0,1);
        Move move=Move(pos,pos2);
        if(game.getCurrentPlayer().getColor()==Color::Blue)
        std::cout << "bleu" << std::endl;
        else if (game.getCurrentPlayer().getColor()==Color::Red)
            std::cout << "red" << std::endl;
        else
            std::cout << "probleme" << std::endl;
        game.validateMove(move);
        game.isItAttack();
        game.move();
        REQUIRE(game.getBoard().isSquareEmpty(pos2)==false);


    }
}
