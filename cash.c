#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){

// Program to determine the least amount of coins needed to make change using American denominations

    // Declare the denominations we are using

    int denominations[4] = {25,10,5,1};
    
    // Find the amount of change the user needs

    float dollars;
    do{
    dollars = get_float("Change owed: ");
    }while(dollars < 0);

    // Check that the math is right

    int cents = round(dollars * 100);

    // Find the right amount of change
    
    int num_coins = 0; 
    
    for(int i = 0; i < 4; i++){
        
        // Figure out how many times the current denomination goes into our current cent total
        
        int q = cents/denominations[i];
        
        if(q > 0){
            
            // Update the current cent tally
            
            cents = cents - (denominations[i]*q);
        }
        
        num_coins = num_coins + q;
    }
    
    printf("%i\n", num_coins);
    
}
