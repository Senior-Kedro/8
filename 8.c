#include <stdio.h>
#include <string.h>
#include <ctype.h>

int factorial(int n) {
    if (n <= 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int countAnagrams(char* word, int ignoreCase) {
    int length = strlen(word);
    int frequency[256] = {0}; // Array to store frequency of each character
    int denominator = 1;

    // Calculate frequency of each character in the word
    for (int i = 0; i < length; i++) {
        char ch = ignoreCase ? tolower(word[i]) : word[i];
        frequency[ch]++;
    }

    // Calculate the denominator for dividing the total permutations
    for (int i = 0; i < 256; i++)
        denominator *= factorial(frequency[i]);

    // Calculate the total number of anagrams
    int totalAnagrams = factorial(length) / denominator;

    return totalAnagrams;
}

int main() {
    char word[100];

    printf("Enter a word: ");
    scanf("%s", word);

    if (strlen(word) > 14) {
        printf("Word is too long.\n");
        return 0;
    }

    int ignoreCase = 1; // Set to 1 to ignore case - default, 0 to consider case

    printf("Set to 1 to ignore case - default, 0 to consider case: ");
    scanf("%d", &ignoreCase);

    int numAnagrams = countAnagrams(word, ignoreCase);

    printf("Number of Anagrams: %d\n", numAnagrams);

    return 0;
}