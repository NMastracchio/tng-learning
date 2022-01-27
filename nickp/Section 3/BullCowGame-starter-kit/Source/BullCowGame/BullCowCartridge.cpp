// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "stdlib.h"
#include "time.h"




void UBullCowCartridge::BeginPlay() // When the game starts
{
    //Unreal Engine Stuff
    Super::BeginPlay();  

    //Seed the RNG                               
    srand (time(NULL));

    //Print the Welcome Message                            
    PrintLine(WelcomeMessage);

    //Pick a random hidden word
    HiddenWord = HiddenWords[rand() % (HiddenWords->Len()-1)];
}

void UBullCowCartridge::OnInput(const FString& Input) // When the player hits enter
{
    //Store the Input here so we can manipulate it
    FString PlayerInput =Input.ToLower();

    //If the game has not been started
    if(!GameStarted){
        //Set the flag to true
        GameStarted=true;

        //Clear the Console
        ClearScreen();
        
        //Clear the Player Input Variable. This erases any input sent in response to the Welcome Message
        //This fails if we don't put the Input in a seperate FString. Weird :/
        PlayerInput = TEXT("");
        
    }
    
    //If the player actually sent something/wasn't erased above
    if(PlayerInput.Len()>0){

        //Echo the Input for Debugging
        PrintLine("You Said:<"+PlayerInput+">");

        //Echo the Hidden Word for Debugging
        PrintLine("Hidden Word is:"+HiddenWord);

        //Print Success or Fail Message
        if(HiddenWord.Equals(PlayerInput))
        {
            PrintLine("You Did it");
        }
        else
        {
            PrintLine("Nope");
        }
        

    }
    
    
    /* Manual Clear Screen lol
    PrintLine("");
    PrintLine("");
    PrintLine("");
    PrintLine("");
    PrintLine("");
    PrintLine("");
    PrintLine("");
    PrintLine("");
    PrintLine("");
    PrintLine("");
    PrintLine("");
    PrintLine("");    
    */ 
   
}