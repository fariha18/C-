/*******************************************************************************
 * Name        : stairclimber.cpp
 * Author      : Fariha Rahman
 * Date        : 02/20/2022
 * Description : Lists the number of ways to climb n stairs.
 * Pledge      : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

vector< vector<int> > get_ways(int num_stairs) {
    // TODO: Return a vector of vectors of ints representing
    // the different combinations of ways to climb num_stairs
    // stairs, moving up either 1, 2, or 3 stairs at a time.

    vector<vector<int>>ways;
    vector<vector<int>>result;

    if(num_stairs <= 0){
        ways.push_back(vector<int>());
    }
    else{
        for(int i = 1; i < 4; i++){
            if(num_stairs >= i){
                result = get_ways(num_stairs - i);
                for(unsigned int j = 0; j < result.size(); j++){
                    result[j].push_back(i);
                    ways.push_back(result[j]);
                }
            }
        }
    }
    return ways;
}

void display_ways(const vector< vector<int> > &ways) {
    // TODO: Display the ways to climb stairs by iterating over
    // the vector of vectors and printing each combination.
    for(unsigned int i = 0; i < ways.size(); i++){
        unsigned int x;
        x = ways.size();
        unsigned int count;
        count = 1;
        while(x >= 10){
            count++;
            x = x / 10;
        }
        cout << setw(count) << i + 1 << ". [";
        for(unsigned int j = ways[i].size() - 1; j >= 1; j--){
            cout << ways[i][j] << ", ";
        }
        cout << ways[i][0] << "]" << endl;
    }
}

int main(int argc, char * const argv[]) {
int n;
istringstream check;

if(argc != 2){
    cerr << "Usage: ./stairclimber <number of stairs>" << endl;
    return 1;
}

check.str(argv[1]);
if(!(check >> n) || n < 1){
    cerr << "Error: Number of stairs must be a positive integer."<< endl;
    return 1;
}

check.clear();
vector<vector<int>>result = get_ways(n);
if(n == 1){
    cout << n << " way to climb " << n << " stair." << endl;
    display_ways(result);
}
else{
    cout << result.size() << " ways to climb " << n << " stairs." << endl;
    display_ways(result);

}
return 0;
}
