#include<stdio.h>
#include<stdlib.h>
void Interface(void);
void Setup(void);
void Sign(void);
void Respond(void);
int CheckIfWon(void);
int i;
char setup[9];
char UserSign, CompSign;
void main()
{
    system("color 10");
    int choice;
    setup[0] = '1';
    setup[1] = '2';
    setup[2] = '3';
    setup[3] = '4';
    setup[4] = '5';
    setup[5] = '6';
    setup[6] = '7';
    setup[7] = '8';
    setup[8] = '9';
    for (i = 1; 1; i++)
    {
        if (i == 1)
        {
            Interface();
            getchar();
            system("cls");
            Sign();
        }
        system("cls");
        Setup();
        printf("Enter your choice.\n");
        scanf("%d", &choice);
        if (choice > 9)
        {
            printf("OOPS! there are only 9 spots in a 3*3 grid.\nPressEnter.\n");
            getchar();
            system("cls");
            Setup();
            i--;
            continue;
        }
        setup[choice - 1] = UserSign;

        if (CheckIfWon() == 1)
        {
            // UserWon();
            system("cls");
            Setup();
            printf(" \n      You Won\n");
            getchar();
            exit(1);
        }
        if (i == 5)
        {
            system("cls");
            Setup();
            printf("MATCH DRAW.\n");
            getchar();
            exit(1);
        }


        Respond();


        if (CheckIfWon() == 0)
        {
            // CompWon();
            system("cls");
            Setup();
            printf("\n      You Lose!\n");
            getchar();
            exit(1);
        }

    }
}

void Interface()
{
    printf("Hello everyone to this game..\n");
    printf("Press Enter.\n");
    printf("Developed by Sumrit Saproo.\n");
    printf("Registered and Copyright Reserved @ 2022.\n");

}

void Setup()
{
    printf("          |   %c   |   %c   |   %c   |\n", setup[0], setup[1], setup[2]);
    printf("        -------------------------------\n");
    printf("          |   %c   |   %c   |   %c   |\n", setup[3], setup[4], setup[5]);
    printf("        -------------------------------\n");
    printf("          |   %c   |   %c   |   %c   |\n\n", setup[6], setup[7], setup[8]);

}

void Sign()
{

    while (1)
    {
        printf("Enter your sign.\n");
        scanf("%c", &UserSign);
        if (UserSign == 'o')
        {
            CompSign = '#';
            break;
        }
        else if (UserSign == '#')
        {
            CompSign = 'o';
            break;
        }
        else
        {
            printf
            ("INVALID INPUT.\nPlease enter any of the signs as mentioned below.\n     o      #\n");
        }
    }
}

void Respond()
{
    if (i == 1 && setup[0] == '1')
    {
        setup[0] = CompSign;
        return;
    }
    else if (i == 1 && setup[2] == '3')
    {
        setup[2] = CompSign;
        return;
    }


    // ROWS

    // R1{
    if (setup[0] == setup[1])
    {
        if (setup[0] == CompSign)
        {
            if (setup[2] == '3')
            {
                setup[2] = CompSign;
                return;
            }
        }
    }

    if (setup[2] == setup[1])
    {
        if (setup[1] == CompSign)
        {
            if (setup[0] == '1')
            {
                setup[0] = CompSign;
                return;
            }
        }
    }

    if (setup[0] == setup[2])
    {
        if (setup[0] == CompSign)
        {
            if (setup[1] == '2')
            {
                setup[1] = CompSign;
                return;
            }
        }
    }

    // }

    // R2{
    if (setup[3] == setup[4])
    {
        if (setup[3] == CompSign)
        {
            if (setup[5] == '6')
            {
                setup[5] = CompSign;
                return;
            }
        }
    }

    if (setup[5] == setup[4])
    {
        if (setup[4] == CompSign)
        {
            if (setup[3] == '4')
            {
                setup[3] = CompSign;
                return;
            }
        }
    }

    if (setup[3] == setup[5])
    {
        if (setup[3] == CompSign)
        {
            if (setup[4] == '5')
            {
                setup[4] = CompSign;
                return;
            }

        }
    }
    // }
    // R3{
    if (setup[6] == setup[7])
    {
        if (setup[6] == CompSign)
        {
            if (setup[8] == '9')
            {
                setup[8] = CompSign;
                return;
            }
        }
    }

    if (setup[6] == setup[8])
    {
        if (setup[6] == CompSign)
        {
            if (setup[7] == '8')
            {
                setup[7] = CompSign;
                return;
            }
        }
    }

    if (setup[8] == setup[7])
    {
        if (setup[7] == CompSign)
        {
            if (setup[6] == '7')
            {
                setup[6] = CompSign;
                return;
            }
        }
    }
    // }

    // COLUMNS

    // C1{
    if (setup[0] == setup[3])
    {
        if (setup[0] == CompSign)
        {
            if (setup[6] == '7')
            {
                setup[6] = CompSign;
                return;
            }
        }
    }

    if (setup[6] == setup[3])
    {
        if (setup[3] == CompSign)
        {
            if (setup[0] == '1')
            {
                setup[0] = CompSign;
                return;
            }
        }
    }

    if (setup[0] == setup[6])
    {
        if (setup[0] == CompSign)
        {
            if (setup[3] == '4')
            {
                setup[3] = CompSign;
                return;
            }
        }
    }

    // }

    // C2{
    if (setup[1] == setup[4])
    {
        if (setup[1] == CompSign)
        {
            if (setup[7] == '8')
            {
                setup[7] = CompSign;
                return;
            }
        }
    }
    if (setup[7] == setup[4])
    {
        if (setup[4] == CompSign)
        {
            if (setup[1] == '2')
            {
                setup[1] = CompSign;
                return;
            }
        }
    }
    if (setup[1] == setup[7])
    {
        if (setup[1] == CompSign)
        {
            if (setup[4] == '5')
            {
                setup[4] = CompSign;
                return;
            }
        }
    }
    // }

    // C3{
    if (setup[2] == setup[5])
    {
        if (setup[2] == CompSign)
        {
            if (setup[8] == '9')
            {
                setup[8] = CompSign;
                return;
            }
        }
    }

    if (setup[8] == setup[5])
    {
        if (setup[5] == CompSign)
        {
            if (setup[2] == '3')
            {
                setup[2] = CompSign;
                return;
            }
        }
    }

    if (setup[2] == setup[8])
    {
        if (setup[2] == CompSign)
        {
            if (setup[5] == '6')
            {
                setup[5] = CompSign;
                return;
            }
        }
    }

    // }


    // DIAGONALS

    // D1{
    if (setup[0] == setup[4])
    {
        if (setup[0] == CompSign)
        {
            if (setup[8] == '9')
            {
                setup[8] = CompSign;
                return;
            }
        }
    }

    if (setup[8] == setup[4])
    {
        if (setup[4] == CompSign)
        {
            if (setup[0] == '1')
            {
                setup[0] = CompSign;
                return;
            }
        }
    }

    if (setup[0] == setup[8])
    {
        if (setup[0] == CompSign)
        {
            if (setup[4] == '5')
            {
                setup[4] = CompSign;
                return;
            }
        }
    }
    // }

    // D2{
    if (setup[2] == setup[4])
    {
        if (setup[2] == CompSign)
        {
            if (setup[6] == '7')
            {
                setup[6] = CompSign;
                return;
            }
        }
    }

    if (setup[6] == setup[4])
    {
        if (setup[4] == CompSign)
        {
            if (setup[2] == '3')
            {
                setup[2] = CompSign;
                return;
            }
        }
    }


    if (setup[2] == setup[6])
    {
        if (setup[2] == CompSign)
        {
            if (setup[4] == '5')
            {
                setup[4] = CompSign;
                return;
            }
        }
    }

    // ROWS

    // R1{
    if (setup[0] == setup[1])
    {
        if (setup[0] == UserSign)
        {
            if (setup[2] == '3')
            {
                setup[2] = CompSign;
                return;
            }
        }
    }

    if (setup[2] == setup[1])
    {
        if (setup[1] == UserSign)
        {
            if (setup[0] == '1')
            {
                setup[0] = CompSign;
                return;
            }
        }
    }

    if (setup[0] == setup[2])
    {
        if (setup[0] == UserSign)
        {
            if (setup[1] == '2')
            {
                setup[1] = CompSign;
                return;
            }
        }
    }

    // }

    // R2{
    if (setup[3] == setup[4])
    {
        if (setup[3] == UserSign)
        {
            if (setup[5] == '6')
            {
                setup[5] = CompSign;
                return;
            }
        }
    }

    if (setup[5] == setup[4])
    {
        if (setup[4] == UserSign)
        {
            if (setup[3] == '4')
            {
                setup[3] = CompSign;
                return;
            }
        }
    }

    if (setup[3] == setup[5])
    {
        if (setup[3] == UserSign)
        {
            if (setup[4] == '5')
            {
                setup[4] = CompSign;
                return;
            }

        }
    }
    // }
    // R3{
    if (setup[6] == setup[7])
    {
        if (setup[6] == UserSign)
        {
            if (setup[8] == '9')
            {
                setup[8] = CompSign;
                return;
            }
        }
    }

    if (setup[6] == setup[8])
    {
        if (setup[6] == UserSign)
        {
            if (setup[7] == '8')
            {
                setup[7] = CompSign;
                return;
            }
        }
    }

    if (setup[8] == setup[7])
    {
        if (setup[7] == UserSign)
        {
            if (setup[6] == '7')
            {
                setup[6] = CompSign;
                return;
            }
        }
    }
    // }

    // COLUMNS

    // C1{
    if (setup[0] == setup[3])
    {
        if (setup[0] == UserSign)
        {
            if (setup[6] == '7')
            {
                setup[6] = CompSign;
                return;
            }
        }
    }

    if (setup[6] == setup[3])
    {
        if (setup[3] == UserSign)
        {
            if (setup[0] == '1')
            {
                setup[0] = CompSign;
                return;
            }
        }
    }

    if (setup[0] == setup[6])
    {
        if (setup[0] == UserSign)
        {
            if (setup[3] == '4')
            {
                setup[3] = CompSign;
                return;
            }
        }
    }

    // }

    // C2{
    if (setup[1] == setup[4])
    {
        if (setup[1] == UserSign)
        {
            if (setup[7] == '8')
            {
                setup[7] = CompSign;
                return;
            }
        }
    }
    if (setup[7] == setup[4])
    {
        if (setup[4] == UserSign)
        {
            if (setup[1] == '2')
            {
                setup[1] = CompSign;
                return;
            }
        }
    }
    if (setup[1] == setup[7])
    {
        if (setup[1] == UserSign)
        {
            if (setup[4] == '5')
            {
                setup[4] = CompSign;
                return;
            }
        }
    }
    // }

    // C3{
    if (setup[2] == setup[5])
    {
        if (setup[2] == UserSign)
        {
            if (setup[8] == '9')
            {
                setup[8] = CompSign;
                return;
            }
        }
    }

    if (setup[8] == setup[5])
    {
        if (setup[5] == UserSign)
        {
            if (setup[2] == '3')
            {
                setup[2] = CompSign;
                return;
            }
        }
    }

    if (setup[2] == setup[8])
    {
        if (setup[2] == UserSign)
        {
            if (setup[5] == '6')
            {
                setup[5] = CompSign;
                return;
            }
        }
    }

    // }


    // DIAGONALS

    // D1{
    if (setup[0] == setup[4])
    {
        if (setup[0] == UserSign)
        {
            if (setup[8] == '9')
            {
                setup[8] = CompSign;
                return;
            }
        }
    }

    if (setup[8] == setup[4])
    {
        if (setup[4] == UserSign)
        {
            if (setup[0] == '1')
            {
                setup[0] = CompSign;
                return;
            }
        }
    }

    if (setup[0] == setup[8])
    {
        if (setup[0] == UserSign)
        {
            if (setup[4] == '5')
            {
                setup[4] = CompSign;
                return;
            }
        }
    }
    // }

    // D2{
    if (setup[2] == setup[4])
    {
        if (setup[2] == UserSign)
        {
            if (setup[6] == '7')
            {
                setup[6] = CompSign;
                return;
            }
        }
    }

    if (setup[6] == setup[4])
    {
        if (setup[4] == UserSign)
        {
            if (setup[2] == '3')
            {
                setup[2] = CompSign;
                return;
            }
        }
    }


    if (setup[2] == setup[6])
    {
        if (setup[2] == UserSign)
        {
            if (setup[4] == '5')
            {
                setup[4] = CompSign;
                return;
            }
        }
    }

    // }
    for (int k = 0; k < 10; k++)
    {
        if (setup[k] >= '1' && setup[k] <= '9')
        {
            setup[k] = CompSign;
            return;
        }
    }

}


int CheckIfWon()
{
    if (setup[0] == setup[1] && setup[0] == setup[2])
    {
        if (setup[0] == UserSign)
        {
            return 1;
        }
        else if (setup[0] == CompSign)
        {
            return 0;
        }

    }

    if (setup[3] == setup[4] && setup[3] == setup[5])
    {
        if (setup[3] == UserSign)
        {
            return 1;
        }
        else if (setup[3] == CompSign)
        {
            return 0;
        }

    }

    if (setup[6] == setup[7] && setup[6] == setup[8])
    {
        if (setup[6] == UserSign)
        {
            return 1;
        }
        else if (setup[6] == CompSign)
        {
            return 0;
        }

    }

    if (setup[0] == setup[3] && setup[0] == setup[6])
    {
        if (setup[0] == UserSign)
        {
            return 1;
        }
        else if (setup[0] == CompSign)
        {
            return 0;
        }

    }

    if (setup[1] == setup[4] && setup[1] == setup[7])
    {
        if (setup[1] == UserSign)
        {
            return 1;
        }
        else if (setup[1] == CompSign)
        {
            return 0;
        }

    }

    if (setup[2] == setup[5] && setup[2] == setup[8])
    {
        if (setup[2] == UserSign)
        {
            return 1;
        }
        else if (setup[2] == CompSign)
        {
            return 0;
        }

    }


    if (setup[0] == setup[4] && setup[0] == setup[8])
    {
        if (setup[0] == UserSign)
        {
            return 1;
        }
        else if (setup[0] == CompSign)
        {
            return 0;
        }

    }


    if (setup[2] == setup[4] && setup[2] == setup[6])
    {
        if (setup[2] == UserSign)
        {
            return 1;
        }
        else if (setup[2] == CompSign)
        {
            return 0;
        }

    }

    return 2;

}
