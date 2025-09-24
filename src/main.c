#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define START_AMOUNT 500
#define JOLLAR_SIGN "Ɉ"

int setBetAmount(int player_money, int desired_bet) {
    if (desired_bet > player_money) {
        desired_bet = player_money;
    } else if (desired_bet <= 0) {
        desired_bet = 1;
    }

    return desired_bet;
}

int flipCoin(void) {
    int result;
    srand(time(NULL));
    result = rand() % 2;
    return result;
}

int main() {
    int player_money = START_AMOUNT;
    int desired_bet, bet_amount, coin_flip;

    while (player_money > 0) {
        printf("Input desired bet: ");
        scanf("%d", &desired_bet);

        bet_amount = setBetAmount(player_money, desired_bet);

        printf("Bet Amount: %s%d\n", JOLLAR_SIGN, bet_amount);

        coin_flip = flipCoin();

        printf("Heads or tails: %d\n", coin_flip);
    }

    return 0;
}
