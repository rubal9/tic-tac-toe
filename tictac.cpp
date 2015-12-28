#include <stdio.h>
#include<stdlib.h>
  int main()
  {
        int winner = 0, count = 0;
        int data[16], index, sign, player, flag, i, k, j;

        for (i = 0; i < 16; i++)
                data[i] = ' ' ;

        while (count < 16)
            {
                flag = 0;
                //system("clear");
                printf("\n\n");
                printf("\t\t\t  %c | %c  | %c  | %c   \n", data[0], data[1], data[2], data[3]);
                printf("\t\t\t----+----+----+----\n");
                printf("\t\t\t  %c | %c  | %c  | %c   \n", data[4], data[5], data[6], data[7]);
                printf("\t\t\t----+----+---+----\n");
                printf("\t\t\t  %c | %c  | %c  | %c  \n", data[8], data[9], data[10], data[11]);
                printf("\t\t\t----+----+---+----\n");
                printf("\t\t\t  %c | %c  | %c  | %c  \n", data[12], data[13], data[14], data[15]);

                if (count % 2 == 0)
                    {
                        sign = 'X';
                        player = 1;
                }
                else
                {

                        sign = 'Y';
                        player = 2;
                }
                printf("Move for player%d(1-16):", player);
                scanf("%d", &index);
                if (index < 1 || index > 16)
                {

                        printf("Allowed index is 1 to 16!!\n");
                        continue;
                }
                if (data[index - 1] == 'X' || data[index - 1] == 'Y')
                    {
                        printf("Position Already occupied!!\n");

                        continue;

                    }
                data[index - 1] = sign;
                count++;

                for (i = 0; i < 16; i++)
                    {
                        if (i % 4 == 0)
                                flag = 0;

                        if (data[i] == sign)
                                flag++;

                        if (flag == 4)
                            {
                                winner = 1;
                                goto win;
                            }
                }

                flag = 0;
                for (i = 0; i < 4; i++)
                    {
                        for (k = i; k <= i + 4; k = k + 4)
                        {
                                if (data[k] == sign)
                                        flag++;
                        }
                        if (flag == 4)
                        {
                                winner = 1;
                                goto win;
                        }
                        flag = 0;
                 }
                if ((data[0] == sign && data[5] == sign && data[10] == sign && data[15] == sign) ||
                        (data[3] == sign && data[6] == sign && data[9] ==  sign && data[12] == sign))
                        {

                        winner = 1;
                        goto win;
                }
        }
  win:
       system("clear");
                printf("\n\n");
                printf("\t\t\t  %c | %c  | %c  | %c   \n", data[0], data[1], data[2], data[3]);
                printf("\t\t\t----+----+----+----\n");
                printf("\t\t\t  %c | %c  | %c  | %c   \n", data[4], data[5], data[6], data[7]);
                printf("\t\t\t----+----+---+----\n");
                printf("\t\t\t  %c | %c  | %c  | %c  \n", data[8], data[9], data[10], data[11]);
                printf("\t\t\t----+----+---+----\n");
                printf("\t\t\t  %c | %c  | %c  | %c  \n", data[12], data[13], data[14], data[15]);

        if (winner) {
                printf("Player %d is the winner. Congrats!!\n", player);
        } else {
                printf("Match draw.. Best of luck for both\n");
        }
        return 0;
  }
