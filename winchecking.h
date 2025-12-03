#ifndef WINCHECKING_H
#define WINCHECKING_H
#include<stdbool.h>
#include "twixt.h"

bool repeat(int x, int y, player *pl);
bool check(int x, int y, int n, player *pl);
bool checkwin(int n, player *pl);

#endif