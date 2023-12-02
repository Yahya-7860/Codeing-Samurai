#include<iostream>
#include<cstdlib> 
#include<windows.h>
using namespace std;
void yellow(string str)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,14);
    cout<<str;
    SetConsoleTextAttribute(h,15);

}
void cyan(string str)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,3);
    cout<<str;
    SetConsoleTextAttribute(h,15);

}
void green(string str)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,10);
    cout<<str;
    SetConsoleTextAttribute(h,15);
}
void red(string str)
{
    HANDLE h=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,12);
    cout<<str;
    SetConsoleTextAttribute(h,15);
}
char board[9]={' ',' ',' ',' ',' ',' ',' ',' ',' '};
void show_board(){
        cout<<"          |          |          "<<endl;
        cout<<"    "<<board[0]<<"     |    "<<board[1]<<"     |   "<<board[2]<<" "<<endl;
        cout<<"__________|__________|__________"<<endl;
        cout<<"          |          |          "<<endl;
        cout<<"    "<<board[3]<<"     |    "<<board[4]<<"     |   "<<board[5]<<" "<<endl;
        cout<<"__________|__________|__________"<<endl;
        cout<<"          |          |          "<<endl;
        cout<<"    "<<board[6]<<"     |    "<<board[7]<<"     |   "<<board[8]<<" "<<endl;
        cout<<"          |          |          "<<endl;
}
void x_player(){
    
    while(true)
    {
        cout<<"Enter Number (1-9) for X = ";
        int num;
        cin>>num;
        num--;
        if(num<0 || num>8)
        {
            red("Enter Valid range");
            cout<<endl;
        }            
        else if(board[num]!=' ')
            cout<<"Space is full choose another"<<endl;
        else
        {
            board[num]='X';
            break;
        }        
    }
}
void o_player(){    
    while(true)
    {
        cout<<"Enter Number (1-9) for O = ";
        int num;
        cin>>num;
        num--;
        if(num<0 || num>8)
        {
            red("Enter Valid range");
            cout<<endl;
        }
        else if(board[num]!=' ')
            cout<<"Space is full choose another"<<endl;
        else
        {
            board[num]='O';
            break;
        }
    }
}
int count(char sym)
{
    int count=0;
    for(int i=0;i<9;i++)
    {
        if(board[i]==sym)
            count++;
    }
    return count;
}

char check_win(){
    //!horizental check
    if(board[0]==board[1] && board[1]==board[2] && board[0]!=' ')
        return board[0];
    if(board[3]==board[4] && board[4]==board[5] && board[0]!=' ')
        return board[3];
    if(board[6]==board[7] && board[7]==board[8] && board[0]!=' ')
        return board[6];

    //!verticle
     if(board[0]==board[3] && board[3]==board[6] && board[0]!=' ')
        return board[0];
    if(board[1]==board[4] && board[4]==board[7] && board[1]!=' ')
        return board[1];
    if(board[2]==board[5] && board[5]==board[8] && board[2]!=' ')
        return board[2];
        
    //!digonal
    if(board[0]==board[4] && board[4]==board[8] && board[0]!=' ')
        return board[0];
    if(board[2]==board[4] && board[4]==board[6] && board[2]!=' ')
        return board[1];

    if(count('X')+count('O')==9)
        return 'd';
    else
        return 'c';         
}
void play(){
    string first_player;
    string second_player;

    cout<<"Enter first player name = ";
    cin>>first_player;
    cout<<"Enter second player name = ";
    cin>>second_player;
    
    while(true)
    {        
    system("cls");
    show_board();
        if(count('X')==count('O'))
        {
            yellow(first_player);
            yellow("'s turn");
            cout<<endl;
            x_player();
            show_board();
        }
        else
        {
            cyan(second_player);
            cyan("'s turn");
            cout<<endl;
            o_player();
            show_board();
        }
        char winner=check_win();

        if(winner=='X')
        {
            system("cls");
            show_board();
            green(first_player);
            green(" won the match");
            break;
        }
        else if(winner=='O')
        {
            system("cls");
            show_board();
            green(second_player);
            green(" won the match");
            break;
        }
        else if(winner=='d')
        {
            system("cls");
            show_board();
            cout<<"Match Draw";
            break;
        }
    }
}
int main(){
    yellow("Tic Tac Toe Game");
    cout<<endl<<"===================="<<endl;
    play();
    return 0;
}