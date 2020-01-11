#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;



struct ConnectFour
{
    char Board[6][7];
    void Fill()
    {
        for(int a =0;a <= 5; a++)
        {
            for(int b = 0; b<=6; b++)
            {
                Board[a][b] = '.';
            }

        }
    }

    void display(){

        cout<<"Cols      ";
        for (int c = 1; c < 8; c++)
            cout<<setw(10)<<left<<c;
        cout<<endl<<"Rows "<<endl;
        for(int r = 0; r < 6; r++){
            cout<<setw(10)<<left<<r+1;
            for (int c = 0; c  < 7; c++){
                    cout<<setw(10)<<left<<Board[r][c];
            }
            cout<<endl<<endl<<endl;
         }
        cout<<endl<<endl;
        for(int i = 0; i< 71; i++)
            cout<<"-";
        cout<<endl<<endl;
    }



    int makeMove(int b, char player)
    {
        if(b >=0 && b<= 6)
        {
            if(Board[0][b] == '.')
            {
                int i;
                for(i = 0;Board[i][b] == '.';i++)
                {
                    if(i == 5)
                    {
                        Board[i][b] = player;
                        return i;
                    }
                }
                i--;
                Board[i][b] =player;
                return i;

            }
            else
            {
                return -1;
            }

        }
        else
        {
            return -1;
        }

    }


    bool GameOver(int a, int b){
        int ver= 1;
        int hor = 1;
        int diaOne = 1;
        int diaTwo = 1;
        char player = Board[a][b];
        int i , j;
        for(i = a +1 ; Board[i][b] == player && i <= 5 ; i++ , ver++);
        for(i = a -1 ; Board[i][b] == player && i >= 0 ; i-- , ver++);
        if(ver >= 4)return true;

        for(j = b -1 ; Board[a][j] == player && j >= 0; j--, hor++);
        for(j = b +1 ; Board[a][j] == player && j <= 6; j++, hor++);
        if(hor >= 4) return true;

        for(i = a -1, j= b -1 ; Board[i][j] == player && i>=0 && j >=0; diaOne++, i--, j--);
        for(i = a +1, j = b+1 ; Board[i][j] == player && i<=5 && j <=6; diaOne++, i++, j++);
        if(diaOne >= 4) return true;

        for(i = a -1, j= b +1 ; Board[i][j] == player && i>=0 && j <= 6; diaTwo++, i--, j++);
        for(i = a +1, j= b -1 ; Board[i][j] == player && i<=5 && j >=0; diaTwo++, i++, j--);
        if(diaTwo >= 4) return true;
        return false;
    }

};


int main()
{

    ConnectFour Game;
    cout << "#######################################################################";
    cout << "\n############################ CONNECT FOUR #############################\n";
    cout << "#######################################################################\n";

    Game.Fill();
    Game.display();
    string A , B;
    cout << "Name of 1st Player is : \n";
    getline(cin,A);
    cout << "\nName of 2nd Player is : \n";
    getline(cin,B);
    cout << "\n\n<!------------------- HOPE YOU MAY ENJOY THE GAME -------------------!>\n\n";
    cout << endl;
    int h1;
    int h2 = 0;
    int placedChar = 0;
    bool GameWin = false;
    char player = 88;
    while(!GameWin)
    {
        if(h2 != -1)
        {
            if(player == 88)
            {
				cout << A << " , your move is : \n" ;
				player = 79;
			}
			else
			{
				cout << B << " , your move is : \n" ;
				player = 88;
			}
        }
        while(true)
        {
            if(placedChar == 42)
                break;
            cin >> h1;
            h1--;
            if(h1 >= 0 && h1 <=6)
                break;
            else
                cout << "\nEnter number between 1 to 7 \n";
            if(cin.fail())
            {
                cin.clear();
                char c;
                cin >> c;
            }
        }
        if(placedChar == 42)
            break;
        h2 = Game.makeMove(h1,player);
        if(h2 == -1)
        {
            cout << "Column is full . Enter any other number  \n";
        }
        else
        {
            GameWin = Game.GameOver(h2,h1);
            placedChar++;
            Game.display();
        }

    }
    if(placedChar == 42)
    {
        cout << "Game is drawn \n";
        return 0;
    }
    if(player == 88)
        cout << "Congratulations !!! Game is won by " << B << " .\n\n\n";
    else
        cout << "Congratulations !!! Game is won by " << A << " .\n\n\n";
    cout << "<!-----------------------------See you soon-----------------------------!>";
    return 0;
}
