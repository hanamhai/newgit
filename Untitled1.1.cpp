#include  <conio.h>
#include  <stdio.h>
#include  <malloc.h>
#include  <memory.h>
#define    RANK  6
void queens_checker  (int** queens, int rank, int current) 
 {
    static int order = 0;  int i, j;
    int s1 = 0, s2 = 0, s3 = 0, s4 = 0;  int k;
    if (current == rank) 
    {     
        printf ("Order %d: \n\n", ++order);
        for (i = 0; i < rank; i++) 
     {
            for (j = 0; j < rank; j++)
                printf ("%4d", queens[i][j]);
            printf("\n\n");
        }  printf("\n");
        return;
    }
    for (j = 0; j < rank; j++)
             {
        s1 = 0;  s2 = 0;  s3 = 0;  s4 = 0;
        if (!queens[current][j] ) 
                        {
            queens[current][j] = 1;
            for (i = 0; i < rank; i++)
                                    {
                s1 += queens[current][i];
                s2 += queens[i][j];
            }  k = 1;
            s3 = queens[current][j];
            while ((current + k) < rank && (j + k) < rank) 
                                    {
                s3 += queens [current + k] [j + k];
                ++k;
            }  k = -1;
            while ((current + k) >= 0 && (j + k) >= 0) 
                                    {
                s3 += queens [current + k] [j + k];
                --k;
           
                                    }  k = 1;
            s4 = queens[current][j];
            while ((current + k) < rank && (j - k) >= 0)
                                    {
                s4 += queens[current + k][j - k];
                ++k;
            }  k = -1;
            while ((current + k) >= 0 && (j - k) < rank) 
                                    {
                s4 += queens [current + k] [j - k];
                --k;
            }
            if ((s1 < 2) && (s2 < 2) && (s3 < 2) && (s4 < 2))
                queens_checker (queens, rank, current + 1);
            queens [current][j] = 0;
        }  /* End if (!queens[current][j] ) */
    }  /*  End for (j = 0; j < rank; j++) */
}
int main() 
{
    int** queens;  int i, j;  int rank = RANK;
    queens = (int **)malloc(rank * sizeof(int *));
    for (i = 0; i < rank; i++) 
            {
        queens[i] = (int *)malloc(rank * sizeof(int));
        memset (queens[i], 0, rank * sizeof(int));
    }
    queens_checker(queens, rank, 0);
    for (i = 0; i < rank; i++)
        free(queens[i]);
    free(queens);  getch();  return 0;
}
