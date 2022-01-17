// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
FString playerName = "";
bool welcome = true;
void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine("Welcome to the Wonderful World of Cows!");
    PrintLine("\"If you ain't having fun...\n you must be full of bull!\"");
    PrintLine("What's your name, buddy?");

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
    if (welcome)
    {
        playerName = Input;
        welcome = false;
        PrintLine("Howdy there, " + playerName + "!");
    }
    
}