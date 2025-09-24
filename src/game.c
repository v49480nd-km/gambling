#include <stdio.h>
#include <stdlib.h>

#include "game.h"

int setBetAmount(int player_money, int desired_bet) {
    if (desired_bet > player_money) {
        desired_bet = player_money;
    } else if (desired_bet <= 0) {
        desired_bet = 1;
    }

    return desired_bet;
}

void game(void) {
    int player_money = START_AMOUNT;
    int desired_bet, bet_amount;

    while (player_money > 0) {
        printf("Input desired bet: ");
        scanf("%d", &desired_bet);
        bet_amount = setBetAmount(player_money, desired_bet);
        printf("Bet Amount: %s%d\n", JOLLAR_SIGN, bet_amount);
    }
}
