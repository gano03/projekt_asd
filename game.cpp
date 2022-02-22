#include <stdio.h>
#include <iostream>
#include "board.h"
#include "enemy.h"

int main ()
{
    std::cout << "Trwa generowanie planszy. Proszę czekac...\n\n";
    Board player;
    Board enemy_board;
    Enemy enemy(player.tab);
    player.setShips();
    enemy_board.setShips();

    while(1)
    {
        std::cout <<"Twoja plansza\n";
        player.display();
        //enemy_board.display();
        std::cout <<"Plansza przeciwnika\n"; 
        enemy_board.displayEnemy();
        player.shot(enemy_board);
        if(enemy_board.defeat() == 1){
            std::cout << "Gracz wygral\n";
            break;
        }
        enemy.move();
        if(player.defeat() == 1){
            std::cout <<"Komputer wygral\n";
            break;
        }

    }




    return 0;
}