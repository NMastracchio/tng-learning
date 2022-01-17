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
    }
    else
    {
        FString hiddenWord = TEXT("bourbon");

    }
    
}