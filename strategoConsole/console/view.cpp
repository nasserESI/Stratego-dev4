#include "view.h"
#include "../metier/stratego.h"


 View::View(){

}
void View::displayBoard( std::array<std::array<model::Square,10>,10> board,model::Color color){
    unsigned value=0;
    std::cout << "    ";
    char c='A';
    for(unsigned i = 0 ; i < board.size() ;i++){

        std::cout << c << "  ";
        c++;
    }
    std::cout << std::endl;
    std::cout << "-----------------------------------------------"<< std::endl;

    for(unsigned i = 0 ; i < board.size() ;i++){
        std::cout << i << " | ";
        for(unsigned j=0; j <board[i].size();j++){
            if(board[j][i].getPiece().has_value()){
                if(board[j][i].getPiece()->getVisible()==true ||board[j][i].getPiece()->getColor()==color ){
                value=board[j][i].getPiece()->getType();

                if(value>9){
                    if(value==10)
                        std::cout << value << " ";
                    else
                        std::cout << char(value) << "  ";

                }else
                    std::cout << value << "  ";
                }else {
                        if(board[j][i].getPiece()->getColor()==model::Color::Blue)
                            std::cout <<  "B  ";
                        else
                            std::cout <<  "R  ";
                  }
            }
            else if(board[j][i].getType()==model::TypeSquare::Water)
                    std::cout << "W  ";
            else
                    std::cout << "   ";
        }
        std::cout << std::endl;
    }
}
void View::welcomeGame(){
     std::cout << "Welcome to Stratego Game !" << std::endl;
}
void View::askWhichModeForInit(){
    std::cout << "Which mode want you to use to configure the board !" << std::endl;
    std::cout << "0 : file configuration" << std::endl;
    std::cout << "1 : put piece one by one" << std::endl;
}
void View::displayError(std::string error){
    std::cout<< error <<std::endl;
}
void View::displayWinner(std::string name){
    std::cout<< "The winner is  "  << name <<std::endl;
}
void View::displayCurrentPlayer(std::string name){
    std::cout<< "it's the turn of  " << name << " to play"<< std::endl ;
}
void View::askPathFile(){
    std::cout<< "Enter the path of file "<< std::endl ;
}
void View::askNbOfFile(){
    std::cout<< "0 : same file "<< std::endl ;
    std::cout<< "1 : different file "<< std::endl ;
}
void View::askPlayerName1(){
    std::cout<< "Enter name of player 1 (color Red)"<< std::endl ;
}
void View::askPlayerName2(){
    std::cout<< "Enter name of player 2 (color Blue)"<< std::endl ;
}
void View::askToChoseSourceMove(){
    std::cout<< "Enter the position of the piece you wanna move (A0)"<< std::endl ;
}
void View::askToChoseDestinationMove(){
    std::cout<< "Enter the position where you want to move your piece exemple(A0)"<< std::endl ;
}
void View::displayPositionsPossible(const std::vector<model::Position>& position){

    std::cout<< "All postion that this piece can go "<< std::endl ;
    for(unsigned i = 0 ; i < position.size() ;i++){
            std::cout << static_cast<char>(position[i].getColumn()+65) << position[i].getRow() << std::endl;
    }

}
void View::askToChoseSymboleToPut(){
    std::cout << "Enter the symbole you want to put in board" << std::endl;
}
void View::askWherePutPiece(){
    std::cout << "Enter the Position where you want to put the Piece" << std::endl;
}
void View::askPlayerRedPutPiece(){

    std::cout << "Player Red chose where you want to put pieces" << std::endl;

}
void View::askPlayerBluePutPiece(){

    std::cout << "Player Blue chose where you want to put pieces" << std::endl;

}
void View::printDraw(){

    std::cout << "DrawGame ! There is no winner !!!!" << std::endl;
}



