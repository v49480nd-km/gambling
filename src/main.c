#include <ctype.h>
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

int placeGuess(void) {
    char guess;
    int format_guess;
    int attempts = 0;

    printf("[h]eads or [t]ails\n");
    while (((tolower(guess) != 'h') || (tolower(guess) != 't')) && attempts < 3) {
        guess = fgetc(stdin);
        attempts++;
    }

    if (guess == 'h') {
        format_guess = 1;
        printf("You guess: Heads\n");
    } else {
        format_guess = 0;
        printf("You guess: Tails\n");
    }

    return format_guess;
}

int main() {
    int player_money = START_AMOUNT;
    int desired_bet, bet_amount, coin_flip, guess;

    while (player_money > 0) {
        printf("Jollars: %s%d\n", JOLLAR_SIGN, START_AMOUNT);
        printf("Input desired bet: ");
        scanf("%d", &desired_bet);

        bet_amount = setBetAmount(player_money, desired_bet);

        printf("Bet Amount: %s%d\n", JOLLAR_SIGN, bet_amount);

        guess = placeGuess();
        coin_flip = flipCoin();
   
        if (coin_flip != guess) {
            printf("LOSS\n");
            player_money -= bet_amount;
        } else {
            printf("WIN\n");
            player_money += floor(player_money * ((bet_amount / player_money) + 1));
        }
    }

    return 0;
}
