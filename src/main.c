#include <stdio.h>

#include "coinflip.h"

int main(void) {
    int game_selected;
    int attempts = 0;

    printf("WELCOME TO THE JASINO\n");
    printf("AVAILABLE GAMES\n");
    printf(
        "[1] Coin Flip\n"
    );

    while (game_selected = fgetc(stdin) && attempts < 3) {
        switch (game_selected) {
            case 1:
                cfgame();
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
