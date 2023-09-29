#include "catch.hpp"
#include "square.h"
using namespace model;
TEST_CASE("Testing methods of the Square class")
{
    SECTION("Test of method isEmpty without piece")
    {
        Square s = Square(TypeSquare::Field);
        REQUIRE(s.isEmpty() ==true);
    }
    SECTION("Test of method isEmpty with piece ")
    {

        Square s = Square(TypeSquare::Field);
        Piece p =  Piece(TypePiece::Commandant,Color::Blue);
        s.setPiece(p);
        REQUIRE(s.isEmpty() ==false);
    }
    SECTION("Test of method isHigherValue with higherValue ")
    {

        Square s = Square(TypeSquare::Field);
        Piece p = Piece(TypePiece::Commandant,Color::Blue);
        s.setPiece(p);
        Piece piece = Piece(TypePiece::Demineur,Color::Red);

        REQUIRE(s.isHigherValue(piece) ==true);
    }
    SECTION("Test of method isHigherValue with LowerValue ")
    {

        Square s = Square(TypeSquare::Field);
        Piece p = Piece(TypePiece::Demineur,Color::Blue);
        s.setPiece(p);
        Piece piece = Piece(TypePiece::Commandant,Color::Red);

        REQUIRE(s.isHigherValue(piece) ==false);
    }
    SECTION("Test of method isHigherValue bombe vs other than demineur ")
    {

        Square s = Square(TypeSquare::Field);
        Piece p = Piece(TypePiece::Bombe,Color::Blue);
        s.setPiece(p);
        Piece piece = Piece(TypePiece::Commandant,Color::Red);

        REQUIRE(s.isHigherValue(piece) ==true);
    }
    SECTION("Test of method isHigherValue demineur vs bombe ")
    {

        Square s = Square(TypeSquare::Field);
        Piece p = Piece(TypePiece::Bombe,Color::Blue);
        s.setPiece( p);
        Piece piece = Piece(TypePiece::Demineur,Color::Red);

        REQUIRE(s.isHigherValue(piece) ==false);
    }
    SECTION("Test of method isHigherValue Espionne  vs Marechal ")
    {

        Square s = Square(TypeSquare::Field);
        Piece p = Piece(TypePiece::Espionne,Color::Blue);
        s.setPiece( p);
        Piece piece = Piece(TypePiece::Marechal,Color::Red);

        REQUIRE(s.isHigherValue(piece) ==true);
    }
    SECTION("Test of method isHigherValue Espionne  vs other ")
    {

        Square s = Square(TypeSquare::Field);
        Piece p =  Piece(TypePiece::Espionne,Color::Blue);
        s.setPiece(p);
        Piece piece = Piece(TypePiece::Lieutenant,Color::Red);

        REQUIRE(s.isHigherValue(piece) ==false);
    }
    SECTION("Test of method isHigherValue other vs bombe  ")
    {

        Square s = Square(TypeSquare::Field);
        Piece p = Piece(TypePiece::Commandant,Color::Blue);
        s.setPiece( p);
        Piece piece = Piece(TypePiece::Bombe,Color::Red);

        REQUIRE(s.isHigherValue(piece) ==false);
    }
    SECTION("Test of method isSameValue with no same value")
    {

        Square s = Square(TypeSquare::Field);
        Piece p = Piece(TypePiece::Commandant,Color::Blue);
        s.setPiece( p);
        Piece piece = Piece(TypePiece::Bombe,Color::Red);

        REQUIRE(s.isSameValue(piece) ==false);
    }
    SECTION("Test of method isSameValue with same value")
    {

        Square s = Square(TypeSquare::Field);
        Piece p = Piece(TypePiece::Commandant,Color::Blue);
        s.setPiece(p);
        Piece piece = Piece(TypePiece::Commandant,Color::Red);

        REQUIRE(s.isSameValue(piece) ==true);
    }
    SECTION("Test of method isSamePice color with same color")
    {

        Square s = Square(TypeSquare::Field);
        Piece p = Piece(TypePiece::Commandant,Color::Blue);
        s.setPiece(p);
        Piece piece = Piece(TypePiece::Commandant,Color::Blue);

        REQUIRE(s.isPieceColor(piece.getColor()) ==true);
    }
    SECTION("Test of method isSamePice color with different color")
    {

        Square s = Square(TypeSquare::Field);
        Piece p =  Piece(TypePiece::Commandant,Color::Blue);
        s.setPiece(p);
        Piece piece = Piece(TypePiece::Commandant,Color::Red);

        REQUIRE(s.isPieceColor(piece.getColor()) ==false);
    }
    SECTION("Test of method swapPiece")
    {

        Square s = Square(TypeSquare::Field);
        std::optional<Piece> piece= Piece(TypePiece::Commandant,Color::Blue);
        s.swapPiece(piece);
        REQUIRE(s.isEmpty() ==false);
    }
    SECTION("Test of method swapPiece")
    {

        Square s = Square(TypeSquare::Field);
        std::optional<Piece> piece;
        Piece p = Piece(TypePiece::Commandant,Color::Blue);
        s.setPiece(p);
        s.swapPiece(piece);
        REQUIRE(s.isEmpty() ==true);
    }


}
