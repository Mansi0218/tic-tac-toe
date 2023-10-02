#include <iostream>
#include <stdlib.h>

using namespace std;

char space[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int choice;
int row, column;
char turn = 'X';
bool draw=false;

 //variable to enter player name
    string n1="";
    string n2="";

void DisplayBoard(){

    //structure of tic-tac-toe
    cout<<"\n\n\n";
    cout<<"        |       |        \n";
    cout<<"    "<<space[0][0]<<"   |"<<"   "<<space[0][1]<<"   |"<<"   "<<space[0][2]<<"   "<<"\n";
    cout<<"  ______|_______|_______ \n";
    cout<<"        |       |        \n";
    cout<<"    "<<space[1][0]<<"   |"<<"   "<<space[1][1]<<"   |"<<"   "<<space[1][2]<<"   "<<"\n";
    cout<<"  ______|_______|_______ \n";
    cout<<"        |       |        \n";
    cout<<"    "<<space[2][0]<<"   |"<<"   "<<space[2][1]<<"   |"<<"   "<<space[2][2]<<"   "<<"\n";
    cout<<"        |       |        \n";



}

void PlayerTurn(){

    //function is to check for valid values


    if(turn=='X'){
        cout<<"\n"<<n1<<" please enter: ";}
    else if(turn=='0'){
        cout<<"\n"<<n2<<" please enter: ";
    }

    cin>>choice;

    if(choice==1){
        row=0;
        column=0;
    }
    else if(choice==2){
        row=0;
        column=1;
    }
    else if(choice==3){
        row=0;
        column=2;
    }
    else if(choice==4){
        row=1;
        column=0;
    }
    else if(choice==5){
        row=1;
        column=1;
    }
    else if(choice==6){
        row=1;
        column=2;
    }
    else if(choice==7){
        row=2;
        column=0;
    }
    else if(choice==8){
        row=2;
        column=1;
    }
    else if(choice==9){
        row=2;
        column=2;
    }
    else
    {
        cout<<"Invalid Move!!!";

    }

    if(turn=='X'&&space[row][column]!='X'&& space[row][column]!='0'){
        space[row][column]='X';
        turn='0';
    } else if(turn=='0'&&space[row][column]!='X'&& space[row][column]!='0'){
        space[row][column]='0';
        turn='X';
    } else{
        cout<<"There is no empty space!"<<endl;
        PlayerTurn();
    }
    DisplayBoard();
}


bool GameOver(){
    //to check who is the winner and whether the game is still running

    //checking the win for horizontal and vertical lines
    for(int i=0;i<3;i++)
    {
        if(space[i][0] == space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i]){
            return false;
    }
    //checking for win in diagonals
    if(space[0][0]==space[1][1] && space[1][1]==space[2][2] || space[0][2]==space[1][1] && space[1][1]==space[2][0])
    return false;

    //checking whether the game is over or not
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(space[i][j]!='X'||space[i][j]!=0){
                return true;
            }
        }
    }

    //checking the if game already true
    draw=true;
    return false;
}
}

int main()
{
    cout<<"enter the name of player1: \n";
    getline(cin,n1);
    cout<<"enter the name of player2: \n";
    getline(cin,n2);
    cout<<"\n";

    cout<<n1<<" is player1 so he/she will play first. \n";
    cout<<n2<<" is player2 so he/she will play second. \n\n";

    while(GameOver()){
        DisplayBoard();
        PlayerTurn();
        GameOver();
    }

    if(turn == 'X' && draw == false){
        cout<<n2<<" Wins!! "<<endl;
    }
    else if(turn =='0' && draw == false){
        cout<<n1<<" Wins!!"<<endl;
    }
    else
    {
        cout<<"Game Redraw!!"<<endl;
    }

    return 0;
}


