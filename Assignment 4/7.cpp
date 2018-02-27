#include <iostream>
int array[] = {0,0,0,0,0,0,0,0,0};
using namespace std;

class Martrix{
public:
    int A[3][3];
    Martrix(int *arr = array){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                A[i][j] = arr[i*3 + j];
            }
        }
    }

    Martrix operator +(Martrix m2){
        Martrix m3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                m3.A[i][j] = A[i][j] + m2.A[i][j];
            }
        }
        return m3;
    }

    Martrix operator -(Martrix m2){
        Martrix m3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                m3.A[i][j] = A[i][j] - m2.A[i][j];
            }
        }
        return m3;
    }

    Martrix operator *(Martrix m2){
        Martrix m3;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                for(int k = 0; k < 3; k++){
                    m3.A[i][j] += A[i][k] * m2.A[k][j];
                }
            }
        }
        return m3;
    }

    int operator ==(Martrix m2){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(A[i][j] != m2.A[i][j])
                    return 0;
            }
        }
        return 1;
    }

    void disp(){
        for(int i = 0; i < 3; i++){
            cout << endl;
            for(int j = 0; j < 3; j++){
                cout << A[i][j] << "\t";
            }
        }
    }
};

int main(){
    int val[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Martrix m1(val), m2(val), m3;
    m3 = m1 + m2;
    m3.disp();
    m3 = m1 - m2;
    cout << endl;
    m3.disp();
    m3 = m1 * m2;
    cout << endl;
    m3.disp();
    int res = m1 == m2;
    cout << endl << endl << res;
    return 0;
}
