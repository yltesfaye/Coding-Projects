#include<stdio.h>
#include<stdlib.h>

int* changeSize(int* array) {

    array = realloc(array, sizeof(int));

    return array;

}

int addValue(int* array, int i) {
    int start;
    int top;
    int num;
    printf("Please enter a value: ");
    scanf("%d", &array[i]);

    

}


int stack(int* array, int i) {
    int top;
    printf("Current Stack: \n");
    if(i == 0) {
        printf("The Stack is currently empty\n\n");
    } else {
    int j;
    for( j = 0; j < i; j++) {
        printf("\t%d ", array[j]);
    }
    top = j;
    }

    return top;
}

int process(int* array, int* z, int i, int* start) {

    
    if(*z == i) {
        printf("The Stack is already empty\n");
    } else {
        
        printf("Now proccessing %d", array[*z-1]);
        *z = *z - i;
    }
}


int main() {

    int size;
    int* array = malloc(sizeof(int));

    
   
    changeSize(array);
    char ans = '1';

    int i = 0;
    int* start = &array[0];
    while(ans != 'q') {

        printf("\n Welcome to the Stack Program! Would you like to:\n\n");
        printf("1.) Add a new value to the stack.\n");
        printf("2.) Process a node on the stack\n");
        printf("q.) Quit\n");
        stack(array, i);
        printf("\ninput: ");
        scanf(" %c", &ans);

        int z;
        if(ans == '1') {
            addValue(array, i);
            i++;
           z = stack(array, i);
        } else if(ans == '2') {
            i--;
            if(i < 0) {
                i = 0;
            }
            process(array, &z, i, start);
            
            
        }
        
    }

   


    free(array);

    return 0;
}