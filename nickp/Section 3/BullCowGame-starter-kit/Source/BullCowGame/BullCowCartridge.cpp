// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"
#include "stdlib.h"
#include "time.h"


void UBullCowCartridge::BeginPlay() // When the game starts
{
    //Unreal Engine Stuff
    Super::BeginPlay();

    //Seed the RNG
    srand(time(NULL));

    //Print the Welcome Message
    PrintLine(WelcomeMessage);
}

void UBullCowCartridge::OnInput(const FString &Input) // When the player hits enter
{
    //Store the Input here so we can manipulate it
    FString PlayerInput = Input.ToLower();
    int32 DetectedBulls = 0;
    int32 DetectedCows = 0;
    int32 LoopIndex = 0;
    FString PlayerOutput;

    //If the game has not been started
    if (!GameStarted)
    {
        //Set the flag to true
        GameStarted = true;

        //Clear the Console
        ClearScreen();

        //Clear the Player Input Variable. This erases any input sent in response to the Welcome Message
        //This fails if we don't put the Input in a seperate FString. Weird :/
        PlayerInput = TEXT("");

        //Set Player Lives
        PlayerLives = 5;

        if(LastHiddenWord.Equals("")){
            //Pick a random hidden word
            HiddenWord = HiddenWords[rand() % (HiddenWords->Len() - 1)];
            LastHiddenWord=HiddenWord;
        }
        else
        {
            while(HiddenWord.Equals(LastHiddenWord))
            {
                HiddenWord = HiddenWords[rand() % (HiddenWords->Len() - 1)];
            }
            LastHiddenWord=HiddenWord;
        }
    

    }

    //If the player actually sent something/wasn't erased above
    if (PlayerInput.Len() > 0)
    {

        //Echo Out Data for Debugging
        PrintLine("You Said:<" + PlayerInput + ">");
        PrintLine("Hidden Word is:" + HiddenWord);

        //If the word matches, end the game, we're done
        if (HiddenWord.Equals(PlayerInput))
        {
            PlayerOutput = FString::Printf(TEXT("You're Right! The Word is:%s!\nYou had %02d lives remaining.\nPress Enter to play again"), *HiddenWord, PlayerLives);
            GameStarted = false;
        }
        else
        {
            //If PlayerInput is exactly 5
            if (PlayerInput.Len() == 5)
            {
                FString cows;
                //Loop through both strings
                for (LoopIndex = 0; LoopIndex < 5; LoopIndex++)
                {

                    //Take 1 character of each FString using FString's Mid function.
                    FString CurrentHiddenWordChar = HiddenWord.Mid(LoopIndex, 1);
                    FString CurrentPlayerInputChar = PlayerInput.Mid(LoopIndex, 1);

                    //Copy the PlayerInput into a seperate string so we can remove the character and compare
                    FString RestOfPlayerInput = FString::Printf(TEXT("%s"),*PlayerInput);
                    RestOfPlayerInput.RemoveAt(LoopIndex,1,true);

                    if(RestOfPlayerInput.Contains(CurrentPlayerInputChar))
                    {
                        //Lazy print
                        PrintLine("Error! Repeating Character Detected");
                        //Lazily deal with this case. 
                        DetectedBulls=-1;
                        DetectedCows=-1;
                        PlayerLives++;
                        break;
                    }
                    //Otherwise If the current characters match, we have a bull, increment the counter
                    else if (CurrentHiddenWordChar.Equals(CurrentPlayerInputChar))
                    {
                        DetectedBulls++;
                    }
                    //Otherwise if the current player character is just in the HiddenWord, we have a cow (man), increment the cow counter
                    else if (HiddenWord.Contains(CurrentPlayerInputChar))
                    {
                        DetectedCows++;
                        //Add the detected letter to the cows string with a comma
                        cows+=(FString::Printf(TEXT("%s,"),*CurrentPlayerInputChar));
                    }

                    
                }
                //Subtract a player life
                PlayerLives--;
                //Remove the trailing comma if the FString has any
                if(cows.Len()>0){
                    cows=cows.Mid(0,cows.Len()-1);
                }
                

                //Prompt the player
                //The Output is built using FString's PrintF Method.  %02d means int32 variable
                PlayerOutput = FString::Printf(TEXT("Bulls:%02d Cows:%02d:%s Lives:%02d"), DetectedBulls, DetectedCows,*cows, PlayerLives);
            }
            //Player Input is wrong length. Don't take a life.
            else
            {
                PlayerOutput = FString::Printf(TEXT("Wrong Length! Word is 5 letters! You entered %02d letters"), PlayerInput.Len());
            }

          
        }

        //If the Player is out of lives
        if (PlayerLives <= 0)
        {
  
            PlayerOutput = FString::Printf(TEXT("Game over :( The correct answer was %s\n Press Enter to play again"), *HiddenWord);
            GameStarted = false;
        }
        //Print the Player Output to the Console
        PrintLine(PlayerOutput);
   
    
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