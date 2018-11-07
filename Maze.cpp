/**********************************************************************************************************************************************************************************
*
* Zachary Torricelli
* Due September 30, 2018
* CSC 412 - Bryant Walley
* 
* The purpose of this program is to create an agent that can process a maze. 
* The maze will be a 10x10 grid. 
* The entry will be designated with an 'E', and the exit will be designated with an 'X'.
* The path that can be traveled in the maze will be designated with a 'P', and the walls
*	will be designated with a 'W'. All perimeter locations other than the entrance and exit
*		will be a 'W'.
*
*
*/


// Include statements and using directive
#include <iostream>
#include <fstream>
#include "BFS.h"
#include "DFS.h"
#define SIZE 10

using namespace std;


// Function prototypes
void printMaze(char[][SIZE], ifstream&);



// Main Driver Function
int main()
{


	// Character array 
	char maze[SIZE][SIZE];


	// Stream writer to read from a file
	ifstream inFile;


	// Opens the input file
	inFile.open("maze.txt");


	// Displays a welcome message to the console
	cout << "Welcome to Zac's AMAZE-ingly Simple Maze Solver!" << endl;


	// Displays a note message to the console
	cout << "Note: Please initialize and display the maze before choosing a search" << endl;


	// Formatting for console output
	cout << endl;


	// Variable used for the menu options with a default value of 0
	int choice = 0;


	// While loop driven menu that continues until 5 is entered
	while (choice != 5)
	{


		// Menu options
		cout << "1. Initialize and Display Maze" << endl;
		cout << "2. Breadth First Search" << endl;
		cout << "3. Depth First Search" << endl;
		cout << "4. All of the Above" << endl;
		cout << "5. Exit" << endl;


		// Formatting for console output
		cout << endl;

	
		//  Obtains the desired option from the user
		cin >> choice;
	
			
		// Switch statement to assign functionality to the menu options
		switch (choice)
		{


			// Option 1 clears the screen and prints the maze to the console
			case 1:
				system("CLS");
				printMaze(maze, inFile);
				cout << endl;
				break;


			// Option 2 clears the screen and performs a breadth first search of the maze
			case 2:
				system("CLS");
				// Creates an object of the class BFS
				BFS implementBFS;
				implementBFS.breadthFirstSearch(maze, SIZE, SIZE);
				cout << endl;
				break;


			// Option 3 clears the screen and performs a depth first search of the maze
			case 3: 
				system("CLS");
				// Creates an object of the class DFS
				DFS implementDFS;
				implementDFS.depthFirstSearch(maze, SIZE, SIZE);
				cout << endl;
				break;


			// Option 4 clears the screen, prints the maze, performs a breadth first search,
				// and a performs a depth first search of the maze
			case 4: 
				system("CLS");
				printMaze(maze, inFile);
				cout << endl << endl;
				implementBFS.breadthFirstSearch(maze, SIZE, SIZE);
				cout << endl << endl;
				implementDFS.depthFirstSearch(maze, SIZE, SIZE);
				cout << endl;
				break;


			// Option 5 exits the program
			case 5:
				exit(0);


			// Default case will collect the invalid options input and let the user try again
			default:
				system("CLS");
				// Displays a message to the console when an invalid option is input
				cout << "Invalid selection. Try again" << endl;


		}


	}
	
	
	// Closes the input file
	inFile.close();

	system("pause");
	return(0);


}


// Function to print the maze to the console
void printMaze(char maze[][SIZE], ifstream &inFile)
{

	
	
	// Verifies if the file is open or not
	if (!inFile.is_open())
	{

		// If not, display a message to the console and exit the program
		cout << "Cannot open input file! " << endl;
		exit(1);

	}


	// Displays a maze label to the console
	cout << "\t\t\t\t AMAZE-ingly Simple Maze" << endl << endl;


	// Formatting for console output
	cout << "\t";



	// For loop to display row numbers accordingly
	for (int i = 0; i < SIZE; i++)
	{

		// Displays the row numbers to the console
		cout << (i) << "\t";

	}


	// Formatting for console output
	cout << endl << endl;



	// For loop to print the 2d maze array
	for (int i = 0; i < SIZE; ++i)
	{

		// Displays the column numbers to the console
		cout << (i) << "\t";


		for (int j = 0; j < SIZE; ++j)
		{


			// Reads and adds the contents of the file to the 2d maze array 
			inFile >> maze[i][j];


			// Displays the 2d maze array to the console
			cout << maze[i][j] << "\t";

		}


		// Formatting for console output
		cout << endl << endl;

	}

	
}
