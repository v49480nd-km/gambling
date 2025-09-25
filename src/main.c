#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define START_AMOUNT 500
#define JOLLAR_SIGN "Ɉ"

/*
 * Show current jollar amount FINISEHD
 * get how much you want to bet FINISHED
 * * use while loop for bounds of 0 to amount of jollars
 * place guess of heads or tails FINISHED
 * * while input isn't h or t
 * flip coin of heads or tails once FINISHED
 * check placed guess vs coin FINISHED
 * if loss lose bet FINISHED
 * if win floor((bet / money) + 1) BUGGY
 * Eventually figure out a way to do file bets
 */

int placeBetAmount(int player_money) {
    int desired_bet = 0;

    while ((desired_bet > player_money) || (desired_bet <= 0)) {
        printf("Input desired bet amount: ");
        scanf("%d", &desired_bet);
    }

    return desired_bet;
}

int placeGuess(void) {
    int guess;

    while (guess = fgetc(stdin)) {
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
                continue;
        }
    }
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
        money = floor(( money * (bet / money) + 1));
        printf("Congrats: You've won\n");
    } else {
        printf("Sorry: You've lost\n");
        money = money - bet;
    }

    return money;
}

int main(void) {
    int money = START_AMOUNT;
    int bet_amount, guess, coin;

    printf("WELCOME TO THE JASINO\n");
    while (money > 0) {
        printf("%s%d\n", JOLLAR_SIGN, money);
        
        bet_amount = placeBetAmount(money);
        guess = placeGuess();
        coin = flipCoin();
        money = checkRound(money, bet_amount, guess, coin);
    }

    return 0;
}
