#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include<ctype.h>
#include "access_exception.h"
#include "stratego.h"
using namespace std;

void tokenize(std::string const &str, const char delim,
            std::vector<std::string> &out)
{
    // construct a stream from the string
    std::stringstream ss(str);

    std::string s;
    while (std::getline(ss, s, delim)) {
        out.push_back(s);
    }
}
bool isParam(string line)
{
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}
/*int main(){
    cout << "yeah 3 " << endl;
        std::string line;
        char delem=' ';

        std::ifstream myfile("../metier/example.txt");
        unsigned row=0;
        if (myfile.is_open())
        {
            cout << "yeah 10 " << endl;
          while (getline(myfile,line))
          {
            std::vector <std::string> out;
            tokenize(line,delem,out);
            for(unsigned i =0;i< out.size();i++){

                model::TypePiece typePiece;
                if(isParam(out.at(i))){
                    typePiece =static_cast<model::TypePiece>(std::stoi(out.at(i)));;
                }
                else{
                     typePiece =static_cast<model::TypePiece>(out.at(i)[0]);

                }
                cout<< typePiece << endl;




                cout << typePiece<< endl;


            }
            row++;

          }
          myfile.close();
            }
        else
            throw std::invalid_argument("File does not exist");
    return 0;
}*/

