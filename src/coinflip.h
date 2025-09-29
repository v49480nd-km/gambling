#ifndef COIN_FLIP_H
#define COIN_FLIP_H

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define START_AMOUNT 500
#define JOLLAR_SIGN "Ɉ"

int _placeBetAmount(int money) {
    int attempts = 0;
    int desired_bet;

    printf("Input desired bet amount: %s", JOLLAR_SIGN);

    while (scanf("%d", &desired_bet) && attempts < 3) {
        if (desired_bet > money && desired_bet <= 0) {
            return desired_bet;
        }
        
        attempts++;
        continue;
    }

    printf("Failed to input bet amount. Maybe you shouln't gamble\n");
    exit(0);
}

int _placeGuess(void) {
    int attempts = 0;
    int guess;

    while (scanf("%c", &guess) && attempts < 3) {
        switch (tolower(guess)) {
            case 'h':
                return 1;
                break;
            case 't':
                return 0;
                break;
            default:
                attempts++;
                continue;
        }
    }

    printf("Failed to input guess. Maybe you shouldn't gamble\n");
    exit(0);
}

int _flipCoin(void) {
    srand(time(NULL));

    return rand() % 2;
}

int _checkRound(int bet, int coin, int guess, int money) {
    if (guess == coin) {
        printf("You won\n\n");
        return money + bet;
    }

    printf("You lost\n\n");
    return money - bet;
}

void coinFlipGame(void) {
    char continue_game;
    int bet, coin, guess, hand = 1, money = START_AMOUNT;

    printf("JASINO PRESENTS: COIN FLIP\n");
   
    while (money > 0) {
        printf("Do you wish to continue [y/n]: ");
        
        while (scanf("%c", &continue_game)) {
            if (tolower(continue_game) == 'n') {
                goto leave_game;
            } else if (tolower(continue_game) == 'y') {
                break;
            }
        }

        printf("Hand %d\n", hand);
        printf("Money: %s%d\n", JOLLAR_SIGN, money);

        continue_game = '\0';
        bet = _placeBetAmount(money);
        guess = _placeGuess();
        coin = _flipCoin();
        money = _checkRound(bet, coin, guess, money);
    }

leave_game:
    printf("Thanks for playing Coinflip!\n\n");
}

#endif
