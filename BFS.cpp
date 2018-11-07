// Include statements and using directive
#include <iostream>
#include <queue>
#include "BFS.h"
#include <vector>
#define SIZE 10

using namespace std;


// Struct to hold our state information
struct queueNode
{

	// Integers to store the current location
	int row;
	int column;
	
	// Vector to record the path that has been traveled
	vector <int> move;

};

// Function to perform the breadth first search of a 2d array
void BFS::breadthFirstSearch(char maze[][SIZE], int rows, int columns)
{

	
	// Creates a queue to hold the nodes
	queue <queueNode> myQueue;

	
	// Creates a node to represent the first entrance state
	queueNode entry;

	
	// Boolean variable to determine the visisted states
	bool found = false;

	
	// Boolean 2d array to determine the visited states
	bool visited[SIZE][SIZE];



	// Initializes the starting entry state 
	for (int i = 0; i < rows; i++)
	{

		for (int j = 0; j < columns; j++)

		{

			// Sets the visited state of all places to false
			visited[i][j] = false;


			// Finds and sets the entry state
			if (maze[i][j] == 'E')
			{

				entry.row = i;
				entry.column = j;

			}

		}

	}


	// Pushes the starting entry state to the queue
	myQueue.push(entry);


	// Marks the entry spot in the maze as visited
	visited[entry.row][entry.column] = true;
	


	// While loop that uses the not empty validation to look at all the possible moves
	while (!myQueue.empty())
	{


		// Creates a new node to represent the current state
		queueNode current;

		// Gets the current location based on the starting entry location in the queue
		current = myQueue.front();

		// Pops the entry state off the queue
		myQueue.pop();

		
		
		//Checks to see if this is the goal state
		if (maze[current.row][current.column] == 'X')
		{

			// Displays a breadth first search label to the console
			cout << "\t\t\t\t Breadth First Search" << endl;


			// For loop to display the path the node contains to the console
			for (int i = 0; i < current.move.size(); i++)
			{

				// Displays the path the node contains to the console
				cout << current.move[i] << ", ";

			}


			// Displays the goal state to the console
			cout << current.row * 10 + current.column << endl;

			
			// Since the goal state was found, we mark this as true
			found = true;

			break;
		
		}



		// MOVE UP: Checks the validity of the move, if visited, and if it is not a wall
		if (current.row - 1 < rows && current.column < columns && current.row - 1 >= 0
			&& current.column >= 0 && visited[current.row - 1][current.column] == false
			&& maze[current.row - 1][current.column] != 'W')
		{


			// Creates a node to setup a temporary location
			queueNode temp;
			temp.row = current.row - 1;
			temp.column = current.column;
			
			// Marks the space as visited
			visited[current.row - 1][current.column] = true;

			// Createss a vector to store the current move
			vector<int> tempVector =current.move;
			int value = current.row * 10 + current.column;
			tempVector.push_back(value);
			temp.move = tempVector;
			
			// Adds location to the queue
			myQueue.push(temp);
			

		}



		// MOVE RIGHT: Checks the validity of the move, if visited, and if it is not a wall
		if (current.row < rows && current.column + 1 < columns && current.row >= 0
			&& current.column + 1 >= 0 && visited[current.row][current.column + 1] == false
			&& maze[current.row][current.column + 1] != 'W')
		{


			// Creates a node to setup a temporary location
			queueNode temp;
			temp.row = current.row;
			temp.column = current.column + 1;
			
			// Marks the space as visited
			visited[current.row][current.column + 1] = true;

			// Createss a vector to store the current move
			vector<int> tempVector = current.move;
			int value = current.row * 10 + current.column;
			tempVector.push_back(value);
			temp.move = tempVector;
			
			// Adds location to the queue
			myQueue.push(temp);
			

		}



		// MOVE DOWN: Checks the validity of the move, if visited, and if it is not a wall 
		if (current.row + 1 < rows && current.column < columns && current.row + 1 >= 0
			&& current.column >= 0 && visited[current.row + 1][current.column] == false
			&& maze[current.row + 1][current.column] != 'W')
		{


			// Creates a node to setup a temporary location
			queueNode temp;
			temp.row = current.row + 1;
			temp.column = current.column;

			// Marks the space as visited
			visited[current.row + 1][current.column] = true;

			// Createss a vector to store the current move
			vector<int> tempVector = current.move;
			int value = current.row * 10 + current.column;
			tempVector.push_back(value);
			temp.move = tempVector;
			
			// Adds location to the queue
			myQueue.push(temp);

			
		}
		


		// MOVE LEFT: Checks the validity of the move, if visited, and if it is not a wall
		if (current.row < rows && current.column - 1 < columns && current.row >= 0
			&& current.column - 1 >= 0 && visited[current.row][current.column - 1] == false
			&& maze[current.row][current.column - 1] != 'W')
		{


			// Creates a node to setup a temporary location
			queueNode temp;
			temp.row = current.row;
			temp.column = current.column - 1;
			
			// Marks the space as visited
			visited[current.row][current.column - 1] = true;

			// Createss a vector to store the current move
			vector<int> tempVector = current.move;
			int value = current.row * 10 + current.column;
			tempVector.push_back(value);
			temp.move = tempVector;
			
			// Adds location to the queue
			myQueue.push(temp);			


		}

	}

}
