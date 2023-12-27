#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

void merge_sort(char** start, char** end);
void End();

int main()
{
    std::cout << "A program for \"lexicographic string sorting\".\nnow you will be entering some set of strings.\nAn empty string is considered a sign of the end of the set.\n\n";
    std::cout << "To start, press any key." << std::endl;
    std::cin.get();

    std::cout << "Enter text:" << std::endl;

    int lineCount = 0;
    int lineSize = 20;
    char** lines = new char* [lineSize];

    if (lines == NULL) {
        End();
    }

    char* line = new char[lineSize];

    if (line == NULL) {
        End();
    }

    char c;
    int endCondition = 1;
    int charCount = 0;

    while (std::cin.get(c)) {
        if (c == '\n') {
            if (endCondition) {
                break;
            }
            else {
                endCondition = 1;
            }

            line[charCount] = '\0';
            lines[lineCount] = line;

            lineCount++;

            if (lineCount >= lineSize) {
                lineSize *= 2;
                lines = new char* [lineSize];

                if (lines == NULL) {
                    End();
                }
            }

            line = new char[lineSize];

            if (line == NULL) {
                End;
            }

            charCount = 0;
        }
        else {
            endCondition = 0;
            line[charCount] = c;
            charCount++;

            if (charCount >= lineSize) {
                lineSize *= 2;

                line = new char[lineSize];

                if (line == NULL) {
                    End();
                }
            }
        }
    }

    delete[] line;

    merge_sort(lines, lines + lineCount - 1);

    std::cout << "\nSorted list of strings:\n\n";

    for (int i = 0; i < lineCount; i++) {
        std::cout << lines[i] << std::endl;
    } 

    delete[] lines;

    return 0;
}

void merge(char** start, char** middle, char** end)
{
    int leftSize = middle - start + 1;
    int rightSize = end - middle;

    char** left = new char* [leftSize];
    char** right = new char* [rightSize];

    if (left == NULL || right == NULL) {
        End();
    }

    for (int i = 0; i < leftSize; i++) {
        left[i] = start[i];
    }

    for (int i = 0; i < rightSize; i++) {
        right[i] = middle[i + 1];
    }

    int leftIndex = 0;
    int rightIndex = 0;
    int mergedIndex = 0;

    while (leftIndex < leftSize && rightIndex < rightSize) {
        if (strcmp(left[leftIndex], right[rightIndex]) <= 0) {
            start[mergedIndex] = left[leftIndex];
            leftIndex++;
        }
        else {
            start[mergedIndex] = right[rightIndex];
            rightIndex++;
        }

        mergedIndex++;
    }

    while (leftIndex < leftSize) {
        start[mergedIndex] = left[leftIndex];
        leftIndex++;
        mergedIndex++;
    }

    while (rightIndex < rightSize) {
        start[mergedIndex] = right[rightIndex];
        rightIndex++;
        mergedIndex++;
    }

    delete[] left;
    delete[] right;
}

void merge_sort(char** start, char** end)
{
    if (start < end) {
        char** middle = start + (end - start) / 2;
        merge_sort(start, middle);
        merge_sort(middle + 1, end);
        merge(start, middle, end);
    }
}

void End()
{
    std::cout << "Memory allocation error!!!";
    exit(0);
}
