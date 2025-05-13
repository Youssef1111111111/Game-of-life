
// File: game of life.cpp
// Author: Youssef Yasser Elsayed
// Section: S11,12
// ID: 20230519 
// Date: 26 Nov 2024
// This is conway's game of life



#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class Universe {
private:
    int rows, columns;
    vector<vector<int>> grid;

public:
    

    void intialize() {
        cout << YELLOW << "Please enter the number of rows: " << RESET << "\n";
        cin >> rows;
        cin.ignore();
        cout << YELLOW << "Please enter the number of columns: " << RESET << "\n";
        cin >> columns;
        cin.ignore();

        grid = vector<vector<int>>(rows, vector<int>(columns, 0));
    }

    void display() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                cout << (grid[i][j] ? "1" : "0") << " ";
            }
            cout << endl;
        }
    }

    void reset() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                grid[i][j] = 0;
            }
        }
    }

    int count_neighbours(int row, int col){
        int neighbors = 0;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) 
                  continue; 
                int r = row + i, c = col + j;
                if (r >= 0 && r < rows && c >= 0 && c < columns) {
                    neighbors += grid[r][c];
                }
            }
        }
        return neighbors;

    }

    void next_generations(){
        for(int i =0; i < rows ; i++){
            for(int j =0 ; j< columns  ; j++){
                   
                int live_cell = count_neighbours(i,j); 
                grid[i][j] = implement_rule(live_cell , grid[i][j]);
                
            }

        }

    }

    int implement_rule(int live_cell , int type){
        if(live_cell < 2 && type ==1){
            return 0;
        }
        else if ( (live_cell == 2 || live_cell ==3)&& type ==1 )
        {
            return 1;
        }
        else if (live_cell >3 && type ==1){
            return 0 ;
        }
        else if (live_cell == 3 && type ==0 ){
            return 1;
        }
        else return type;


    }

    void run(){
        Universe universe;
        universe.intialize();
        universe.display();
        

        char choice = 'y';
        while (choice == 'y' || choice == 'Y') {
            universe.make_cell_alive();
            universe.display();

            cout << MAGENTA << "Do you want to make another cell alive? y/n: " << RESET;
            cin >> choice;
            cin.ignore();

        }
        while ( true)
        {
                           
            int times;
            int counts = 1;
            cout <<MAGENTA << "what is the number of generations you want?" << RESET<< "\n";
            cin >> times;
            cin.ignore();

            while (times--)
            {
                universe.next_generations();
                cout <<"Generation " << counts << endl;
                universe.display();
                counts++;
            }
            cout<<RED << "Do you want to Reset? (y/n)" << RESET << endl;
            string reset;
            cin >>  reset;
            if ( reset == "y" || reset == "Y")
            {
            universe.reset(); 
            }
            cout<<"Do you want to continue generating ? (y/n)" << endl;
            string continue_generating;
            cin >> continue_generating;
            if ( continue_generating == "y" || continue_generating == "Y")
            {
                continue;
            }
            else break;
        }   
    }

    void make_cell_alive() {
        int row, col;
        cout << CYAN << "Enter the row index of the cell to make alive : " << RESET;
        cin >> row;
        cin.ignore();
        cout << CYAN << "Enter the column index of the cell to make alive : " << RESET;
        cin >> col;
        cin.ignore();

        if (row >= 0 && row < rows && col >= 0 && col < columns) {
            grid[row][col] = 1;
        } else {
            cout << RED << "Invalid indices. Please try again.\n" << RESET;
        }
    }

    
};

int main() {
    Universe universe;
    universe.run();
    return 0;
}
