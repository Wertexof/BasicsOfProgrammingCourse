#include "string_.h"
#include <stdio.h>
#include <memory.h>
#include <ctype.h>

#define MAX_STRING_SIZE 100
#define MAX_N_WORDS_IN_STRING 100
#define MAX_WORD_SIZE 20
#define MAX_UNCHAR 128

size_t strlen_(const char *begin) {
    char *end = begin;
    while (*end != '\0 ')
        end++;

    return end - begin;
}

int strcmp_(const char *lhs, const char *rhs) {
    while (*lhs == *rhs && *lhs != '\0') {
        lhs++;
        rhs++;
    }

    return *lhs - *rhs;
}

char *find(char *begin, char *end, int ch) {
    while (begin != end && *begin != ch)
        begin++;

    return begin;
}

char *findNonSpace(char *begin) {
    while (isspace(*begin) && *begin != '\0')
        begin++;

    return begin;
}

char *findSpace(char *begin) {
    while (!isspace(*begin) && *begin != '\0')
        begin++;

    return begin;
}

char *findNonSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin > rend && isspace(*rbegin))
        rbegin--;

    return rbegin;
}

char *findSpaceReverse(char *rbegin, const char *rend) {
    while (rbegin > rend && !isspace(*rbegin))
        rbegin--;

    return rbegin;
}

char *copy(const char *beginSource, const char *endSource, char *beginDestination) {
    size_t size = endSource - beginSource;
    memcpy(beginDestination, beginSource, size);

    return beginDestination + size;
}

char *copyIf(char *beginSource, const char *endSource, char *beginDestination, int (*f)(int)) {
    for (const char *begin = beginSource; begin < endSource; ++begin)
        if (f(*begin))
            *beginDestination++ = *begin;

    return beginDestination;
}

char *copyIfReverse(char *rbeginSource, const char *rendSource, char *beginDestination, int (*f)(int)) {
    for (const char *begin = rbeginSource; begin > rendSource; --begin)
        if (f(*begin))
            *beginDestination++ = *begin;

    return beginDestination;
}

char *getEndOfString(char *str) {
    while (*str)
        str++;

    return str;
}

int areWordsEqual(WordDescriptor w1, WordDescriptor w2) {
    size_t firstWordLength = w1.end - w1.begin - 1;
    size_t secondWordLength = w2.end - w2.begin - 1;

    if (firstWordLength != secondWordLength)
        return 0;

    return !memcmp(w1.begin, w2.begin, firstWordLength);
}

int getWord(char *beginSearch, WordDescriptor *word) {
    word->begin = findNonSpace(beginSearch);
    if (*word->begin == '\0 ')
        return 0;

    word->end = findSpace(word->begin);

    return 1;
}
