//board.h
#ifndef BOARD_H
#define BOARD_H
#include <stdio.h>
#include <iostream>
#include "ships.h"
#define SIZE 10 //rozmiar planszy

class Board
{
    public: Ships *ship1;
    public: Ships *ship2;
    public: Ships *ship3;
    public: Ships *ship4;
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
        this->ship1 = new Ships(2, tab);
        this->ship2 = new Ships(3, tab);
        this->ship3 = new Ships(3, tab);
        this->ship4 = new Ships(5, tab);
       setShips();
       display();
    }
    public:~Board (){
        std::cout <<"Destruktor\n";
        for(int i = 0; i < SIZE; i++){
            delete [] tab[i];
        }
        delete [] tab;
    }
    public:void display()
    {
        for(int i = 0; i < SIZE; i++){
            for( int j = 0; j < SIZE; j++){
                std::cout << "   " << tab[i][j];
                if(j == SIZE-1){
                   std::cout<<"\n\n"; 
                }
            }
        }
        std::cout <<"\n\n";
    }
    public:void setShips()
    {

        this->ship1->position(tab,2);
        this->ship2->position(tab,3);
        this->ship3->position(tab,4);
        this->ship4->position(tab,5);
    }


};
#endif