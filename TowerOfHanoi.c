#include<stdio.h>


// n is the number of disks we need to move. An integer
// from is the tower we are moving from (can be A, B, or C)
// to is the tower we want out disks to 
// aux is the tower that's helping and can hold disks(A, B, or C)
                    // A         // C     // B
void hanoi(int n, char from, char to, char aux) {

    if( n == 1) // only one disk to move
    {
        printf("MOVE disk %d from %c to %c \n", n, from, to);
        return;
    }

    hanoi(n-1, from, aux, to); // move disks on top of n out of the way
    printf("move disk %d from %c to %c\n", n, from, to); // move biggest disk
    hanoi(n-1, aux, to, from); // aux not doing anything at that time
}

int main() {

    int n;
    printf("How many disks are on the starting tower: ");
    scanf("%d", &n);

    hanoi(n, 'A', 'C', 'B');


    return 0;
}