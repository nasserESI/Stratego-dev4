#include "catch.hpp"
#include "board.h"
using namespace model;
TEST_CASE("Testing methods of the Board class")
{
    Board board = Board();

    SECTION("Test of method isPositionInBoard ")
    {
        Position pos = Position(0,12);

        REQUIRE(board.isPositionInBoard(pos)==false);


    }
    SECTION("Test of method isSquareEmpty with wrong position ")
    {
        Position pos = Position(0,12);



        REQUIRE_THROWS_AS(board.isSquareEmpty(pos),std::invalid_argument);

    }
    SECTION("Test of method isSquareEmpty with good position and empty square ")
    {
        Position pos = Position(0,3);



        REQUIRE(board.isSquareEmpty(pos)==true);

    }
    SECTION("Test of method isSquareEmpty with good position and not empty square ")
    {
        Position pos = Position(0,3);
        Piece p = Piece(TypePiece::Bombe,Color::Blue);
        board.put(pos,p);

        REQUIRE(board.isSquareEmpty(pos)==false);

    }
    SECTION("Test of method sameColor  not same ")
    {
        Position pos = Position(0,3);
        Piece p = Piece(TypePiece::Bombe,Color::Blue);
        board.put(pos,p);

        REQUIRE(board.isSameColor(pos,Color::Red)==false);

    }
    SECTION("Test of method sameColor   same ")
    {
        Position pos = Position(0,3);
        Piece p = Piece(TypePiece::Bombe,Color::Blue);
        board.put(pos,p);

        REQUIRE(board.isSameColor(pos,Color::Blue)==true);

    }
    SECTION("Test of method checkMove Wrong move")
    {
        Board board2=Board("../metier/example.txt");
        Position p1=Position(0,1);
        Position p2 = Position(0,2);
        Move move=Move(p1,p2);
       REQUIRE_THROWS_AS(board2.checkMove(move,Color::Red),std::invalid_argument);

    }
    SECTION("Test of method checkMove Good move")
    {
        Board board2=Board("../metier/example.txt");
        Position p1=Position(4,3);
        Position p2 = Position(4,4);
        Move move=Move(p1,p2);
       REQUIRE(board2.checkMove(move,Color::Blue)==true);

    }
    SECTION("Test of method checkMove wrong move")
    {
        Board board2=Board("../metier/example.txt");
        Position p1=Position(3,3);
        Position p2 = Position(3,4);
        Move move=Move(p1,p2);
        REQUIRE_THROWS_AS(board2.checkMove(move,Color::Red),std::invalid_argument);

    }
    SECTION("Test of method checkMove good move")
    {
        Board board2=Board("../metier/example.txt");
        Position p1=Position(5,3);
        Position p2 = Position(5,4);
        Move move=Move(p1,p2);
        REQUIRE(board2.checkMove(move,Color::Blue)==true);

    }
    SECTION("Test of method checkMove wrong move")
    {
        Board board2=Board("../metier/example.txt");
        Position p1=Position(5,3);
        Position p2 = Position(5,5);
        Move move=Move(p1,p2);
        REQUIRE_THROWS_AS(board2.checkMove(move,Color::Red),std::invalid_argument);

    }
    SECTION("Test of method checkMove good move")
    {   Piece p = Piece(TypePiece::Eclaireur,Color::Red);

        Position p1=Position(3,0);
        board.put(p1,p);
        Position p2 = Position(3,7);
        Move move=Move(p1,p2);
        REQUIRE_THROWS_AS(board.checkMove(move,Color::Red),std::invalid_argument);

    }
    SECTION("Test of method checkMove wrong move")
    {   Piece p = Piece(TypePiece::Eclaireur,Color::Red);

        Position p1=Position(3,0);
        board.put(p1,p);
        Position p2 = Position(3,3);
        Move move=Move(p1,p2);
        REQUIRE(board.checkMove(move,Color::Red)==true);

    }
    SECTION("Test of method checkMove wrong move")
    {   Piece p = Piece(TypePiece::Eclaireur,Color::Red);

        Position p1=Position(3,0);
        Position p3=Position(3,2);
        board.put(p1,p);
        board.put(p3,p);
        Position p2 = Position(3,3);
        Move move=Move(p1,p2);
        REQUIRE_THROWS_AS(board.checkMove(move,Color::Red),std::invalid_argument);

    }
    SECTION("Test of method checkMove good  attack")
    {   Piece p = Piece(TypePiece::Eclaireur,Color::Red);
        Piece piece2 = Piece(TypePiece::Eclaireur,Color::Blue);

        Position p1=Position(3,0);
        Position p3=Position(3,2);
        board.put(p1,p);
        board.put(p3,piece2);
        Move move=Move(p1,p3);
        REQUIRE(board.checkMove(move,Color::Red)==true);

    }
    SECTION("Test of method checkMove Wrong color")
    {   Piece p = Piece(TypePiece::Eclaireur,Color::Red);
        Piece piece2 = Piece(TypePiece::Eclaireur,Color::Blue);

        Position p1=Position(3,0);
        Position p3=Position(3,2);
        board.put(p1,p);
        board.put(p3,piece2);
        Move move=Move(p1,p3);
        REQUIRE_THROWS_AS(board.checkMove(move,Color::Blue),std::invalid_argument);

    }
    SECTION("Test of method isAttack  no attack")
    {   Piece p = Piece(TypePiece::Eclaireur,Color::Red);

        Position p1=Position(3,0);
        Position p3=Position(3,2);
        board.put(p1,p);
        Move move=Move(p1,p3);
        REQUIRE(board.isItAttack(move,Color::Red)==false);

    }
    SECTION("Test of method isAttack attack")
    {   Piece p = Piece(TypePiece::Eclaireur,Color::Red);
         Piece piece2 = Piece(TypePiece::Eclaireur,Color::Blue);
        Position p1=Position(3,0);
        Position p3=Position(3,2);
        board.put(p1,p);
        board.put(p3,piece2);
        Move move=Move(p1,p3);
        REQUIRE(board.isItAttack(move,Color::Red)==true);

    }
    SECTION("Test of method isAttack with piece can't move")
    {   Piece p = Piece(TypePiece::Bombe,Color::Red);
         Piece piece2 = Piece(TypePiece::Eclaireur,Color::Blue);
        Position p1=Position(3,0);
        Position p3=Position(3,2);
        board.put(p1,p);
        board.put(p3,piece2);
        Move move=Move(p1,p3);
        REQUIRE_THROWS_AS(board.isItAttack(move,Color::Blue),std::invalid_argument);

    }
    SECTION("Test of method Attack bombe")
    {   Piece p = Piece(TypePiece::Bombe,Color::Red);
         Piece piece2 = Piece(TypePiece::Eclaireur,Color::Blue);
        Position p1=Position(3,0);
        Position p3=Position(3,2);
        board.put(p1,p);
        board.put(p3,piece2);
        Move move=Move(p3,p1);
        board.attack(move);
        REQUIRE(board.isSquareEmpty(p3)==true);

    }
    SECTION("Test of method Attack 2 pion same value")
    {   Piece p = Piece(TypePiece::Eclaireur,Color::Red);
         Piece piece2 = Piece(TypePiece::Eclaireur,Color::Blue);
        Position p1=Position(3,0);
        Position p3=Position(3,2);
        board.put(p1,p);
        board.put(p3,piece2);
        Move move=Move(p3,p1);
        board.attack(move);
        REQUIRE((board.isSquareEmpty(p3) && board.isSquareEmpty(p1)) ==true);

    }
    SECTION("Test of method Attack  espionne vs Marechal")
    {   Piece p = Piece(TypePiece::Espionne,Color::Red);
         Piece piece2 = Piece(TypePiece::Marechal,Color::Blue);
        Position p1=Position(3,0);
        Position p3=Position(3,1);
        board.put(p1,p);
        board.put(p3,piece2);
        Move move=Move(p1,p3);
        board.attack(move);
        REQUIRE((!board.isSquareEmpty(p3) && board.isSquareEmpty(p1)) ==true);

    }
    SECTION("Test of method Attack  espionne vs Marechal")
    {   Piece p = Piece(TypePiece::Espionne,Color::Red);
         Piece piece2 = Piece(TypePiece::Marechal,Color::Blue);
        Position p1=Position(3,0);
        Position p3=Position(3,1);
        board.put(p1,p);
        board.put(p3,piece2);
        Move move=Move(p1,p3);
        board.attack(move);
        REQUIRE(board.getBoard()[p3.getColumn()][p3.getRow()].getPiece()->getType() == TypePiece::Espionne);

    }





}
