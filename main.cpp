/*
 * main.cpp
 *
 *  Created on: Nov 17, 2019
 *      Author: denni
 */
#include <iostream>
#include <vector>
#include "multiply.h"
using namespace std;

int main() {
    int arows;
    int acols;
    int brows;
    int bcols;
    bool accurate = true;;
    while(true){
        while(accurate){
            cout << "Enter first matrix rows\n";
            cin >> arows;
            cout << "Enter first matrix columns\n";
            cin >> acols;
            cout<<"Enter second matrix rows\n";
            cin >> brows;
            cout << "Enter first matrix columns\n";
            cin >> bcols;

            if (acols == brows){
                accurate = false;

            }
        }
        
        vector<vector<int> > a(arows, vector<int>(acols));
        vector<vector<int> > b(brows, vector<int>(bcols));

        for (vector<int> i : a){
            for (int j : i){
                cout << j << " ";
            }
            cout << "\n";
        }

        cout << "\n";
        for (vector<int> i : b){
            for (int j : i){
                cout << j << " ";
            }
            cout << "\n";
        }

        cout << "\n";

        vector<vector<int> > c = multiply(a, b);

        for (vector<int> x: c){
            for (int y : x){
                cout << y << " ";
            }
            cout << "\n";
        }
        break;
    }
    return 0;
}