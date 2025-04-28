#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isNumber(char str[]) {
  for (int i = 0; i < strlen(str); i++) {
    if (!isdigit(str[i])) {
      return 0;
    }
  }
  return 1;
}

float overs(int balls) {
  int completeOvers = balls / 6;
  int remainingBalls = balls % 6;
  return completeOvers + (remainingBalls / 10.0);
}

void menu() {
  printf("|---------|\n");
  printf(" Scorecard\n");
  printf("|---------|\n");
  printf("Update the score!\n");
  printf(
      "[1]Ones [2]Twos [3]Four [4]Six [5]Wide [6]Noball [7]Wicket [8]Exit\n");
  printf("Enter your choice (1-8): ");
}

void displayScoreboard(int score, int wickets, int balls, int ones, int twos,
                       int fours, int sixes, int wide, int noballs) {
  printf("\n");
  printf("--------------------------\n");
  printf("\nCurrent Score: %d - %d (%.1f)\n", score, wickets, overs(balls));
  printf("\n--------------------------\n");
  printf("\n");
  printf("-Stats for nerds-\n");
  printf("--------------------------\n");
  printf("Fours: %d  Sixes: %d \n", fours, sixes);
  printf("Ones: %d  Twos: %d \n", ones, twos);
  printf("Wide: %d  Noballs: %d \n", wide, noballs);
  printf("--------------------------\n");
}

int addOne(int s) {
  s = s + 1;
  return s;
}

int addTwo(int s) {
  s = s + 2;
  return s;
}

int addFour(int s) {
  s = s + 4;
  return s;
}

int addSix(int s) {
  s = s + 6;
  return s;
}

int addNoball(int s) {
  s = s + 1;
  return s;
}

int addWide(int s) {
  s = s + 1;
  return s;
}

int main() {
  int wide = 0, ones = 0, twos = 0, fours = 0, sixes = 0, noballs = 0;
  int score = 0, wickets = 0, balls = 0, choice;
  char input[100];

  while (1) {
    system("clear");
    menu();
    displayScoreboard(score, wickets, balls, ones, twos, fours, sixes, noballs,
                      wide);
    scanf("%s", input);
    printf("\n-------------------------\n");

    if (!isNumber(input)) {
      printf("Invalid input! Please choose an option mentioned above\n");
      getchar();
      continue;
    }

    choice = atoi(input);

    if (choice < 1 || choice > 8) {
      printf("Invalid input. Please choose an option mentioned above.\n");
      continue;
    }

    switch (choice) {
    case 1:
      score = addOne(score);
      ones++;
      balls++;
      break;

    case 2:
      score = addTwo(score);
      twos++;
      balls++;
      break;

    case 3:
      score = addFour(score);
      fours++;
      balls++;
      break;

    case 4:
      score = addSix(score);
      sixes++;
      balls++;
      break;

    case 5:
      score = addNoball(score);
      noballs++;
      break;

    case 6:
      score = addWide(score);
      wide++;
      break;

    case 7:
      wickets++;
      balls++;
      break;

    case 8:
      printf("Exiting...\n");
      printf("-------------------------\n");
      printf("Final score: %d - %d (%.1f)\n", score, wickets, overs(balls));
      return 0;

    default:
      printf("\nPlease enter a valid number (1-7).");
      break;
    }
  }
  return 0;
}
