//ships.h
#ifndef SHIPS_H
#define SHIPS_H
#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#define SIZE 10

class Ships
{
    public: int ship_size;
    public:int **tab;
    public:int row;
    public:int col;
    public:int opt;
    public:Ships(int ship_size, int ** tab){
        this->ship_size = ship_size;
        this->tab = tab;
    
    }
    public:~Ships(){}
    public:void position(int **tab, int ship_size){
        usleep(50);
        srand(time(NULL));
        int row = (std::rand())%SIZE;
        int col = (std::rand())%SIZE;
        int opt = (std::rand())%2;
        //std::cout << "row to " <<row <<" col to " << col <<"\n";
        //std::cout << "opt to " << opt <<"\n";
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
                for(int i = row; i < (row+ship_size); i++){
                    //std::cout <<"Blad2\n\n";
                    if(tab[i][col] == 1){
                        position(tab, ship_size);
                        return;
                    }
                }
                for(int i = row; i < (row+ship_size); i++){
                    tab[i][col] = 1;
                }
                this->row = row;
                this->col = col;
                this->opt = opt;
                break;
            case 1:
                if((col+ship_size) > (SIZE-1)){
                    position(tab, ship_size);
                    return;
                }
                for(int i = col; i < (col+ship_size); i++){
                    if(tab[row][i] == 1){
                        position(tab, ship_size);
                        return;
                    }
                }
                for(int i = col; i < (col+ship_size); i++){
                    tab[row][i] = 1;
                }
                this->row = row;
                this->col = col;
                this->opt = opt;
                break;
        } 
    
    }
    public:int exist() // 0 - statek jeszcze istnieje, -1 - statek juz zniszczony
    {
        if(this->opt == 0){
            for(int i = this->row; i < this->row + this->ship_size; i++){
               if(tab[i][this->col] == 1){
                   return 0;
               } 
            }
        }
        else if(this->opt == 1){
            for(int i = this->col; i <this->col + this->ship_size; i++){
                if(tab[this->row][i] == 1){
                    return 0;
                }
            }
        }
        return -1;
    }


    
    

};


#endif