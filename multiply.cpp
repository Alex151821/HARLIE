/*
 * multiply.cpp
 *
 *  Created on: Nov 17, 2019
 *      Author: denni
 */
#include <vector>
#include <iostream>
#include "multiply.h"

using namespace std;

vector<vector<int> > multiply(vector<vector<int> > a, vector<vector<int> > b){
  vector<vector<int> > c(a.size());
  int total = 0;

  for (int arow = 0; arow < a.size(); arow++){
    int bcol = 0;
    int acol = 0;
    //cout << "\n";
    //cout << "\n";

    for (int bcol = 0; bcol < b[0].size(); bcol ++){
      for (int brow = 0; brow < b.size(); brow ++){
        //cout << b[brow][bcol] << " ";
        //cout << a[arow][acol] << "\n";

        total += (a[arow][acol]* b[brow][bcol]);
        //cout << total << "\n";
        acol ++;

      }
    c[arow].push_back(total);
    total = 0;
    acol = 0;

    }
  }



//cout << "\n";
/*
  for (vector<int> i : c){
    for (int j : i){
      cout << j << " ";
    }
    cout << "\n";
  }*/
  return c;
}