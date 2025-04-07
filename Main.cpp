#include <iostream>
#include <algorithm>
#include <string>

#define CARD_COUNT		52

using namespace std;

//global variable
int Deck[CARD_COUNT] = { 0, };
int ADD(int A, int B)
{
	return (A % 13 + 1) + (B % 13 + 1);
}

int ConvertJQK(int A)
{
	if ((A%13) >= 10)
		A = 10;
	return A;
}

void Initialize()
{
	srand((unsigned int)time(NULL));

	for (int Index = 0; Index < CARD_COUNT; Index++)
	{
		Deck[Index] = Index + 1;
	}
}

void Shuffle()
{
	int Temp = 0;
	for (int Count = 0; Count < CARD_COUNT * 1000; Count++)
	{
		int First = rand() % CARD_COUNT;
		int Second = rand() % CARD_COUNT;
		Temp = Deck[First];
		Deck[First] = Deck[Second];
		Deck[Second] = Temp;
	}
}

int PrintCard(int CardRealNumber)
{
	//Type
	//Heart,Clover,Space,Diamond
	int CardType = CardRealNumber / 13;
	int CardNumber = CardRealNumber % 13+1;
	int Score = CardNumber;

	if (CardType == 0)
	{
		cout << "Heart" << " ";

	}
	else if (CardType == 1)
	{
		cout << "Clover" << " ";

	}
	else if (CardType == 2)
	{
		cout << "Space" << " ";

	}
	else
	{
		cout << "Diamond" << " ";

	}
	if (CardNumber == 1)
	{
		cout << "A" << endl;
	}
	else if (CardNumber == 11)
	{
		cout << "J" << endl;
		Score = 10;
	}
	else if (CardNumber == 12)
	{
		cout << "Q" << endl;
		Score = 10;
	}
	else if (CardNumber == 13)
	{
		cout << "K" << endl;
		Score = 10;
	}
	else
	{
		cout << CardNumber << endl;
	}


	return Score;
}

void Print()
{
	

	int ComputerScore = 0;
	int PlayerScore = 0;


	cout << "Computer" << endl;

	//PrintCard(Deck[0]);
	//PrintCard(Deck[1]);

	ComputerScore += PrintCard(Deck[0]);
	ComputerScore += PrintCard(Deck[1]);

	if ((Deck[0]%13==0 || Deck[1] % 13 ==0 ) && (ComputerScore>10))
		ComputerScore += 10;
	cout << ComputerScore << endl;

	cout << "----------" << endl;
	cout << "Player" << endl;;
	//PrintCard(Deck[2]);
	//PrintCard(Deck[3]);
	PlayerScore += PrintCard(Deck[2]);
	PlayerScore += PrintCard(Deck[3]);

	if ((Deck[2] % 13 == 0 || Deck[3] % 13 == 0) && (PlayerScore > 10))
		PlayerScore += 10;
	cout << PlayerScore << endl;
		


	cout << endl;

	if(ComputerScore >= 21)
		cout << "Player Win!" << endl;
	else if (PlayerScore >= 21)
		cout << "Computer Win!" << endl;
	else
	{
		if (ComputerScore  > PlayerScore)
			cout << "Computer Win!" << endl;
		else
			cout << "Player Win!" << endl;
	}

}

//비주얼스튜디오에서만 가능한 방법


int main()
{
	string Data = "Hello World";
	cout << Data << endl;

	Initialize();
	Shuffle();
	Print();

	const char* Type[4] = {
	"♥",
	"◆",
	"♣",
	"♠"
	};



	return 0;
}