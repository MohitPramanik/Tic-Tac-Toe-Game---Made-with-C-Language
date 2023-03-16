#include <stdio.h>
#include <stdlib.h>

char player1[30], player2[30];
int count = 0;


void welcomeMessage()
{
    printf("\n\n\n");
    printf("\t\t\t\t\t\t\t __________________________\n");
    printf("\t\t\t\t\t\t\t|                          |\n");
    printf("\t\t\t\t\t\t\t|  Welcome to Tic-Tac-Toe  |\n");
    printf("\t\t\t\t\t\t\t|__________________________|\n\n\n\n\n\n");
}

void playerName()
{
    printf("\t\t\t\t\t\t\tPlayer 1 : ");
    gets(player1);
    printf("\n\t\t\t\t\t\t\tPlayer 2 : ");
    gets(player2);
}

void gameName()
{
    printf("\t\t\t\t\t\t\t   ____________________");
    printf("\n\t\t\t\t\t\t\t  |                    |");
    printf("\n\t\t\t\t\t\t\t  |  Tic-Tac-Toe Game  |");
    printf("\n\t\t\t\t\t\t\t  |____________________|\n\n\n");
}

void gameTemplate(char *position)
{
    gameName();
    printf("\t\t\t\t\t\t\t|-------|-------|-------|\n");
    printf("\t\t\t\t\t\t\t|   %c   |   %c   |   %c   |\n", position[0], position[1], position[2]);
    printf("\t\t\t\t\t\t\t|-------|-------|-------|\n");
    printf("\t\t\t\t\t\t\t|   %c   |   %c   |   %c   |\n", position[3], position[4], position[5]);
    printf("\t\t\t\t\t\t\t|-------|-------|-------|\n");
    printf("\t\t\t\t\t\t\t|   %c   |   %c   |   %c   |\n", position[6], position[7], position[8]);
    printf("\t\t\t\t\t\t\t|-------|-------|-------|\n");
}

void play(char *position)
{
    int index;
// Player 1
start1:
    printf("\n\n\t\t\t\t\t\t\t\t%s turn\n\n", player1);
    printf("\nEnter position : ");
    scanf("%d", &index);
    if (position[index - 1] == 'X' || position[index - 1] == 'O')
    {
        system("cls");
        gameTemplate(position);
        goto start1;
    }
    else
    {
        position[index - 1] = 'X';
        count++;
    }

    if (count == 9)
    {
        return;
    }

    system("cls");
    gameTemplate(position);
    printf("\n\n");

// Player 2
start2:
    printf("\t\t\t\t\t\t\t\t%s turn\n\n", player2);
    printf("\nEnter position : ");
    scanf("%d", &index);
    if (position[index - 1] == 'X' || position[index - 1] == 'O')
    {
        system("cls");
        gameTemplate(position);
        goto start2;
    }
    else
    {
        position[index - 1] = 'O';
        count++;
    }
}

void checkWin(char *position)
{
    if ((position[0] == 'X' && position[1] == 'X' && position[2] == 'X') ||
        (position[3] == 'X' && position[4] == 'X' && position[5] == 'X') ||
        (position[6] == 'X' && position[7] == 'X' && position[8] == 'X') ||
        (position[0] == 'X' && position[3] == 'X' && position[6] == 'X') ||
        (position[1] == 'X' && position[4] == 'X' && position[7] == 'X') ||
        (position[2] == 'X' && position[5] == 'X' && position[8] == 'X') ||
        (position[0] == 'X' && position[4] == 'X' && position[8] == 'X') ||
        (position[2] == 'X' && position[4] == 'X' && position[6] == 'X'))
    {
        printf("WOHOOOO!!!, %s won", player1);
    }
    else if ((position[0] == 'O' && position[1] == 'O' && position[2] == 'O') ||
             (position[3] == 'O' && position[4] == 'O' && position[5] == 'O') ||
             (position[6] == 'O' && position[7] == 'O' && position[8] == 'O') ||
             (position[0] == 'O' && position[3] == 'O' && position[6] == 'O') ||
             (position[1] == 'O' && position[4] == 'O' && position[7] == 'O') ||
             (position[2] == 'O' && position[5] == 'O' && position[8] == 'O') ||
             (position[0] == 'O' && position[4] == 'O' && position[8] == 'O') ||
             (position[2] == 'O' && position[4] == 'O' && position[6] == 'O'))
    {
        printf("WOHOOOO!!!, %s won", player2);
    }
    else
    {
        printf("Match Tied!!!");
    }
}

int main()
{
    system("cls"); // to clear screen

    char playAgain;

    welcomeMessage();

    restart:
    char position[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    playerName();
    printf("\n\n\t\t\t\t\t\t  Press enter to continue...");
    getchar();
    system("cls"); 


    while (count < 9)
    {
        gameTemplate(position);
        play(position);
        system("cls"); 
    }

    gameTemplate(position);
    printf("\n\n\n");
    checkWin(position);

    getchar();
    printf("\n\nWanna play again (y/n) : ");
    scanf("%c", &playAgain);
    getchar();

    if (playAgain == 'y')
    {
        count = 0;
        goto restart;
    }

    return 0;
}