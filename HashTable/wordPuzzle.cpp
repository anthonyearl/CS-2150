//Brandon Feng yf2km 5PM 3/16/17 wordPuzzle.cpp
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include <iomanip>
#include "timer.h"
#include "hashTable.h"

using namespace std;

// We create a 2-D array of some big size, and assume that the grid
// read in will be less than this size (a valid assumption for lab 6)
#define MAXROWS 500
#define MAXCOLS 500
#define MAXLEN 22
char grid[MAXROWS][MAXCOLS];
timer t;

// Forward declarations
bool readInGrid (string filename, int &rows, int &cols);
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);


int main (int argc, char ** argv)
{
  string dict = argv[1];
  ifstream scan(dict.c_str());
  string dummy;
  int nLines = 0;
  while (getline(scan, dummy))
    {
	nLines++;
    }
  scan.close();

  scan.open(dict.c_str());
  hashTable *hTable = new hashTable((0.75*nLines));
  string cur;
  while (scan.good())
    {
	getline(scan, cur);
	hTable->insert(cur);
    }
  scan.close();
  
  string grid = argv[2];
  scan.open(grid.c_str());
  int rows = 0;
  int cols = 0;
  int found = 0;
  string res;
  string dir;
  readInGrid(grid.c_str(), rows, cols);
  
  t.start();
  for ( int curRow = 0; curRow < rows; curRow++ ) {
      for ( int curCol = 0; curCol < cols; curCol++ ) {
	  for ( int curDir = 0; curDir <= 7; curDir++) {
	      for ( int len = 3; len <= MAXLEN; len++ ) {
		  string curWord = getWordInGrid (curRow, curCol, curDir, len, rows,cols);
		  if (curWord.length() < len) break;
		  if (hTable->contains(curWord)) {
		      found++;
		      switch (curDir) {
			  case 0:
			      dir = "N";
			      break;
			  case 1:
			      dir = "NE";
			      break;
			  case 2:
			      dir = "E";
			      break;
			  case 3:
			      dir = "SE";
			      break;
			  case 4:
			      dir = "S";
			      break;
			  case 5:
			      dir = "SW";
			      break;
			  case 6:
			      dir = "W";
			      break;
			  case 7:
			      dir = "NW";
			      break;
		      }
			  stringstream ss;
			  ss << dir << " (" << curRow << ", " << curCol << "): \t" << curWord << endl;
			  res += ss.str();
		  }
	      }
	  }
      }
  }
  t.stop();
  double time = t.getTime();
  
  cout << res;
  cout << found << " words found" << endl;
  cout << "Found all words in " << std::fixed << time << " seconds" << endl;
  int ti = (int)(time*1000);
  cout << ti << endl;
}


/** This function will read in a grid file, as per the format in the
 * CS 2150 lab 6 document, into a global grid[][] array.  It uses C++
 * file streams, and thus requires the the <fstream> #include header.
 *
 * @return true or false, depending on whether the file was
 *         successfully opened.
 * @param filename The file name to read in -- it's assumed to be in
 *                 the file format described in the lab document.
 * @param rows The number of rows as specified in the input file;
 *             as this is a reference, it is set by the function.
 * @param cols The number of columnss as specified in the input file;
 *             as this is a reference, it is set by the function.
 */
bool readInGrid (string filename, int &rows, int &cols) {
    // a C++ string to hold the line of data that is read in
    string line;
    // set up the file stream to read in the file (takes in a C-style
    // char* string, not a C++ string object)
    ifstream file(filename.c_str());
    // upon an error, return false
    if ( !file.is_open() )
        return false;
    // the first line is the number of rows: read it in
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the second line is the number of cols: read it in and parse it
    file >> cols;
    //cout << "There are " << cols << " cols." << endl;
    getline (file,line); // eats up the return at the end of the line
    // the third and last line is the data: read it in
    getline (file,line);
    // close the file
    file.close();
    // convert the string read in to the 2-D grid format into the
    // grid[][] array.  In the process, we'll print the grid to the
    // screen as well.
    int pos = 0; // the current position in the input data
    for ( int r = 0; r < rows; r++ ) {
        for ( int c = 0; c < cols; c++ ) {
            grid[r][c] = line[pos++];
            //cout << grid[r][c];
        }
	// cout << endl;
    }
    // return success!
    return true;
}



/** This function will retrieve a word in a grid of letters in a given
 * direction.  If the end of the grid is encountered before the length
 * of the desired string is reached, then a shorter string will be
 * returned.  The data is retrieved from a global char grid[][]
 * array, which is assumed to be defined (and in scope).  NOTE: The
 * return value is a static char[][] variable (for efficiency
 * reasons), so a successive return value will overwrite a previous
 * return value.
 *
 * @return A char* containing the letters in the provided direction
 *         (NOTE: it is returned in a static char array).
 * @param startRow The starting (row,col) position to find the word.
 * @param startCol The starting (row,col) position to find the word.
 * @param dir The direction to move: 0 is north (upwards), 1 is
 *            northeast, and it rotates around clockwise until it
 *            reaches 7 for northwest.
 * @param len The desired length of the string to return (assuming
 *            the edge of the grid is not reached--if the edge of the
 *            grid is reached, it will return as many characters as
 *            possible up to the edge of the grid, so the returned
 *            string may not have the same length as this parameter
 *            indicates).
 * @param numRows The number of rows in the global char grid[][]
 *                array.
 * @param numCols The number of columns in the global char grid[][]
 *                array.
 */
char* getWordInGrid (int startRow, int startCol, int dir, int len,
                     int numRows, int numCols) {
    // the static-ness of this variable prevents it from being
    // re-declared upon each function invocataion.  It also prevents it
    // from being deallocated between invocations.  It's probably not
    // good programming practice, but it's an efficient means to return
    // a value.
    static char output[256];
    // make sure the length is not greater than the array size.
    if ( len >= 255 )
        len = 255;
    // the position in the output array, the current row, and the
    // current column
    int pos = 0, r = startRow, c = startCol;
    // iterate once for each character in the output
    for ( int i = 0; i < len; i++ ) {
        // if the current row or column is out of bounds, then break
        if ( (c >= numCols) || (r >= numRows) || (r < 0) || (c < 0) )
            break;
        // set the next character in the output array to the next letter
        // in the grid
        output[pos++] = grid[r][c];
        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }
    // set the next character to zero (end-of-string)
    output[pos] = 0;
    // return the string (a C-style char* string, not a C++ string
    // object)
    return output;
}
