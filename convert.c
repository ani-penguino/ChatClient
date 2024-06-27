#include <stdlib.h>
#include <string.h>

char* convert(const char *keystate) {
    char* charArray = malloc(2 * sizeof(char));
    if (charArray == NULL) {
        return NULL;
    }
    if (strcmp(keystate, "00 28 00") == 0) {
	charArray[0] = 13; //return character
    } else if (strcmp(keystate, "00 2a 00") == 0) {
        charArray[0] = 8; // backspace 
    } else if (strcmp(keystate, "00 50 00") == 0) {
        charArray[0] = 1; // leftarrow
    } else if (strcmp(keystate, "00 4f 00") == 0) {
        charArray[0] = 2; // rightarrow
    } else if (strcmp(keystate, "00 04 00") == 0) {
        charArray[0] = 97; // a
    } else if (strcmp(keystate, "00 05 00") == 0) {
        charArray[0] = 98; // b
    } else if (strcmp(keystate, "00 06 00") == 0) {
        charArray[0] = 99; // c
    } else if (strcmp(keystate, "00 07 00") == 0) {
        charArray[0] = 100; // d
    } else if (strcmp(keystate, "00 08 00") == 0) {
        charArray[0] = 101; // e
    } else if (strcmp(keystate, "00 09 00") == 0) {
        charArray[0] = 102; // f
    } else if (strcmp(keystate, "00 0a 00") == 0) {
        charArray[0] = 103; // g
    } else if (strcmp(keystate, "00 0b 00") == 0) {
        charArray[0] = 104; // h
    } else if (strcmp(keystate, "00 0c 00") == 0) {
        charArray[0] = 105; // i
    } else if (strcmp(keystate, "00 0d 00") == 0) {
        charArray[0] = 106; // j
    } else if (strcmp(keystate, "00 0e 00") == 0) {
        charArray[0] = 107; // k
    } else if (strcmp(keystate, "00 0f 00") == 0) {
        charArray[0] = 108; // l
    } else if (strcmp(keystate, "00 10 00") == 0) {
        charArray[0] = 109; // m
    } else if (strcmp(keystate, "00 11 00") == 0) {
        charArray[0] = 110; // n
    } else if (strcmp(keystate, "00 12 00") == 0) {
        charArray[0] = 111; // o
    } else if (strcmp(keystate, "00 13 00") == 0) {
        charArray[0] = 112; // p
    } else if (strcmp(keystate, "00 14 00") == 0) {
        charArray[0] = 113; // q
    } else if (strcmp(keystate, "00 15 00") == 0) {
        charArray[0] = 114; // r
    } else if (strcmp(keystate, "00 16 00") == 0) {
        charArray[0] = 115; // s
    } else if (strcmp(keystate, "00 17 00") == 0) {
        charArray[0] = 116; // t
    } else if (strcmp(keystate, "00 18 00") == 0) {
        charArray[0] = 117; // u
    } else if (strcmp(keystate, "00 19 00") == 0) {
        charArray[0] = 118; // v
    } else if (strcmp(keystate, "00 1a 00") == 0) {
        charArray[0] = 119; // w
    } else if (strcmp(keystate, "00 1b 00") == 0) {
        charArray[0] = 120; // x
    } else if (strcmp(keystate, "00 1c 00") == 0) {
        charArray[0] = 121; // y
    } else if (strcmp(keystate, "00 1d 00") == 0) {
        charArray[0] = 122; // z
    } else if (strcmp(keystate, "02 04 00") == 0) {
        charArray[0] = 65; // A
    } else if (strcmp(keystate, "02 05 00") == 0) {
        charArray[0] = 66; // B
    } else if (strcmp(keystate, "02 06 00") == 0) {
        charArray[0] = 67; // C
    } else if (strcmp(keystate, "02 07 00") == 0) {
        charArray[0] = 68; // D
    } else if (strcmp(keystate, "02 08 00") == 0) {
        charArray[0] = 69; // E
    } else if (strcmp(keystate, "02 09 00") == 0) {
        charArray[0] = 70; // F
    } else if (strcmp(keystate, "02 0a 00") == 0) {
        charArray[0] = 71; // G
    } else if (strcmp(keystate, "02 0b 00") == 0) {
        charArray[0] = 72; // H
    } else if (strcmp(keystate, "02 0c 00") == 0) {
        charArray[0] = 73; // I
    } else if (strcmp(keystate, "02 0d 00") == 0) {
        charArray[0] = 74; // J
    } else if (strcmp(keystate, "02 0e 00") == 0) {
        charArray[0] = 75; // K
    } else if (strcmp(keystate, "02 0f 00") == 0) {
        charArray[0] = 76; // L
    } else if (strcmp(keystate, "02 10 00") == 0) {
        charArray[0] = 77; // M
    } else if (strcmp(keystate, "02 11 00") == 0) {
        charArray[0] = 78; // N
    } else if (strcmp(keystate, "02 12 00") == 0) {
        charArray[0] = 79; // O
    } else if (strcmp(keystate, "02 13 00") == 0) {
        charArray[0] = 80; // P
    } else if (strcmp(keystate, "02 14 00") == 0) {
        charArray[0] = 81; // Q
    } else if (strcmp(keystate, "02 15 00") == 0) {
        charArray[0] = 82; // R
    } else if (strcmp(keystate, "02 16 00") == 0) {
        charArray[0] = 83; // S
    } else if (strcmp(keystate, "02 17 00") == 0) {
        charArray[0] = 84; // T
    } else if (strcmp(keystate, "02 18 00") == 0) {
        charArray[0] = 85; // U
    } else if (strcmp(keystate, "02 19 00") == 0) {
        charArray[0] = 86; // V
    } else if (strcmp(keystate, "02 1a 00") == 0) {
        charArray[0] = 87; // W
    } else if (strcmp(keystate, "02 1b 00") == 0) {
        charArray[0] = 88; // X
    } else if (strcmp(keystate, "02 1c 00") == 0) {
        charArray[0] = 89; // Y
    } else if (strcmp(keystate, "02 1d 00") == 0) {
        charArray[0] = 90; // Z
    } else if (strcmp(keystate, "00 2c 00") == 0) {
        charArray[0] = 32; // space
    } else if (strcmp(keystate, "00 36 00") == 0) {
        charArray[0] = 44; // comma
    } else if (strcmp(keystate, "00 37 00") == 0) {
        charArray[0] = 46; // dot
    } else if (strcmp(keystate, "00 38 00") == 0) {
        charArray[0] = 47; // /
    } else if (strcmp(keystate, "00 1e 00") == 0) {
        charArray[0] = 49; // 1
    } else if (strcmp(keystate, "00 34 00") == 0) {
        charArray[0] = 39; // '
    } else if (strcmp(keystate, "20 04 00") == 0) {
        charArray[0] = 65; // A
    } else if (strcmp(keystate, "20 05 00") == 0) {
        charArray[0] = 66; // B
    } else if (strcmp(keystate, "20 06 00") == 0) {
        charArray[0] = 67; // C
    } else if (strcmp(keystate, "20 07 00") == 0) {
        charArray[0] = 68; // D
    } else if (strcmp(keystate, "20 08 00") == 0) {
        charArray[0] = 69; // E
    } else if (strcmp(keystate, "20 09 00") == 0) {
        charArray[0] = 70; // F
    } else if (strcmp(keystate, "20 0a 00") == 0) {
        charArray[0] = 71; // G
    } else if (strcmp(keystate, "20 0b 00") == 0) {
        charArray[0] = 72; // H
    } else if (strcmp(keystate, "20 0c 00") == 0) {
        charArray[0] = 73; // I
    } else if (strcmp(keystate, "20 0d 00") == 0) {
        charArray[0] = 74; // J
    } else if (strcmp(keystate, "20 0e 00") == 0) {
        charArray[0] = 75; // K
    } else if (strcmp(keystate, "20 0f 00") == 0) {
        charArray[0] = 76; // L
    } else if (strcmp(keystate, "20 10 00") == 0) {
        charArray[0] = 77; // M
    } else if (strcmp(keystate, "20 11 00") == 0) {
        charArray[0] = 78; // N
    } else if (strcmp(keystate, "20 12 00") == 0) {
        charArray[0] = 79; // O
    } else if (strcmp(keystate, "20 13 00") == 0) {
        charArray[0] = 80; // P
    } else if (strcmp(keystate, "20 14 00") == 0) {
        charArray[0] = 81; // Q
    } else if (strcmp(keystate, "20 15 00") == 0) {
        charArray[0] = 82; // R
    } else if (strcmp(keystate, "20 16 00") == 0) {
        charArray[0] = 83; // S
    } else if (strcmp(keystate, "20 17 00") == 0) {
        charArray[0] = 84; // T
    } else if (strcmp(keystate, "20 18 00") == 0) {
        charArray[0] = 85; // U
    } else if (strcmp(keystate, "20 19 00") == 0) {
        charArray[0] = 86; // V
    } else if (strcmp(keystate, "20 1a 00") == 0) {
        charArray[0] = 87; // W
    } else if (strcmp(keystate, "20 1b 00") == 0) {
        charArray[0] = 88; // X
    } else if (strcmp(keystate, "20 1c 00") == 0) {
        charArray[0] = 89; // Y
    } else if (strcmp(keystate, "20 1d 00") == 0) {
        charArray[0] = 90; // Z
    } else if (strcmp(keystate, "20 36 00") == 0) {
        charArray[0] = 60; // <
    } else if (strcmp(keystate, "20 37 00") == 0) {
        charArray[0] = 62; // >
    } else if (strcmp(keystate, "20 38 00") == 0) {
        charArray[0] = 63; // ?
    } else if (strcmp(keystate, "20 1e 00") == 0) {
        charArray[0] = 33; // !
    } else if (strcmp(keystate, "20 34 00") == 0) {
        charArray[0] = 34; // "
    } else if (strcmp(keystate, "02 36 00") == 0) {
        charArray[0] = 60; // <
    } else if (strcmp(keystate, "02 37 00") == 0) {
        charArray[0] = 62; // >
    } else if (strcmp(keystate, "02 38 00") == 0) {
        charArray[0] = 63; // ?
    } else if (strcmp(keystate, "02 1e 00") == 0) {
        charArray[0] = 33; // !
    } else if (strcmp(keystate, "02 34 00") == 0) {
        charArray[0] = 34; // "
    } else if (strcmp(keystate, "00 35 00") == 0) {
        charArray[0] = 96; // `
    } else if (strcmp(keystate, "00 1f 00") == 0) {
        charArray[0] = 50; // 2
    } else if (strcmp(keystate, "00 20 00") == 0) {
        charArray[0] = 51; // 3
    } else if (strcmp(keystate, "00 21 00") == 0) {
        charArray[0] = 52; // 4
    } else if (strcmp(keystate, "00 22 00") == 0) {
        charArray[0] = 53; // 5
    } else if (strcmp(keystate, "00 23 00") == 0) {
        charArray[0] = 54; // 6
    } else if (strcmp(keystate, "00 24 00") == 0) {
        charArray[0] = 55; // 7
    } else if (strcmp(keystate, "00 25 00") == 0) {
        charArray[0] = 56; // 8
    } else if (strcmp(keystate, "00 26 00") == 0) {
        charArray[0] = 57; // 9
    } else if (strcmp(keystate, "00 27 00") == 0) {
        charArray[0] = 48; // 0
    } else if (strcmp(keystate, "00 2d 00") == 0) {
        charArray[0] = 45; // -
    } else if (strcmp(keystate, "00 2e 00") == 0) {
        charArray[0] = 61; // =
    } else if (strcmp(keystate, "00 2f 00") == 0) {
        charArray[0] = 91; // [
    } else if (strcmp(keystate, "00 30 00") == 0) {
        charArray[0] = 93; // ]
    } else if (strcmp(keystate, "00 31 00") == 0) {
        charArray[0] = 92; //
    } else if (strcmp(keystate, "00 33 00") == 0) {
        charArray[0] = 59; // ;
    } else if (strcmp(keystate, "20 35 00") == 0) {
        charArray[0] = 126; // ~
    } else if (strcmp(keystate, "20 1f 00") == 0) {
        charArray[0] = 64; // @
    } else if (strcmp(keystate, "20 20 00") == 0) {
        charArray[0] = 35; // #
    } else if (strcmp(keystate, "20 21 00") == 0) {
        charArray[0] = 36; // $
    } else if (strcmp(keystate, "20 22 00") == 0) {
        charArray[0] = 37; // %
    } else if (strcmp(keystate, "20 23 00") == 0) {
        charArray[0] = 94; // ^
    } else if (strcmp(keystate, "20 24 00") == 0) {
        charArray[0] = 38; // &
    } else if (strcmp(keystate, "20 25 00") == 0) {
        charArray[0] = 42; // *
    } else if (strcmp(keystate, "20 26 00") == 0) {
        charArray[0] = 40; // (
    } else if (strcmp(keystate, "20 27 00") == 0) {
        charArray[0] = 41; // )
    } else if (strcmp(keystate, "20 2d 00") == 0) {
        charArray[0] = 95; // _
    } else if (strcmp(keystate, "20 2e 00") == 0) {
        charArray[0] = 43; // +
    } else if (strcmp(keystate, "20 2f 00") == 0) {
        charArray[0] = 123; // {
    } else if (strcmp(keystate, "20 30 00") == 0) {
        charArray[0] = 125; // }
    } else if (strcmp(keystate, "20 31 00") == 0) {
        charArray[0] = 124; // |
    } else if (strcmp(keystate, "20 33 00") == 0) {
        charArray[0] = 58; // :
    } else if (strcmp(keystate, "02 35 00") == 0) {
        charArray[0] = 126; // ~
    } else if (strcmp(keystate, "02 1f 00") == 0) {
        charArray[0] = 64; // @
    } else if (strcmp(keystate, "02 20 00") == 0) {
        charArray[0] = 35; // #
    } else if (strcmp(keystate, "02 21 00") == 0) {
        charArray[0] = 36; // $
    } else if (strcmp(keystate, "02 22 00") == 0) {
        charArray[0] = 37; // %
    } else if (strcmp(keystate, "02 23 00") == 0) {
        charArray[0] = 94; // ^
    } else if (strcmp(keystate, "02 24 00") == 0) {
        charArray[0] = 38; // &
    } else if (strcmp(keystate, "02 25 00") == 0) {
        charArray[0] = 42; // *
    } else if (strcmp(keystate, "02 26 00") == 0) {
        charArray[0] = 40; // (
    } else if (strcmp(keystate, "02 27 00") == 0) {
        charArray[0] = 41; // )
    } else if (strcmp(keystate, "02 2d 00") == 0) {
        charArray[0] = 95; // _
    } else if (strcmp(keystate, "02 2e 00") == 0) {
        charArray[0] = 43; // +
    } else if (strcmp(keystate, "02 2f 00") == 0) {
        charArray[0] = 123; // {
    } else if (strcmp(keystate, "02 30 00") == 0) {
        charArray[0] = 125; // }
    } else if (strcmp(keystate, "02 31 00") == 0) {
        charArray[0] = 124; // |
    } else if (strcmp(keystate, "02 33 00") == 0) {
        charArray[0] = 58; // :


    } else {
        charArray[0] = '\0'; // Null character to signify end of string
    }
    charArray[1] = 0;

    return charArray;
}



