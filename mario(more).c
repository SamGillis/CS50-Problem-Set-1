#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    do 
    {
        //prompts user for size 
        n = get_int("Size: ");
    }
    //reprompts for size when not a positive interger
    while (n < 1 || n > 8);
    
    //makes the pyramid
    //row 
    for (int i = 0; i < n; i++)
    {
        //columns
        for (int j = 0; j < n; j++)
        {
            //first right aligned group
            if (j + 1 >= n - i)
            {
                printf("#");
            }
            else 
            {
                printf(" ");   
            }
        }

        // spaces between the pryamid
        printf("  ");

        //left alligned pryamid 
        for (int j = n - 1 - i; j < n; j++)
        {   
            printf("#");   
        } 
        //new line
        printf("\n");
    }
}
