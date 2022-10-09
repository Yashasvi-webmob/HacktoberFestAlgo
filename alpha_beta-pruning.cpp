
#include<bits/stdc++.h> 
using namespace std; 

// Initial values of 
// Aplha and Beta 
const int MAX = 1000; 
const int MIN = -1000; 

// Returns optimal value for 
// current player(Initially called 
// for root and maximizer) 
int minimax(int depth, int IndexofNode, 
			bool maximizingPlayer, 
			int values[], int alpha, 
			int beta) 
{ 
	
	// Terminating condition. i.e 
	// leaf node is reached 
	if (depth == 3) 
		return values[IndexofNode]; 

	if (maximizingPlayer) 
	{ 
		int optimal= MIN; 

		// Recur for left and 
		// right children 
		for (int i = 0; i < 2; i++) 
		{ 
			
			int val = minimax(depth + 1, IndexofNode * 2 + i, 
							false, values, alpha, beta); 
			optimal= max(optimal, val); 
			alpha = max(alpha, optimal); 

			// Alpha Beta Pruning 
			if (beta <= alpha) 
				break; 
		} 
		return optimal; 
	} 
	else
	{ 
		int optimal= MAX; 

		// Recur for left and 
		// right children 
		for (int i = 0; i < 2; i++) 
		{ 
			int val = minimax(depth + 1, IndexofNode * 2 + i, 
							true, values, alpha, beta); 
			optimal = min(optimal, val); 
			beta = min(beta, optimal); 

			// Alpha Beta Pruning 
			if (beta <= alpha) 
				break; 
		} 
		return optimal; 
	} 
} 

// Driver Code 
int main() 
{ 
	int x=0;
	int values[8];
	
	cout<<"Input the value for array \n";
	
	for(x=0;x<8;x++)
	{
		cout<<"Enter value "<<x+1<<"\n";
		cin>>values[x];
	} 
	cout <<"The optimal value is : "<< minimax(0, 0, true, values, MIN, MAX);
	return 0; 
} 

