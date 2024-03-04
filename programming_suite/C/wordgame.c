#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_WORDS 5
#define MAX_WORD_LENGTH 10

// Function to pick a random word from an array
char* getRandomWord() {
    char* words[MAX_WORDS] = {"po", "shifu", "oogway", "tigress", "monkey"};
    return words[rand() % MAX_WORDS];
}

// Function to display the current state of the word (with hidden letters)
void displayWord(char* word, char* guessedLetters) {
    for (int i = 0; i < strlen(word); i++) {
        if (strchr(guessedLetters, word[i]) != NULL) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));  // Seed the random number generator with the current time

    char* word = getRandomWord();
    char guessedLetters[MAX_WORD_LENGTH] = ""; // To store guessed letters
    int attempts = 0, maxAttempts = 6; // Set the maximum number of incorrect attempts

    printf("===== Hangman Game =====\n");

    do {
        printf("\nAttempts remaining: %d\n", maxAttempts - attempts);
        displayWord(word, guessedLetters);

        // Get user input for a guess
        char guess;
        printf("Enter a letter: ");
        scanf(" %c", &guess);

        // Convert the guess to lowercase
        guess = tolower(guess);

        // Check if the letter has already been guessed
        if (strchr(guessedLetters, guess) != NULL) {
            printf("You've already guessed that letter. Try again.\n");
            continue;
        }

        // Add the guessed letter to the list
        strncat(guessedLetters, &guess, 1);

        // Check if the guess is correct
        if (strchr(word, guess) == NULL) {
            attempts++;
            printf("Incorrect guess!\n");
        } else {
            printf("Correct guess!\n");
        }

        // Check if the player has guessed the entire word
        if (strspn(word, guessedLetters) == strlen(word)) {
            printf("Congratulations! You guessed the word: %s\n", word);
            break;
        }

    } while (attempts < maxAttempts);

    if (attempts == maxAttempts) {
        printf("Sorry, you ran out of attempts. The correct word was: %s\n", word);
    }

    return 0;
}
