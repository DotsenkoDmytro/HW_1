#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int coins = 100;

    while(coins > 0) {
        int length, bet, win = 0;
        printf("You have %d coins\n", coins);
        printf("Enter the length of the sequence: ");
        scanf("%d", &length);
        printf("Enter your bet (0 to exit): ");
        scanf("%d", &bet);

        if(bet == 0) break;
        if(bet > coins) {
            printf("You cannot bet more coins than you have!\n");
            continue;
        }

        int *sequence = malloc(length * sizeof(int));
        if(sequence == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Sequence: ");
        for(int i = 0; i < length; i++) {
            sequence[i] = rand() % 10;
            printf("%d ", sequence[i]);
            if(sequence[i] == 7) win = bet;
        }
        printf("\n");

        int *frequency = calloc(10, sizeof(int));
        if(frequency == NULL) {
            free(sequence);
            printf("Memory allocation failed!\n");
            return 1;
        }

        for(int i = 0; i < length; i++) {
            frequency[sequence[i]]++;
        }

        for(int i = 0; i < 10; i++) {
            if(frequency[i] == length) {
                win = i == 7 ? bet * 3 : bet * 2;
                break;
            }
        }

        for(int i = 0; i < 10; i++) {
            if(frequency[i] >= (length + 2) / 3) {
                if(win == 0) win = bet;
                break;
            }
        }

        coins = coins - bet + win;

        if(win) {
            printf("Congratulations! You win %d coins\n", win);
        } else {
            printf("Sorry! You lose your bet!\n");
        }

        free(sequence);
        free(frequency);

        if(coins == 0) {
            printf("You've run out of coins!\n");
        }
    }
    printf("Game Over!\n");
    printf("You left with %d coins\n", coins);
    return 0;
}
