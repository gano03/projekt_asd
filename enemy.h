//enemy.h
#ifndef ENEMY_H
#define ENEMY_H
#include <stdio.h>
#include <iostream>
#include <ctime>
#include <unistd.h>
#include "board.h"
#define SHIP 1
#define SHIP_MISSED 3
#define SHIP_HIT 8

class Enemy
{
    int row = -1, col = -1;
    int **tab;
    public:Enemy(int ** tab){
        this->tab = tab;
    }
    public:~Enemy(){}
    public:void move()
    {
        if(this->row == -1 && this->col == -1){
            srand(time(NULL));
            this->row = (std::rand()) % SIZE;
            this->col = (std::rand()) % SIZE;
            if(this->tab[this->row][this->col] == SHIP_MISSED){
                move();
                return;
            }
            if(this->tab[this->row][this->col] == SHIP){
                std::cout <<"Zostales trafiony\n";
                this->tab[this->row][this->col] = SHIP_HIT;
                return;
            }
            else{
                tab[this->row][this->col] = SHIP_MISSED;
                this->row = -1;
                this->col = -1;
                return;
            }
        }
        while(1){
            usleep(50);
            int opt = (std::rand()) % 4;
            switch(opt){
                case 0:
                    this->row++;
                    if((this->row > SIZE-1) || (this->row < 0) || (this->tab[this->row][this->col] == SHIP_MISSED)){
                        this->row--;
                        break;
                    }
                    if(this->tab[this->row][this->col] == SHIP){
                        std::cout <<"Zostales trafiony\n";
                        this->tab[this->row][this->col] = SHIP_HIT;
                        return;
                    }
                        tab[this->row][this->col] = SHIP_MISSED;
                        this->row = -1;
                        this->col = -1;
                        return;
                    
                case 1:
                 
                    this->row--;
                    if((this->row > SIZE-1) || (this->row < 0) || (this->tab[this->row][this->col] == SHIP_MISSED)){
                        this->row++;
                        break;
                    }
                    if(this->tab[this->row][this->col] == SHIP){
                        std::cout <<"Zostales trafiony\n";
                        this->tab[this->row][this->col] = SHIP_HIT;
                        return;
                    }
                        tab[this->row][this->col] = SHIP_MISSED;
                        this->row = -1;
                        this->col = -1;
                        return;
                    
                case 2:
                 
                    this->col++;
                    if((this->row > SIZE-1) || (this->row < 0) || (this->tab[this->row][this->col] == SHIP_MISSED)){
                        this->col--;
                        break;
                    }
                    if(this->tab[this->row][this->col] == SHIP){
                        std::cout <<"Zostales trafiony\n";
                        this->tab[this->row][this->col] = SHIP_HIT;
                        return;
                    }
                        tab[this->row][this->col] = SHIP_MISSED;
                        this->row = -1;
                        this->col = -1;
                        return;
                    
                case 3:
                 
                    this->col--;
                    if((this->row > SIZE-1) || (this->row < 0) || (this->tab[this->row][this->col] == SHIP_MISSED)){
                        this->col++;
                        break;
                    }
                    if(this->tab[this->row][this->col] == SHIP){
                        std::cout <<"Zostales trafiony\n";
                        this->tab[this->row][this->col] = SHIP_HIT;
                        return;
                    }
                        tab[this->row][this->col] = SHIP_MISSED;
                        this->row = -1;
                        this->col = -1;
                        return;
                
            }
            continue;
            
        }
    }



};

#endif