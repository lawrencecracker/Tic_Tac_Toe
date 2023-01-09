#include<bits/stdc++.h>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

char current_marker;
int current_player;
string Player_1,Player_2;

void draw_board()
{
    cout<<"    "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<"\n";
    cout<<"   -----------"<<"\n";
    cout<<"    "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<"\n";
    cout<<"   -----------"<<"\n";
    cout<<"    "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<"\n";
}

int slot_validation_check(int slot)
{
    if(slot < 1 || slot > 9)
    {
        cout<<"Please choose slot b/w [1 - 9]\n";
        return 0;
    }
    return 1;

}

int place_marker(int slot)
{
    int row;
    if(slot % 3 == 0) row = (slot / 3) - 1;
    else row = slot / 3;

    int col;
    if(slot % 3 == 0) col = 2;
    else col = (slot % 3) - 1;

    if(board[row][col] == 'O' || board[row][col] == 'X')
    {
        cout<<"!!Slot already marked!!\n";
        return 0;
    }

    board[row][col] = current_marker;
    return 1;
}

int winner()
{
    for(int i=0;i<3;i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2]) return current_player;

        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]) return current_player;
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]) return current_player;
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]) return current_player;

    return 0;
}

void swap_player_and_marker()
{
    if(current_marker == 'X') current_marker = 'O';
    else current_marker = 'X';

    if(current_player == 1) current_player = 2;
    else current_player = 1;
}

void game()
{
    cout<<Player_1<<" choose your Marker : ";
    char marker_p1;
    cin>>marker_p1;

    current_marker = marker_p1;
    current_player = 1;

    int player_won;
    for(int i=0;i<9;i++)
    {
        system("cls");
        draw_board();
        int slot, flag = 1;
        do{
            cout<<"It's Player "<<current_player<<" turn, Choose your Slot : ";
            cin>>slot;

            flag = slot_validation_check(slot);

            if(flag)
                flag = place_marker(slot);

        }while(flag != 1);

        player_won = winner();
        if(player_won == 1)
        {
            system("cls");
            cout<<"--> "<<Player_1<<" <--"<<" won the game !!Congrats!!"<<"\n\n";
            break;
        }
        else if (player_won == 2)
        {
            system("cls");
            cout<<"--> "<<Player_2<<" <--"<<" won the game !!Congrats!!"<<"\n\n";
            break;
        }
        swap_player_and_marker();
    }

    if(player_won == 0)
    {
        system("cls");
        cout<<"!! Its a tie game !!\n\n";
    }
}

int main()
{
    system("color B");
    cout<<"Welcome to Tic Tac Toi Game 2020\nValid Markers are [X] & [O]\n\n";
    cout<<"Enter Name of [Player 1] : ";
    getline(cin,Player_1);
    cout<<"Enter Name of [Player 2] : ";
    getline(cin,Player_2);
    game();
    system("color A");
    draw_board();

    return 0;
}
