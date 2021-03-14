#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<float>> A(n, vector<float>(n + 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    for (int i = 0; i < n; i++)
        cin >> A[i][n];

    for (int j = 0; j < n; j++) {
        float Max = -2e9;
        int Max_i = -1;
        for (int i = j; i < n; i++) {
            if (A[i][j] > Max) {
                Max = A[i][j];
                Max_i = i;
            }
        }
        swap(A[j], A[Max_i]);
        for (int i = j; i < n; i++) {
            float x = A[i][j];
            for (int k = j; k < n + 1; k++)
                A[i][k] /= x;
        }
        
        for (int i = j + 1; i < n; i++) {
            for (int k = j; k < n + 1; k++) {
                A[i][k] -= A[j][k];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << A[i][j] << ' ';
        cout << "| " <<  A[i][n] << '\n';
    }
}

