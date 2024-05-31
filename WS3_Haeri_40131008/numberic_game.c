#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void print_message(int player_score, int numfather_number_1) {
 // system("clear");
  printf("player score: %d \nfirst number of numfather: %d \n", player_score, numfather_number_1);
  printf("what is your choice: (1 = AddAdad / 2 = AdadBas):\n");
}

void print_scores (int player_score, int numfather_score) {
  printf("player score: %d\nnumfather score: %d\n", player_score, numfather_score);
}

void print_result(int player_score, int numfather_score) {
  printf("\n\n************************************************\n");
  if (player_score > 21 || ((player_score < numfather_score) && numfather_score <= 21 )) {
    printf("numfather is winner\n");
    print_scores(player_score, numfather_score);

  } else if (numfather_score > 21 || (numfather_score < player_score && player_score <= 21)) {
    printf("player is winner\n");
    print_scores(player_score, numfather_score);

  } else {
    printf("result is equal\n");
    print_scores(player_score, numfather_score);

  }
  printf("************************************************\n");
}

int main(int argc, char const *argv[]) {
  srand(time(NULL)); // set seed for random funciton

  int numfather_number_1 = ((rand() % 10) + 1);
  int numfather_number_2 = ((rand() % 10) + 1);

  int numfather_score = numfather_number_1 + numfather_number_2;
  int player_score = ((rand() % 10) + 1) + ((rand() % 10) + 1);

  while (player_score < 21) {
    print_message(player_score, numfather_number_1);
    int answer;
    scanf("%d", &answer);
    if (answer == 1) {
      player_score += ((rand() % 10) + 1);
    } else if (answer == 2) {
      numfather_score += ((rand() % 17) + 1);
      break;
    } else {
      printf("your input in not currect, please try again.\n");
    }
  }

  print_result(player_score, numfather_score);
  return 0;
}
