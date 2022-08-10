#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printBoard(char board[3][3]);

//returned Zero means couldn't place Marker, try again. 1 good
int placeMarker(char board[3][3], int row, int col, int player);

int computerMove(char board[3][3]);

int checkwinner(char board[3][3], int player);

int main() {

    char board[3][3];

    //Fill Board with empty space
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    
    int row, col;



    int isOver = 0; // 0 - game NOT over
    int player = 1; //Indicate who's making a move, 1 or -1
    int x = 0;
    while(isOver == 0) {

        if(player == 1){ 
            printBoard(board);
            printf("\n\nPlease choose a row and column (1 - 3): ");
            scanf("%d%d", &row, &col);

            while((row < 1 || row > 3) || (col < 1 || col > 3)) {
            
            printf("Invalid input! Enter numbers from (1 - 3) ");
            scanf("%d%d", &row, &col);

            }   
            
            row--;
            col--;
            placeMarker(board, row, col, player);
        } else { //player -1

            computerMove(board);
        }

      
        if(checkwinner(board, player) == 1) {
              printBoard(board);
            printf("\n\n\tPlayer 1 won the game!\n");
            break;
        } else if(checkwinner(board, player) == -1) {
              printBoard(board);
            printf("\n\n\tPlayer 2(Computer) won the game!\n");
            break;
        }


            x++;

            if(x > 8) {
                printBoard(board);
                printf("\n\n\tIt's a cats game. No one won!\n");
                break;
            }
           
        
        //play game
        
        player = player * -1;
        //call function to check if game is over...have to use isOver

    }



    return 0;
}

void printBoard(char board[3][3]) {

    printf("\n");

    for(int r = 0; r < 3; r++ ) {
        for(int c = 0; c < 3; c++) {

            printf("%c", board[r][c]);
            if(c <= 1) {
                printf("|");
            }
        
        }

        if(r <= 1) {
            printf("\n-----\n");
        }
    }

}
int computerMove(char board[3][3]) {

    int row, col;

    while(1) {
        // 
        srand(time(NULL));
        row = rand() % 3;
        col = rand() % 3;



        // check if avial
        if (board[row][col] == ' ') {
            
            board[row][col] = 'O';
            return 1;


        }

    }


}
int placeMarker(char board[3][3], int row, int col, int player) {
    
    while (board[row][col] != ' ') {
        printf("There is a piece is already there. Try again.\n");
        
        printf("Please enter a row and column: ");
        scanf("%d", &row, &col);
        printf("\n");
    }

    if (player == 1) {
        board[row][col] = 'X';
    } else{
        board[row][col] = 'O';   
    }
    return 1;
}

char rules(char board[3][3]){

    if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') {
                return 'X';
        } else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') {
                return 'O';
        } else if(board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X') {
                return 'X';
        } else if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O') {
                return 'O';
        } else if(board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') {
                return 'X';
        } else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') {
                return 'O';
        } else if(board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X') {
                return 'X';
        } else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O') {
                return 'O';
        } else if(board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X') {
                return 'X';
        } else if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O') {
                return 'O';
        } else if(board[1][0] == 'X' && board[1][1] == 'X' && board[2][1] == 'X') {
                return 'X';
        } else if (board[1][0] == 'O' && board[1][1] == 'O' && board[2][1] == 'O') {
                return 'O';
        } else if(board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X') {
                return 'X';
        } else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O') {
                return 'O';
        } else if(board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X') {
                return 'X';
        } else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O') {
                return 'O';
        } 

        return 'N';

       /* 
        int x = 0;
       
        for(int j = 0; j < 3; j++) {
            for(int i = 0; i < 3; i++){
                while(board[i][j] != ' ') {
                    x++;
                }
            }
        }

        if(x < 8) {
            return 'B';
        }
        */


}
int checkwinner(char board[3][3], int player) {

    if(player == 1 && rules(board) == 'X') {
        
        return 1;
    } else if(player == -1 && rules(board) == 'O') {
        return -1;
    } else if (rules(board) == 'N') {
        return 2;
    }/* else if(rules(board) == 'B') {
        return 3;
    }*/

   

       


}