#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random character from a given set of characters
char getRandomChar(const char *charSet, int setSize) {
    return charSet[rand() % setSize];
}

// Function to generate a strong password of a given length
void generatePassword(int length) {
    const char lowercaseChars[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercaseChars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char digitChars[] = "0123456789";
    const char specialChars[] = "!@#$%^&*()";

    const int lowercaseSize = sizeof(lowercaseChars) - 1;
    const int uppercaseSize = sizeof(uppercaseChars) - 1;
    const int digitSize = sizeof(digitChars) - 1;
    const int specialSize = sizeof(specialChars) - 1;

    for (int i = 0; i < length; i++) {
        int charType = rand() % 4;  // 0: lowercase, 1: uppercase, 2: digit, 3: special

        switch (charType) {
            case 0:
                putchar(getRandomChar(lowercaseChars, lowercaseSize));
                break;
            case 1:
                putchar(getRandomChar(uppercaseChars, uppercaseSize));
                break;
            case 2:
                putchar(getRandomChar(digitChars, digitSize));
                break;
            case 3:
                putchar(getRandomChar(specialChars, specialSize));
                break;
        }
    }
    putchar('\n');
}

int main() {
    int passwordLength;

    srand(time(NULL)); // Seed the random number generator

    printf("Enter the length of the password: ");
    scanf("%d", &passwordLength);

    if (passwordLength < 8) {
        printf("Password length must be at least 8 characters.\n");
    } else {
        printf("Generated strong password: ");
        generatePassword(passwordLength);
    }

    return 0;
}
