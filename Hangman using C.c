#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>  // for usleep function

#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20
#define MAX_ATTEMPTS 7

// Function to choose a random word from the list
char *chooseWord();

// Function to display the current state of the word with correct guesses
void displayWord(char *word, char *guessedLetters);

// Function to check if the guessed letter is correct and update the state of the word
int checkGuess(char *word, char *guessedLetters, char guess);

// Function to print the Hangman figure based on the number of incorrect attempts
void printHangman(int incorrectAttempts);

int main() {
    char *word = chooseWord();
    char guessedLetters[MAX_WORD_LENGTH] = {'\0'};
    int incorrectAttempts = 0;
    int wordLength = strlen(word);
    int correctGuesses = 0;

    printf("Welcome to Animated Hangman!\n");

    do {
        displayWord(word, guessedLetters);

        printf("Enter a letter: ");
        char guess;
        scanf(" %c", &guess);  // Read a single character

        // Convert the guess to lowercase
        guess = tolower(guess);

        // Check if the guess is correct
        int correct = checkGuess(word, guessedLetters, guess);

        if (correct) {
            printf("Correct guess!\n");
            correctGuesses++;
        } else {
            printf("Incorrect guess.\n");
            incorrectAttempts++;
            printHangman(incorrectAttempts);
        }

    } while (incorrectAttempts < MAX_ATTEMPTS && correctGuesses < wordLength);

    if (correctGuesses == wordLength) {
        printf("Congratulations! You guessed the word: %s\n", word);
        printf("Hangman got saved!\n"); // Congratulations statement
    } else {
        printf("Sorry, you ran out of attempts. The correct word was: %s\n", word);
        printHangman(MAX_ATTEMPTS);  // Display the full Hangman figure
        printf("Hangman got hanged! Try again\n");
    }

    free(word);  // Free the allocated memory for the word

    return 0;
}

char *chooseWord() {
    char *wordList[MAX_WORDS] = {"hangman", "computer", "programming", "language", "keyboard",
                                 "science", "algorithm", "software", "developer", "debugging"};

    srand(time(NULL));
    int index = rand() % MAX_WORDS;

    char *chosenWord = malloc(MAX_WORD_LENGTH);
    strcpy(chosenWord, wordList[index]);

    return chosenWord;
}

void displayWord(char *word, char *guessedLetters) {
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        if (strchr(guessedLetters, word[i]) != NULL) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }

    printf("\n");
}

int checkGuess(char *word, char *guessedLetters, char guess) {
    int length = strlen(word);

    for (int i = 0; i < length; i++) {
        if (word[i] == guess) {
            // Update the guessedLetters array with the correct guess
            guessedLetters[strlen(guessedLetters)] = guess;
            return 1;  // The guess is correct
        }
    }

    return 0;  // The guess is incorrect
}

void printHangman(int incorrectAttempts) {
    printf("Incorrect Attempts: %d\n", incorrectAttempts);

    switch (incorrectAttempts) {
        case 1:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 2:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 3:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf("  |   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 4:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|   |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 5:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 6:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" /    |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        case 7:
            printf("  +---+\n");
            printf("  |   |\n");
            printf("  O   |\n");
            printf(" /|\\  |\n");
            printf(" / \\  |\n");
            printf("      |\n");
            printf("=========\n");
            break;
        default:
            printf("  +---+\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("      |\n");
            printf("=========\n");
    }
}
