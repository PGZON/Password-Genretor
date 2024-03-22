#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <malloc.h>
#include <Windows.h>

void display()
{
    //time_t rawtime; // Declare rawtime variable
    //struct tm* timeinfo; // Declare timeinfo variable

    //time(&rawtime);
    //timeinfo = localtime(&rawtime);


        printf("\t\t\t***********************************************************\n");
        printf("\t\t\t*                                                         *\n");
        printf("\t\t\t*                    PASSWORD GENERATOR                   *\n");
        printf("\t\t\t*                                                         *\n");
        printf("\t\t\t***********************************************************\n");
    

}

void about()
{
        system("cls");
        printf("\t\t\t***********************************************************\n");
        printf("\t\t\t*                                                         *\n");
        printf("\t\t\t*                      About                              *\n");
        printf("\t\t\t*                                                         *\n");
        printf("\t\t\t***********************************************************\n");

		
		printf("\n\n\nThe Program is Password Genretor is dedicated to Online saftey\n");
		printf("To Enhance the online sequrity we make our powerfl application it protect from online theif\n");
		printf("\n\n\n\t\t\tBe safe Be Explore...!\n");
		//printf("\n\n\n\t\t\t 2024 By Group\n");
		Sleep(10000);
}

//void printCurrentTime() {
//    time_t rawtime;
//    struct tm* timeinfo;
//
//    time(&rawtime);
//    timeinfo = localtime(&rawtime);
//
//    printf("\rCurrent time: %.2d:%.2d:%.2d", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
//}

void load()
{
    printf("\nBe patient, your password is being generated...\n");
    for (int i = 0; i <= 30; i++) {
        printf("=");
        fflush(stdout);
        Sleep(100);
    }
    printf("\n");
}

void exiit() {
    printf("\n\n\n\n");
    const char* message = "Exiting Program. Thanks for Visiting.....";
    printf("\t\t\t");
    for (int i = 0; message[i] != '\0'; i++) {
        printf("%c", message[i]);
        fflush(stdout);
        Sleep(150);
    }
    printf("\n");
}

// Function to generate a random character from a given character set
char getRandomChar(const char* charSet) {
    size_t charSetLength = strlen(charSet);
    return charSet[rand() % charSetLength];
}

// Function to generate a random password
char* generatePassword(int length, int numDigits, int numChars, int numSymbols) {
    const char* error_message = "Invalid input. Sum of digits, characters, and symbols exceeds password length.";

    if (length < numDigits + numChars + numSymbols) {
        char* result = (char*)malloc((strlen(error_message) + 1) * sizeof(char));
        strcpy_s(result, strlen(error_message) + 1, error_message);
        return result;
    }

    // Define character sets for digits, characters, and symbols
    const char* digits = "0123456789";
    const char* chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char* symbols = "!@#$%^&*()_-+=<>?";

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Allocate memory for the password
    char* password = (char*)malloc((size_t)(length + 1) * sizeof(char));
    password[length] = '\0';

    // Generate random digits, characters, and special symbols
    for (int i = 0; i < numDigits; ++i) {
        password[i] = getRandomChar(digits);
    }
    for (int i = numDigits; i < numDigits + numChars; ++i) {
        password[i] = getRandomChar(chars);
    }
    for (int i = numDigits + numChars; i < numDigits + numChars + numSymbols; ++i) {
        password[i] = getRandomChar(symbols);
    }

    // Generate the remaining characters
    size_t allCharactersLength = strlen(digits) + strlen(chars) + strlen(symbols);
    char* allCharacters = (char*)malloc((allCharactersLength + 1) * sizeof(char));
    if (allCharacters == NULL) {
        // Handle allocation failure
        free(password);
        return NULL;
    }
    strcpy_s(allCharacters, allCharactersLength + 1, digits);
    strcat_s(allCharacters, allCharactersLength + 1, chars);
    strcat_s(allCharacters, allCharactersLength + 1, symbols);

    for (size_t i = (size_t)(numDigits + numChars + numSymbols); i < (size_t)length; ++i) {
        password[i] = getRandomChar(allCharacters);
    }

    // Shuffle the characters to create the final password
    for (size_t i = (size_t)(length - 1); i > 0; --i) {
        size_t j = (size_t)(rand() % (i + 1));
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    free(allCharacters); // Free the allocated allCharacters memory

    return password;
}

int getInput(const char* prompt, int* value) {
    printf("%s", prompt);
    if (scanf_s("%d", value) != 1) {
        // Input is not a valid integer
        printf("Invalid input. Please enter a valid integer.\n");
        while (getchar() != '\n'); // Clear input buffer
        return 0; // Return failure
    }
    return 1; // Return success
}

int main() {
    int choice;
    do {
        system("cls"); // Clear the screen
        display(); // Reprint the display function
       // printCurrentTime();

        printf("\nOptions:\n");
        printf("1] Generate Password As ur Need\n");
        printf("2] Generate 9 Digit Password\n");
		printf("3] About\n");
        printf("4] Exit\n");
        printf("Enter your choice: ");
        if (!getInput("", &choice)) {
            // Error getting input, retry the loop
            continue;
        }

        switch (choice) {
        case 1: {
            int length, numDigits, numChars, numSymbols;

            // Get user input
            if (!getInput("Enter the length of the password: ", &length) ||
                !getInput("Enter the number of digits: ", &numDigits) ||
                !getInput("Enter the number of characters: ", &numChars) ||
                !getInput("Enter the number of special symbols: ", &numSymbols)) {
                // Error getting input, retry the loop
                continue;
            }
            load();
            // Generate and print the password
            char* password = generatePassword(length, numDigits, numChars, numSymbols);
            if (password == NULL) {
                printf("Memory allocation failed.\n");
            }
            else if (strcmp(password, "Invalid input. Sum of digits, characters, and symbols exceeds password length.") == 0) {
                printf("%s\n", password);
            }
            else {
                printf("\n\n\t\tGenerated Password: %s\n", password);
                free(password);
            }

            break;
        }
        case 2: {
            int length = 9; // Total length of password
            int numDigits = 4; // Number of digits
            int numChars = 4; // Number of characters
            int numSymbols = 1; // Number of symbols

            load();
            // Generate and print the password
            char* password = generatePassword(length, numDigits, numChars, numSymbols);
            if (password == NULL) {
                printf("Memory allocation failed.\n");
            }
            else if (strcmp(password, "Invalid input. Sum of digits, characters, and symbols exceeds password length.") == 0) {
                printf("%s\n", password);
            }
            else {
                printf("\n\n\t\tGenerated Password: %s\n", password);
                free(password);
            }
            break;
        }
		case 3:
			about();
			break;
        case 4:
            system("cls");
            display();
            exiit();
            system("cls");
            printf("\n\n\n\n\n\n");
            display();
            Sleep(3000);
           // printf("Exiting program. Goodbye!\n");
            return 0; // Exiting the program here
        default:
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
        Sleep(5000);
    } while (choice != 4);

    return 0;
}
