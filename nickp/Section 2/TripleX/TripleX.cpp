#include <iostream>
#include <ctime>

void PrintFuckingIntroduction(int d)
{
    std::cout << "Boooooooooooooooooooooooooobs";
    //Print Welcome Message
    std::cout << "The world's about to end n shit. Let's do some math";
    std::cout << std::endl;
    std::cout << "Enter the right code to not end the world? n shit?";
    std::cout << "\n It's this hard:" << d << " Stop giggling\n";
}
//This is a test
bool FuckingPlayIt(int LevelD)
{
    PrintFuckingIntroduction(LevelD);

    const int Code1 = rand() % (2 + LevelD);
    const int Code2 = rand() % (2 + LevelD);
    const int Code3 = rand() % (3 + LevelD);

    std::cout << std::endl;
    std::cout << Code1 << std::endl;
    std::cout << Code2 << std::endl;
    std::cout << Code3 << std::endl;

    const int CodeSum = Code1 + Code2 + Code3;
    const int CodeProduct = Code1 * Code2 * Code3;

    std::cout << std::endl;
    std::cout << "\n * There are 3 numbers in the code";
    std::cout << "\n * The codes add-up to:" << CodeSum;
    std::cout << "\n * The codes multiply to give:" << CodeProduct << std::endl;

    int GuessA;
    int GuessB;
    int GuessC;

    std::cin >> GuessA;
    std::cin >> GuessB;
    std::cin >> GuessC;

    std::cin.clear();
    std::cin.ignore();
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    std::cout << "You guessed:" << GuessA << GuessB << GuessC << std::endl;

    

    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "You Win";
    }
    else
    {
        std::cout << "You Lose";
    }

    bool ReturnVal = 
        GuessSum 
            == 
        CodeSum 


        && 



        GuessProduct == CodeProduct;

    //return ReturnBal;

    return GuessSum == CodeSum && GuessProduct == CodeProduct;
}

int main()
{

    int x = 10;

    printf("The value of x is %d",x);

    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxLevel = 5;
    while (LevelDifficulty <= MaxLevel)

    {
        bool YouFuckingDidIt = FuckingPlayIt(LevelDifficulty);
        if (YouFuckingDidIt)
        {
            ++LevelDifficulty;
        }
    }

    std::cout << "==============\nYay you did it==============";
    return 0;
}