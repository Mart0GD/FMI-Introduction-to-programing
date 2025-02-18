

/*
Напишете програма, която форматира подаден текст в 80 колони без да разделя думи. Трябва да форматирате текста:
 а) ляво (left); б) дясно (; в) центрирано (center); г) подравнено (justified)
*/#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#pragma warning(disable: 4996)

#define MAX_WIDTH 80
#define MAX_WORDS 1000

 // Разделя текста на думи
int splitWords(char* text, char* words[MAX_WORDS]) {
    int count = 0;
    char* token = strtok(text, " \n");
    while (token) {
        words[count++] = token;
        token = strtok(NULL, " \n");
    }
    return count;
}

// Ляво подравняване
void alignLeft(char* words[MAX_WORDS], int wordCount) {
    int lineLength = 0;
    for (int i = 0; i < wordCount; i++) {
        if (lineLength + strlen(words[i]) > MAX_WIDTH) {
            printf("\n");
            lineLength = 0;
        }
        printf("%s ", words[i]);
        lineLength += strlen(words[i]) + 1;
    }
    printf("\n");
}

// Дясно подравняване
void alignRight(char* words[MAX_WORDS], int wordCount) {
    char line[MAX_WIDTH + 1] = "";
    int lineLength = 0;

    for (int i = 0; i < wordCount; i++) {
        if (lineLength + strlen(words[i]) > MAX_WIDTH) {
            printf("%*s\n", MAX_WIDTH, line);
            line[0] = '\0';
            lineLength = 0;
        }
        strcat(line, words[i]);
        strcat(line, " ");
        lineLength += strlen(words[i]) + 1;
    }
    if (lineLength > 0) printf("%*s\n", MAX_WIDTH, line);
}

// Центрирано подравняване
void alignCenter(char* words[MAX_WORDS], int wordCount) {
    char line[MAX_WIDTH + 1] = "";
    int lineLength = 0;

    for (int i = 0; i < wordCount; i++) {
        if (lineLength + strlen(words[i]) > MAX_WIDTH) {
            int padding = (MAX_WIDTH - lineLength) / 2;
            printf("%*s%s\n", padding, "", line);
            line[0] = '\0';
            lineLength = 0;
        }
        strcat(line, words[i]);
        strcat(line, " ");
        lineLength += strlen(words[i]) + 1;
    }
    if (lineLength > 0) printf("%*s%s\n", (MAX_WIDTH - lineLength) / 2, "", line);
}

// Подравняване (Justified)
void alignJustified(char* words[MAX_WORDS], int wordCount) {
    char line[MAX_WORDS][MAX_WIDTH + 1];
    int lineLength = 0, wordIndex = 0, lineWordCount = 0;

    for (int i = 0; i < wordCount; i++) {
        if (lineLength + strlen(words[i]) > MAX_WIDTH) {
            int extraSpaces = MAX_WIDTH - lineLength;
            int spacesBetween = lineWordCount > 1 ? extraSpaces / (lineWordCount - 1) : 0;
            int remainder = lineWordCount > 1 ? extraSpaces % (lineWordCount - 1) : 0;

            for (int j = 0; j < lineWordCount; j++) {
                printf("%s", line[j]);
                if (j < lineWordCount - 1) {
                    printf("%*s", spacesBetween + (j < remainder ? 1 : 0), "");
                }
            }
            printf("\n");
            lineLength = 0;
            lineWordCount = 0;
        }
        strcpy(line[lineWordCount++], words[i]);
        lineLength += strlen(words[i]) + 1;
    }
    for (int j = 0; j < lineWordCount; j++) printf("%s ", line[j]);
    printf("\n");
}

int main_08_09() {
    char text[5000];
    printf("Enter text: \n");
    fgets(text, sizeof(text), stdin);

    char* words[MAX_WORDS];
    int wordCount = splitWords(text, words);

    printf("\nLeft Aligned:\n");
    alignLeft(words, wordCount);

    printf("\nRight Aligned:\n");
    alignRight(words, wordCount);

    printf("\nCentered:\n");
    alignCenter(words, wordCount);

    printf("\nJustified:\n");
    alignJustified(words, wordCount);

    return 0;
}
