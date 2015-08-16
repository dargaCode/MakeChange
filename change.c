#include <cs50.h>
#include <stdio.h>
#include <math.h>

// prototypes
float GetPositiveFloat();
int RemoveCoin(int change_left, int coin_num);

int main(void)
{
    int total_coins = 0;
    int remaining_change = round(GetPositiveFloat() * 100);
    
    while (remaining_change > 0)
    {
        total_coins++;
        remaining_change = RemoveCoin(remaining_change, total_coins);
    }
    printf("      Total coins required: %i\n", total_coins);
}

/*
 * Prompt for and validate a positive float
 */
float GetPositiveFloat()
{
    float input;
    do 
    {
        printf("  How much change is owed? $");
        input = GetFloat();
    }
    while (input <= 0.00 );
    return input;
}

/*
 *  Remove the largest coin denomination possible
 */
int RemoveCoin(int cents, int coin_num)
{   string coin;
    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;
    
    if (cents >= quarter)
    {
        cents -= quarter;
        coin = "quarter";
        
    }
    else if (cents >= dime)
    {
        cents -= dime;
        coin = "   dime";
    }
    else if (cents >= nickel)
    {
        cents -= nickel;
        coin = " nickel";
    }
    else
    {
        cents -= penny;
        coin = "  penny";
    }
    
    printf("    Coin %02i = %s. %i cents remaining. \n", coin_num, coin, cents);
    return cents;
}
