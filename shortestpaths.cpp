/*******************************************************************************
 * Name    : shortestpaths.cpp
 * Author  : Fariha Rahman and Fiona Brockner
 * Version : 1.0
 * Date    : April 28, 2022
 * Description : Solve the all pairs shortest paths problem with Floyd’s algorithm.
 * Pledge : I pledge my honor that I have abided by the Stevens Honor System.
 ******************************************************************************/
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

long** pathLengths;
long** intermediateVertices;
long INF = numeric_limits<long>::max();

//find number of digits for display_table function
long len(long num){
  long count = 1;
  while((num / 10) >= 1){
    count ++;
    num /= 10;
  }
  return count;
}

//displays the matrix on the screen formatted as a table.
void display_table(long** const matrix, const string &label, long num_vertices,
                   const bool use_letters = false) {
  cout << label << endl;
  long max_val = 0;
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      long cell = matrix[i][j];
      if (cell < INF && cell > max_val) {
        max_val = matrix[i][j];
      }
    }
  }
  int max_cell_width = use_letters ? len(max_val) :
    len(max(static_cast<long>(num_vertices), max_val));
  cout << ' ';
  for (int j = 0; j < num_vertices; j++) {
    cout << setw(max_cell_width + 1) << static_cast<char>(j + 'A');
  }
  cout << endl;
  for (int i = 0; i < num_vertices; i++) {
    cout << static_cast<char>(i + 'A');
    for (int j = 0; j < num_vertices; j++) {
      cout << " " << setw(max_cell_width);
      if (matrix[i][j] == INF) {
        cout << "-";
      } else if (use_letters) {
        cout << static_cast<char>(matrix[i][j] + 'A');
      } else {
        cout << matrix[i][j];
      }
    }
    cout << endl;
  }
  cout << endl;
}

//traces intermediate vertices for full path 
vector<char> backTracker(long** pathLengths, long** matrix, long num_vertices, long index1, long index2){
    vector<char> left;
    vector<char> right;

    if(matrix[index1][index2] == matrix[0][0]){
      char firstVertex = 'A' + index1;
      char secondVertex = 'A' + index2;
      left.push_back(secondVertex);
      left.push_back(firstVertex);
      return left;
    }
    else{
      left = backTracker(pathLengths, matrix, num_vertices, index1, intermediateVertices[index1][index2]);
      right = backTracker(pathLengths, matrix, num_vertices, intermediateVertices[index1][index2], index2);
      right.insert(right.end(), left.begin()+1, left.end());
      return right;
    }
}

//implements the floyd warshall algorithms to find all pairs shortest paths 
void floydWarshall(long** distance, long num_vertices){
    pathLengths = new long*[num_vertices];
    intermediateVertices = new long*[num_vertices];

    //fills intermediateVertices with INF
    for(long i = 0; i < num_vertices; i++){
        intermediateVertices[i] = new long[num_vertices];
        for (long j = 0; j < num_vertices; j++){
          intermediateVertices[i][j] = INF;
        }
    }

    //fills pathLengths with distance matrix
    for (long i = 0; i < num_vertices; i++){
      pathLengths[i] = new long[num_vertices];
        for (long j = 0; j < num_vertices; j++){
            pathLengths[i][j] = distance[i][j];
        }
    }

    //Floyd Warshall Algorithm all pairs shortest path
    for (long i = 0; i < num_vertices; i++){
        for (long j = 0; j < num_vertices; j++){
            for (long k = 0; k < num_vertices; k++){
                if (pathLengths[j][i] != INF && pathLengths[i][k] != INF && pathLengths[j][i] + pathLengths[i][k] < pathLengths[j][k]){
                    pathLengths[j][k] = pathLengths[j][i] + pathLengths[i][k];
                    intermediateVertices[j][k] = i;
                }
            }
        }
    }

  display_table(distance, "Distance matrix:", num_vertices, false);
  display_table(pathLengths, "Path lengths:", num_vertices, false);
  display_table(intermediateVertices, "Intermediate vertices:", num_vertices, true);

  //print out paths in format A -> B 
  vector<char> vertexPath;
	for(long i = 0; i < num_vertices; i++){
	  char firstVertex = 'A' + i;
		for(long j = 0; j < num_vertices; j++){
		    char secondVertex = 'A' + j;
        if (i==j){ 
            cout << firstVertex << " -> " << secondVertex << ", distance: 0, path: " << firstVertex << endl;
        } 
        else{
          vertexPath = backTracker(pathLengths, intermediateVertices, num_vertices, i, j);
          reverse(vertexPath.begin(),vertexPath.end());
          cout << firstVertex << " -> " << secondVertex << ", distance: ";

          if(pathLengths[i][j] == INF){
              cout << "infinity, path: none";
          }
          else {
            cout << pathLengths[i][j] << ", path: " << vertexPath[0];
            for(size_t k = 1; k < vertexPath.size(); k++){
              cout << " -> " << vertexPath[k];
            }
          }
          cout << endl;
        }
      }
    }
}

//checks if a string is a number
bool isNumber(string input){
	for(size_t i = 0; i < input.size(); i++){
		if(!(isdigit(input[i]))){
			return false;
		}
	}
	return true;
}

//checks if string is negative by checking first index for -
bool isValidNumber(string input) {
  if (input[0] == '-' || input[0] == '0'){
    return false;
  }
  else{
    return true;
  }
}

//deletes matrix
void deleteHeap(long **array, long W){
    for(long i = 0; i < W; i++){
        delete [] array[i];
    }
    delete [] array;
}

int main(int argc, const char *argv[]) {
    // Make sure the right number of command line arguments exist.
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 0;
    }
    // Create an ifstream object.
    ifstream input_file(argv[1]);
    // If it does not exist, print an error message.
    if (!input_file) {
        cerr << "Error: Cannot open file '" << argv[1] << "'." << endl;
        return 1;
    }
    // Add read errors to the list of exceptions the ifstream will handle.
    input_file.exceptions(ifstream::badbit);
    string line;
    vector<string> inputVector;
    try {
        unsigned int line_number = 1;
        // Use getline to read in a line.
        // See http://www.cplusplus.com/reference/string/string/getline/
        while (getline(input_file, line)) {
            //cout << line_number << ":\t" << line << endl;
            inputVector.push_back(line);
            ++line_number;
        }
        // Don't forget to close the file.
        input_file.close();
    } catch (const ifstream::failure &f) {
        cerr << "Error: An I/O error occurred reading '" << argv[1] << "'.";
        return 1;
    }

    //checks if number of vertices is an int between 1 and 26
    for (size_t i = 0; i < inputVector[0].length(); i++){
        if (isdigit(inputVector[0][i]) == false){
          cerr << "Error: Invalid number of vertices '" << inputVector[0] << "' on line 1.";
          return 1;
        }
    }

    int num_vertices = stoi(inputVector[0]);

    if (num_vertices > 26 || num_vertices < 1){
        cerr << "Error: Invalid number of vertices '" << num_vertices << "' on line 1.";
        return 1;
    }

    //creates distance matrix and fills with INF or 0
    long** distance = new long*[num_vertices];
       for(long i = 0; i < num_vertices; i++){
           distance[i] = new long[num_vertices];
           for(long j = 0; j < num_vertices; j++){
               if(i != j){
                   distance[i][j] = INF;
               }
               else{
                   distance[i][j] = 0;
               }
           }
       }

    char space = ' ';
    //loops through every line in the input file
    for (size_t i = 1; i < inputVector.size(); i++) {
      
      //checks if there are 3 components per lines
      int countSpaces = 0;
      string inputLine = inputVector[i];
      for(size_t j = 0; j < inputLine.length();j++){
        if (inputLine[j] == space){
          countSpaces ++;
        }
      }
      if (countSpaces != 2){
        cerr << "Error: Invalid edge data '" << inputLine << "' on line " << i + 1 << "." << endl;
        deleteHeap(distance, num_vertices);
        return 1;
      }

      string firstComponent;
      string secondComponent;
      string thirdComponent;

      int firstSpaceIndex = 0;
      int secondSpaceIndex = 0;

      //splits first, second, and third components
      for(size_t j = 0; j < inputLine.length();j++){
        if(inputLine[j] == space){
          firstSpaceIndex = j;
          break;
        }
        firstComponent += inputLine[j];
      }

      for(size_t j = firstSpaceIndex+1; j < inputLine.length();j++){
        if(inputLine[j] == space){
          secondSpaceIndex = j;
          break;
        }
        secondComponent += inputLine[j];
      }

      for(size_t j = secondSpaceIndex + 1; j < inputLine.length();j++){
        if(inputLine[j] == space){
          break;
        }
        thirdComponent += inputLine[j];
      }

      //checks if component is number or valid letter
      if (isNumber(firstComponent) || firstComponent[0] < 65 || firstComponent[0] > (64 + num_vertices) || firstComponent.size()>1){
          cerr << "Error: Starting vertex '" << firstComponent << "' on line " << i + 1 
                << " is not among valid values A-" << char(64 + num_vertices) << "."  << endl;
                deleteHeap(distance, num_vertices);
                return 1;
      }
      if (isNumber(secondComponent)|| secondComponent[0] < 65 || secondComponent[0] > (64 + num_vertices)|| secondComponent.size()>1){
          cerr << "Error: Ending vertex '" << secondComponent << "' on line " << i + 1 
                << " is not among valid values A-" << char(64 + num_vertices) << "."  << endl;
                deleteHeap(distance, num_vertices);
                return 1;
      }

     //checks if edge weight is positive integer
      if (!(isNumber(thirdComponent)) || !(isValidNumber(thirdComponent))){
          cerr << "Error: Invalid edge weight '" << thirdComponent << "' on line " << i + 1 << "." << endl;
          deleteHeap(distance, num_vertices);
          return 1;
      }

      //fills distance matrix
      distance[firstComponent[0]-65][secondComponent[0]- 65] =  stol(thirdComponent);
  }

  floydWarshall(distance, num_vertices);

  deleteHeap(distance, num_vertices);
  deleteHeap(pathLengths, num_vertices);
  deleteHeap(intermediateVertices, num_vertices);

  return 0;
}