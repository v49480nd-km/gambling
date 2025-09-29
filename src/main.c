#include <stdio.h>
#include <stdlib.h>

#include "coinflip.h"

int main(void) {
    int attempts = 0;
    int game_select;

    printf("WELCOME TO THE JASINO\n");
game_select:
    printf("AVAILABLE GAMES\n");
    printf(
        "[1] Coin Flip\n"
        "[0] Exit\n"
        "> "
    );

    while (scanf("%d", &game_select)) {
        switch (game_select) {
            case 0:
                printf("Thanks for playing at the Jasino\n");
                exit(0);
            case 1:
                coinFlipGame();
                goto game_select;
                break;
            case 2:
                printf("Under construction\n");
                break;
            default:
                printf("Not an option\n");
                attempts++;
                continue;
        }
    }

    printf("Thanks for playing at the Jasino\n");

    return 0;
}
