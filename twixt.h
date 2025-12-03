#ifndef TWIXT_H
#define TWIXT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
    int x, y;
    struct node *next;
} node;

typedef struct {
    char name[100];
    int id;
    char identifier;
    node *moves;
} player;
bool checkvalidity( int x, int y, player *pl1, player *pl2);
void place(int x, int y, player *pl, player *pl1, player *pl2);
void printboard(player *pl1, player *pl2);
void freespace(player *pl);
bool loadcurrentgame(player *pl1, player *pl2, bool play, char *file);
void savecurrentgame(player *pl1, player *pl2, bool play, char *file);

#endif