//board.h
#ifndef BOARD_H
#define BOARD_H
#include <stdio.h>
#include <iostream>
#define SIZE 10 //rozmiar planszy

class Board
{
    public: int ** tab;
    public:Board (){
       this->tab = new int*[SIZE];
       for(int i = 0; i < SIZE; i++){
           this->tab[i] = new int[SIZE];
       }
       for(int i = 0; i < SIZE; i++){
           for(int j; j < SIZE; j++){
               this->tab[i][j] = 0;
           }
       }
       display();
    }
    public:~Board (){
        for(int i = 0; i < SIZE; i++){
            delete [] tab[i];
        }
        delete [] tab;
    }
    public:void display()
    {
        for(int i = 0; i < SIZE; i++){
            for( int j = 0; j < SIZE; j++){
                std::cout << "  " << tab[i][j];
                if(j == SIZE-1){
                   std::cout<<"\n"; 
                }
            }
        }
        std::cout <<"\n\n";
    }
    public:void setShips()
    {
        
    }


};
#endif