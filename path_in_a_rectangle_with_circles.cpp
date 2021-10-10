// C++ program to find out path in
// a rectangle containing circles.
#include <iostream>
#include <math.h>
#include <vector>
 
using namespace std;
 
// Function to find out if there is
// any possible path or not.
bool isPossible(int m, int n, int k, int r, vector<int> X,
                vector<int> Y)
{
    // Take an array of m*n size and
    // initialize each element to 0.
    int rect[m][n] = { 0 };
 
    // Now using Pythagorean theorem find if a
    // cell touches or within any circle or not.
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int p = 0; p < k; p++) {
                if (sqrt((pow((X[p] - 1 - i), 2)
                          + pow((Y[p] - 1 - j), 2)))
                    <= r) {
                    rect[i][j] = -1;
                }
            }
        }
    }
 
    // If the starting cell comes within
    // any circle return false.
    if (rect[0][0] == -1)
        return false;
 
    // Now use BFS to find if there
    // is any possible path or not.
 
    // Initialize the queue which holds
    // the discovered cells whose neighbors
    // are not discovered yet.
    vector<vector<int> > qu;
 
    rect[0][0] = 1;
    qu.push_back({ 0, 0 });
 
    // Discover cells until queue is not empty
    while (!qu.empty()) {
        vector<int> arr = qu.front();
        qu.erase(qu.begin());
        int elex = arr[0];
        int eley = arr[1];
 
        // Discover the eight adjacent nodes.
        // check top-left cell
        if ((elex > 0) && (eley > 0)
            && (rect[elex - 1][eley - 1] == 0)) {
            rect[elex - 1][eley - 1] = 1;
            vector<int> v = { elex - 1, eley - 1 };
            qu.push_back(v);
        }
 
        // check top cell
        if ((elex > 0) && (rect[elex - 1][eley] == 0)) {
            rect[elex - 1][eley] = 1;
            vector<int> v = { elex - 1, eley };
            qu.push_back(v);
        }
 
        // check top-right cell
        if ((elex > 0) && (eley < n - 1)
            && (rect[elex - 1][eley + 1] == 0)) {
            rect[elex - 1][eley + 1] = 1;
            vector<int> v = { elex - 1, eley + 1 };
            qu.push_back(v);
        }
 
        // check left cell
        if ((eley > 0) && (rect[elex][eley - 1] == 0)) {
            rect[elex][eley - 1] = 1;
            vector<int> v = { elex, eley - 1 };
            qu.push_back(v);
        }
 
        // check right cell
        if ((eley < n - 1) && (rect[elex][eley + 1] == 0)) {
            rect[elex][eley + 1] = 1;
            vector<int> v = { elex, eley + 1 };
            qu.push_back(v);
        }
 
        // check bottom-left cell
        if ((elex < m - 1) && (eley > 0)
            && (rect[elex + 1][eley - 1] == 0)) {
            rect[elex + 1][eley - 1] = 1;
            vector<int> v = { elex + 1, eley - 1 };
            qu.push_back(v);
        }
 
        // check bottom cell
        if ((elex < m - 1) && (rect[elex + 1][eley] == 0)) {
            rect[elex + 1][eley] = 1;
            vector<int> v = { elex + 1, eley };
            qu.push_back(v);
        }
 
        // check bottom-right cell
        if ((elex < m - 1) && (eley < n - 1)
            && (rect[elex + 1][eley + 1] == 0)) {
            rect[elex + 1][eley + 1] = 1;
            vector<int> v = { elex + 1, eley + 1 };
            qu.push_back(v);
        }
    }
 
    // Now if the end cell (i.e. bottom right cell)
    // is 1(reachable) then we will send true.
    return (rect[m - 1][n - 1] == 1);
}
 
// Driver Program
int main()
{
 
    // Test case 1
    int m1 = 5, n1 = 5, k1 = 2, r1 = 1;
    vector<int> X1 = { 1, 3 };
    vector<int> Y1 = { 3, 3 };
   
    // Function call
    if (isPossible(m1, n1, k1, r1, X1, Y1))
        cout << "Possible" << endl;
    else
        cout << "Not Possible" << endl;
 
    // Test case 2
    int m2 = 5, n2 = 5, k2 = 2, r2 = 1;
    vector<int> X2 = { 1, 1 };
    vector<int> Y2 = { 2, 3 };
   
    // Function call
    if (isPossible(m2, n2, k2, r2, X2, Y2))
        cout << "Possible" << endl;
    else
        cout << "Not Possible" << endl;
 
    return 0;
}
