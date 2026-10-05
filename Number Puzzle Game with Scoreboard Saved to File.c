#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void saveScore(char name[], int attempts) {
    FILE *file = fopen("scores.txt", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(file, "%s %d\n", name, attempts);
    fclose(file);
}

void showScoreboard() {
    FILE *file = fopen("scores.txt", "r");
    char name[50];
    int attempts;

    if (file == NULL) {
        printf("\nNo scores available yet.\n");
        return;
    }

    printf("\n🏆 SCOREBOARD 🏆\n");
    printf("------------------\n");
    while (fscanf(file, "%s %d", name, &attempts) != EOF) {
        printf("%s - %d attempts\n", name, attempts);
    }
    fclose(file);
}

void playGame() {
    int number, guess, attempts = 0;
    char name[50];

    printf("\nEnter your name: ");
    scanf("%s", name);

    number = rand() % 100 + 1;

    printf("\nI have selected a number between 1 and 100.\n");

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        attempts++;

        if (guess > number)
            printf("Too high!\n");
        else if (guess < number)
            printf("Too low!\n");
        else
            printf("🎉 Correct! You guessed it in %d attempts.\n", attempts);

    } while (guess != number);

    saveScore(name, attempts);
}

int main() {
    int choice;

    srand(time(0));

    do {
        printf("\n=== NUMBER PUZZLE GAME ===\n");
        printf("1. Play Game\n");
        printf("2. View Scoreboard\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                showScoreboard();
                break;
            case 3:
                printf("Thank you for playing!\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    return 0;
}