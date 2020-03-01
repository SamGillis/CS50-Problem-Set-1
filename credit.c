#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long card;
    int i = 0;
    int d = 0;
    do 
    {
        card = get_long("Credit Card Number: ");
    }

    //reprompts for negative amount 
    while (card < 0); 

    //get final number 
    //this makes sure I can check the card number later and stores card
    long t = card;
    // loop for adding up the digits in the card number
    while (t > 0)
    {
        i = t % 10;
        t = t / 10; 
        d = d + i;
        i = t % 10; 
        t = t / 10;
        //adds the digits, not the products
        int p = 2 * i;
        if (p > 9) 
        {
            p = p - 9;
        }
        d = d + p;
    }
    //calculates the ones place of the above equation
    int checksum = d % 10;

    //checks the card checksum or says invalid
    if (checksum == 0)
    {
        //checks the type of card 
        //American Express
        //checks if the card is 15 digits
        if (card > 339999999999999 && card < 380000000000000)
        {
            //gets the 14th digit in the card
            if (((card = card % 100000000000000) && ((card / 10000000000000) == 4)) || ((card = card % 100000000000000)
                    && ((card / 10000000000000) == 7)))
            {
                //if all true, prints AMEX
                printf("AMEX\n");
            }
            else 
            {
                printf("INVALID\n");
            }
        }
        //Visa 
        //checks if the card starts with 4 and is 13 or 16 digits
        else if ((card > 3999999999999 && card < 5000000000000) || (card > 3999999999999999 && card < 5000000000000000))
        {
            //outputs Visa
            printf("VISA\n");
        }
        //Mastercard
        //checks if the card is 16 digits and starts 51 - 55
        else if (card > 5099999999999999 && card < 5600000000000000)
        {
            printf("MASTERCARD\n");
        }
        else 
        {
            //if doesn't meet any of the criteria prints invalid
            printf("INVALID\n");
        }
    }
    else 
    {
        //if doesn't meet checksum, prints invalid 
        printf("INVALID\n");
    }
}
