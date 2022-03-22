#include <iostream>
#include <string.h>
#include <math.h>
#include <iomanip>
using namespace std;

void show_matrix();
void add_matrix();
void subtract_matrix();
void multiply_matrix();
void trans_matrix();
void trans_cofactor();
double determinant(double matrix[50][50], int r);
void cofactor(double matrix[50][50]);
void inverse_matrix();
void multiply_invmatrix();
void divide_matrix();

double matrix_A[50][50], matrix_B[50][50];
int column_A, row_A;
int column_B, row_B;
double res[50][50];
double transpose[50][50];
double cofac[50][50];
double inv[50][50];
bool large;
bool square;
bool inf;

int main()
{
    cout << "Enter Matrix A number of columns: "; cin >> column_A;
    cout << "Enter Matrix A number of rows: "; cin >> row_A;
    cout << "Enter Matrix B number of columns: "; cin >> column_B;
    cout << "Enter Matrix B number of rows: "; cin >> row_B;

    cout << "Enter Matix A Values: ";
    for (int i = 0; i < row_A; i++) {
        for (int j = 0; j < column_A; j++)
            cin >> matrix_A[i][j];
    }

    cout << "Enter Matix B Values: ";
    for (int i = 0; i < row_B; i++) {
        for (int j = 0; j < column_B; j++)
            cin >> matrix_B[i][j];
    }

    char another_options;
    do {
        cout << "Choose from the following options: \n";
        cout << " A.Show matrix\n B.Add matrices\n C.Subtract matrices\n D.Multiply matrices\n E.Transpose matrix\n F.Divide matrices\n";
        cout << "Choice: ";
        char options;   cin >> options;

        if (options == 'A' || options == 'a')
            show_matrix();
        else if (options == 'B' || options == 'b')
            add_matrix();
        else if (options == 'C' || options == 'c')
            subtract_matrix();
        else if (options == 'D' || options == 'd')
            multiply_matrix();
        else if (options == 'E' || options == 'e')
            trans_matrix();
        else if (options == 'F' || options == 'f')
            divide_matrix();
        else
            cout << "Invalid Choice\n";
        cout << "Another Options (y/n): ";   cin >> another_options;
    } while (another_options == 'y' || another_options == 'Y');

    return 0;
}
void show_matrix() {
    char matrix_choice;
    cout << " A.Matrix A\n B. Matrix B\n"; cout << "Choice: "; cin >> matrix_choice;
    if (matrix_choice == 'A' || matrix_choice == 'a') {
        cout << "Matrix A: \n";
        for (int i = 0; i < row_A; i++) {
            for (int j = 0; j < column_A; j++) {
                cout << matrix_A[i][j] << " ";
            }
            cout << endl;
        }
    }
    else if (matrix_choice == 'B' || matrix_choice == 'b') {
        cout << "Matrix B: \n";
        for (int i = 0; i < row_B; i++) {
            for (int j = 0; j < column_B; j++) {
                cout << matrix_B[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
        cout << "Invalid Option\n";
}
void add_matrix() {
    if (column_A == column_B && row_A == row_B) {
        for (int i = 0; i < row_B; i++) {
            for (int j = 0; j < column_B; j++)
                cout << matrix_A[i][j] + matrix_B[i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "Number of rows and columns in both matrices has to be equal\n";
}
void subtract_matrix() {
    if (column_A == column_B && row_A == row_B) {
        for (int i = 0; i < row_B; i++) {
            for (int j = 0; j < column_B; j++)
                cout << matrix_A[i][j] - matrix_B[i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "Number of rows and columns in both matrices has to be equal\n";
}
void multiply_matrix() {
    if (column_A == row_B) {
        for (int i = 0; i < row_A; i++) {
            for (int j = 0; j < column_B; j++) {
                res[i][j] = 0;
                for (int z = 0; z < row_B; z++)
                    res[i][j] += matrix_A[i][z] * matrix_B[z][j];
            }
        }
        for (int i = 0; i < row_A; i++) {
            for (int j = 0; j < column_B; j++)
                cout << res[i][j] << " ";
            cout << endl;
        }
    }
    else
        cout << "Matrix A columns and Matrix B rows has to be equal\n";
}
void trans_matrix() {
    char matrix_choice;
    cout << " A.Matrix A\n B. Matrix B\n"; cout << "Choice: "; cin >> matrix_choice;
    if (matrix_choice == 'A' || matrix_choice == 'a') {
        cout << "Matrix A: \n";
        for (int i = 0; i < row_A; i++) {
            for (int j = 0; j < column_A; j++){
                cout << matrix_A[j][i] << " ";
            }
            cout << endl;
        }
    }
    else if (matrix_choice == 'B' || matrix_choice == 'b') {
        cout << "Matrix B: \n";
        for (int i = 0; i < row_B; i++) {
            for (int j = 0; j < column_B; j++){
                cout << matrix_B[j][i] << " ";
            }
            cout << endl;
        }
    }
    else
        cout << "Invalid Option\n";
}
void trans_cofactor(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            transpose[i][j]= cofac[j][i];
        }
    }
}
double determinant( double matrix[50][50], int r) {
    double det = 0;
   double submatrix[50][50];
   if(r==1){
       return matrix[0][0];
   }
   if (r == 2)
   return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
   else {
      for (int x = 0; x < r; x++) {
         int subi = 0;
         for (int i = 1; i < r; i++) {
            int subj = 0;
            for (int j = 0; j < r; j++) {
               if (j == x)
               continue;
               submatrix[subi][subj] = matrix[i][j];
               subj++;
            }
            subi++;
         }
         det = det + (pow(-1, x) * matrix[0][x] * determinant( submatrix, r - 1 ));
      }
   }
    return det;
}
void cofactor(double matrix[50][50]){

    cofac[0][0] = (matrix[1][1]*matrix[2][2]) - (matrix[2][1]*matrix[1][2]);
    cofac[0][1] = -1*((matrix[1][0]*matrix[2][2]) - (matrix[2][0]*matrix[1][2]));
    cofac[0][2] = (matrix[1][0]*matrix[2][1]) - (matrix[2][0]*matrix[1][1]);
    cofac[1][0] = -1*((matrix[0][1]*matrix[2][2]) - (matrix[2][1]*matrix[0][2]));
    cofac[1][1] = (matrix[0][0]*matrix[2][2]) - (matrix[2][0]*matrix[0][2]);
    cofac[1][2] = -1*((matrix[0][0]*matrix[2][1]) - (matrix[2][0]*matrix[0][1]));
    cofac[2][0] = (matrix[0][1]*matrix[1][2]) - (matrix[1][1]*matrix[0][2]);
    cofac[2][1] = -1*((matrix[0][0]*matrix[1][2]) - (matrix[1][0]*matrix[0][2]));
    cofac[2][2] = (matrix[0][0]*matrix[1][1]) - (matrix[1][0]*matrix[0][1]); 
}
void inverse_matrix(double matrix[50][50],int r,int c){
    square =true;
    large = false;
    if(r==c){
    if(r==1){
        inv[0][0]=1/matrix[0][0];
    }
    double d=determinant(matrix,r);
        if(d != 0){
        d=1/d;
     if(r == 2){
        inv[0][0] = d*matrix[1][1];
		inv[1][1] = d*matrix[0][0];
		inv[0][1] = -1*d*matrix[0][1];
		inv[1][0] = -1*d*matrix[1][0];
		
    }
    else if(r == 3){
        cofactor(matrix);
        trans_cofactor();
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                inv[i][j]= d*transpose[i][j];
            }
        }
    }
    else{
        cout<<"matrix is too large to proccess";
        large=true;
    }
    }
    else{cout<<"determinant is equal to zero can't find inverse matrix"<<endl;
    inf = true;
    return;
        }
    }
    else{
        square=false;
    }
}
void multiply_invmatrix(){
    double ew;
     for (int i = 0; i < row_A; i++) {
            for (int j = 0; j < column_B; j++) {
                res[i][j] = 0;
                for (int z = 0; z < row_B; z++){
                    res[i][j] += matrix_A[i][z] * inv[z][j];
                }
            }
        }
        for (int i = 0; i < row_A; i++) {
            for (int j = 0; j < column_B; j++){
                
                cout <<fixed << setprecision(2)<<res[i][j] << " ";
            }
            cout << endl;
        }
}
void divide_matrix() {
    if (column_A == row_B) {
        inverse_matrix(matrix_B,row_B,column_B);
        if(inf == false){
        if(square == true && large == false){
        multiply_invmatrix();
        }
        else{
            cout<<"only applicable for square matrix of maximum size 3"<<endl;
        }
    }
    else{
        return;
    }
    }
    else
        cout << "Matrix A columns and Matrix B rows has to be equal\n";
}


