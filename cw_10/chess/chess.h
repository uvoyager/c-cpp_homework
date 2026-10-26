#ifndef CLIONPROJECTS_CHESS_H
#define CLIONPROJECTS_CHESS_H
#include <stdbool.h>

typedef struct Chessfield_ {
    char hor;
    char vert;
} Chessfield;

void print_chessfield(Chessfield c);
bool input_chessfield(Chessfield *c);
bool queen_square_check(Chessfield *c);

#endif //CLIONPROJECTS_CHESS_H