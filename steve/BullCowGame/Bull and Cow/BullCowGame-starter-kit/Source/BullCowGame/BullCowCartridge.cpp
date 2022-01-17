// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
FString playerName = "";
bool welcome = true;



void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to the Wonderful World of Cows!"));
    PrintLine(TEXT("\"If you ain't having fun...\n you must be full of bull!\""));
    PrintLine(TEXT("What's your name, buddy?"));

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
        PrintLine(TEXT("You need to guess the isogram! It's as simple as that!"));
        PrintLine(TEXT("What's an isogram, you say? It's a word with no repeated letters."));
        PrintLine(TEXT("Enter your guess to begin!"));
    }
    else
    {
        FString hiddenWord = TEXT("ravens");
        if (hiddenWord.Equals(Input))
        {
            PrintLine(TEXT("Wow! I didn't think it was possible!"));
            PrintLine(TEXT("Awesome job getting the word!"));
            PrintLine(TEXT("Come back again sometime!"));
        }
        else
        {
            PrintLine(TEXT("Nope! The correct word was: " + hiddenWord));
        }

    }
    
}