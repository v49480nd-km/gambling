#ifndef COIN_FLIP_H
#define COIN_FLIP_H

#define START_AMOUNT 500
#define JOLLAR_SIGN "Ɉ"

/*
 * Figure out a way to save jollar amount and read from that
 * * If certain file doesn't exist
 * * make file and write starting amount
 * * if file exists read money amount
 */

int placeBetAmount(int);
int placeGuess(void);
int flipCoin(void);
int checkRound(int, int, int, int);
int cfgame(void);

#endif
