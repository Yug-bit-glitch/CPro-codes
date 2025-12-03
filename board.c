#include "twixt.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 24

#define RESET "\033[0m"
#define RED "\033[31m"
#define BLUE "\033[34m"

bool checkvalidity(int x, int y, player *pl1, player *pl2)
{
    if (x < 0 || x >= N || y < 0 || y >= N)
    {
        return false;
    }

    if ((x == 0 && y == 0) || (x == 0 && y == N-1) || (x == N-1 && y == 0) || (x == N-1 && y == N-1))
    {
        return false;
    }

    node *temp = pl1->moves;
    while (temp != NULL)
    {
        if (temp->x == x && temp->y == y)
        {
            return false;
        }
        temp = temp->next;
    }

    node *temp2 = pl2->moves;
    while (temp2 != NULL)
    {
        if (temp2->x == x && temp2->y == y)
        {
            return false;
        }
        temp2 = temp2->next;
    }

    return true;
}

void place(int x, int y, player *pl, player *pl1, player *pl2)
{
    if (checkvalidity(x, y, pl1, pl2) == false) 
    {
        printf("INVALID MOVE BRO :(\n");
        return;
    }

    node *temp1 = malloc(sizeof(node));
    temp1->x = x;
    temp1->y = y;
    temp1->next = pl->moves;
    pl->moves = temp1;

    node *temp = pl->moves->next;
    while (temp != NULL)
    {
        if (temp->x == x + 2 && temp->y == y + 1)
        {
            printf("joined to (%d,%d)\n", temp->x, temp->y);
        }
        if (temp->x == x + 2 && temp->y == y - 1)
        {
            printf("joined to (%d,%d)\n", temp->x, temp->y);
        }
        if (temp->x == x - 2 && temp->y == y + 1)
        {
            printf("joined to (%d,%d)\n", temp->x, temp->y);
        }
        if (temp->x == x - 2 && temp->y == y - 1)
        {
            printf("joined to (%d,%d)\n", temp->x, temp->y);
        }
        if (temp->x == x + 1 && temp->y == y + 2)
        {
            printf("joined to (%d,%d)\n", temp->x, temp->y);
        }
        if (temp->x == x + 1 && temp->y == y - 2)
        {
            printf("joined to (%d,%d)\n", temp->x, temp->y);
        }
        if (temp->x == x - 1 && temp->y == y + 2)
        {
            printf("joined to (%d,%d)\n", temp->x, temp->y);
        }
        if (temp->x == x - 1 && temp->y == y - 2)
        {
            printf("joined to (%d,%d)\n", temp->x, temp->y);
        }
        temp = temp->next;
    }
}

void printboard(player *pl1, player *pl2)
{
    char board[N][N];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            board[i][j] = '.';
        }
    }

    node *temp = pl1->moves;
    while (temp != NULL)
    {
        board[temp->x][temp->y] = pl1->identifier;
        temp = temp->next;
    }

    temp = pl2->moves;
    while (temp != NULL)
    {
        board[temp->x][temp->y] = pl2->identifier;
        temp = temp->next;
    }

    printf("\n");
    
    printf("  ");
    for (int j = 0; j < N; j++)
    {
        printf(". ");
    }
    printf("\n");

    printf(" .");
    for (int j = 0; j < N; j++)
    {
        printf("--");
    }
    printf(".\n");

    for (int i = 0; i < N; i++)
    {
        printf(".|");
        
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 'A')
            {
                printf(RED "A" RESET);
            }
            else if (board[i][j] == 'B')
            {
                printf(BLUE "B" RESET);
            }
            else
            {
                printf(".");
            }
            
            printf(" ");
        }
        
        printf("|.\n");
    }

    printf(" .");
    for (int j = 0; j < N; j++)
    {
        printf("--");
    }
    printf(".\n");

    printf("  ");
    for (int j = 0; j < N; j++)
    {
        printf(". ");
    }
    printf("\n");
}

void savecurrentgame(player *pl1, player *pl2, bool play, char *file)
{
    FILE *fp = fopen(file, "w");
    if (fp == NULL)
    {
        printf("ERROR IN SAVING GAME:(\n");
        return;
    }
    if (play == true)
    {
        fprintf(fp, "%d\n", 1);
    }
    else
    {
        fprintf(fp, "%d\n", 0);
    }
    
    int count = 0;
    node *temp = pl1->moves;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    fprintf(fp, "%d\n", count);

    temp = pl1->moves; 
    while (temp != NULL)
    {
        fprintf(fp, "%d %d\n", temp->x, temp->y);
        temp = temp->next;
    }
    
    count = 0;
    temp = pl2->moves;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    fprintf(fp, "%d\n", count);

    temp = pl2->moves;
    while (temp != NULL)
    {
        fprintf(fp, "%d %d\n", temp->x, temp->y);
        temp = temp->next;
    }
    
    fclose(fp);
    printf("GAME IS SUCCESSFULLY SAVED\n");
}

bool loadcurrentgame(player *pl1, player *pl2, bool play, char *file)
{
    FILE *fp = fopen(file, "r");
    if (fp == NULL)
    {
        printf("NO CURRENT GAME IS SAVED\n");
        return true;
    }
    int ya;
    fscanf(fp, "%d", &ya);

    play = ya;
    int count, x, y;

    fscanf(fp, "%d", &count);
    for (int i = 0; i < count; i++)
    {
        fscanf(fp, "%d %d", &x, &y);
        node *newnode = malloc(sizeof(node));
        newnode->x = x;
        newnode->y = y;
        newnode->next = pl1->moves;
        pl1->moves = newnode;
    }

    fscanf(fp, "%d", &count);
    for (int i = 0; i < count; i++)
    {
        fscanf(fp, "%d %d", &x, &y);
        node *newnode = malloc(sizeof(node));
        newnode->x = x;
        newnode->y = y;
        newnode->next = pl2->moves;
        pl2->moves = newnode;
    }

    fclose(fp);
    printf("GAME LOADED SUCCESSFULLY\n");

    return play;
}

void freespace(player *pl)
{
    node *temp = pl->moves;
    while (temp != NULL)
    {
        node *temp1 = temp;
        temp = temp->next;
        free(temp1);
    }
    pl->moves = NULL;
}