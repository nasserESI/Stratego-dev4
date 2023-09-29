#include "square.h"
namespace model{
Square::Square()
{

}

Square::Square(TypeSquare type):type(type){

}

bool Square::isEmpty() const{
    return !this->piece.has_value();
}
bool Square::isHigherValue(const Piece &piece) const{

    return this->piece->isHigherValue(piece);
}
bool Square::isSameValue(const Piece &piece) const{
    return this->piece->hasSameRank(piece);
}
bool Square::isPieceColor(Color color)const{
    return this->piece->isMyColor(color);
}
void Square::setPieceVisible(bool value){
    return this->piece->setVisiblity(value);
}
void Square::swapPiece(std::optional<Piece> &piece){
    this->piece.swap(piece);
}
void Square::setType(TypeSquare type){
    this->type=type;
}
TypeSquare Square::getType()const{
    return this->type;
}
 std::optional<Piece>& Square::getPieceToSwap(){
    return this->piece;
}

 void Square::setPiece(Piece &piece){
    this->piece=piece;

 }
 const std::optional<Piece>& Square::getPiece() const{
     return this->piece;
 }
}

