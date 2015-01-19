#include <iostream>

using namespace std;

/*
	Solves Eight Queens Puzzle and prints all possible solutions.
*/

const int size = 8;
// size2 = size*2 - 1; number of diagonals.
const int size2 = 15;

// We hold result in t. t[i] is a position of a queen in i-row.
int t[size];
// info if there is a queen in certain diagonal.
bool right_diag[size2];
bool left_diag[size2];

void printResult ();
void setQueen (int col);

int main ()
{
	//Preparing our arrays
	for (int i = 0; i < size; i++)
		t[i] = 0;

	for (int i = 1; i < size2; i++)
	{
		right_diag[i] = false;
		left_diag[i] = false;
	}
	// start from column number 1
	setQueen(1);
}


// prints the chessboard
void printResult ()
{
	for (int j = 0; j < size; j++)
	{
		// dots before the queen
		for (int i = 0; i < t[j] - 1; i++)
			cout << " .";
		// queen
		cout << " $";
		// dots after the queen
		for (int i = t[j] + 1; i <= size; i++)
			cout << " .";
		cout << endl;
	}
	cout << endl;
}

// Places a queen on the chessboard
void setQueen (int col)
{
	int row;

	if (col > size)
		printResult();
	else
		for (row = 0; row < size; row++)
		{
			//We check if setting a queen on this position will cause any collisions.
			if ((t[row] == 0) && (!right_diag[row + col - 1]) && (!left_diag[size - col + row]))
			{
				//We save the position of the queen and set diagonals to true.
				t[row] = col;
				right_diag[row + col - 1] = true;
				left_diag[size - col + row] = true;

				setQueen(col + 1);

				//After we checked all possible ways from this point, we take away the queen and go back.
				t[row] = 0;
				right_diag[row + col - 1] = false;
				left_diag[size - col + row] = false;
			}
		}
}
