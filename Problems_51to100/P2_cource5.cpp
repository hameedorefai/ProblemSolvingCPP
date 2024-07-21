//???? ????? ?? ???? mixlevel ????? ??? ???? ?? 100
// ????? ?? ???? Operation Mix
#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
using namespace std;

enum enQuizLevel { Easy = 1, Mid, Hard, LvLMix };
enum enQuizOperations { Add = 1, Sub, Mul, Div, OpMix };
struct stMathGame {
	enQuizLevel Level;
	enQuizOperations Operation = OpMix;
	char chOperation='!';
	float FirstNumber = 0;
	float LastNumber = 0;
	float PlayerAnswer = 0;
	float TheAnswer = 0;
	short RightAnswersTimes = 0;
	short WrongAnswersTimes = 0;
	short QuizLength = 0;
	short RoundNumber = 0;

};

struct stPlayer {
	string Name = "Player";
	string Choice = "";
	short WinCount = 0;
	short DrawCount = 0;
	short LoseCount = 0;
	short RoundsPlayed = 0;
	bool IsRoundWinner = false;
};
// Start Basics Functions
string Tabs(short TabsNumber) {
	string t = "\t";
	for (int i = 0; i < TabsNumber; i++) {
		t += t;
	}
	return t;
}
string ReadPlayerName() {
	string PlayerName;
	cout << "Enter your name : ";
	cin >> PlayerName;
	return PlayerName;
}
void ReadPlayerInfo(stPlayer& Player) {
	Player.Name = ReadPlayerName();
}
float ReadNumber(string Message) {
	float Number;
	cout << Message;
	cin >> Number;
	return Number;
}
short ReadPositiveNumber(string Message) {
	short Number;
	do {
		cout << Message;
		cin >> Number;
	} while (Number < 1 || Number>10);
	return Number;
}
short ReadNumberInRange(string Message, short From, short To) {
	short Number;
	do {
		cout << Message;
		cin >> Number;
	} while (Number > To || Number < From);
	return Number;
}
short RandNumberInRange(short From, short To) {
	short RandNumber;
	do {
		RandNumber = rand() % (To - From + 1) + From;
	} while (RandNumber == 44 || RandNumber == 46);
	return RandNumber;
}
char ReadChar(string Message) {
	char Char;
	cout << Message;
	cin >> Char;
	return Char;
}
void RingBell() {
	cout << "\a";
}
void ResetScreen() {
	system("cls");
	system("Color 0F");
}
string DisplayQuestionsLevel() {
	return "Question Level [1] Easy, [2] Med, [3] Hard, [4] Mix ";
}
string DisplayQuizOperations() {
	return "Operation Tybe [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix ";
}
void ReadQuizLength(stMathGame& Game) {
	Game.QuizLength = ReadPositiveNumber("How many Questions do you want to answer(1-10)? : ");
}

bool IsContinuePlay() {
	char Answer = ReadChar("Do you want to play Again ?[Y],[N] : ");
	if (Answer == 'Y' || Answer == 'y') {
		ResetScreen();
		return 1;
	}
	return 0;
}
void RightAnswer(stMathGame& Game) {
	Game.RightAnswersTimes++;
	cout << "Right Answer :-)" << endl;
	system("Color 2F");
	cout << "Right Answer, The Real Right Answer is : " << Game.TheAnswer << endl;
	cout << "The First Number is : " << Game.FirstNumber << endl;
	cout << "The Last Number is : " << Game.LastNumber << endl;
	cout << "The Operation is " << Game.chOperation << endl;
}
void WrongAnswer(stMathGame& Game) {
	Game.WrongAnswersTimes++;
	cout << "Wrong Answer :-(" << endl;
	system("Color 4F");
	RingBell();
	cout << "Wrong Answer, The Right Answer is : " << Game.TheAnswer << endl;
	cout << "The First Number is : " << Game.FirstNumber << endl;
	cout << "The Last Number is : " << Game.LastNumber << endl;
	cout << "The Operation is " << Game.chOperation << endl;
}


void GetMixOperation(stMathGame& Game) {
	cout <<endl<<endl<< Game.Operation << "   " << Game.chOperation<<endl;

	Game.Operation = (enQuizOperations)RandNumberInRange(42, 47);
	Game.chOperation = (char)Game.Operation;
	cout << Game.Operation << "   " << Game.chOperation << endl << endl;
}
void CalculateTheRightAnswer(stMathGame& Game) {
	short First = Game.FirstNumber;
	short Last = Game.LastNumber;
	float Answer = 0;
	char op = 'c';
	switch (Game.Operation) {
	case Add:
		Game.chOperation = '+';
		Answer = First + Last;
		break;
	case Sub:
		Game.chOperation = '-';
		Answer = First - Last;
		break;
	case Mul:
		Game.chOperation = '*';
		Answer = First * Last;
		break;
	case Div:
		Game.chOperation = '/';
		Answer = First / Last;
		break;
	default:
		cout << "Error in Function : CalculateTheRightAnswer !!" << endl;
	}
	//Game.chOperation = op;
	Game.TheAnswer = Answer;

}
void EasyLevel(stMathGame& Game) {
	Game.FirstNumber = RandNumberInRange(1, 10);
	Game.LastNumber = RandNumberInRange(1, 10);
}
void MidLevel(stMathGame& Game) {
	Game.FirstNumber = RandNumberInRange(20, 50);
	Game.LastNumber = RandNumberInRange(20, 50);
}
void HardLevel(stMathGame& Game) {
	Game.FirstNumber = RandNumberInRange(50, 100);
	Game.LastNumber = RandNumberInRange(50, 100);
}
void MixLevel(stMathGame& Game) {
	short From = RandNumberInRange(1, 100);
	short To = RandNumberInRange(1, 100);
	Game.FirstNumber = RandNumberInRange(From, To);
	Game.LastNumber = RandNumberInRange(From, To);
}
void GetQuestionsNumbers(stMathGame& Game) {
	switch (Game.Level) {
	case Easy:
		EasyLevel(Game);
		break;
	case Mid:
		MidLevel(Game);
		break;
	case Hard:
		HardLevel(Game);
		break;
	case LvLMix:
		MixLevel(Game);
		break;
	default:
		cout << "!! Error in Function : GetQuestionsNumbers(stMathGame& Game) !!" << endl;
	}
}
void ReadQuizLevel(stMathGame& Game) {
	string Message = "Enter " + DisplayQuestionsLevel() + ": ";
	Game.Level = (enQuizLevel)ReadNumberInRange(Message, 1, 4);
}

void GetcharOperation(stMathGame& Game) {
	switch (Game.Operation) {
	case Add:
		Game.chOperation = '+';
		break;
	case Sub:
		Game.chOperation = '-';
		break;
	case Mul:
		Game.chOperation = '*';
		break;
	case Div:
		Game.chOperation = '/';
		break;
	case OpMix:
		cout << "@@@@@@@@@@@@@ 	Befor   GetMixOperation(Game) " << Game.chOperation << endl;;
		GetMixOperation(Game);
		cout << "@@@@@@@@@@@@@ 		GetMixOperation(Game) " << Game.chOperation << endl;;

		break;
	default:
		cout << "Error in Function : GetcharOperation ! " << endl;
	}

}

void ReadQuizOperation(stMathGame& Game) {

	string Message = "Enter " + DisplayQuizOperations() + ": ";
	Game.Operation = (enQuizOperations)ReadNumberInRange(Message, 1, 5);
	GetcharOperation(Game);

}
void ReadPlayerAnswer(stMathGame& Game) {
	Game.PlayerAnswer = ReadNumber("");
}
void DisplayTheQuestion(stMathGame& Game) {
	cout << "Question [" << Game.RoundNumber << "/" << Game.QuizLength << "]\n" << endl;
	cout << Game.FirstNumber << endl;
	cout << Game.LastNumber << " ";
	cout << Game.chOperation;
	cout << "_____________" << endl;
}
void Question(stMathGame& Game) {
	GetQuestionsNumbers(Game);
	DisplayTheQuestion(Game);

}
void CheckQuestionResult(stMathGame& Game) {
	CalculateTheRightAnswer(Game);
	if (Game.PlayerAnswer == Game.TheAnswer)
		RightAnswer(Game);
	else
		WrongAnswer(Game);
}
void StartQuiz(stMathGame& Game) {
	ReadQuizLevel(Game);
	ReadQuizOperation(Game);
	for (int i = 0; i < Game.QuizLength; i++) {
		
		Question(Game);
		ReadPlayerAnswer(Game);
		CheckQuestionResult(Game);

		Game.RoundNumber++;
	}
}


void StartGame() {
	stMathGame Game;
	do {
		ReadQuizLength(Game);
		StartQuiz(Game);

	} while (IsContinuePlay());
}
int main() {

	StartGame();

	return 0;
}


