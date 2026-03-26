// project 2 algorithems 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
enum enQuestionsLevel{ easy=1,mid=2,hard=3,mix=4};
enum enOperationType{add=1,sub=2,mel=3,Div=4,MixOp=5};

enQuestionsLevel ReadQuiztionLevel() {
	short quiztionLevel;
	do
	{
		cout << "what level do u wanto quiztion to be?easy[1],mid[2],hard[3],mix[4]" << endl;

		cin >> quiztionLevel;
	} while (quiztionLevel<1||quiztionLevel>4);
	return (enQuestionsLevel)quiztionLevel;
}
int RandomNumber(int From, int To) {
	int randNum = rand() % (To - From + 1) + From; return randNum;
}

enOperationType ReadOpType() {
	short Op;
	do
	{
		cout << "What Operation Type do you want quiztion about?add[1],sub[2],mel[3],div[4],mix[5]" << endl;;
		cin >> Op;
	} while (Op<1||Op>5);
	return(enOperationType)Op;
}
string GetQuiztionLevel(enQuestionsLevel QuizLevel) {

	string arr[4] = { "easy","Mid","hard","Mix" };
	return arr[QuizLevel - 1];
}
string GetOpTypeSumple(enOperationType OpType) {

	string arrOptype[5] = { "add","sub","mel","Div","MixOp" };
	return arrOptype[OpType - 1];
}
enOperationType GetRandomOpType() {
	int RandomOp = RandomNumber(1, 4);
	return (enOperationType)RandomOp;
}
int SimpleCalculater(int Number1,int Number2,enOperationType OP) {

	switch (OP) {
	case enOperationType::add: 
return Number1 + Number2;
	case enOperationType::Div :
		return Number1 - Number2;
		case
		enOperationType::mel : return Number1 * Number2;
		case enOperationType::sub: return Number1 / Number2;
		default: return
			Number1 + Number2; 
	}
}





struct strQuiztion {
	int Number1 = 0;
	int Number2 = 0;
	enQuestionsLevel QuiztionLevel;
	enOperationType OpType;
	short CorrectAnswer = 0;
	short PlayerAnswer = 0;
	bool AnswerResulte= false;


};

struct strQuizez {

	strQuiztion QuiztionList[100];
	enQuestionsLevel QuiztionsLevel;
	enOperationType OpType;
	short NumberOfQuiztion = 0;
	short NumberofRightAnswer = 0;
	short NumberOfWrongAnswer = 0;
	bool IsPass = false;

};








void SetColorScreen(bool Right) {
	if (Right) {
		system("color 2F");
	}
	else{system("color 4F");
	cout << "\a";
	}
		

}


void PrintTheQuiztion(strQuizez Quizz, short NumberOfQuiztion){

	cout << "Quiztion [" << NumberOfQuiztion + 1 << "/" << Quizz.NumberOfQuiztion << "]" << endl;
	cout << endl << Quizz.QuiztionList[NumberOfQuiztion].Number1 << endl;
	cout << Quizz.QuiztionList[NumberOfQuiztion].Number2 << " ";
	cout << Quizz.QuiztionList[NumberOfQuiztion].OpType;
	cout << "\n---------";

}

int ReadQuiztionAnswer() {
	int Answer = 0;
	cin >> Answer;
	return Answer;
}

short ReadHowManyQuiztions() {
	short NumberOfQuizz;
	do
	{
		cout << "enter how many quiztion do you want to answer?[1]-[10];" << endl;
		cin >> NumberOfQuizz;
	} while (NumberOfQuizz<1||NumberOfQuizz>10);
	return NumberOfQuizz;
}


void CorrectTheQuiztionAnswer(short QuiztionNumber, strQuizez& Quizz) {

	if (Quizz.QuiztionList[QuiztionNumber].PlayerAnswer != Quizz.QuiztionList[QuiztionNumber].CorrectAnswer) {
		
		Quizz.QuiztionList[QuiztionNumber].AnswerResulte = false;
		Quizz.NumberOfWrongAnswer++;

		cout << "Wrong Answer :-(" << endl;
		cout << "The Right Answer is :" << Quizz.QuiztionList[QuiztionNumber].CorrectAnswer;
		cout << "\n";
	}
	else {

		Quizz.QuiztionList[QuiztionNumber].AnswerResulte = true;
		Quizz.NumberofRightAnswer++;

		cout << "Rignt answer :-)" << endl;

	}
	cout << endl;
	SetColorScreen(Quizz.QuiztionList[QuiztionNumber].AnswerResulte);

}

void GetFinalResluteText(bool Pass) {
	if (Pass) {
		cout << "Pass :-)";
	}
	else
		cout << "Fail :-(";
}

strQuiztion GeneratQuiztion(enOperationType OPType, enQuestionsLevel QuizLevel) {

	strQuiztion Quiztion;
	if (QuizLevel == enQuestionsLevel::mix) {
		QuizLevel = (enQuestionsLevel)RandomNumber(1, 3);
	};
	if (OPType == enOperationType::MixOp) {
		OPType=GetRandomOpType();
	}
	switch (QuizLevel)
	{
	case easy:
		 Quiztion.Number1= RandomNumber(1, 10);
		 Quiztion.Number2 = RandomNumber(1, 10);



		 Quiztion.CorrectAnswer = SimpleCalculater(Quiztion.Number1, Quiztion.Number2,Quiztion.OpType);
		 Quiztion.QuiztionLevel = QuizLevel;
		 return Quiztion;

	case mid:
		Quiztion.Number1 = RandomNumber(10, 50);
		Quiztion.Number2 = RandomNumber(10, 50);

		Quiztion.CorrectAnswer = SimpleCalculater(Quiztion.Number1, Quiztion.Number2, Quiztion.OpType);
		return Quiztion;
		
	case hard:
		Quiztion.Number1=RandomNumber(50,100);
		Quiztion.Number2=RandomNumber(50, 100);

		Quiztion.CorrectAnswer = SimpleCalculater(Quiztion.Number1, Quiztion.Number2, Quiztion.OpType);
		return Quiztion;
		
	}
	return Quiztion;

}


void GeneratQuizzQuiztions(strQuizez&Quizz) {
	for (short Quiztion = 0; Quiztion < Quizz.NumberOfQuiztion;Quiztion ++)
	{
		Quizz.QuiztionList[Quiztion] = GeneratQuiztion(Quizz.OpType,Quizz.QuiztionsLevel);

	}
}

void AskAndCorrectAnswer(strQuizez& Quizz) {

	for (short QuiztionNumber = 0; QuiztionNumber < Quizz.NumberOfQuiztion; QuiztionNumber++)
	{
		PrintTheQuiztion(Quizz, QuiztionNumber);
		Quizz.QuiztionList[QuiztionNumber].PlayerAnswer=ReadQuiztionAnswer();

		CorrectTheQuiztionAnswer( QuiztionNumber,Quizz);


	}
	Quizz.IsPass = Quizz.NumberofRightAnswer >= Quizz.NumberOfWrongAnswer;

}



void PrintQuizResulte(strQuizez Quizz) {

	cout << "-------------------------" << endl;
	cout << "Final Reslute"; GetFinalResluteText(Quizz.IsPass) ;
	cout << "\n-------------------------" << endl;
	cout << "Number Of Quiztion :" << Quizz.NumberOfQuiztion << endl;
	cout << "The Level Of Quiztions :" << GetQuiztionLevel(Quizz.QuiztionsLevel) << endl;
	cout << "Operation Type :" << GetOpTypeSumple(Quizz.OpType);
	cout << "Correct answers :" << Quizz.NumberofRightAnswer << endl;
	cout << "Wrong answers :" << Quizz.NumberOfWrongAnswer << endl;
	cout << "-------------------------" << endl;

}


void PlayMathGame() {

	strQuizez Quizz;
	Quizz.NumberOfQuiztion = ReadHowManyQuiztions();
	Quizz.QuiztionsLevel = ReadQuiztionLevel();
	Quizz.OpType = ReadOpType();

	GeneratQuizzQuiztions(Quizz);
	AskAndCorrectAnswer(Quizz);
	PrintQuizResulte(Quizz);


}

void ResetScreen() {
	system("cls");
	system("color 0F");
}


void StartGame() {
	char PlayAgain = 'y';

	do
	{
		ResetScreen();
		PlayMathGame();
		
		cout << "do you want to play angain ? Y/N" << endl;
		cin >> PlayAgain;


	} while (PlayAgain=='y' || PlayAgain == 'Y');

}










int main()
{
	srand((unsigned)time(NULL));
	StartGame();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
