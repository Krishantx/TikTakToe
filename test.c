#include <stdio.h>
char a[9]={'1','2','3','4','5','6','7','8','9'};
int move;
void board();
int win();
int main()
{
    char test;
    int i=1;
    int pos;
    int b[9]={1,1,1,1,1,1,1,1,1};
    g1:
    board();
    move = (i%2==0)?'X':'O';
    if (win()==2)
    {
    }
    else if (win() == 0)
    {
        printf("O won\n");
        goto end;
    }
    else
    {
        printf("X won\n");
        goto end;
    }
    
    scanf("%d", &pos);


   
    if (b[pos-1]!=1)
    {
        {
            printf("Invalid Move 2\n");
            goto g1;    
        }
    }
    else
    {
    (b[pos-1])=0;
    }
    if (pos<10)
    {
        a[pos-1]=move;
        i++;
        win();
        goto g1;
    }
    else
    {
        printf("Invalid move 1\n");
        goto g1;
    }
    end:
    printf("Thanks for playing\nPress enter to quit");
    getchar();
    return 0;

}
void board()
{
    printf(" %c | %c | %c\n",a[0],a[1],a[2]);
    printf("-----------\n");
    printf(" %c | %c | %c\n",a[3],a[4],a[5]);
    printf("-----------\n");
    printf(" %c | %c | %c\n",a[6],a[7],a[8]);
}

int win()
{
    if (a[0]=='1')
    {
        return 2;
    }
    //row win condition
     for(int j=0;j<9;j=j+3)
    {
        char p=(a[j]=='X')?'X':'O';
        if (a[j+1]==p)
        {
            if (a[j+2]==p)
            {
                //printf("%c won\n", p);
                return (p=='X')?1:0;
            }
        }
    }
    //Column win condition
    for (int j=0;j<9;j=j+3)
    {
         char p=(a[j]=='X')?'X':'O';
        if (a[j+3]==p)
        {
            if (a[j+6]==p)
            {
                //printf("%c won\n", p);
                return (p=='X')?1:0;
            }
        }        
    }
    //diagonal win condition
    char p=(a[4]=='X')?'X':'O';
    if (a[0]==p)
    {
        if (a[8]==p)
        return (p=='X'?1:0);
    }
    if (a[2]==p)
    {
        if (a[6]==p)
            return ((p=='X')?1:0);
    }
    return 2;
}