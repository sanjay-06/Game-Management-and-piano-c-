#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
#include <cstdlib>
#include<ctime>
#include <string>
#define clear system("cls");
using namespace std;		// sudoku grid size
const int UNASSIGNED = 0;// empty cells in the sudoku table
const int N = 9; 
class Game
{		
	int choice;
	public:
		Game();
		int choice_select();
		friend class sudoku;
		friend int sudokku_exe();
};
Game::Game()
{
	choice=0;
}
class TicTacToe
{
public: 
    TicTacToe();
    int Pick_Player();
    int Pick_Row();
    int Pick_Column();
    int Check_Board();
    void Choice_by_Player(int);
    void Choice_of_Row(int);
    void Choice_of_Column(int);
    void Tic_Tac_Toe_Board();
    bool Check_Move (int, int);
private: 
    int row;
    int column;
    int player;
    int board[3][3];
    char display_board[3][3];
};
TicTacToe::TicTacToe()
{
    row=0,column=0;
    player=1;
    int i=0;
    int j=0; //where i is row and j will be columns
    for (i=0; i<3; i++)
    {
        for (j=0; j<3; j++)
        {
            board[i][j] =0;
            display_board[i][j] = ' ';
        }
    }
}
int TicTacToe::Pick_Player()
{
    return player;
}
int TicTacToe::Pick_Row()
{
    return row;
}
int TicTacToe::Pick_Column()
{
    return column;
}
void TicTacToe::Choice_by_Player(int a)
{
    player=a;
}
void TicTacToe::Choice_of_Row(int b)
{
    row=b;
}
void TicTacToe::Choice_of_Column(int c)
{
    column=c;
}
bool TicTacToe::Check_Move(int row, int column)
{
    if (row!=0 && row!=1 && row!=2 )
    {
        cout<<"Invalid choice!!"<<endl;
        return 0;
    }
    else if (column!=0 && column!=1 && column!=2 )
    {
        cout<<"Invalid choice!!"<<endl;
        return 0;
    }
    else if (board[row][column] ==1 || board[row][column] ==2)
    {
        cout<<"Space already used. Try Again." <<endl;
        return 0;
    }
    else
    {
        board[row][column] = player;
        return 1;
    }
}
int TicTacToe::Check_Board()
{
    int i=0;
    int j=0;
    int sum= 0;
    int test= 0;
    int count= 0;
    for (i= 0; i<3; i++)
    {
        sum=0;
        for(j=0; j<3; j++)
        {
            if (board[i][j] ==0)
            {
                count++;
            }
            sum +=(board[i][j]*board[i][j]);
        }
        if (sum==3 ||sum==12)
        {
            test=sum;
            break;
        }
        sum=0;
    }
    for (j=0; j<3; j++)
    {
        sum=0;
        for (i=0; i<3; i++)
        {
            sum+=(board[i][j]*board[i][j]);
        }
        if (sum==3 || sum==12)
        {
            test=sum;
            break;
        }
        sum=0;
    }
    if(test!=3 ||test!=12)
    {
        sum = (board[0][0] * board[0][0])+ (board[1][1] * board[1][1]) + (board[2][2] * board[2][2]);
        if ( sum == 3 || sum == 12)
        {
            test=sum;
        }
    }
    if (test != 3 || test != 12)
    {
        sum = (board[2][0] * board[2][0])+ (board[1][1] * board[1][1]) + (board[0][2] * board[0][2]);
        if (sum==3||sum==12)
        {
            test=sum;
        }
    }
    if (test==3)
    {
        test=1;
    }
    else if (test==12)
    {
        test=2;
    }
    else if (count==0)
    {
        test=3;
    }
    else
    {
        test=0;
    }
    return test;
}
void TicTacToe::Tic_Tac_Toe_Board()
{
    for ( int row = 0; row < 3; row ++)
    {
        for ( int column = 0; column < 3; column++)
        {
            if ( board[row][column] == 0)
            {
                display_board[row][column] = ' ';
            }
            if ( board[row][column] == 1)
            {
                display_board[row][column] = 'X';
            }
            if ( board[row][column] == 2)
            {
                display_board[row][column] = 'O';
            }
        }
    }
    cout<<"Welcome to Tic-Tac-toe!"<<endl<<endl;;
    cout<< " Current Player: 1 (X) Current Player: 2 (O) " << endl<<endl<<endl;
    cout << endl;
    /*cout<<" Current Player "<<player;
    cout<< endl;*/ 
        cout << "     |     |     " << endl;
        cout << "  " << display_board[0][1] << "  |  " << display_board[0][2] << "  |  " << display_board[0][3] << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << display_board[0][4] << "  |  " << display_board[0][5] << "  |  " << display_board[0][6] << endl;
        cout << "_____|_____|_____" << endl;
        cout << "     |     |     " << endl;
        cout << "  " << display_board[0][7] << "  |  " << display_board[0][8] << "  |  " << display_board[0][9] << endl;
        cout << "     |     |     " << endl << endl;
}
inline int ticktack_exe()
{
    TicTacToe game;
    bool test;
    bool more=true;
    int row=0;
    int column=0;
    int player;
    int check=0;
    TicTacToe();
    while (more)
    {
        game.Tic_Tac_Toe_Board();
        player= game.Pick_Player();
       /* cout<<" Current Player "<<player;
        cout<< endl;*/
        cout<< "Enter Row Index (0, 1, or 2): " <<endl;
        cin>>row;
        cout<<"Enter Column Index (0, 1, or 2): "<<endl;
        cin>>column;
        game.Choice_of_Row(row);
        game.Choice_of_Column(column);
        test= game.Check_Move( game.Pick_Row(), game.Pick_Column());
        if (test==1)
        {
            check=game.Check_Board();
        }
        else
        {
            while (test==0)
            {
                cout<<"Current player"<<game.Pick_Player()<<"Invalid Choice"<<endl;
                cout<<"Enter Row Index (0, 1, or 2): "<<endl;
                cin>>row;
                cout<<"Enter Column Index (0, 1, or 2): "<<endl;
                cin>>column;
                game.Choice_of_Row(row);
                game.Choice_of_Column(column);
                test=game.Check_Move(game.Pick_Row(), game.Pick_Column());
            }
            check= game.Check_Board();
        }
        if (check==1 ||check==1)
        {
            break;
        }
        else if (check==3)
        {
            game.Tic_Tac_Toe_Board();
            cout<<"The game is tied. "<<endl;
        }
        if (player ==1)
        {
            player==2;
        }
        else
        {
            player=1;
        }
        game.Choice_by_Player(player);
    }
    game.Tic_Tac_Toe_Board();
    cout<<"Player "<<check<<" wins! "<<endl;
    return 0;
}
class Sudoku:public Game
{
	public:
		bool usedInRow(int grid[N][N], int row, int number);
		bool usedInCol(int grid[N][N], int col, int number);
        bool usedInBox(int grid[N][N], int row, int col, int number);
        bool isValid(int grid[N][N], int row, int col, int number);
        bool findUnassignedLocation(int grid[N][N], int &row, int &col);
        bool solveSudoku(int grid[N][N]);
        void displayGrid(int grid[N][N]);
    	Sudoko();          
};
class twozerofoureigth
{
		int i,j,li,ri;
	public:
		int call();
		void downmove(int a[4][4]);
		void upmove(int a[4][4]);
		void leftmove(int a[4][4]);
		void rightmove(int a[4][4]);
		void addblock(int a[4][4]);		
	    void disp(int a[4][4]);
		int checkover(int a[4][4]);	
	    int check(int tmp[4][4],int a[4][4]);
};
class Wordguess
{
	int MAX_TRIES;
    public:
    	int guess_call();
    	int letterFill (char, string, string&);
    	Wordguess();
};
Wordguess::Wordguess()
{
	MAX_TRIES=5;
}
void twozerofoureigth::upmove(int a[4][4])
{

	for(j=0;j<4;j++)
	{
		li=0,ri=j;
		for(i=1;i<4;i++)
		{
			if(a[i][j]!=0)
			{
				if(a[i-1][j]==0 || a[i-1][j]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[++li][ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else li++;
			}
		}
	}
}
void twozerofoureigth::downmove(int a[4][4])
{
	for(j=0;j<4;j++)
	{
		li=3,ri=j;
		for(i=2;i>=0;i--)
		{
			if(a[i][j]!=0)
			{
				if(a[i+1][j]==0 || a[i+1][j]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[--li][ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else li--;
			}
		}
	}
}
void twozerofoureigth::leftmove(int a[4][4])
{
	for(i=0;i<4;i++)
	{
		li=i,ri=0;
		for(j=1;j<4;j++)
		{
			if(a[i][j]!=0)
			{
				if(a[i][j-1]==0 || a[i][j-1]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[li][++ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else ri++;
			}
		}
	}
}

void twozerofoureigth::rightmove(int a[4][4])
{
	for(i=0;i<4;i++)
	{
		li=i,ri=3;
		for(j=2;j>=0;j--)
		{
			if(a[i][j]!=0)
			{
				if(a[i][j+1]==0 || a[i][j+1]==a[i][j])
				{
					if(a[li][ri]==a[i][j])
					{
						a[li][ri]*=2;
						a[i][j]=0;
					}
					else
					{
						if(a[li][ri]==0)
						{
							a[li][ri]=a[i][j];
							a[i][j]=0;
						}
						else
						{
							a[li][--ri]=a[i][j];
							a[i][j]=0;
						}
					}
				}
				else ri--;
			}
		}
	}
}

void twozerofoureigth::addblock(int a[4][4])
{
	srand(time(0));
	while(1)
	{
		li=rand()%4;
		ri=rand()%4;
		if(a[li][ri]==0)
		{
			a[li][ri]=pow(2,li%2 + 1);
			break;
		}
	}

}

void twozerofoureigth::disp(int a[4][4])
{
	cout<<"\n\t\tPress Esc anytime to quit the game";
	cout<<"\n\n\n\n";
	int i,j;
	for(i=0;i<4;i++)
	{
		cout<<"\t\t\t\t-----------------\n\t\t\t\t";
		for(j=0;j<4;j++)
		{
			if(a[i][j]==0) cout<<"|   ";
			else
				cout<<"| "<<a[i][j]<<" ";
		}
		cout<<"|"<<endl;
	}
	cout<<"\t\t\t\t-----------------\n";
}

int twozerofoureigth::check(int tmp[4][4],int a[4][4])
{
	int fl=1,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(tmp[i][j]!=a[i][j])
    		{
    			fl=0;
    			break;
			}
	return fl;
}

int twozerofoureigth::checkover(int a[4][4])
{
	int fl=0,gl=0,i,j;
	for(i=0;i<4;i++)
    	for(j=0;j<4;j++)
    		if(a[i][j]==0)
    		{
    			fl=1;
				break;	
			}
			
	for(i=0;i<3;i++)
    	for(j=0;j<3;j++)
    		if(a[i+1][j]==a[i][j] || a[i][j+1]==a[i][j])
    		{
    			gl=1;
    			break;
			}
			
	if(fl || gl) return 1;
	else return 0;
}

int twozerofoureigth::call()
{
	cout<<"\n\n\n\n\t\t\t2048 GAME\n\n\n\t\tPress any key to continue";
	getch();
	system("cls");
	int i1,i2,i3,i4,i,j;
	int a[4][4]={0},tmp[4][4]={0};
	srand(time(0));
	i1=rand()%4;
	i2=rand()%4;
	while(1)
	{
		i3=rand()%4;
		i4=rand()%4;
		if(i3!=i1 && i4!=i2) break;
	}
	a[i1][i2]=2;
	a[i3][i4]=4;
	disp(a);                               ////important feauture
	int ch;
	while (1)
    {
    	for(i=0;i<4;i++)
    		for(j=0;j<4;j++)
    			tmp[i][j]=a[i][j];
    	ch=getch();
    	system("cls");
    	if(ch==72) upmove(a);
    	if(ch==80) downmove(a);
    	if(ch==75) leftmove(a);
    	if(ch==77) rightmove(a);
		if(ch==27) break;
		
		if(!check(tmp,a))
			addblock(a);
		disp(a);
			
		if(!checkover(a))
		{
			cout<<"\n\n\t\t\tGAME OVER!!\n\n\n";
			getch();
			break;
		}	
	}
	return 0;
}
inline int sudokku_exe()
{
		int grid[N][N];
		Sudoku obj;
		cout << "Enter the Sudoku grid (Use 0 for empty cells): " << endl;
        for (int i = 0; i < N; i++) {
             for (int j = 0; j < N; j++) {
                   cin >> grid[i][j];
              }
        }
       cout << endl;
	     if (obj.solveSudoku(grid) == true)
	     {
	       cout << "Solution: " << endl;
	       obj.displayGrid(grid);
	      } 
	    else 
		 {
	        cout << "No solution exists. " << endl;
	        cout << "Are you sure you entered it correctly?" << endl;
	     }
}
int Game::choice_select()
{
			l1:cout<<"\t\t\t\t\t\tGAME SELECTION\n";
        	cout<<"\n\n\n\n\t\t\t\t\t\t1]sudokku";
        	cout<<"\n\t\t\t\t\t\t2]2048";
			cout<<"\n\t\t\t\t\t\t3]Hangman";
			cout<<"\n\t\t\t\t\t\t4]TicTackToe";
        	cout<<"\n\t\t\t\t\t\t0]EXIT\n";
        	cout<<"\n\n ENTER YOUR CHOICE"<<" ";
        	cin>>choice;
        	try
        	{
        		if(choice==1)
        		{
        			 clear;
        		     sudokku_exe();
			    }
			    else if(choice==2)
			    {
			    	clear;
			    	twozerofoureigth game2;
					game2.call();
				}
				else if(choice==3)
				{
					clear;
					Wordguess game3;
	                game3.guess_call();
				}
				else if(choice==4)
				{
					ticktack_exe();
				}
				else if(choice==0||choice==27)
				{
					return 0;
				}
				else
				{
					throw 1;
				}
		    }
            catch(int a)
            {
            	cout<<"THE CHOICE IS INVALID";
            	goto l1;
			}
        	
}

// returns whether or not "number" has been used in particular row
bool Sudoku:: usedInRow(int grid[N][N], int row, int number) {
  for (int col = 0; col < N; col++)
    if (grid[row][col] == number)
      return true;
  return false;
}
bool Sudoku:: usedInCol(int grid[N][N], int col, int number) {
  for (int row = 0; row < N; row++)
    if (grid[row][col] == number)
      return true;
  return false;
}
 
// returns whether or not "number" has been used in particular box
bool Sudoku:: usedInBox(int grid[N][N], int row, int col, int number) {
  int boxStartRow = row - row % 3;
  int boxStartCol = col - col % 3;
  for (int ii = 0; ii < 3; ii++)
    for (int jj = 0; jj < 3; jj++)
      if (grid[boxStartRow + ii][boxStartCol + jj] == number)
        return true;
  return false;
}
 
// checks whether or not it is valid to place "number" in the given position
bool Sudoku:: isValid(int grid[N][N], int row, int col, int number) {
  return !usedInRow(grid, row, number) &&
       !usedInCol(grid, col, number) &&
       !usedInBox(grid, row, col, number);
}
 
// finds the first unassigned or empty cell in sudoku grid. row and column are passed by reference
bool Sudoku:: findUnassignedLocation(int grid[N][N], int &row, int &col) {
  for (row = 0; row < N; row++)
    for (col = 0; col < N; col++)
      if (grid[row][col] == UNASSIGNED)
        return true;
  return false;
}
 
bool Sudoku:: solveSudoku(int grid[N][N]) {
  int row, col;
  if (!findUnassignedLocation(grid, row, col))
    return true;
  for (int number = 1; number <= 9; number++) {
    if (isValid(grid, row, col, number)) {
      grid[row][col] = number;
      if (solveSudoku(grid))
        return true;
      grid[row][col] = UNASSIGNED;
    }
  }
  return false;
}
void Sudoku:: displayGrid(int grid[N][N]) {
  for (int row = 0; row < N; row++) {
    for (int col = 0; col < N; col++)
      cout << grid[row][col] << " ";
    cout << endl;
  }
}
int Wordguess::guess_call()
{
	string name;
	char letter;
	int num_of_wrong_guesses=0;
	string word;
	string words[] =
	{
		"india",
		"pakistan",
		"nepal",
		"malaysia",
		"philippines",
		"australia",
		"iran",
		"ethiopia",
		"oman",
		"indonesia"
	};

	//choose and copy a word from array of words randomly
	srand(time(NULL));
	int n=rand()% 10;
	word=words[n];
    
	// Initialize the secret word with the * character.
	string unknown(word.length(),'*');

	// welcome the user
	cout << "\n\nWelcome to hangman...Guess a country Name";
	cout << "\n\nEach letter is represented by a star.";
	cout << "\n\nYou have to type only one letter in one try";
	cout << "\n\nYou have " << MAX_TRIES << " tries to try and guess the word.";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    
	// Loop until the guesses are used up
	while (num_of_wrong_guesses < MAX_TRIES)
	{
		cout << "\n\n" << unknown;
		cout << "\n\nGuess a letter: ";
		cin >> letter;
		// Fill secret word with letter if the guess is correct,
		// otherwise increment the number of wrong guesses.
		if (letterFill(letter, word, unknown)==0)
		{
			cout << endl << "Whoops! That letter isn't in there!" << endl;
			num_of_wrong_guesses++;
		}
		else
		{
			cout << endl << "You found a letter! Isn't that exciting!" << endl;
		}
		// Tell user how many guesses has left.
		cout << "You have " << MAX_TRIES - num_of_wrong_guesses;
		cout << " guesses left." << endl;
		// Check if user guessed the word.
		if (word==unknown)
		{
			cout << word << endl;
			cout << "Yeah! You got it!";
			break;
		}
	}
	if(num_of_wrong_guesses == MAX_TRIES)
	{
		cout << "\nSorry, you lose...you've been hanged." << endl;
		cout << "The word was : " << word << endl;
	}
	cin.ignore();
	cin.get();
	return 0;
}

/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */

int Wordguess::letterFill (char guess, string secretword, string &guessword)
{
	int i;
	int matches=0;
	int len=secretword.length();
	for (i = 0; i< len; i++)
	{
		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
			return 0;
		// Is the guess in the secret word?
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}



