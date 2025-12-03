#include "twixt.h"
#include "winchecking.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define N 24

#define RESET "\033[0m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define BLACK "\033[30m"
#define YELLOW "\033[33m"

int main()
{
    player *pl1 = malloc(sizeof(player));
    player *pl2 = malloc(sizeof(player));

    pl1->identifier = 'A';
    pl1->moves = NULL;

    pl2->identifier = 'B';
    pl2->moves = NULL;

    int x, y;
    bool play = true;
    bool gameRunning = true;

    printf(BLUE "*****************************\n" RESET);
    printf(YELLOW "WELCOME TO TWIXT LITE\n" RESET);
    printf(BLUE "*****************************\n" RESET);

    printf(GREEN "MAIN MENU\n" RESET);
    printf("1) CREATE A NEW GAME\n");
    printf("2) LOAD THE PREVIOUS SAVED GAME\n");
    printf("3) ABORT THE GAME\n");
    printf(GREEN "--------------------------------\n" RESET);
    
    int a;
    scanf("%d", &a);

    switch (a)
    {
        case 1:
            play = true;
            break;
        
        case 2:
            play = loadcurrentgame(pl1, pl2, play, "game.txt");
            if (pl1->moves == NULL && pl2->moves == NULL)
            {
                play = true;
            }
            break;

        case 3:
            freespace(pl1);
            freespace(pl2);
            free(pl1);
            free(pl2);
            return 0;

        default:
            play = true;
            break;
    }

    while (gameRunning)
    {
        printboard(pl1, pl2);
        
        printf(BLUE "\n DEAR PLAYER %c MAKE YOUR MOVE\n" RESET, play ? 'A' : 'B');
        printf(YELLOW "CHOOSE THE OPTION FROM MENU :\n" RESET);
        printf("1) PLACE THE PEG\n");
        printf("2) SAVE GAME\n");
        printf("3) EXIT GAME\n");
        printf(GREEN "--------------------------------\n" RESET);
        
        int choice;
        scanf("%d", &choice);
        
        switch (choice)
        {
            case 1:
                printf("ENTER COORDINATES (x y):\n ");
                scanf("%d %d", &x, &y);
                
                if (x < 0 || x >= N || y < 0 || y >= N)
                {
                    printf(RED "INVALID COORDINATES! USE 0 TO 23.\n" RESET);
                    break;
                }

                if (play)
                {
                    if (x == 0 || x == N-1)
                    {
                        printf(RED "CANNOT PLACE ON OPPONENT'S BORDER!\n" RESET);
                        break;
                    }
                    if (checkvalidity(x, y, pl1, pl2))
                    {
                        place(x, y, pl1, pl1, pl2);
                        if (checkwin(N, pl1))
                        {
                            printboard(pl1, pl2);
                            printf(YELLOW "★★★ PLAYER A WINS! ★★★\n" RESET);
                            gameRunning = false;
                        }
                        else
                        {
                            play = !play;
                        }
                    }
                    else
                    {
                        printf(RED "INVALID MOVE (Occupied or Illegal Link)\n" RESET);
                    }
                }
                else
                {
                    if (y == 0 || y == N-1)
                    {
                        printf(BLUE "CANNOT PLACE ON OPPONENT'S BORDER!\n" RESET);
                        break;
                    }
                    if (checkvalidity(x, y, pl1, pl2))
                    {
                        place(x, y, pl2, pl1, pl2);
                        if (checkwin(N, pl2))
                        {
                            printboard(pl1, pl2);
                            printf(YELLOW "★★★ PLAYER B WINS! ★★★\n" RESET);
                            gameRunning = false;
                        }
                        else
                        {
                            play = !play;
                        }
                    }
                    else
                    {
                        printf(RED "INVALID MOVE (Occupied or Illegal Link)\n" RESET);
                    }
                }
                break;
            
            case 2:
                savecurrentgame(pl1, pl2, play, "game.txt");
                break;
            
            case 3:
                printf(YELLOW "DO YOU WANT TO SAVE YOUR PROGRESS OR LET IS PERISH:(\n " RESET);
                printf("YES ,THEN ENTER 1,NO THEN ENTER 0\n");
                int save;
                scanf("%d", &save);
                if (save == 1)
                {
                    savecurrentgame(pl1, pl2, play, "game.txt");
                }
                gameRunning = false;
                break;
            
            default:
                break;
        }
    }

    freespace(pl1);
    freespace(pl2);
    free(pl1);
    free(pl2);

    return 0;
}