#include <stdio.h>
#include "chess.h"
int main() {
    Chessfield test_fields[] = {
        {'A', 1},
        {'H', 8},
        {'D', 4},
        {'I', 5},
        {'C', 0},
        {'E', 9}
    };
    int n=sizeof(test_fields)/sizeof(test_fields[0]);
    for (int i=0; i<n; i++) {
        printf("testing test_fields[%d]\n", i);
        print_chessfield(test_fields[i]);
        printf("\n");
    }
    Chessfield c1;
    input_chessfield(&c1);
    printf("your chess position: ");
    print_chessfield(c1);
    printf("\n");
    if (queen_square_check(&c1)) {
        printf("yes, your queen can move to your position %c%hhu ", c1.hor, c1.vert);
    }
    else {
        printf("no, your queen cannot move to your position %c%hhu ", c1.hor, c1.vert);
    }
}