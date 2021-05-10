/*
 * File name:           BlackJack.c
 * Author:              Prarthona Paul 
 * Date:                Feb 1, 2021
 * Description:         This program is a simplified game of blackjack that uses numerical input from the 
 *                      user to run the game on a command line environment. 
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

int main(int argc, char **argv)
{
    if(argc==1)
        srand(time(NULL));
    else
        srand(atoi(argv[1]));
        
    int playerScore = 0;
    int dealerScore = 0;                        //playerScore and dealerScore hold the total score of the players.
    int hit_Or_Stay, playerRand, dealerRand;   //hit_Or_Stay stores the player's decision to hit or stay
   
    dealerRand = rand() %13 + 1;   
    playerRand = rand() % 13 + 1;       //PlayerRand and dealerRand generates a random card from 1 to 13, which gets added to total score.

     // The following 2 if statements check the value of the card and changes values 10+ to 10.          
    if(playerRand > 9)
        playerScore += 10;        //cards with face value greater than 1 becomes 10 for the player
    else 
        playerScore += playerRand;
                
    if(dealerRand > 9)
        dealerScore += 10; 
    else 
        dealerScore += dealerRand;
        
	printf("First cards: player %d, dealer %d\n", playerRand, dealerRand);
   
    do{                 //Loop used to control Player's turn
        printf("Type 1 for hit, 0 to stay: ");
        scanf("%d", &hit_Or_Stay);      //reads if the player decides to hit or stay as an integer. 

        if (hit_Or_Stay == 0) 
            break;      //Player's turn ends and dealer's turn begins. 
            
        else if (hit_Or_Stay == 1)
        {
            playerRand = rand() % 13+1;
            
            if(playerRand > 9)
                playerScore += 10;      //Adds only a 10 to the score if the face value of the card without changing the 
            else 
                playerScore += playerRand;  //When the facevalue is < 9, then the facevalue is added to the score. 
            
            printf("Player gets a %d, worth is %d\n", playerRand, playerScore);
            
            if(playerScore > 21)       //Player loses if the player goes over 21. 
            {
                printf("Player over 21, dealer wins\n");    //dealer does not need to play, they automatically win.
                break;                  //Player's turn is over, so game exits loop to end player's turn. 
            }
        }
        else      //hit or stay can only be 1 or 0, user will be asked to reenter
        {
            printf("Incorrect input. Please enter '1' or '0'\n");
            hit_Or_Stay = 1; //This variable also determines if the player can continue playing.
        }
        
    } while (hit_Or_Stay == 1);     //Ends loop that controls player's turn.
        
    if (hit_Or_Stay == 0)          //Only lets dealer play if player quit game before 21.
    {
        printf("Dealer gets: ");   //Displays dealer's score
        
        while(dealerScore <= 17)       //Loop used to generate score for dealer, Dealer must stop after 17
        {
        dealerRand = rand() %13 + 1;   
     
            if(dealerRand > 9)
                dealerScore += 10;      //score is 10 if facevalue is 10 or more and facevalue if it is 9 or lower
            else 
                dealerScore += dealerRand; 
            printf("%d ", dealerRand);     //displays dealer's score sepeated by a space
        }                                   //End loop 
        
        if(dealerScore <= 21)        //If statements to determine results of the game
        {
            if(dealerScore > playerScore)       
                printf("\nDealer better than Player, Dealer wins\n"); //dealer wins
            
            else if (dealerScore == playerScore)                //Tie between players
                printf("\nTie!\n");
            
            else                                        //Dealer is not better than player and theyre not equal.        
                printf("\nPlayer better than Dealer, Player wins\n");   //Player wins
        }
        else
            printf("\nDealer goes over 21, Player wins\n");     //Dealer loses if score >21
    }
     return 0;
}
