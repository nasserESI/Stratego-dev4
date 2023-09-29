#include "Position.h"
namespace model{
Position::Position(){

        }

Position::Position(int column,int row):column(column),row(row){

        }
int Position::getColumn()const {
            return this->column;
        }
int Position::getRow()const {
            return this->row;
        }
int Position::operator-(const Position &pos) const{
    return (this->getRow()+this->getColumn())-(pos.getRow()+pos.getColumn());
}
}

