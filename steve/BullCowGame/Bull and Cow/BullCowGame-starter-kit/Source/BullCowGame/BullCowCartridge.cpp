// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay() // When the game starts
{
    Super::BeginPlay();
    PrintLine("Welcome to the Wonderful World of Cows!");
    PrintLine("\"If you ain't having fun, you're full of bull!\"");
    PrintLine("What's your name, buddy?");

}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    ClearScreen();
}