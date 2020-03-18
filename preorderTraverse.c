//
// Created by jer on 18.03.20.
//

#include <stdio.h>
#include <string.h>

void PreorderTraversal(char * strArr[]) {

    // code goes here
    printf("%s", strArr[0]);

}

int main(void) {

    // keep this function call here
    /* Note: In C you first have to initialize an array and set
       it equal to the stdin to test your code with arrays. */

    char * A[] = {"4", "1", "5", "2", "#", "#", "#"};
    PreorderTraversal(A);
    return 0;

}