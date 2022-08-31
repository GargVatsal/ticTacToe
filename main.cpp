#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

string is_a_winner(const char (*pos)[3], string p1, string p2);
void print(const char (*pos)[3], string p1, string p2);
int chance(int ctr,char (*pos)[3], string p1);

int main(){
    string p1;
    string p2;

    int ctr {0};
    cout << "Enter the name of player 1 \n";
    getline(cin,p1);
    cout << "Enter the name of player 2 \n";
    getline(cin,p2);
    
    char pos [3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}}; // positions for the game
    
    while(ctr < 10){
        
        print(pos, p1, p2);
        if (is_a_winner(pos, p1, p2) != "\n"){
            cout << "\t**********--- " << is_a_winner(pos, p1, p2) << " WON ---**********" << endl;
            cout << "Press Enter to exit" ;
            getchar();
            while(getchar() != '\n'){
                
            }
            break;
        }if (ctr == 9){
            cout << "OOPS! nobody Won \nBetter luck next time" << endl;
            break;
        }
        ctr -= chance(ctr, pos, p1);
        ctr++;
    }
    return 0;
}

string is_a_winner(const char (*pos)[3], string p1, string p2){
    for (size_t i {0}; i < 3; i++){
        // Veritical check
        if (pos[0][i] == pos[1][i] && pos[1][i] == pos[2][i]){
            return pos[0][i] == 'x' ? p1 : p2;
        }
        // Horizontal check
        else if (pos[i][0] == pos[i][1] && pos[i][1] == pos[i][2]){
            return pos[i][0] == 'x' ? p1: p2;
        }
        // Diagonal check
        else if ((i == 0 && pos[i][i] == pos[i+1][i+1] && pos[i+1][i+1] == pos[i+2][i+2]) || (i == 2 && pos[i][i-2] == pos[i-1][i-1] && pos[i-2][i] == pos[i-1][i-1])){
            return pos[1][1] == 'x' ? p1: p2;
        }
    }
    return "\n";
}

void print(const char (*pos)[3], string p1, string p2){
    system("cls");  // to clear the screen and print the updated matrix
    cout << "\t\t " << pos[0][0] << "  | "<< pos[0][1] <<" |  "<< pos[0][2] <<" "<< endl;
    cout << "\t\t____|___|____"<< endl;
    cout << "\t\t " << pos[1][0] << "  | "<< pos[1][1] <<" |  "<< pos[1][2] <<" "<< endl;
    cout << "\t\t____|___|____"<< endl;
    cout << "\t\t " << pos[2][0] << "  | "<< pos[2][1] <<" |  "<< pos[2][2] <<" "<< endl;
    cout << "\t\t    |   |    "<< endl;
    cout << endl;
    cout << "Player 1 -- " << p1 << "\tPlayer 2 -- " << p2 << endl;
}

int chance(int ctr, char (*pos)[3], string p1){
    int choice {0};
    char mark;
    ctr & 1 == 1 ? cout << "                 @" : cout << " @";
    cout << endl;
    ctr & 1 == 1 ? cout << "                  " : cout << " ";
    cin >> choice;
    ctr & 1 == 1 ? mark = '0' : mark = 'x';
    
    if (choice / 10 == 0 && choice != 0 && pos[0][choice - 1] != 'x' && pos[0][choice - 1] != '0' && pos[1][choice - 4] != 'x' && pos[1][choice - 4] != '0' && pos[2][choice -7] !='x' && pos[2][choice -7] != '0'){   
        if(choice < 4){
            pos[0][choice - 1] = mark;
        }else if(choice < 7){
            pos[1][choice - 4] = mark;
        }else{
            pos[2][choice -7] = mark;
        }
        return 0;
    }else{  
        //entered choice is  either not within 1-9 or repeated value
        cout << "Wrong Choice!" << endl;
        return 1;
    }
}