#include <stdio.h>
#include <string.h>

#define words_len 7

typedef struct {
    int length;
    char keys[11];
    int value;

} chars_values;


int ScrabbleScore(char scrample_word[50]) {
    chars_values chars[words_len];
    int sum = 0;
    char words[words_len][11] = {"AEIOULNRST\x00", "DG\x00", "BCMP\x00", "FHVWY\x00", "K\x00", "JX\x00", "QZ\x00"};
    int values[words_len] = {1,2,3,4,5,8,10};

    for (int i = 0; i < words_len; i ++) {

        chars[i].length = (int) strlen(words[i]);
        for (int j = 0; j < chars[i].length; j ++) {
            if (words[i][j] == '\x00') {
                break;
            }
            chars[i].keys[j] = words[i][j];
        }
        chars[i].value = values[i];
    }

    for (int i = 0; i < strlen(scrample_word); i ++) {
        for (int j = 0;j < words_len; j++) {
            for (int k = 0; k < chars[j].length; k++) {
                if (chars[j].keys[k] == scrample_word[i]) {
                    sum = sum + chars[j].value;
                }
            }
        }
    }

    return sum;
}


int main(void) {
    char word[50];

    printf("Give word:");
    scanf("%50s", word);

    int score = ScrabbleScore(word);

    printf("Points for word %s are %d.", word, score);
}
