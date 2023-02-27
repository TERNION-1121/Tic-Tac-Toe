#include<stdio.h>
#include<stdlib.h>

#define REPR(pos) (pos == -1) ? 'X' : ((pos == 1) ? 'O' : ' ')   
#define WHOSE_TURN(num) (num == 1) ? 'O' : 'X'
#define DOUBLE_NEWLINE printf("\n\n")

int garbage;

void main() {
    int find_best_move(int [], int);
    int evaluate(int []);
    int moves_left(int []);
    char home_menu();

    void board(int []);
    void help();
    void human_vs_human();
    void human_vs_ai(int);


    int game_over;
    char game_choice;

    game_over = 0;
    
    while (!game_over) {
        game_choice = home_menu();
        switch (game_choice) {
            case 'H':
                system("cls");
                help();
                break;
            case '1':
                system("cls");
                human_vs_human();
                break;
            case '2':
                system("cls");
                human_vs_ai(1);
                break;
            case 'E':
                game_over = 1;
                break;
            default:
                system("cls");
                break;
        }
    }
}

int evaluate(int p[]) {
    int sum_row, sum_col, sum_d1, sum_d2;
    int r, c;

    for (r = 2, c = 0; r <= 8 || c <= 2 ; r+=3, ++c) {
        sum_row = p[r] + p[r-1] + p[r-2];
        sum_col = p[c] + p[c+3] + p[c+6];
        if (sum_row == 3 || sum_col == 3)
            return 1; // O won
        else if (sum_row == -3 || sum_col == -3)
            return -1; // X won
    }
    sum_d1 = p[0] + p[4] + p[8];
    sum_d2 = p[2] + p[4] + p[6];

    if (sum_d1 == 3 || sum_d2 == 3)
        return 1;
    else if (sum_d1 == -3 || sum_d2 == -3)
        return -1;
    
    return 0; // no winner
}

char home_menu() {
    char choice;
    
    printf("---Welcome to Tic-Tac-Toe---");
    DOUBLE_NEWLINE;
    printf("Press:\n");
    printf("\'H\' for help.\n");
    printf("\'1\' to play Human v/s Human.\n");
    printf("\'2\' to play Human v/s AI (coming soon...).\n");
    printf("\'E\' to exit.\n");
    DOUBLE_NEWLINE;
    scanf("%c", &choice);

    return choice;

}

void board(int p[]) {
    printf("|---|---|---|\n");
    printf("| %c | %c | %c |\n", REPR(p[0]), REPR(p[1]), REPR(p[2]));
    printf("|---|---|---|\n");
    printf("| %c | %c | %c |\n", REPR(p[3]), REPR(p[4]), REPR(p[5]));
    printf("|---|---|---|\n");
    printf("| %c | %c | %c |\n", REPR(p[6]), REPR(p[7]), REPR(p[8]));
    printf("|---|---|---|\n");
}

void help()
{   

    printf("How To Play: Tic-Tac-Toe\n");
    DOUBLE_NEWLINE;
    printf("The game is played on a grid that's 3 squares by 3 squares.\n\n");
    printf("|---|---|---|\n");
    printf("| 0 | 1 | 2 |\n");
    printf("|---|---|---|\n");
    printf("| 3 | 4 | 5 |\n");
    printf("|---|---|---|\n");
    printf("| 6 | 7 | 8 |\n");
    printf("|---|---|---|\n");              
    printf("You have to enter the square's number on which you want to place your mark whether 'X' or 'O'.\n\
[Remember not to enter a square number which is not inclusive of range(0-8), or is already occupied!]\n");
    DOUBLE_NEWLINE;
    printf("The first player to get 3 of their marks in a row(across), column(up/down), or diagonally is the winner.\n\n");
    printf("|---|---|---|\t\t\t\t|---|---|---|\t\t\t\t|---|---|---|\n");
    printf("| X | X | X |\t\t\t\t| X |   |   |\t\t\t\t| X |   | O |\n");
    printf("|---|---|---|\t\t\t\t|---|---|---|\t\t\t\t|---|---|---|\n");
    printf("|   | O |   |\t\t\t\t| X | O | O |\t\t\t\t|   | X |   |\n");
    printf("|---|---|---|\t\t\t\t|---|---|---|\t\t\t\t|---|---|---|\n");
    printf("| O |   |   |\t\t\t\t| X |   |   |\t\t\t\t| O |   | X |\n");
    printf("|---|---|---|\t\t\t\t|---|---|---|\t\t\t\t|---|---|---|\n");
    printf("> X makes a row(across), wins\t\t> X makes a column(up/down), wins\t> X makes a diagonal, wins\n");
    DOUBLE_NEWLINE;
    printf("If all the squares are occupied, and no player wins, it is a draw.\n\n");
    printf("|---|---|---|\n");
    printf("| O | X | X |\n");
    printf("|---|---|---|\n");
    printf("| X | X | O |\n");
    printf("|---|---|---|\n");
    printf("| O | O | X |\n");
    printf("|---|---|---|\n");
    printf("> Draw\n");

    DOUBLE_NEWLINE;
    printf("When done, press any alphabet key and hit enter to return to the home menu: ");
    scanf("%d", garbage); 
    system("cls");
    
}

void human_vs_human() 
{

    int positions[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int iterations;
    int turn, user_choice; 
    int win_val;
    int error;
    int running;

    char current_player;

    error = iterations = 0;
    running = turn = 1;

    while (running) {
        iterations+=1;

        board(positions);
        DOUBLE_NEWLINE;
        current_player = WHOSE_TURN(turn);
        printf("\'%c\'s move.\nChoose a square: ", current_player);
        scanf("%d", &user_choice);
        DOUBLE_NEWLINE;
            
        if (user_choice < 0 || user_choice > 8)
            error = 1;

        if (positions[user_choice] == 0) 
            positions[user_choice] = (turn == 1) ? 1 : -1;
        else 
            error = 1;

        win_val = evaluate(positions);
        if (win_val == 1) {
            DOUBLE_NEWLINE;
            board(positions);
            printf("\n\'O\' Won!\n");
            running = 0;
        }
        else if (win_val == -1) {
            DOUBLE_NEWLINE;
            board(positions);
            printf("\n\'X\' Won!\n");
            running = 0;
        }
        else if (iterations == 9) {  // draw
            board(positions);
            DOUBLE_NEWLINE;
            printf("Draw!\n");
            running = 0;
        }
        turn *= -1; // reverse turn

        if (error) {
            printf("Invalid square choice!\n\
    >>> Square either already occupied or Square number out of range(0-8)!\n\n\
Try again!\n");
            turn *= -1;
            error = 0;
            --iterations;
        }
    }
    DOUBLE_NEWLINE;
    printf("Press any key and hit enter to return to the home menu: ");
    scanf("%d", garbage);
    system("cls");
}

void human_vs_ai(int human)
{   
    int find_best_move(int [], int);

    int positions[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int iterations;
    int user_choice;
    int win_val;
    int ai;
    int error;
    int running;
    int best_move;

    error = iterations = 0;
    running = 1;
    ai = (human == 1) ? -1 : 1;

    while (running) {
        ++iterations;
        
        do {
            board(positions);
            DOUBLE_NEWLINE;
            printf("\'%c\'s move.\nChoose a square: ", WHOSE_TURN(human));
            scanf("%d", &user_choice);
            DOUBLE_NEWLINE;

            if (user_choice < 0 || user_choice > 8)
                error = 1;
            if (positions[user_choice] == 0) {
                positions[user_choice] = human;
                error = 0;
            }
            else
                error = 1;

            if (error) {
            printf("Invalid square choice!\n\
    >>> Square either already occupied or Square number out of range(0-8)!\n\n\
Try again!\n");
            error = 1;
            }
        } while (error);

        win_val = evaluate(positions);
        if (win_val == 1 || win_val == -1 || iterations == 9) 
            goto gameOver;

        best_move = find_best_move(positions, ai);
        board(positions);
        positions[best_move] = ai;
        DOUBLE_NEWLINE;
        printf("A.I. picks square %d\n", best_move);
        DOUBLE_NEWLINE;
        ++iterations;

        gameOver:
            win_val = evaluate(positions);
            if (win_val == 1) {
                board(positions);
                printf("'O' Won!\n");
                running = 0;
            }
            else if (win_val == -1) {
                board(positions);
                printf("\n\'X\' Won!\n");
                running = 0;
            }
            else if (iterations == 9) {  // draw
                board(positions);
                printf("Draw!\n");
                running = 0;
            }
    
    }
    DOUBLE_NEWLINE;
    printf("Press any key and hit enter to return to the home menu: ");
    scanf("%d", garbage);
    system("cls");
    
}

int is_moves_left(int p[])
{
    for (int i = 0; i <= 8; ++i)
        if (p[i] == 0)
            return 1;
    return 0;
}

int find_best_move(int positions[], int player)
{
    int minimax(int [], int, int);

    int best_move = player == 1 ? -1000 : 1000;
    int best_pos = -1;

    for (int i = 0; i <= 8; ++i) {
        if (positions[i] == 0) {
            positions[i] = player;

            int moveVal = minimax(positions, 9, player == 1 ? 0 : 1);

            positions[i] = 0;
        
            if (best_move == 1000) {
                if (moveVal < best_move) {
                    best_pos = i;
                    best_move = moveVal;
                }
            }
            else {
                if (moveVal > best_move) {
                    best_pos = i;
                    best_move = moveVal;
                }
            }
        }
    }
    return best_pos;
}

int minimax(int p[], int depth, int maximizingPlayer)
{   
    int max(int, int);
    int min(int, int);
    int is_moves_left(int []);

    int val;
    if ((val = evaluate(p)) == 1 || val == -1 || !is_moves_left(p) || depth == 0)
        return val;
    if (maximizingPlayer) {
        int maxEval = -1000;
        for (int i = 0; i <= 8; ++i) {
            if (p[i] == 0) {
                p[i] = 1;
                maxEval = max(maxEval, minimax(p, depth - 1, 0));
                p[i] = 0;
            }
        }
        return maxEval - depth;
    }

    else {
        int minEval = 1000; 
        for (int k = 0; k <= 8; ++k) {
            if (p[k] == 0) {
                p[k] = -1;
                minEval = min(minEval, minimax(p, depth - 1, 1));
                p[k] = 0;
            }
        }
        return minEval + depth;
    }
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}