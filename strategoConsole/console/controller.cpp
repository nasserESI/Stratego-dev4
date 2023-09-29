#include "controller.h"

Controller::Controller(View view):view(view)
{
this->game=model::Stratego();
}
void Controller::start(){
    std::string input;
    view.welcomeGame();
    initGame();
    view.askPlayerName1();
    std::cin>> input;
    this->game.addPlayer(input,model::Color::Red);
    view.askPlayerName2();
    std::cin>> input;
    this->game.addPlayer(input,model::Color::Blue);
    game.initCurrentPlayer();
    view.displayBoard(game.getBoard().getBoard(),game.getCurrentPlayer().getColor());
    bool value=false;
    bool value2=false;
        model::Position pos;
        while(game.checkWinner()==model::Color::Null){
            view.displayCurrentPlayer(game.getCurrentPlayer().getName());

        do {
            view.askToChoseSourceMove();
            std::cin>> input;
            while(input.size()!=2){
                view.displayError("Wrong position");
                view.askToChoseSourceMove();
                std::cin>> input;
            }
            pos = model::Position(static_cast<int>(input[0])-65,static_cast<int>(input[1])-48);
           if(game.getBoard().isPositionInBoard(pos)){
               const std::vector<model::Position>& position = game.getPositions(pos);
               if(position.size()!=0){
                do{
                        view.displayPositionsPossible(position);
                         view.askToChoseDestinationMove();
                           std::cin>> input;
                           while(input.size()!=2){
                               view.displayError("Wrong position");
                               view.askToChoseDestinationMove();
                               std::cin>> input;
                           }
                          model::Position pos2 = model::Position(static_cast<int>(input[0])-65,static_cast<int>(input[1])-48);
                          if(std::find(position.begin(), position.end(), pos2) != position.end()){
                              model::Move move=model::Move(pos,pos2);
                              if(game.validateMove(move)){
                                  if(game.isItAttack()){
                                      game.setVisibilityPiece();
                                      view.displayBoard(game.getBoard().getBoard(),game.getCurrentPlayer().getColor());
                                      game.attack();
                                      view.displayBoard(game.getBoard().getBoard(),game.getCurrentPlayer().getColor());
                                      if(!game.getMode())
                                          game.resetVisibilityPiece();
                                    value=true;
                                    value2=true;
                                  }else{
                                      game.move();
                                      view.displayBoard(game.getBoard().getBoard(),game.getCurrentPlayer().getColor());
                                      value=true;
                                      value2=true;
                                  }
                              }
                          }else{
                              view.displayError("Wrong position");
                          }

                   }while(!value2) ;


               }
                else{
                   view.displayError("You can't move this piece ");
               }
           }else{
               view.displayError("Wrong position");
           }

        } while (!value);



        }
        if(game.checkWinner()==model::Color::Draw)
            view.printDraw();
        else
            view.displayWinner(game.getNamePlayer(game.checkWinner()));










}
bool isParam(std::string line)
{
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}

void Controller::initGame(){

    std::string input;
    do{
        view.askWhichModeForInit();
        std::cin>>input;
    }while(input!="0" && input!="1");
    if(input=="0"){
         do{
        view.askNbOfFile();
        std::cin>>input;
        }while(input!="0" && input!="1");
        if(input=="0"){

           bool value=false;
           do{
               try {
                   view.askPathFile();
                   std::cin>>input;
                   this->game=model::Stratego(false,input);
                   value=true;
               }  catch (std::invalid_argument &exception) {
                   view.displayError(exception.what());

               }
           }while(!value);
        }
        if(input=="1"){
            std::string input2;

            bool value=false;
            do{
                try {
                    view.askPathFile();
                    std::cin>>input;
                    view.askPathFile();
                    std::cin>>input2;
                    this->game=model::Stratego(false,input,input2);
                    value=true;
                }  catch (std::invalid_argument &exception) {
                    view.displayError(exception.what());
                }
            }while(!value);
        }
    }
    if(input=="1"){
        this->game=model::Stratego(false);

        std::array<std::string,12> symboles={"10","9","8","7","6","5","4","3","2","1","D","B"};

        std::map<std::string, int> map ;
        map["10"]=1;
        map["9"]=1;
        map["8"]=2;
        map["7"]=3;
        map["6"]=4;
        map["5"]=4;
        map["4"]=4;
        map["3"]=5;
        map["2"]=8;
        map["1"]=1;
        map["D"]=1;
        map["B"]=6;
        unsigned p=0;
        std::string input;
        std::string symbole;
        while(p < 2){
            if(p==0)
                view.askPlayerRedPutPiece();
            if(p==1)
                view.askPlayerBluePutPiece();
            std::map<std::string, int> map ;
            map["10"]=1;
            map["9"]=1;
            map["8"]=2;
            map["7"]=3;
            map["6"]=4;
            map["5"]=4;
            map["4"]=4;
            map["3"]=5;
            map["2"]=8;
            map["1"]=1;
            map["D"]=1;
            map["B"]=6;
            unsigned nbPiece=0;
            while (nbPiece < 40){
                if(p==0)
                    view.displayBoard(game.getBoard().getBoard(),model::Color::Red);
                if(p==1)
                    view.displayBoard(game.getBoard().getBoard(),model::Color::Blue);
                std::cout << "(symbole" << " : " << "number of pieces)" << " " << std::endl;
                for(unsigned i = 0 ; i< symboles.size(); i++){
                    if(map.find(symboles[i])->second > 0)
                        std::cout << map.find(symboles[i])->first << " : " << map.find(symboles[i])->second << " | ";

                    if(i ==5)
                        std::cout << std::endl;


                }
                std::cout << std::endl;
                do{
                view.askToChoseSymboleToPut();
                std::cin>>symbole;

                }while(map.count(symbole) < 1 || map.find(symbole)->second<1);
                bool value=false;
                while(!value){
                    try {
                        view.askWherePutPiece();
                        std::cin>> input;
                        while(input.size()!=2){
                            view.displayError("Wrong position");
                            view.askWherePutPiece();
                            std::cin>> input;
                        }
                         model::Position pos = model::Position(static_cast<int>(input[0])-65,static_cast<int>(input[1])-48);
                         model::TypePiece typePiece;
                         try {
                             if(isParam(symbole))
                                typePiece =static_cast<model::TypePiece>(std::stoi(symbole));
                             else
                                 typePiece =static_cast<model::TypePiece>(symbole[0]);
                         } catch (...) {
                             view.displayError("Wrong position");
                             continue;
                         }

                         model::Color color;
                         if(p==0)
                             color=model::Color::Red;
                         else
                             color=model::Color::Blue;

                           model::Piece piece = model::Piece(typePiece,color);
                         game.put(pos,piece);
                         value=true;
                         map.find(symbole)->second--;
                         nbPiece++;
                    } catch (std::invalid_argument & error) {
                        view.displayError(error.what());
                    }
                }


            }
            p++;

        }

    }
}
