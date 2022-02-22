//board.h
#ifndef BOARD_H
#define BOARD_H
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <unistd.h>
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
        this->ship3 = new Ships(4, tab);
        this->ship4 = new Ships(5, tab);
        //setShips();
        display();
    }
    public:~Board (){
        for(int i = 0; i < SIZE; i++){
            delete [] tab[i];
        }
        delete [] tab;
        delete ship1;
        delete ship2;
        delete ship3;
        delete ship4;
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
    public:void displayEnemy()
    {
        for(int i = 0; i < SIZE; i++){
            for( int j = 0; j < SIZE; j++){
                if(tab[i][j] == 1){
                    std::cout << "   "<<0;
                }
                else
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
    public:int defeat() // 1 porażka, 0 statki nadal istnieją
    {
        if((this->ship1->exist() == -1 && this->ship2->exist() == -1 && this->ship3->exist() == -1 &&
        this->ship4->exist() == -1)){
            return 1;
        }
        return 0;
    }
    public:void shot(Board &enemy)
    {
        int row, col;
        std::cout << "Wybierz rzad i kolumne\n";
        std::cin >> row;
        std::cin >> col;
        if(row > SIZE-1 || row < 0 || col > SIZE-1 || col < 0){
            shot(enemy);
            return;
        }
        if(enemy.tab[row][col] == 1){
            std::cout << "Przeciwnik zostal trafion\n";
            enemy.tab[row][col] = 8;
        }
        else{
            enemy.tab[row][col] = 3;
            std::cout << "Pudlo\n";
        }
        
    }


};
#endif