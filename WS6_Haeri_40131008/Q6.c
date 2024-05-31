#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// my OS is ubuntu linux
// #include <windows.h>

int main() {
	srand(time(NULL));

	int goal;
	int player_choice, bot_choice;
	int player_score = 0, bot_score = 0;

	printf("Enter the Goal:\n");
	scanf("%d", &goal);

	while (player_score < goal && bot_score < goal) {
		// change cls to clear
		system("clear");

		// print the scores at the top of the window
		printf("Your score : %d\t\tBot score : %d\n\n", player_score, bot_score);

		// get player choice
		printf("Press 1 for Rock, Press 2 for Paper, Press 3 for Scissors\n");
		scanf("%d", &player_choice);

		// make a random choice for the computer
		bot_choice = rand() % 3 + 1;
		printf("bot chice: %d\nplayer choice: %d\n", bot_choice, player_choice);

		switch (bot_choice) {
			case 1:
				if (player_choice == 2) {
					player_score++;
				} else if (player_choice == 3) {
					bot_score++;
				}
			break;
			case 2:
				if (player_choice == 3) {
					player_score++;
				} else if (player_choice == 1) {
					bot_score++;
				}
			break;
			case 3:
				if (player_choice == 1) {
					player_score++;
				} else if (player_choice == 2) {
					bot_score++;
				}
			break;
		};

		// clear the console
		system("sleep 2");
	}

	// print final result
	system("clear");
	printf("Your score : %d\t\tBot score : %d\n\n", player_score, bot_score);

    // Check who is the winner and congrats him/her/it!!
	if (player_score > bot_score) {
		printf("player is winner\ncongratulations to you :)");
	} else {
		printf("oh sorry!\nbot is winner :(");
	}
}
