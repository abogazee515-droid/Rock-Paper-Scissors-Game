#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int j = 0;

enum enChoice { Rock = 1, Paper = 2, Scissors = 3 };

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

int ReadPlayer1Choice()
{
    int Choice;
    do
    {
        cout << "Your Choice [1] Rock, [2] Paper, [3] Scissors: ";
        cin >> Choice;
    } while (Choice < 1 || Choice > 3);

    return Choice;
}

int WhoWonTheRound(int Player1Choice, int ComputerChoice)
{
    if (Player1Choice == ComputerChoice)
        return 0;

    if ((Player1Choice == Rock && ComputerChoice == Scissors) ||
        (Player1Choice == Paper && ComputerChoice == Rock) ||
        (Player1Choice == Scissors && ComputerChoice == Paper))
        return 1;

    return 2;
}

string ChoiceName(int Choice)
{
    switch (Choice)
    {
    case Rock: return "Rock";
    case Paper: return "Paper";
    case Scissors: return "Scissors";
    default: return "";
    }
}

void GameRounds(int NumberOfRounds, int& Player1Wins, int& ComputerWins, int& Draws)
{
    Player1Wins = 0;
    ComputerWins = 0;
    Draws = 0;

    for (int i = 1; i <= NumberOfRounds; i++)
    {
        j++;

        int Player1Choice = ReadPlayer1Choice();
        int ComputerChoice = RandomNumber(1, 3);
        int Winner = WhoWonTheRound(Player1Choice, ComputerChoice);

        cout << "\nRound [" << j << "]\n";
        cout << "Player 1 Choice : " << ChoiceName(Player1Choice) << "\n";
        cout << "Computer Choice : " << ChoiceName(ComputerChoice) << "\n";

        if (Winner == 0)
        {
            Draws++;
            cout << "Round [" << j << "] Result : [Draw]\n";
        }
        else if (Winner == 1)
        {
            Player1Wins++;
            cout << "Round [" << j << "] Result : [Player 1 Wins]\n";
        }
        else
        {
            ComputerWins++;
            cout << "Round [" << j << "] Result : [Computer Wins]\n";
        }
    }
}

void TheFinalResult(int Player1Wins, int ComputerWins, int Draws)
{
    cout << "\n==============================================\n";
    cout << "                 Final Result\n";
    cout << "==============================================\n";
    cout << "Player 1 Wins : " << Player1Wins << "\n";
    cout << "Computer Wins : " << ComputerWins << "\n";
    cout << "Draws         : " << Draws << "\n";

    if (Player1Wins > ComputerWins)
        cout << "Game Winner   : Player 1\n";
    else if (ComputerWins > Player1Wins)
        cout << "Game Winner   : Computer\n";
    else
        cout << "Game Winner   : Draw\n";
}

bool PlayagainOrNot()
{
    char Answer;
    cout << "\nDo you want to play again? Y/N: ";
    cin >> Answer;
    return Answer == 'Y' || Answer == 'y';
}

void StartGame()
{
    char PlayAgain = 'Y';

    while (PlayAgain == 'Y' || PlayAgain == 'y')
    {
        system("cls");
        system("color 0F");

        int Player1Wins, ComputerWins, Draws;
        GameRounds(3, Player1Wins, ComputerWins, Draws);
        TheFinalResult(Player1Wins, ComputerWins, Draws);

        if (!PlayagainOrNot())
            break;
    }
}

int main()
{
    srand((unsigned)time(NULL));
    StartGame();
    return 0;
}
