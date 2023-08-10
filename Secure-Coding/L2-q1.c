#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isSpecialChar(char c) {
    char specialChars[] = "!@#$%^&*()";
    for (int i = 0; i < strlen(specialChars); i++) {
        if (c == specialChars[i]) {
            return 1;
        }
    }
    return 0;
}

double computeStrength(char password[]) {
    int length = strlen(password);
    int hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            hasLower = 1;
        }
        if (isupper(password[i])) {
            hasUpper = 1;
        }
        if (isdigit(password[i])) {
            hasDigit = 1;
        }
        if (isSpecialChar(password[i])) {
            hasSpecial = 1;
        }
    }

    int criteriaMet = hasLower + hasUpper + hasDigit + hasSpecial;
    double strength = (double)criteriaMet / 4.0 * 100.0;
    return strength;
}

int main() {
    char password[100];
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    
    // Remove newline character from password
    password[strcspn(password, "\n")] = '\0';

    double strength = computeStrength(password);
    printf("Password Strength: %.2f%%\n", strength);

    return 0;
}

