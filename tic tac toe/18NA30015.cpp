#include <iostream>

using namespace std;


//function declaration
void printstate(char array[3][3]); //to print state of game
void cpu_tactics(char array[3][3], int a); //Tactics of CPU to avoid loss and attempt victory whenever possible
int result(char array[3][3],int x);//To find the winner of game
void inversion(char array[3][3]); // To make player one 'X' and player 2 'o' always


int main() {

    int games=1; //To allow user to play multiple games.

    cout << "\n";
    cout << "        ________________________"<<endl;
    cout << "       |________________________|"<<endl;
    cout << "       |    TIC-TAC-TOE GAME    |"<<endl;
    cout << "       |________________________|"<<endl;
    cout << "       |________________________|"<<endl;
    cout <<"\n";

    cout << "player1 [X] player2 [o]\n"<<endl;

    while(games==1) {

        char tic[3][3]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}}; //2D array to store game
        int turn,position,win=0,user_position;

        cout << "Which player you want to be (enter 1 or 2) : " << endl;
        cin >> turn; //player 1 or 2
        cin.clear(); //Just in case user enter non int type value which gives error because of turn variable declared of type int
        cin.ignore();// so to handle this these two functions are used. These are two inbuilt cin functions to reset error flag.


        // if user is first player
        if (turn == 1) {
            // Game runs until no result. Win store info of result
            //win is changed by result functions because of pass by reference of win variable
            while (win == 0) {
                cout << "Enter position : ";
                cin >> position; //User position
                cin.clear();
                cin.ignore();
                user_position = position;
                cout << "\n";

                //To change user entered position to 2-D array position
                if (position <= 3) {
                    //Only entry at free position allowed
                    if (tic[0][position - 1] == ' ') {
                        tic[0][position - 1] = 'X';
                        printstate(tic);//print game state after user's entry
                    } else {
                        cout << "Position not free. Please select different location\n" << endl;
                        continue;
                    }
                }


                else if (position >= 4 && position <= 6) {
                    if (tic[1][position - 4] == ' ') {
                        tic[1][position - 4] = 'X';
                        printstate(tic);
                    } else {
                        cout << "Position not free. Please select different location\n" << endl;
                        continue;
                    }
                }


                else if (position >= 7 && position <= 9) {
                    if (tic[2][position - 7] == ' ') {
                        tic[2][position - 7] = 'X';
                        printstate(tic);
                    } else {
                        cout << "Position not free. Please select different location\n" << endl;
                        continue;
                    }
                }

                //Out of range position
                else {
                    cout << "Please enter empty position from 1 to 9 only\n\n";
                    continue;
                }


                win = result(tic, win);//To check if user won or not or match is drawn
                if (win==0) {
                    cout << "CPU is making it's move................" << endl;
                    cpu_tactics(tic, user_position); // CPU's use its tactics
                    printstate(tic);//print state of game after CPU's turn
                    win = result(tic, win); //Once again check that if CPU can win on not or match is drawn
                }

            }

        }


        // IF user select to be second player

        else if (turn == 2) {

            // here 'o' is used for player1 (CPU) just in code
            //While printing we will change 'o' to 'X' i.e. now player1(CPU) has 'X'.

            char reverse[3][3]; // to manipulate game state data
            tic[0][0] = 'o';//fixed initial move by cpu

            // we do all operations on tic array but print its copy reverse array where 'X' is replaced by 'o' and 'o' by 'X'.
            // to make 'X' for player 1 and 'o' for player 2
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j <3 ; ++j) {
                    reverse[i][j] = tic[i][j];
                }
            }

             // we use reverse array and inversion function to make cpu 'X' and player 'o'

            inversion(reverse);

            cout << "CPU is making initial move...........\n";

            printstate(reverse); // only printstate function use reverse array .

            //Game progress until result
            while (win == 0) {

                //User's entry in game
                cout << "Enter position : ";
                cin >> position;
                cin.clear();
                cin.ignore();
                user_position = position;
                cout << "\n";

                //Change user position to position in 2-D array
                if (position <= 3) {
                    if (tic[0][position - 1] == ' ') {
                        tic[0][position - 1] = 'X';
                    } else {
                        cout << "Position not free. Please select different location\n" << endl;
                        continue;
                    }
                }

                else if (position >= 4 && position <= 6) {
                    if (tic[1][position - 4] == ' ') {
                        tic[1][position - 4] = 'X';
                    } else {
                        cout << "Position not free. Please select different location\n" << endl;
                        continue;
                    }
                }

                else if (position >= 7 && position <= 9) {
                    if (tic[2][position - 7] == ' ') {
                        tic[2][position - 7] = 'X';
                    } else {
                        cout << "Position not free. Please select different location\n" << endl;
                        continue;
                    }
                }

                else {
                    cout << "Please enter empty position from 1 to 9 only\n\n";
                    continue;
                }

                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j <3 ; ++j) {
                        reverse[i][j] = tic[i][j];
                    }
                }

                inversion(reverse); // interchanging 'X' and 'o'.

                printstate(reverse);

                win = result(tic, win); //Check win
                cout << "CPU is making its move ...."<<endl;
                cpu_tactics(tic, user_position); // Cpu attempt to win

                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j <3 ; ++j) {
                        reverse[i][j] = tic[i][j];
                    }
                }

                inversion(reverse);
                // copy elements of tic array in reverse array.

                if (win==0) {
                    printstate(reverse); //print game state after inversion.
                    win = result(tic, win); // check if anyone won or not or its a draw
                }

                // cpu_tactics and result function operates on tic array
                // while printstate will operate on reverse array after inversion function

            }


        }


        else {
            cout << "Invalid turn. Please select either 1 or 2\n\n";
            continue; // Take input until valid turn is not entered
        }

        cout << "If you want to play another game please press 1 else press any other key to end game.\n";
        cin >>games;
        //Ask user for another game
    }

    return 0;

}


// function definition


void printstate(char array[3][3]){

    // To print the game's current state
    cout <<"The current state of game is  : "<<endl;
    //2 for loops to print 2-D array
    for (int i = 0; i <3 ; ++i) {
        for (int j = 0; j <3 ; ++j) {
            if(j==2) {
                cout << "| " << array[i][j] << " |";
            }
            else{
                cout << "| " << array[i][j] << " ";
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

void cpu_tactics(char array[3][3], int a){

    int move = 0; // To find that CPU made a move or not
    int counter = 0; // to find empty positions

    for (int i = 0; i <3 ; ++i) {
        for (int j = 0; j <3 ; ++j) {
            if (array[i][j]==' '){
                counter++;
            }
        }
    }

    if(array[1][1]==' '  && counter ==8){
        array[1][1]='o' ; // CPU will go for position 5 for first move provided its free.
        move++;
        //Special case
        //TO boost chance of win
    }

    else if(array[0][0]==' '  && counter == 8){
        array[0][0]='o' ; // CPU will go for position 1 if first move by player is 5.
        move++;
        //Special case
        //TO boost chance of win
    }

    //Then CPU use these tactics to attempt possible win
    else {
        for (int i = 0; i < 3; ++i) {
            //Conditions when CPU can win

            //Two 'o' and one ' ' horizontally
            if (array[i][0] == 'o' && array[i][1]=='o' && array[i][2]==' '){
                array[i][2]='o';
                move++;
                break;
            }
            else if(array[i][1] == 'o' && array[i][2]=='o'&& array[i][0]==' '){
                array[i][0]='o';
                move++;break;
            }
            else if(array[i][0] == 'o' && array[i][2]=='o'&& array[i][1]==' '){
                array[i][1]='o';
                move++;break;
            }

                //Two 'o' and one ' ' vertically
            else if (array[0][i] == 'o' && array[1][i]=='o'&& array[2][i]==' '){
                array[2][i]='o';
                move++;break;
            }
            else if (array[0][i] == 'o' && array[2][i]=='o'&& array[1][i]==' '){
                array[1][i]='o';
                move++;break;
            }
            else if (array[2][i] == 'o' && array[1][i]=='o'&& array[0][i]==' '){
                array[0][i]='o';
                move++;break;
            }

            //Two 'o' and one ' ' diagonally
            else if (array[2][2] == 'o' && array[1][1]=='o'&& array[0][0]==' '){
                array[0][0]='o';
                move++;break;
            }
            else if (array[2][2] == 'o' && array[1][1]==' '&& array[0][0]=='o'){
                array[1][1]='o';
                move++;break;
            }
            else if (array[2][2] == ' ' && array[1][1]=='o'&& array[0][0]=='o'){
                array[2][2]='o';
                move++;break;
            }
            else if (array[0][2] == 'o' && array[1][1]=='o'&& array[2][0]==' '){
                array[2][0]='o';
                move++;break;
            }
            else if (array[0][2] == 'o' && array[1][1]==' '&& array[2][0]=='o'){
                array[1][1]='o';
                move++;break;
            }
            else if (array[0][2] == ' ' && array[1][1]=='o'&& array[2][0]=='o'){
                array[0][2]='o';
                move++;break;
            }
        }


        for (int i = 0; i <3 ; ++i) {

            // Same cases to block player's victory.

            if (move == 0) {
                if (array[i][0] == 'X' && array[i][1] == 'X' && array[i][2] == ' ') {
                    array[i][2] = 'o';
                    move++;
                    break;
                } else if (array[i][1] == 'X' && array[i][2] == 'X' && array[i][0] == ' ') {
                    array[i][0] = 'o';
                    move++;
                    break;
                } else if (array[i][0] == 'X' && array[i][2] == 'X' && array[i][1] == ' ') {
                    array[i][1] = 'o';
                    move++;
                    break;
                } else if (array[0][i] == 'X' && array[1][i] == 'X' && array[2][i] == ' ') {
                    array[2][i] = 'o';
                    move++;
                    break;
                } else if (array[0][i] == 'X' && array[2][i] == 'X' && array[1][i] == ' ') {
                    array[1][i] = 'o';
                    move++;
                    break;
                } else if (array[2][i] == 'X' && array[1][i] == 'X' && array[0][i] == ' ') {
                    array[0][i] = 'o';
                    move++;
                    break;
                } else if (array[2][2] == 'X' && array[1][1] == 'X' && array[0][0] == ' ') {
                    array[0][0] = 'o';
                    move++;
                    break;
                } else if (array[2][2] == 'X' && array[1][1] == ' ' && array[0][0] == 'X') {
                    array[1][1] = 'o';
                    move++;
                    break;
                } else if (array[2][2] == ' ' && array[1][1] == 'X' && array[0][0] == 'X') {
                    array[2][2] = 'o';
                    move++;
                    break;
                } else if (array[0][2] == 'X' && array[1][1] == 'X' && array[2][0] == ' ') {
                    array[2][0] = 'o';
                    move++;
                    break;
                } else if (array[0][2] == 'X' && array[1][1] == ' ' && array[2][0] == 'X') {
                    array[1][1] = 'o';
                    move++;
                    break;
                } else if (array[0][2] == ' ' && array[1][1] == 'X' && array[2][0] == 'X') {
                    array[0][2] = 'o';
                    move++;
                    break;
                }
            }
        }

    }


    //if none of above conditions satisfied
    if(move==0){
        // a is last entered position by user
        //Normally CPU occupy adjacent position to user's last entered position in same row
        if (a%3==0 && array[a/3 - 1][1]==' '){
            array[a/3 - 1][1]='o';
        }
        else if(a%3!=0 && array[a/3][a%3]==' ') {
            array[a/3][a%3] = 'o';
        }

        //If no position is empty in same row
        else{
            int brk =0;//same as move variable declared before

            for (int i = 0; i <3 ; ++i) {
                for (int j = 0; j <3 ; ++j) {
                    //In this case CPU make move vertically adjacent to 'o' to have winning chances

                  if(array[i][j]=='o' && brk==0){
                      if ((i==0 || i==1)&&array[i + 1][j] == ' ') {
                          array[i + 1][j] = 'o';
                          brk++;
                      }
                      else if (i==2&&array[i - 1][j] == ' '){
                          array[i - 1][j] = 'o';
                          brk++;
                      }

                  }

                }
                if(brk>0){
                    break;
                }
            }

            // if all the cases are unavailable then make move at first empty position
            // Anyways this won't happen
            if (brk == 0 ){
                for (int i = 0; i <3 ; ++i) {
                    for (int j = 0; j <3 ; ++j) {
                        if (array[i][j]==' ' && brk==0){
                            array[i][j] = 'o';
                            brk++;
                        }
                    }
                }
            }

        }

    }

}

int result(char array[3][3],int x){

    //All the cases of victory for both players.
    for (int i = 0; i < 3; ++i) {
            if (array[i][0]=='o' && array[i][1]=='o' && array[i][2]=='o'){
                cout << "CPU won\n\n";
                x = 2; //x=2 is condition to terminate current session of game with a result
                break; //breaks out of loop
            }
            else if ((array[i][0]=='X' && array[i][1]=='X' && array[i][2]=='X')){
                cout << "You won\n\n"; // cpu_tactics function will make sure that these condition where user win will never occur.
                x = 2;
                break;
            }
            else if((array[0][i]=='X' && array[1][i]=='X' && array[2][i]=='X')){
                cout << "You won\n\n";
                x = 2;
                break;
            }
            else if((array[0][i]=='o' && array[1][i]=='o' && array[2][i]=='o')){
                cout << "CPU won\n\n";
                x = 2;
                break;
            }
            else if((array[1][1]=='o' && array[0][0]=='o' && array[2][2]=='o')){
                cout<< "CPU won\n\n";
                x = 2;
                break;
            }
            else if((array[1][1]=='X' && array[0][0]=='X' && array[2][2]=='X')){
                cout<< "You won\n\n";
                x = 2;
                break;
            }
            else if((array[1][1]=='o' && array[0][2]=='o' && array[2][0]=='o')){
                cout<< "CPU won\n\n";
                x = 2;
                break;
            }
            else if((array[1][1]=='X' && array[0][2]=='X' && array[2][0]=='X')){
                cout<< "You won\n\n";
                x =2;
                break;
            }
    }

    //Draw when board fills completely before any player's victory
    int draw = 0; //filled places counter
    for (int j = 0; j <3 ; ++j) {
        for (int i = 0; i <3 ; ++i) {
            if (array[j][i]!=' '){
                draw++; //places filled
            }
        }
    }

    //All places filled and none is victorious
    if(draw==9 && x!=2){
        x = 2; //Terminate games with result draw
        cout << "Match draw\n\n";
    }

    return x;

}

void inversion(char array[3][3]){

    // we are replacing 'o' by 'X' so that it will not needed to write different functions when user is player 1 or 2

    for (int i = 0; i <3 ; ++i) {
        for (int j = 0; j <3 ; ++j) {
            if (array[i][j]=='o'){
                array[i][j] = 'X';
            }
            else if (array[i][j] == 'X'){
                array[i][j] = 'o';
            }
        }
    }
}
