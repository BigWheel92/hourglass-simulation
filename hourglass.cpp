#include <iostream>
using namespace std;
#include <Windows.h>
#include <chrono>
#include <thread>

void gotoxy(int x, int y);
void simulateHourGlass(int const numOfSeconds, int const startingXCoord, int startingYCoord, char const character='*')
{
	int x = startingXCoord;
	int y = startingYCoord;
	gotoxy(x, y);
	
	//printing first line using -
	for (int i = 0; i < (numOfSeconds*2)+3; i++)
	{
		cout << "-";
	}

	y++;
	for (int i = 0; i < numOfSeconds ; i++)
	{
		gotoxy(x,y);
		cout<<"\\";
		for (int j = 0; j < numOfSeconds-i; j++)
		{
			cout << " "<<character;
		}
		cout << " /";
		x++;
		y++;
	}


	x--;
	//lower half of hour glass
	for (int i = 0; i <numOfSeconds; i++)
	{
	
		gotoxy(x, y);
		cout << "/";
		for (int j = 0; j <= (i+1)*2; j++)
		{
			cout << " ";
		}
		cout << "\\";
		cout << endl;
		x--;
		y++;

	}

	//the last line
	for (int i = 0; i < (numOfSeconds * 2) + 3; i++)
	{
		x++;
		gotoxy(x, y);
		cout << "-";
		
		
	}
	y++;
	gotoxy(0, y);

	/////now starting the simulation////
	int upperX = startingXCoord + 1;
	int upperY = startingYCoord + 1;
	int lowerX = startingXCoord + 1;
	int lowerY = numOfSeconds*2+startingYCoord;

	for (int i = 0; i < numOfSeconds; i++)
	{
		this_thread::sleep_for(chrono::milliseconds(1000));

		gotoxy(upperX, upperY);
		//removing one line from upper half
		for (int j = 0; j < numOfSeconds - i; j++)
		{
			cout << "  ";
		}
		upperX++;
		upperY++;
		//adding one line to lower half.
		gotoxy(lowerX, lowerY);
		for (int j = 0; j < numOfSeconds - i; j++)
		{
			cout << " "<<character;
		}
		lowerX++;
		lowerY--;

	}
	gotoxy(0,numOfSeconds * 2 + startingYCoord + 1);
}



void gotoxy(int x, int y)
{
	COORD coordinates;     // coordinates is declared as COORD
	coordinates.X = x;     // defining x-axis
	coordinates.Y = y;     //defining  y-axis
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}



int main()
{	

	simulateHourGlass(20, 0, 0, '*');
	return 0;
}