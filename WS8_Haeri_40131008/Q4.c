#include <stdio.h>
#include <stdbool.h>

#define INIT_CAKE_NUM 40
#define INIT_COOKIE_NUM 40
#define INIT_COFFEE_NUM 40

/* global variable declaration */
int choice = 0;

void menu(int cake, int cookie, int coffee) {
  printf("\n---------- Menu ------------\n");
  printf("What do you want to order?\n");
  printf("1) cake : %d\n", cake);
  printf("2) cookie : %d\n", cookie);
  printf("3) coffee : %d\n", coffee);
  printf("4) add resource\n");
  printf("5) Checkout\n");
  printf("----------------------------\n");
}

void add_resource_menu() {
  printf("\n------ setting menu --------\n");
  printf("1) add cake\n");
  printf("2) add cookie\n");
  printf("3) add coffee\n");
  printf("----------------------------\n");
}

void add_resource(int &init_cake_num, int &init_cookie_num, int &init_coffee_num) {
  // print add_resource_menu
  add_resource_menu();
  int input;
  scanf("%d", &input);

  // check input
  if (input == 1 || input == 2 || input == 3) {
    printf("how many you want add? \n");
  } else {
    printf("Incorrect input!\n");
    return;
  }

  int amount;
  scanf("%d", &amount);

  // check input and if is correct add amount to that
  if (amount >= 0) {
    if (input == 1) {
      init_cake_num += amount;
    } else if (input == 2) {
      init_cookie_num += amount;

    } else if (input == 3) {
      init_coffee_num += amount;
    }
  } else {
    printf("Oops!\nIncorrect amount!\n");
  }
}

void buy() {
  /* static variable declaration */
  static int init_cake_num = INIT_CAKE_NUM;
  static int init_cookie_num = INIT_COOKIE_NUM;
  static int init_coffee_num = INIT_COFFEE_NUM;

  // Print menu
  menu(init_cake_num, init_cookie_num, init_coffee_num);
  scanf("%d", &choice);

  /* local variable declaration */
  int pic = 0;

  switch (choice) {
  case 1:
    // check cake amount is enough or not
    if (init_cake_num == 0) {
      printf("there is not enough cake\n");
      return;
    }
    init_cake_num--;
    break;
  case 2:
    // check cookie amount is enough or not
    if (init_cookie_num == 0) {
      printf("there is not enough cookie\n");
      return;
    }
    init_cookie_num--;
    break;
  case 3:
    // check coffee amount is enough or not
    if (init_coffee_num == 0) {
      printf("there is not enough coffee\n");
      return;
    }
    init_coffee_num--;
    break;
  case 4:
    // add amount of resource
    add_resource(init_cake_num, init_cookie_num, init_coffee_num);
    break;
  case 5:
    printf("Do you want a picture?\n1) yes\n0) no\n");
    int a;
    scanf("%d", &a);
    if (a)
      pic++;
    break;
  default:
    printf("Incorrect input!\nplease try again.\n");
    break;
  };
  printf("pic num = %d\n", pic);
}

int main() {

  while(choice != 5) {
    buy();
  }

  printf("C U soon\n");

  return 0;
}
