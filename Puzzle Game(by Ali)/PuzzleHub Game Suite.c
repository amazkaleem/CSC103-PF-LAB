#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <windows.h>
#include <time.h>

// UI functions
void clearScreen();
void setColor(WORD color);
void waitMs(int ms);
void loadingScreen();
void loadingScreenGame();
int loadUsers(char users[][30]);
int saveUser(const char *username);
int loginMenu(char *currentUser);
void mainMenu(const char *user);
void gamesMenu(const char *user);
void viewScores(const char *user);
void viewLeaderboard();
void creditsScreen();

// Games
void sudokuGame(const char *user);
void mathSolverGame(const char *user);
void ticTacToeGame(const char *user);
void wordleGame(const char *user);
void anagramGame(const char *user);
void riddleGame(const char *user);
void hangmanGame(const char *user);
void drawHangman(int attemptsLeft);

int main(){
    char currentUser[30] = {0};
    while(1){
        clearScreen();
        loadingScreen();
        if(loginMenu(currentUser)==0){
            clearScreen();
            setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            printf("Welcome, %s!\n", currentUser);
            setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            waitMs(800);
            mainMenu(currentUser);
        }
		else{
            break;
        }
    }
    clearScreen();
    printf("Thank you for using PuzzleHub. Goodbye!\n");
    return 0;
}

void clearScreen(){
    system("cls");
}

void setColor(WORD color){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void waitMs(int ms){
    Sleep(ms);
}

void loadingScreen(){
    setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("Loading PuzzleHub");
    for(int i=0; i<5; i++){
        printf(".");
        Sleep(300);
    }
    printf("\n");
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    waitMs(500);
}

void loadingScreenGame(){
    setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	printf("Loading");
    for(int i=0; i<3; i++){
        printf(".");
        Sleep(300);
    }
    printf("\n");
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    waitMs(200);
}

int loadUsers(char users[][30]){
    FILE *fp = fopen("users.txt", "r");
    if(!fp) return 0;
    int count = 0;
    while(count<100 && fgets(users[count], 30, fp)){
        users[count][strcspn(users[count], "\r\n")]='\0';
        if(strlen(users[count]) > 0) count++;
    }
    fclose(fp);
    return count;
}

int saveUser(const char *username){
    FILE *fp = fopen("users.txt", "a");
    if(!fp) return -1;
    fprintf(fp, "%s\n", username);
    fclose(fp);
    return 0;
}

int loginMenu(char *currentUser){
    char users[100][30];
    int userCount = loadUsers(users);
    int choice;
    char temp[30];
    do{
        clearScreen();
        setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
        printf("-------------------------------------------------------\n");
		printf("                PuzzleHub Gaming Suite                 \n");
		printf("-------------------------------------------------------\n\n");
		setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("                    -:{ Login }:-                   \n\n");
        printf("Choose a User or create new one.\n\n");
        for(int i=0; i<userCount; i++){
            printf("    [%d] %s\n", i+1, users[i]);
        }
        printf("    [%d] Create New User\n", userCount+1);
        printf("    [0] Quit\n\n\n");
        printf("Enter: ");
        scanf("%d", &choice);
        getchar();
        if(choice == 0){
            return -1;
        }
		else if(choice == userCount+1){
            printf("\n\n----------------- Enter New Username ------------------\n\n=> ");
            fgets(temp, 30, stdin);
            temp[strcspn(temp, "\r\n")]='\0';
            if(strlen(temp) > 0){
                saveUser(temp);
                strcpy(currentUser, temp);
                char filename[64];
                sprintf(filename, "%s_scores.txt", temp);
                FILE *f = fopen(filename, "w");
                if(f){
                    fprintf(f, "Sudoku: 0\n");
                    fprintf(f, "MathSolver: 0\n");
                    fprintf(f, "TicTacToe: 0\n");
                    fprintf(f, "Wordle: 0\n");
                    fprintf(f, "Anagram: 0\n");
                    fprintf(f, "Riddle: 0\n");
                    fprintf(f, "Hangman: 0\n");
                    fclose(f);
                }
                return 0;
            }
        }
		else if(choice>0 && choice<=userCount){
            strcpy(currentUser, users[choice-1]);
            return 0;
        }
    } while(1);
}

void mainMenu(const char *user){
    int choice;
    do{
        clearScreen();
        setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("-------------------------------------------------------\n");
		printf("                PuzzleHub Gaming Suite                 \n");
		printf("-------------------------------------------------------\n\n");
		setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("                  -:{ Main Menu }:-                  \n\n");
        printf("User Signed in: %s\n\n", user);
		printf("    [1] Play \n");
        printf("    [2] Scores\n");
        printf("    [3] Credits\n");
        printf("    [4] Logout\n");
        printf("    [0] Quit\n\n\n");
        printf("Enter: ");
        scanf("%d", &choice);
        getchar();
        switch(choice){
            case 1: gamesMenu(user);  break;
            case 2: viewScores(user); break;
            case 3: creditsScreen();  break;
            case 4: return;
            case 0: exit(0);
            default:
                printf("Invalid choice!\n");
                waitMs(500);
        }
    } while(1);
}

void gamesMenu(const char *user){
    int choice;
    do{
        clearScreen();
        setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("-------------------------------------------------------\n");
		printf("                PuzzleHub Gaming Suite                 \n");
		printf("-------------------------------------------------------\n\n");
		setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("                  -:{ Game Menu }:-                  \n\n");
        printf("Select a game to play.\n\n");
        printf("    [1] Sudoku\n");
        printf("    [2] Math Eq Solver\n");
        printf("    [3] Tic Tac Toe\n");
        printf("    [4] Wordle\n");
        printf("    [5] Anagram Game\n");
        printf("    [6] Riddle Game\n");
        printf("    [7] Hangman\n");
        printf("    [8] View Leaderboards\n");
        printf("    [0] Back\n\n\n");
        printf("Enter: ");
        scanf("%d", &choice);
        getchar();
        if(choice>=1 && choice<=7){
        	clearScreen();
        	loadingScreenGame();
		}
        switch(choice){
            case 1: sudokuGame(user); break;
            case 2: mathSolverGame(user); break;
            case 3: ticTacToeGame(user); break;
            case 4: wordleGame(user); break;
            case 5: anagramGame(user); break;
            case 6: riddleGame(user); break;
            case 7: hangmanGame(user); break;
            case 8: viewLeaderboard(); break;
            case 0: return;
            default:
                printf("Invalid choice!\n");
                waitMs(500);
        }
    } while(1);
}

void viewScores(const char *user){
    clearScreen();
    char filename[64];
    sprintf(filename, "%s_scores.txt", user);
    FILE *fp = fopen(filename, "r");
    int sudoku = 0, wordle = 0, anagram = 0, riddle = 0, hangman = 0, tictactoe = 0, mathsolver = 0;
    if(!fp){
        printf("No scores available for %s.\n", user);
    }
	else{
        char line[128];
        while(fgets(line, sizeof(line), fp)){
            if(strncmp(line, "Sudoku: ", 8) == 0) sscanf(line + 8, "%d", &sudoku);
            else if(strncmp(line, "Wordle: ", 8) == 0) sscanf(line + 8, "%d", &wordle);
            else if(strncmp(line, "Anagram: ", 9) == 0) sscanf(line + 9, "%d", &anagram);
            else if(strncmp(line, "Riddle: ", 8) == 0) sscanf(line + 8, "%d", &riddle);
            else if(strncmp(line, "Hangman: ", 9) == 0) sscanf(line + 9, "%d", &hangman);
            else if(strncmp(line, "TicTacToe: ", 11) == 0) sscanf(line + 11, "%d", &tictactoe);
            else if(strncmp(line, "MathSolver: ", 12) == 0) sscanf(line + 12, "%d", &mathsolver);
        }
        fclose(fp);
        setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		printf("--------------------------------------\n");
		printf("         Scores for %s                \n", user);
		printf("--------------------------------------\n");
		setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("Sudoku:      %d\n", sudoku);
        printf("Wordle:      %d\n", wordle);
        printf("Anagram:     %d\n", anagram);
        printf("Riddle:      %d\n", riddle);
        printf("Hangman:     %d\n", hangman);
        printf("TicTacToe:   %d\n", tictactoe);
        printf("MathSolver:  %d\n", mathsolver);
    }
    printf("\nPress Enter to continue...");
    getchar();
}

void viewLeaderboard(){
    clearScreen();
    setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("--------------------------------------------------\n");
    printf("                    Leaderboard                   \n");
    printf("--------------------------------------------------\n\n");
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    const char *games[] = {"Sudoku", "MathSolver", "TicTacToe", "Wordle", "Anagram", "Riddle", "Hangman"};
    const int gameCount = sizeof(games)/sizeof(games[0]);
    struct{
        char name[32];
        int score;
    } topPlayers[7] = { {"", 0}, {"", 0}, {"", 0}, {"", 0}, {"", 0}, {"", 0}, {"", 0} };
    struct dirent *entry;
    DIR *dp = opendir(".");
    if(dp == NULL){
        printf("Unable to open directory.\n");
        printf("Press Enter to continue...");
        getchar();
        return;
    }
    while((entry = readdir(dp))){
        if(strstr(entry->d_name, "_scores.txt")){
            FILE *fp = fopen(entry->d_name, "r");
            if(fp){
                char line[128];
                while(fgets(line, sizeof(line), fp)){
                    for(int i=0; i<gameCount; i++){
                        char tag[20];
                        sprintf(tag, "%s: ", games[i]);
                        if(strncmp(line, tag, strlen(tag))==0){
                            int score;
                            sscanf(line + strlen(tag), "%d", &score);
                            if(score>topPlayers[i].score){
                                strncpy(topPlayers[i].name, entry->d_name, sizeof(topPlayers[i].name));
                                topPlayers[i].score = score;
                                topPlayers[i].name[strcspn(topPlayers[i].name, "_")]='\0';
                            }
                        }
                    }
                }
                fclose(fp);
            }
        }
    }
    closedir(dp);
    for(int i=0; i<gameCount; i++){
        printf("%-12s | %-12s | Score: %d\n", games[i], topPlayers[i].name[0] ? topPlayers[i].name : "N/A", topPlayers[i].score);
    }
    printf("\nPress Enter to continue...");
    getchar();
}


void creditsScreen(){
    clearScreen();
    printf("PuzzleHub v2.0\n");
    printf("Developed by Muhammad Ali Shahzad\n");
    printf("Student of COMSATS University Islamabad\n");
    waitMs(1500);
}

void sudokuGame(const char *user){
    clearScreen();
    setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("---------------------------------------------------------------\n");
	printf("                            Sudoku                             \n");
	printf("---------------------------------------------------------------\n\n");
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("HOW TO PLAY:\n");
    printf("- Fill the empty cells (shown as 0) with numbers from 1 to 9.\n");
    printf("- Each row, column, and 3x3 grid must contain all digits from 1 to 9.\n");
    printf("- Enter your move as: row col value (e.g., 0 2 5).\n");
    printf("- You have to fill 30 values.\n");
    printf("\nPress Enter to start...");
    getchar();
    int grid[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };
    int filled = 0, input, row, col;
    clock_t start = clock();
    while(filled < 30){
        clearScreen();
        setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    	printf("--------------------------------------------\n");
		printf("                Sudoku Board                \n");
		printf("--------------------------------------------\n\n");
		setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    	for(int i=0; i<9; i++){
            if(i%3==0 && i!=0) printf("------+-------+------\n");
            for(int j=0; j<9; j++){
                if(j%3==0 && j!=0) printf("| ");
                if(grid[i][j] == 0)
                    printf(". ");
                else
                    printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        printf("\nEnter row (0-8), col (0-8), and value (1-9): ");
        scanf("%d %d %d", &row, &col, &input);
        if(row>=0 && row<9 && col>=0 && col<9 && grid[row][col]==0 && input>=1 && input<=9){
            grid[row][col] = input;
            filled++;
        }
    }
    clock_t end = clock();
    int timeTaken = (int)((end - start)/CLOCKS_PER_SEC);
    int score = 1000 - timeTaken * 10;
    if(score < 0) score = 0;
    char filename[64];
    sprintf(filename, "%s_scores.txt", user);
    FILE *fp = fopen(filename, "r");
    int sudoku = 0, ttt = 0, math = 0, hangman = 0;
    if(fp){
        char line[100];
        while(fgets(line, sizeof(line), fp)){
            if(strncmp(line, "Sudoku: ", 8) == 0)
                sscanf(line+8, "%d", &sudoku);
            else if(strncmp(line, "TicTacToe: ", 11) == 0)
                sscanf(line+11, "%d", &ttt);
            else if(strncmp(line, "MathSolver: ", 12) == 0)
                sscanf(line+12, "%d", &math);
            else if(strncmp(line, "Hangman: ", 9) == 0)
                sscanf(line+9, "%d", &hangman);
        }
        fclose(fp);
    }
    if(score > sudoku) sudoku = score;
    fp = fopen(filename, "w");
    if(fp){
        fprintf(fp, "Sudoku: %d\n", sudoku);
        fprintf(fp, "TicTacToe: %d\n", ttt);
        fprintf(fp, "MathSolver: %d\n", math);
        fprintf(fp, "Hangman: %d\n", hangman);
        fclose(fp);
    }
    printf("\nGame complete! Your score: %d\n", score);
    printf("High score: %d\n", sudoku);
    printf("\nPress Enter to return to menu...");
    getchar(); getchar();
}

void mathSolverGame(const char *user){
    clearScreen();
    setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("----------------------------------------------------------\n");
	printf("                   Math Equation Solver                   \n");
	printf("----------------------------------------------------------\n");
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("\nHOW TO PLAY:\n");
    printf("- Solve 10 math problems as fast and accurately as you can.\n");
    printf("- Problems include +, -, *, and / (division has whole number answers).\n");
    printf("- Your score is based on speed and correct answers.\n");
    printf("\nPress Enter to start...");
    getchar();
    int correct = 0, total = 10;
    int a, b, answer, userAns;
    char op;
    srand(time(NULL));
    clock_t start = clock();
    for(int i=1; i<=total; i++){
        clearScreen();
        setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    	printf("------------------------------------------\n");
		printf("           Math Equation Solver           \n");
		printf("------------------------------------------\n");
		setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		op = "+-*/"[rand() % 4];
        a = rand() % 50 + 1;
        b = rand() % 50 + 1;
        if(op == '/'){
            answer = a;
            a = a * b;
        }
		else if(op == '-'){
            if(a < b){
                int temp = a;
                a = b;
                b = temp;
            }
        }
        switch (op){
            case '+': answer = a + b; break;
            case '-': answer = a - b; break;
            case '*': answer = a * b; break;
            case '/': answer = a / b; break;
        }
        printf("\nQ%d: %d %c %d = ", i, a, op, b);
        scanf("%d", &userAns);
        if(userAns == answer){
            printf("Correct!\n");
            correct++;
        } else {
            printf("Wrong! Correct answer: %d\n", answer);
        }
        waitMs(700);
    }
    clock_t end = clock();
    int timeTaken = (int)((end - start)/CLOCKS_PER_SEC);
    int score = correct * 100 - timeTaken * 5;
    if(score < 0) score = 0;
    char filename[64];
    sprintf(filename, "%s_scores.txt", user);
    FILE *fp = fopen(filename, "r");
    int sudoku = 0, ttt = 0, math = 0, hangman = 0;
    if(fp){
        char line[100];
        while(fgets(line, sizeof(line), fp)){
            if(strncmp(line, "Sudoku: ", 8)==0)
                sscanf(line+8, "%d", &sudoku);
            else if(strncmp(line, "TicTacToe: ", 11)==0)
                sscanf(line+11, "%d", &ttt);
            else if(strncmp(line, "MathSolver: ", 12)==0)
                sscanf(line+12, "%d", &math);
            else if(strncmp(line, "Hangman: ", 9)==0)
                sscanf(line+9, "%d", &hangman);
        }
        fclose(fp);
    }
    if(score > math) math = score;
    fp = fopen(filename, "w");
    if(fp){
        fprintf(fp, "Sudoku: %d\n", sudoku);
        fprintf(fp, "TicTacToe: %d\n", ttt);
        fprintf(fp, "MathSolver: %d\n", math);
        fprintf(fp, "Hangman: %d\n", hangman);
        fclose(fp);
    }
    printf("\nGame Over! Your score: %d\n", score);
    printf("High score: %d\n", math);
    printf("\nPress Enter to return to menu...");
    getchar(); getchar();
}

void ticTacToeGame(const char *user){
    typedef struct {
        char board[3][3];
        int score;
        char winner;
    } TicTacToe;
    TicTacToe game = {
        .board = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} },
        .score = 0,
        .winner = ' '
    };
    int move, turn = 0, filled = 0;
    char player = 'X', ai = 'O', input;
    clearScreen();
    setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("-----------------------------------------------------\n");
	printf("                     Tic Tac Toe                     \n");
	printf("-----------------------------------------------------\n");
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("\nYou are 'X' and AI is 'O'.\n\n");
    printf("Press Enter to start...");
    getchar();
    while(1){
        clearScreen();
        setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    	printf("-----------------------------------\n");
		printf("            Tic Tac Toe            \n");
		printf("-----------------------------------\n");
		setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		printf("\nYou (X) vs AI (O)\n\n");
        for(int i=0; i<3; i++){
            printf(" %c | %c | %c\n", game.board[i][0], game.board[i][1], game.board[i][2]);
            if(i<2) printf("---+---+---\n");
        }
        if(turn % 2 == 0){
            printf("\nYour move (1-9): ");
            scanf(" %c", &input);
            int placed = 0;
            for(int i=0; i<3 && !placed; i++){
                for(int j=0; j<3; j++){
                    if(game.board[i][j] == input){
                        game.board[i][j] = player;
                        placed = 1;
                        filled++;
                        break;
                    }
                }
            }
            if(!placed){
                printf("Invalid move!\n");
                waitMs(800);
                continue;
            }
        }
		else{
            int done = 0;
            for(int i=0; i<3 && !done; i++){
                for(int j=0; j<3; j++){
                    if(game.board[i][j] != player && game.board[i][j] != ai){
                        game.board[i][j] = ai;
                        filled++;
                        done = 1;
                        break;
                    }
                }
            }
        }
        for(int i=0; i<3; i++){
            if((game.board[i][0]==game.board[i][1] && game.board[i][1]==game.board[i][2]) ||
			   (game.board[0][i]==game.board[1][i] && game.board[1][i]==game.board[2][i]))
                goto END;
        }
        if((game.board[0][0]==game.board[1][1] && game.board[1][1]==game.board[2][2]) ||
           (game.board[0][2]==game.board[1][1] && game.board[1][1]==game.board[2][0]))
            goto END;
        if(filled == 9) break;
        turn++;
    }
END:
    clearScreen();
    setColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    printf("-----------------------------------\n");
	printf("            Tic Tac Toe            \n");
	printf("-----------------------------------\n\n");
	setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	for(int i=0; i<3; i++){
        printf(" %c | %c | %c\n", game.board[i][0], game.board[i][1], game.board[i][2]);
        if(i<2) printf("---+---+---\n");
    }
    for(int i=0; i<3; i++){
        if(game.board[i][0]==game.board[i][1] && game.board[i][1]==game.board[i][2]) game.winner = game.board[i][0];
        if(game.board[0][i]==game.board[1][i] && game.board[1][i]==game.board[2][i]) game.winner = game.board[0][i];
    }
    if(game.board[0][0]==game.board[1][1] && game.board[1][1]==game.board[2][2]) game.winner = game.board[0][0];
    if(game.board[0][2]==game.board[1][1] && game.board[1][1]==game.board[2][0]) game.winner = game.board[0][2];
    if(game.winner == player){
        printf("\nYou win!\n");
        game.score = 100;
    }
	else if(game.winner == ai){
        printf("\nAI wins. Try again!\n");
    }
	else{
        printf("\nIt's a draw.\n");
        game.score = 50;
    }
    char filename[64];
    sprintf(filename, "%s_scores.txt", user);
    FILE *fp = fopen(filename, "r");
    int sudoku = 0, math = 0, ttt = 0, hangman = 0;
    if(fp){
        char line[100];
        while(fgets(line, sizeof(line), fp)){
            if(strncmp(line, "Sudoku: ", 8) == 0) sscanf(line+8, "%d", &sudoku);
            else if(strncmp(line, "MathSolver: ", 12) == 0) sscanf(line+12, "%d", &math);
            else if(strncmp(line, "TicTacToe: ", 11) == 0) sscanf(line+11, "%d", &ttt);
            else if(strncmp(line, "Hangman: ", 9) == 0) sscanf(line+9, "%d", &hangman);
        }
        fclose(fp);
    }
    if(game.score > ttt) ttt = game.score;
    fp = fopen(filename, "w");
    if(fp){
        fprintf(fp, "Sudoku: %d\n", sudoku);
        fprintf(fp, "MathSolver: %d\n", math);
        fprintf(fp, "TicTacToe: %d\n", ttt);
        fprintf(fp, "Hangman: %d\n", hangman);
        fclose(fp);
    }
    printf("Your score: %d | High score: %d\n", game.score, ttt);
    printf("\nPress Enter to return to menu...");
    getchar(); getchar();
}

void wordleGame(const char *user){
    clearScreen();
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("----------------------------------------------------\n");
    printf("                       Wordle                       \n");
    printf("----------------------------------------------------\n\n");
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("HOW TO PLAY:\n");
    printf("- Guess the 5-letter secret word within 6 tries.\n");
    printf("- Green = correct letter and position\n");
    printf("- Yellow = correct letter, wrong position\n");
    printf("- Gray = wrong letter\n");
    printf("\nPress Enter to start...");
    getchar();
    const char *wordList[] = {"CRANE", "PLANT", "BRICK", "SHEET", "GHOST", "BLAST"};
    const int WORD_COUNT = sizeof(wordList) / sizeof(wordList[0]);
    char secret[6];
    strcpy(secret, wordList[rand() % WORD_COUNT]);
    char guesses[6][6] = {{0}};
    int attempts = 0;
    int won = 0;
    while(attempts<6 && !won){
        clearScreen();
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("--------------------------------------\n");
        printf("                Wordle                \n");
        printf("--------------------------------------\n");
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        for(int i=0; i<6; i++){
            for(int j=0; j<5; j++){
                char display = guesses[i][j] ? guesses[i][j] : ' ';
                WORD color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
                if(guesses[i][j]){
                    if(guesses[i][j] == secret[j]){
                        color = BACKGROUND_GREEN | FOREGROUND_INTENSITY;
                    }
					else{
                        int found = 0;
                        for(int k=0; k<5; k++){
                            if(guesses[i][j] == secret[k]){
                                found = 1;
                                break;
                            }
                        }
                        color = found ? BACKGROUND_RED | BACKGROUND_GREEN : 0;
                    }
                }
                setColor(color | FOREGROUND_INTENSITY);
                printf(" [%c] ", display);
                setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            }
            printf("\n\n");
        }
        if(won || attempts == 6) break;
        char input[10];
        printf("Enter guess %d (5-letter word): ", attempts + 1);
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\r\n")]='\0';
        if(strlen(input) != 5){
            printf("Invalid input. Try a 5-letter word.\n");
            waitMs(1000);
            continue;
        }
        for(int i=0; i<5; i++){
            guesses[attempts][i] = toupper(input[i]);
        }
        if(strncmp(guesses[attempts], secret, 5)==0){
            won = 1;
        }
        attempts++;
    }
    clearScreen();
    if(won){
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("--------------------------------------\n");
        printf("                Wordle                \n");
        printf("--------------------------------------\n");
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("\nCongratulations! You guessed it in %d tries!\n", attempts);
    }
	else{
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("--------------------------------------\n");
        printf("                Wordle                \n");
        printf("--------------------------------------\n");
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("\nSorry, the word was: %s\n", secret);
    }
    int score = won ? (700 - attempts * 100) : 0;
    char filename[64];
    sprintf(filename, "%s_scores.txt", user);
    FILE *fp = fopen(filename, "r");
    int sudoku = 0, math = 0, ttt = 0, hangman = 0, wordle = 0;
    if(fp){
        char line[100];
        while(fgets(line, sizeof(line), fp)){
            if(strncmp(line, "Sudoku: ", 8) == 0) sscanf(line+8, "%d", &sudoku);
            else if(strncmp(line, "MathSolver: ", 12) == 0) sscanf(line+12, "%d", &math);
            else if(strncmp(line, "TicTacToe: ", 11) == 0) sscanf(line+11, "%d", &ttt);
            else if(strncmp(line, "Hangman: ", 9) == 0) sscanf(line+9, "%d", &hangman);
            else if(strncmp(line, "Wordle: ", 8) == 0) sscanf(line+8, "%d", &wordle);
        }
        fclose(fp);
    }
    if (score > wordle) wordle = score;
    fp = fopen(filename, "w");
    if(fp){
        fprintf(fp, "Sudoku: %d\n", sudoku);
        fprintf(fp, "MathSolver: %d\n", math);
        fprintf(fp, "TicTacToe: %d\n", ttt);
        fprintf(fp, "Hangman: %d\n", hangman);
        fprintf(fp, "Wordle: %d\n", wordle);
        fclose(fp);
    }
    printf("Your score: %d\n", score);
    printf("High score: %d\n", wordle);
    printf("\nPress Enter to return to menu...");
    getchar();
}

void anagramGame(const char *user){
    clearScreen();
    setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("----------------------------------------------------\n");
    printf("                    Anagram Game                    \n");
    printf("----------------------------------------------------\n\n");
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("HOW TO PLAY:\n");
    printf("- A scrambled word (anagram) will be shown.\n");
    printf("- You have 3 chances to guess the original word.\n");
    printf("- Each correct guess gives you 100 points.\n");
    printf("\nPress Enter to start...");
    getchar();
    const char *wordList[] = {"APPLE", "BRAVE", "CRANE", "PLANT", "STONE", "MOUSE", "LEMON", "TRAIN"};
    const int wordCount = sizeof(wordList) / sizeof(wordList[0]);
    char word[16], scrambled[16], guess[16];
    int score = 0;
    while(1){
        strcpy(word, wordList[rand() % wordCount]);
        strcpy(scrambled, word);
        for(int i=0; i<5; i++){
            int j = rand() % 5;
            char temp = scrambled[i];
            scrambled[i] = scrambled[j];
            scrambled[j] = temp;
        }
        clearScreen();
        setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("----------------------------------------\n");
        printf("              Anagram Game              \n");
        printf("----------------------------------------\n");
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("Scrambled word: %s\n", scrambled);
        int attempts = 3;
        int correct = 0;
        while(attempts > 0){
            printf("Guess the word (%d attempts left): ", attempts);
            fgets(guess, sizeof(guess), stdin);
            guess[strcspn(guess, "\r\n")]='\0';
            for (int i = 0; guess[i]; i++) guess[i] = toupper(guess[i]);
            if(strcmp(guess, word) == 0){
                printf("Correct!\n");
                score += 100;
                correct = 1;
                break;
            }
			else{
                printf("Wrong!\n");
                attempts--;
            }
        }
        if(!correct){
            printf("The word was: %s\n", word);
        }
        printf("\nCurrent Score: %d\n", score);
        printf("Do you want to play another round? (y/n): ");
        char ch = getchar();
        getchar();
        if(ch!='y' && ch!='Y') break;
    }
    char filename[64];
    sprintf(filename, "%s_scores.txt", user);
    int sudoku = 0, math = 0, ttt = 0, hangman = 0, wordle = 0, anagram = 0;
    FILE *fp = fopen(filename, "r");
    if(fp){
        char line[100];
        while(fgets(line, sizeof(line), fp)){
            if(strncmp(line, "Sudoku: ", 8) == 0) sscanf(line+8, "%d", &sudoku);
            else if(strncmp(line, "MathSolver: ", 12) == 0) sscanf(line+12, "%d", &math);
            else if(strncmp(line, "TicTacToe: ", 11) == 0) sscanf(line+11, "%d", &ttt);
            else if(strncmp(line, "Hangman: ", 9) == 0) sscanf(line+9, "%d", &hangman);
            else if(strncmp(line, "Wordle: ", 8) == 0) sscanf(line+8, "%d", &wordle);
            else if(strncmp(line, "Anagram: ", 9) == 0) sscanf(line+9, "%d", &anagram);
        }
        fclose(fp);
    }
    if(score > anagram) anagram = score;
    fp = fopen(filename, "w");
    if(fp){
        fprintf(fp, "Sudoku: %d\n", sudoku);
        fprintf(fp, "MathSolver: %d\n", math);
        fprintf(fp, "TicTacToe: %d\n", ttt);
        fprintf(fp, "Hangman: %d\n", hangman);
        fprintf(fp, "Wordle: %d\n", wordle);
        fprintf(fp, "Anagram: %d\n", anagram);
        fclose(fp);
    }
    printf("Final Score: %d\n", score);
    printf("High Score: %d\n", anagram);
    printf("\nPress Enter to return to menu...");
    getchar();
}

void riddleGame(const char *user){
    clearScreen();
    setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    printf("-------------------------------------------------------------\n");
    printf("                         Riddle Game                         \n");
    printf("-------------------------------------------------------------\n\n");
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("HOW TO PLAY:\n");
    printf("- A riddle will be shown and you must type the correct answer.\n");
    printf("- Each correct answer gives 50 points.\n");
    printf("- Type 'skip' to move to the next riddle.\n");
    printf("- Type 'quit' to end the game.\n");
    printf("\nPress Enter to start...");
    getchar();
    typedef struct{
        char question[200];
        char answer[100];
    } Riddle;
    FILE *fp = fopen("riddles.txt", "r");
    if(!fp){
        printf("Riddle file not found!\n");
        printf("Make sure 'riddles.txt' exists in the same folder.\n");
        printf("Press Enter to return...");
        getchar();
        return;
    }
    char line[256], userInput[100];
    int score = 0;
    Riddle r;
    while(fgets(line, sizeof(line), fp)){
        char *sep = strchr(line, '|');
        if(!sep) continue;
        *sep = '\0';
        strcpy(r.question, line);
        strcpy(r.answer, sep+1);
        r.answer[strcspn(r.answer, "\r\n")]='\0';
        clearScreen();
        setColor(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        printf("-----------------------------------------------\n");
        printf("                  Riddle Game                  \n");
        printf("-----------------------------------------------\n");
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        printf("\nRiddle: %s\n", r.question);
        printf("Your answer: ");
        fgets(userInput, sizeof(userInput), stdin);
        userInput[strcspn(userInput, "\r\n")]='\0';
        for(int i=0; userInput[i]; i++) userInput[i] = tolower(userInput[i]);
        for(int i=0; r.answer[i]; i++) r.answer[i] = tolower(r.answer[i]);
        if(strcmp(userInput, "quit")==0) break;
        if(strcmp(userInput, r.answer)==0){
            printf("\nCorrect!\n");
            score += 50;
        }
		else if(strcmp(userInput, "skip")==0){
            printf("Skipped!\n");
        }
		else{
            printf("\nWrong! Correct answer: %s\n", r.answer);
        }
        printf("Current score: %d\n", score);
        printf("Press Enter to continue...");
        getchar();
    }
    fclose(fp);
    char filename[64];
    sprintf(filename, "%s_scores.txt", user);
    int sudoku = 0, wordle = 0, anagram = 0, hangman = 0, math = 0, ttt = 0, riddle = 0;
    fp = fopen(filename, "r");
    if(fp){
        while(fgets(line, sizeof(line), fp)){
            if(strncmp(line, "Sudoku: ", 8) == 0) sscanf(line+8, "%d", &sudoku);
            else if(strncmp(line, "Wordle: ", 8) == 0) sscanf(line+8, "%d", &wordle);
            else if(strncmp(line, "Anagram: ", 9) == 0) sscanf(line+9, "%d", &anagram);
            else if(strncmp(line, "Hangman: ", 9) == 0) sscanf(line+9, "%d", &hangman);
            else if(strncmp(line, "MathSolver: ", 12) == 0) sscanf(line+12, "%d", &math);
            else if(strncmp(line, "TicTacToe: ", 11) == 0) sscanf(line+11, "%d", &ttt);
            else if(strncmp(line, "Riddle: ", 8) == 0) sscanf(line+8, "%d", &riddle);
        }
        fclose(fp);
    }
    if(score > riddle) riddle = score;
    fp = fopen(filename, "w");
    if(fp){
        fprintf(fp, "Sudoku: %d\n", sudoku);
        fprintf(fp, "MathSolver: %d\n", math);
        fprintf(fp, "TicTacToe: %d\n", ttt);
        fprintf(fp, "Hangman: %d\n", hangman);
        fprintf(fp, "Wordle: %d\n", wordle);
        fprintf(fp, "Anagram: %d\n", anagram);
        fprintf(fp, "Riddle: %d\n", riddle);
        fclose(fp);
    }
    printf("\nFinal Score: %d\n", score);
    printf("High Score: %d\n", riddle);
    printf("\nPress Enter to return to menu...");
    getchar();
}

void drawHangman(int attemptsLeft){
    int stage = 6 - attemptsLeft;
    const char *stages[] = {
        "  +---+\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "      |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        "  |   |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|   |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " /    |\n"
        "      |\n"
        "=========\n",

        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        " / \\  |\n"
        "      |\n"
        "=========\n"
    };
    printf("%s", stages[stage]);
}

void hangmanGame(const char *user){
    typedef struct {
        const char *word;
        char guessed[20];
        char display[20];
        int len;
        int correct;
        int attemptsLeft;
        int score;
    } HangmanGame;
    clearScreen();
    setColor(FOREGROUND_RED | FOREGROUND_GREEN);
    printf("-----------------------------------------------------\n");
    printf("                       Hangman                       \n");
    printf("-----------------------------------------------------\n\n");
    setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
    printf("HOW TO PLAY:\n");
    printf("- Try to guess the hidden word one letter at a time.\n");
    printf("- You have 6 incorrect guesses before the man is hanged.\n");
    printf("- Correct guesses will reveal letters in the word.\n");
    printf("- Incorrect guesses draw parts of the hangman figure.\n");
    printf("- If you guess the word before running out of attempts, you win!\n");
    printf("\nPress Enter to begin...");
    getchar();
    srand(time(NULL));
    const char *words[] = {"banana", "puzzle", "rocket", "laptop", "planet"};
    const int wordCount = sizeof(words)/sizeof(words[0]);
    HangmanGame game;
    game.word = words[rand() % wordCount];
    game.len = strlen(game.word);
    game.guessed[0] = '\0';
    game.correct = 0;
    game.attemptsLeft = 6;
    game.score = 0;

    for(int i=0; i<game.len; i++){
        game.display[i] = '_';
    }
    game.display[game.len] = '\0';
    while(game.attemptsLeft>0 && game.correct<game.len){
        clearScreen();
        setColor(FOREGROUND_RED | FOREGROUND_GREEN);
        printf("-------------------------------------\n");
        printf("               Hangman               \n");
        printf("-------------------------------------\n");
        setColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
        drawHangman(game.attemptsLeft);
        printf("\nWord: ");
        for (int i = 0; i < game.len; i++) {
            printf("%c ", game.display[i]);
        }
        printf("\n\nAttempts Left: %d\n", game.attemptsLeft);
        printf("Guessed: %s\n", game.guessed);
        printf("\nEnter a letter: ");
        char input = getchar();
        getchar();
        if(strchr(game.guessed, input)){
            printf("You already guessed '%c'. Try another letter.\n", input);
            waitMs(1000);
            continue;
        }
        strncat(game.guessed, &input, 1);
        int found = 0;
        for(int i=0; i<game.len; i++){
            if (game.word[i] == input && game.display[i] == '_'){
                game.display[i] = input;
                game.correct++;
                found = 1;
            }
        }
        if(!found){
            game.attemptsLeft--;
        }
    }
    clearScreen();
    if(game.correct == game.len){
        printf("Congratulations! You guessed the word: %s\n", game.word);
        game.score = 100 + game.attemptsLeft * 10;
    }
	else{
        printf("Game Over! The word was: %s\n", game.word);
        game.score = game.correct * 10;
    }
    int sudoku = 0, wordle = 0, anagram = 0, riddle = 0, math = 0, ttt = 0, hangman = 0;
    char line[100], filename[64];
    sprintf(filename, "%s_scores.txt", user);
    FILE *f = fopen(filename, "r");
    if(f){
        while (fgets(line, sizeof(line), f)) {
            if(strncmp(line, "Sudoku: ", 8)==0) sscanf(line+8, "%d", &sudoku);
            else if(strncmp(line, "Wordle: ", 8)==0) sscanf(line+8, "%d", &wordle);
            else if(strncmp(line, "Anagram: ", 9)==0) sscanf(line+9, "%d", &anagram);
            else if(strncmp(line, "Riddle: ", 8)==0) sscanf(line+8, "%d", &riddle);
            else if(strncmp(line, "MathSolver: ", 12)==0) sscanf(line+12, "%d", &math);
            else if(strncmp(line, "TicTacToe: ", 11)==0) sscanf(line+11, "%d", &ttt);
            else if(strncmp(line, "Hangman: ", 9)==0) sscanf(line+9, "%d", &hangman);
        }
        fclose(f);
    }
    if(game.score > hangman) hangman = game.score;
    f = fopen(filename, "w");
    if(f){
        fprintf(f, "Sudoku: %d\n", sudoku);
        fprintf(f, "MathSolver: %d\n", math);
        fprintf(f, "TicTacToe: %d\n", ttt);
        fprintf(f, "Hangman: %d\n", hangman);
        fprintf(f, "Wordle: %d\n", wordle);
        fprintf(f, "Anagram: %d\n", anagram);
        fprintf(f, "Riddle: %d\n", riddle);
        fclose(f);
    }
    printf("\nYour Score: %d\n", game.score);
    printf("High Score: %d\n", hangman);
    printf("\nPress Enter to return...");
    getchar();
}

