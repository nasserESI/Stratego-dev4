#ifndef POSITION_H
#define POSITION_H
namespace model{
    /**
     * @brief this class define a position by to data
     * the horizontal one and vertical one
     * 
     */
class Position{
private:
    int column;
    int row;
public:
    Position();
     /**
    * @brief Position::Position: this constructor define what is a position.
    * @param column : that is the horizintal data
    * @param row : that is the verticale data.
    */
    Position(int row,int column);
    /**
    * @brief Position::getRow : this methods says in which column is a pawn.
    * @return the number of the column
    */
    int getColumn()const;
    /**
    * @brief Position::getRow : this methods says in which row is a pawn.
    * @return the number of the row
    */
    int getRow()const;
    /**
    * @brief Position::operator - : this substract two position
    * @param pos this is the oposite position
    * @return should return 1 if it is ok.
    */
    int operator-(const Position &pos) const ;

};
/**
 * @brief operator == check the equivalence between two positions
 * @param pos : first position
 * @param pos2 : second position
 * @return a boolean : true if they are equals or false in the opposite case.
 */
inline bool operator==(const Position &pos,const Position &pos2){
    return pos.getRow() == pos2.getRow() && pos.getColumn() == pos2.getColumn();
}

}
#endif // POSITION_H
