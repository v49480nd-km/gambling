#ifndef COIN_FLIP_H
#define COIN_FLIP_H

#define START_AMOUNT 500
#define JOLLAR_SIGN "Ɉ"

int _placeBetAmount(int money);
int _placeGuess(void);
int _flipCoin(void);
int _checkRound(int bet, int coin, int guess, int money);
void coinFlipGame(void);

#endif
