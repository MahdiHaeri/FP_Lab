#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <time.h>


#define MAX_LENGTH_OF_NAME 100

void print_array(int array[], int size) {
    static int count = 1; // static variable to count the number of combinations 
    printf("%d: ", count);
    count++;
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// function to generate all combinations of teams with backtracking 
void combination(int n, const int fix_n, int array[], int answer[]) {
    if (n == 0) {
        print_array(answer, fix_n);
        return;
    }

    for (int i = 0; i < fix_n; i++) { 
        if (array[i] != 0) {
            array[i] = 0;
            answer[fix_n - n] = i + 1;
            n--;
            combination(n, fix_n, array, answer);

            array[i] = 1;
            n++;
            answer[fix_n - n] = 0;
        }
    }
}

// set all elements of array to 1
void set_one_to_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = 1;
    }
}

// add new team to array of teams
void add_team(char **array_of_teams, char* new_team) { 
    int array_size = sizeof(array_of_teams) / sizeof(char**);
    array_of_teams = (char**)realloc(array_of_teams, (array_size + 1) * sizeof(char**));
    array_of_teams[array_size] = new_team;
}

char* new_string() {
    char *string = (char*)malloc(MAX_LENGTH_OF_NAME * sizeof(char));
    return string;
}

int factorial(int n) { // calculate factorial of n
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

// print combination random_number
void combination_with_index(int one_array[], int count_of_teams, int random_number) {
    int team_number;
    int count_of_combination = factorial(count_of_teams - 1);
    for (int i = 0; i < count_of_teams; i++) {
        team_number = ceil(((double)random_number / (double)count_of_combination));
        for (int j = 0; j < count_of_teams; j++) {
            if (one_array[j] == 1) {
                team_number--;
            } 
            if (team_number <= 0) {
                printf("%d ", j + 1);
                one_array[j] = 0;
                break;
            }
        }
        if (i == count_of_teams - 1) {
            printf("\n");
            break;
        }
        random_number = ((random_number - 1) % count_of_combination) + 1;
        count_of_combination /= (count_of_teams - i - 1);
    }
}

void random_combination(int one_array[], int count_of_teams) { 
    int random_number = rand() % factorial(count_of_teams) + 1;
    printf("random team: %d\n", random_number);
    combination_with_index(one_array, count_of_teams, random_number);
}

void get_teams(char*** array_of_teams, int *count_of_teams) {
    char *name_of_team; 
    printf("Enter a list of teams (\"finish\" to end): \n");
    while (true) { // get the list of teams
        name_of_team = new_string(); // allocate memory for new team
        scanf("%s", name_of_team); 
        if (strcmp(name_of_team, "finish") == false) { 
            break;
        }        
        (*count_of_teams)++;
        *array_of_teams = (char**)realloc(*array_of_teams, (*count_of_teams) * sizeof(char*)); 
        (*array_of_teams)[(*count_of_teams) - 1] = name_of_team;
    }
}

void print_teams(char** array_of_teams, int count_of_teams) {
    printf("count of teams: %d\n", count_of_teams);
    for (int i = 0; i < count_of_teams; i++) {
        printf("%d: %s\n", i + 1, array_of_teams[i]);
    }
}

int main(int argc, char const *argv[]) {
    srand(time(NULL)); // for random number generator :)

    // char *name_of_team; 
    char **array_of_teams = NULL;
    int count_of_teams = 0;


    get_teams(&array_of_teams, &count_of_teams);

    printf("\n--------------------------------\n\n");
    
    print_teams(array_of_teams, count_of_teams);
    
    printf("\n--------------------------------\n\n");

    int one_array[count_of_teams];
    int answer[count_of_teams];
    set_one_to_array(one_array, count_of_teams);
    combination(count_of_teams, count_of_teams, one_array, answer);

    printf("\n--------------------------------\n\n");
    
    set_one_to_array(one_array, count_of_teams);
    random_combination(one_array, count_of_teams);

    return 0;
}
