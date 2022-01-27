// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
	GENERATED_BODY()

	public:
	virtual void BeginPlay() override;
	virtual void OnInput(const FString& Input) override;

	// Your declarations go below!
	private:
	//Boolean used to flag if the game has started or not
	bool GameStarted = false;

	//Welcome Message we print at the start of the game.
	const FString WelcomeMessage = TEXT("Hello There, Welcome to Bulls Cow Game!!!!\nYou will be guessing a 5 letter word!\nPress Enter to Have Fun!");

	//static ConstructorHelpers::FObjectFinder<USoundBase> Soundf(TEXT("/Content/Environment/Sounds/bling.wav"));

	//Array of Hidden Words
	FString HiddenWords[28]={
		TEXT("house"),
		TEXT("horse"),
		TEXT("rakes"),
		TEXT("cream"),
		TEXT("dream"),
		TEXT("trams"),
		TEXT("hands"),
		TEXT("forth"),
		TEXT("sixth"),
		TEXT("first"),
		TEXT("flirt"),
		TEXT("exact"),
		TEXT("zebra"),
		TEXT("lions"),
		TEXT("cubes"),
		TEXT("scare"),
		TEXT("break"),
		TEXT("pause"),
		TEXT("print"),
		TEXT("table"),
		TEXT("shift"),
		TEXT("forms"),
		TEXT("tiger"),
		TEXT("roast"),
		TEXT("feast"),
		TEXT("feats"),
		TEXT("rouse"),
		TEXT("mouse")
	};

	//Variable to Hold the Hidden Word
	FString HiddenWord;

	//Variable to Hold the Last Hidden Word
	FString LastHiddenWord;

	//Variable to Hold Player Lives
	int32 PlayerLives;
	
};
