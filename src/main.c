#include <stdio.h>

#include "coinflip.h"

int main(void) {
    int attempts = 0;
    int game_select;

    printf("WELCOME TO THE JASINO\n");
    printf("AVAILABLE GAMES\n");
    printf(
        "[1] Coin Flip\n"
        "> "
    );

    while (game_select = fgetc(stdin) != '\n') {
        switch (game_select) {
            case 1:
                coinFlipGame();
                printf("Thanks for playing Coinflip!\n");
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
