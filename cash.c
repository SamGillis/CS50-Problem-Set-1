#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float x;
    int o = 0;

    //Prompts for change amount
    do 
    {
        x = get_float("Change owed: ");
    }

    //reprompts for negative amount 
    while (x < 0); 
    
    //rounds to cents
    int c = round(x * 100);

    //continue running program while cents are still owed
    while (c > 0)
    {
        //how many quarters
        if (c >= 25)
        {
            c = c - 25; 
        }
        //how many dimes
        else if (c >= 10)
        {
            c = c - 10; 
        }
        //how many nickels
        else if (c >= 5)
        {
            c = c - 5; 
        }
        //how many pennies
        else 
        {
            c = c - 1; 
        }
        //increase the amount of coins owed 
        o++;
    }
    //print amount of coins owed 
    printf("%i\n", o);
}
