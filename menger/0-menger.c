#include <stdio.h>
#include <stdlib.h>
#include "menger.h"


/**
*menger - draws a 2d Menger Sponge at a given level 
* @level: Level of the Menger Sponge to draw
*/

void menger(int level)
{
    int n, m, j, x, y;
    char s;


    m =(int)pow(3, level); //// Cast to int to avoid floating-point issues
    for (n = 0; n < m; n++)
    {
        for (j = 0; j < m;)
        {
            s = '#';
            x = n;
            y = j++;
            while (x > 0 || y > 0)
            {
                if (x % 3 == 1 && y % 3 == 1)
                {
                    s = ' ';
                    break; // Exit loop early once space is confirmed
                }
                x /= 3;
                y /= 3;
            }
            putchar(s);// Use putchar instead of printf for efficiency
            
        }
        putchar('\n');

    }
}



