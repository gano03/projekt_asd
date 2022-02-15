//ships.h
#ifndef SHIPS_H
#define SHIPS_H
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#define SIZE 10

class Ships
{
    public: int ship_size;
    public:int **tab;
    public:Ships(int ship_size, int ** tab){
        this->ship_size = ship_size;
        this->tab = tab;

    }
    public:~Ships(){}
    public:void position(int **tab, int ship_size){
        srand(time(NULL));
        int row = (std::rand())%SIZE;
        int col = (std::rand())%SIZE;
        int opt = (std::rand())%2;
        if(tab[row][col] == 1){
            position(tab,ship_size);
            return;
        }
        switch(opt){
            case 0:
                if((row+ship_size) > (SIZE-1)){
                    position(tab, ship_size);
                    return;
                }
                for(int i = row; i <= (row+ship_size); i++){
                    if(tab[i][col] == 1){
                        position(tab, ship_size);
                        return;
                    }
                }
                for(int i = row; i <= (row+ship_size); i++){
                    tab[i][col] = 1;
                }
            case 1:
                if((col+ship_size) > (SIZE-1)){
                    position(tab, ship_size);
                    return;
                }
                for(int i = col; i <= (col+ship_size); i++){
                    if(tab[row][i] == 1){
                        position(tab, ship_size);
                        return;
                    }
                }
                for(int i = col; i <= (col+ship_size); i++){
                    tab[row][i] = 1;
                }
        } 
        
    }


};


#endif