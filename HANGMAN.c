#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 5
#define MAX_WORD_LENGTH 20

int main() {
    char word[MAX_WORD_LENGTH];
    char guessed[MAX_WORD_LENGTH];
    int numTries = 0;
    int length;
    int i;
    int found = 0;

    printf("Enter the word to guess: ");
    scanf("%s", word);

    length = strlen(word);

    // Initialize guessed array with dashes
    for (i = 0; i < length; i++) {
        guessed[i] = '_';
    }
    guessed[length] = '\0';

    while (numTries < MAX_TRIES && !found) {
        char guess;
        printf("\n\nWord: %s\n", guessed);
        printf("Enter a letter to guess: ");
        scanf(" %c", &guess);

        int correct = 0;
        for (i = 0; i < length; i++) {
            if (tolower(word[i]) == tolower(guess)) {
                guessed[i] = word[i];
                correct = 1;
            }
        }

        if (!correct) {
            numTries++;
            printf("Incorrect guess! Tries left: %d\n", MAX_TRIES - numTries);
        } else {
            printf("Correct guess!\n");
        }

        if (strcmp(word, guessed) == 0) {
            found = 1;
            printf("\nCongratulations! You guessed the word: %s\n", word);
        }
    }

    if (!found) {
        printf("\nSorry, you've run out of tries. The word was: %s\n", word);
    }

  


}
