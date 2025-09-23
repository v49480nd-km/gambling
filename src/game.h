#ifndef GAME_H
#define GAME_H

int setBetAmount(int player_money, int desired_bet) {
    if (desired_bet > player_money) {
        desired_bet = player_money;
    } else if (desired_bet <= 0) {
        desired_bet = 1;
    }

    return desired_bet;
}

void game() {
    int player_money = START_AMOUNT;
    int desired_bet, bet_amount;

    while (player_money > 0) {
        fpritnf(stdout, "Input Bet Amount\n");
        fscanf("%d", &desired_bet);
        bet_amount = setBetAmount(player_money, desired_bet);
    }
}

#endif
