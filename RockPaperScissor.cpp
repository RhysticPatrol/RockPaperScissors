#include <iostream>
#include <string>
#include <ctime>
#include <random>

using namespace std;

random_device engine;
uniform_int_distribution<int> randomInt(0,2);

string choices[3] = {"rock", "paper", "scissors"}; //array for player/pc options
string endState[3] = {"win", "lose", "tie"}; //for results at the end of the round
int playerScore = 0;
int pcScore = 0;

int didPlayerWin(int comChoice,  int playerChoice) { //function to determine winner and bump up victors score
	if ((comChoice == 0 && playerChoice == 1)
		&& (comChoice == 1 && playerChoice == 2)
		&& (comChoice == 2 && playerChoice == 0)) {
		playerScore++;
  		return 0;
	}
	else if(comChoice == playerChoice)
	return 2;
	else{pcScore++; return 1;}
}

int main() {
	int ComC = randomInt(engine);
	int PlayC;
	string win;
	cout << "Pick one: \n 0) Rock\n 1) Paper\n 2) Scissors\n 3) Quit\n"; //player options
	cin >> PlayC;
	if(PlayC < 0 || PlayC > 3){ //invalid input
		cout << "Please pick a valid option";
		main();
		return 0;
	}
	if(PlayC == 3){
		cout << "You:" << playerScore << " Computer:" << pcScore; //score results before you exit
		if(playerScore > pcScore){
			cout << "\nYou win!";
		}

		else if (playerScore == pcScore){
			cout << "\nYou tied";
		}
		else{ cout << "\nYou lose";}
		return 0;
	}
	cout << "You choose " << choices[PlayC] << " and the computer choose " << choices[ComC];
	cout << "\nYou " << endState[didPlayerWin(PlayC, ComC)];
	main(); //loop main function
	return 0;
}