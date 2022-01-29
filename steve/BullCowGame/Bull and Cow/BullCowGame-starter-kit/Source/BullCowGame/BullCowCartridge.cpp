// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to the Wonderful World of Cows!"));
    PrintLine(TEXT("\"If you ain't having fun...\n you must be full of bull!\""));
    PrintLine(TEXT("What's your name, buddy?"));
    welcome = true;
    gameOver = false;
    lives = 5;
    hiddenWord = TEXT("ravens");

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    if (welcome)
    {
        playerName = Input;
        welcome = false;
        PrintLine(TEXT("Howdy there, " + playerName + "!"));
        PrintLine(TEXT("Here's how the game works:"));
        PrintLine(TEXT("You need to guess the isogram! \nIt's as simple as that!"));
        PrintLine(TEXT("What's an isogram, you say? \nIt's a word with no repeated letters."));
        PrintLine(TEXT("You will then be given information about your guess"));
        PrintLine(TEXT("Enter your guess to begin!"));
    }
    else
    {
        if (gameOver == false)
        {
            if (hiddenWord.Equals(Input))
            {
                PrintLine(TEXT("Wow! I didn't think it was possible!"));
                PrintLine(TEXT("Awesome job getting the word!"));
                PrintLine(TEXT("Come back again sometime!"));
                gameOver = true;
            }
            else
            {
                bool valid = true;
                if (valid)
                {
                    PrintLine(TEXT("Nope! That is not correct!"));
                    lives--;
                    if(lives > 0)
                    {
                        PrintLine(TEXT("Lives remaining: "));
                        PrintLine("" + lives);
                        PrintLine(TEXT("Guess again..."));
                    }
                    else
                    {
                        gameOver = true;
                        PrintLine(TEXT("Bummer. You didn't get it."));
                        PrintLine(TEXT("The word was: " + hiddenWord));
                    }
                }
            }
        }
    }
    
}