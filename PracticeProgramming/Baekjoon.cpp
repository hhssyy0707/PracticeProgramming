#include <iostream>
#include "main.h"
using namespace std;


void MinMax() {
    int n;
    int m;
    cin >> n;
    //int* anumber = new int[n];
    vector<int> vnumber;
    for (int i = 0; i < n; i++) {
        //cin>>anumber[i];
        cin >> m;
        vnumber.push_back(m);
    }
    int max = *max_element(vnumber.begin(), vnumber.end());
    int min = *min_element(vnumber.begin(), vnumber.end());
    cout << max << min;
}

void InputBall() {
    int n;
    int m;
    int i_str, j_fns, k;
    cin >> n >> m;
    int* Basket = new int[n];
    fill_n(Basket, m + 1, 0);

    for (int i = 0; i < m; i++) {//입력m번 받기
        cin >> i_str >> j_fns >> k;
        for (i_str; i_str <= j_fns; i_str++) {
            Basket[i_str - 1] = k;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << Basket[i] << " ";
    }
}

void ChangeBall() {
    int n;
    int m;
    int iball, jball;

    cin >> n >> m;
    int* Basket = new int[n];

    for (int i = 0; i < n; i++) {
        Basket[i] = i + 1;
    }

    for (int j = 0; j < n; j++) {
        cout << Basket[j] << " ";
    }
    cout << endl;

    for (int i = 0; i < m; i++) {

        int temp;
        cin >> iball >> jball;
        temp = Basket[iball - 1];
        Basket[iball - 1] = Basket[jball - 1];
        Basket[jball - 1] = temp;

        /*
        for (int i = 0; i < n; i++) {
            cout << Basket[i] << " ";
        }*/
    }

    for (int i = 0; i < n; i++) {
        cout << Basket[i] << " ";
    }
}


void ArrayAdd() {
    int column, row;
    int element;
    cin >> column >> row;

    int** mapA = new int* [row];
    int** mapB = new int* [row];

    for (int i = 0; i < row; i++) {
        mapA[i] = new int[column];
        mapB[i] = new int[column];
    }

    for (int i = 0; i < column; i++) {
        for (int j = 0; j < row; j++) {
            cin >> mapA[i][j];
        }
    }


    for (int i = 0; i < column; i++) {
        for (int j = 0; j < row; j++) {
            cin >> mapB[i][j];
        }
    }

    for (int i = 0; i < column; i++) {
        for (int j = 0; j < row; j++) {
            cout << mapA[i][j] + mapB[i][j] << " ";
        }
        cout << endl;
    }
}

void MaxValue() {
    int mapMax[9][9];
    int numMax = 0;
    int row, col;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> mapMax[i][j];
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (numMax < mapMax[i][j]) {
                numMax = mapMax[i][j];
            }
        }
    }


    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (numMax == mapMax[i][j]) {
                row = i;
                col = j;
            }
        }
    }
    cout << numMax << endl;
    cout << row + 1 << "col" << col + 1 << "row" << endl;
}

void BlackPart() {
    int paperNum;
    int mapMax[100][100];
    int count = 0;
    int lenght = 10;//가로세로길이10

    cin >> paperNum;//3개

    int** paperPosition = new int* [paperNum];

    for (int i = 0; i < paperNum; i++) {
        paperPosition[i] = new int[2];//x,y location
    }
    for (int i = 0; i < paperNum; i++) {
        cin >> paperPosition[i][0] >> paperPosition[i][1];
    }

    fill(mapMax[0], mapMax[100], 0);

    for (int i = 0; i < paperNum; i++) {
        for (int j = paperPosition[i][1]; j < paperPosition[i][1] + 10; j++) {
            for (int k = paperPosition[i][0]; k < paperPosition[i][0] + 10; k++) {
                mapMax[j][k]++;
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            cout << mapMax[i][j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (mapMax[i][j] > 0) {
                count++;
            }
        }
    }

    cout << count;
}
