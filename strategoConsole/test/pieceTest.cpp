#include "catch.hpp"
#include "piece.h"
using namespace model;
TEST_CASE("Testing methods of the Piece class")
{


    SECTION("Test of method addMove ")
    {
        Piece p=Piece(TypePiece::Colonel,Color::Blue);
       Position posAller = Position(0,1);
       Position posAller2= Position(0,2);


       Move move1 = Move(posAller,posAller2);
       Move move2 = Move(posAller2,posAller);
        Move move3 = Move(posAller,posAller2);
         Move move4 = Move(posAller2,posAller);
         Move move5 = Move(posAller,posAller2);

         p.addMove(move1);
        p.addMove(move2);
        p.addMove(move3);
        p.addMove(move4);
        p.addMove(move5);
        REQUIRE(p.getLenghtHistorical()==5);
    }
    SECTION("Test of method CheckroundTrip where round trip = true")
    {
        Piece p=Piece(TypePiece::Colonel,Color::Blue);
       Position posAller = Position(0,1);
       Position posAller2= Position(0,2);


       Move move1 = Move(posAller,posAller2);
       Move move2 = Move(posAller2,posAller);
        Move move3 = Move(posAller,posAller2);
         Move move4 = Move(posAller2,posAller);
         Move move5 = Move(posAller,posAller2);
           Move move6 = Move(posAller2,posAller);

         p.addMove(move1);
        p.addMove(move2);
        p.addMove(move3);
        p.addMove(move4);
        p.addMove(move5);
        REQUIRE(p.checkRoundTrip(move6)==true);
    }
    SECTION("Test of method CheckroundTrip where round trip = False")
    {
        Piece p=Piece(TypePiece::Colonel,Color::Blue);
       Position posAller = Position(0,1);
       Position posAller2= Position(0,2);
       Position rienAvoir1=Position(0,8);


       Move move1 = Move(rienAvoir1,posAller2);
       Move move2 = Move(posAller2,posAller);
        Move move3 = Move(posAller,posAller2);
         Move move4 = Move(posAller2,posAller);
         Move move5 = Move(posAller,posAller2);
           Move move6 = Move(posAller2,posAller);

         p.addMove(move1);
        p.addMove(move2);
        p.addMove(move3);
        p.addMove(move4);
        p.addMove(move5);
        REQUIRE(p.checkRoundTrip(move6)==false);
    }


}
