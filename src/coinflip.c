#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "coinflip.h"

/*
 * Figure out a way to save jollar amount and read from that
 * * If certain file doesn't exist
 * * make file and write starting amount
 * * if file exists read money amount
 */

int placeBetAmount(int player_money) {
    int desired_bet = 0;
    int attempts;

    while ((desired_bet > player_money) || (desired_bet <= 0) && attempts < 3) {
        printf("Input desired bet amount: ");
        scanf("%d", &desired_bet);
        attempts++;
    }

    if (attempts >= 2) {
        printf(
            "You couldn't put how much to bet between 1 and how much you have,"
            " you aren't smart enough to gamble and I'm protecting you.\n"
        );
        exit(0);
    }

    return desired_bet;
}

int placeGuess(void) {
    int guess;
    int attempts = 0;

    while (guess = fgetc(stdin) && attempts < 3) {
        printf("[h]eads or [t]ails: ");
        scanf("%c", &guess);

        switch (tolower(guess)) {
            case 'h':
                printf("Your Guess: Heads\n");
                return 1;
                break;
            case 't':
                printf("Your Guess: Tails\n");
                return 0;
                break;
            default:
                fflush(stdin);
                attempts++;
                continue;
        }
    }

    printf(
        "You couldn't put heads or tails in 3 attempts. You aren't smart "
        "enough to gamble and I'm protecting you.\n"
    );
    exit(0);
}

int flipCoin(void) {
    int result;

    srand(time(NULL));
    
    result = rand() % 2;

    switch (result) {
        case 0:
            printf("Coin: Tails\n");
            return 0;
            break;
        case 1:
            printf("Coin: Heads\n");
            return 1;
            break;
    }
}

int checkRound(int money, int bet, int guess, int coin) {
    if (guess == coin) {
        printf("Congrats: You've won\n\n");
        return money + bet;
    }

    printf("Sorry: You've lost\n\n");
    return money - bet;
}

int cfgame(void) {
    int hand = 1;
    int money = START_AMOUNT;
    int bet_amount, guess, coin;

    printf("JASINO PRESENTS: COIN FLIP\n");
    while (money > 0) {
        printf("Hand %d: %s%d\n", hand, JOLLAR_SIGN, money);
        
        bet_amount = placeBetAmount(money);
        guess = placeGuess();
        coin = flipCoin();
        money = checkRound(money, bet_amount, guess, coin);
        hand++;
    }

    printf("You've lost all your money, better luck next time!\n");
    exit(0);
}
