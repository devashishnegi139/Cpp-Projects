#include<iostream>

using std::cout;
using std::cin;

int a[4][4], b[4][4];
int dd, mm, yy1, yy2, sum{0};

void getInput(){
    cout<<"Enter your date of birth\nDD: ";
    cin>>dd;
    cout<<"MM: ";
    cin>>mm;
    cout<<"YYYY: ";
    int temp;
    cin>>temp;

    yy1 = temp/100;
    yy2 = temp%100;
}

void executeProgram(){
    sum = dd + mm + yy1 + yy2;
	
    a[2][0] = dd;
	a[0][3] = mm;
	a[1][2] = yy1;
	a[3][1] = yy2;
	
    a[0][0] = a[0][3] - 3;
    a[0][1] = a[0][3] - 2;
    a[0][2] = a[0][3] - 1;
    a[1][0] = a[1][2] - 2;
    a[1][1] = a[1][2] - 1;
    a[1][3] = a[1][2] + 1;
    a[2][1] = a[2][0] + 1;
    a[2][2] = a[2][0] + 2;
    a[2][3] = a[2][0] + 3;
    a[3][0] = a[3][1] - 1;
    a[3][2] = a[3][1] + 1;
    a[3][3] = a[3][1] + 2;

    b[0][0] = a[2][0];
    b[0][1] = a[0][3];
    b[0][2] = a[1][2];
    b[0][3] = a[3][1];
    b[1][0] = a[3][2];
    b[1][1] = a[1][1];
    b[1][2] = a[0][0];
    b[1][3] = a[2][3];
    b[2][0] = a[0][1];
    b[2][1] = a[2][2];
    b[2][2] = a[3][3];
    b[2][3] = a[1][0];
    b[3][0] = a[1][3];
    b[3][1] = a[3][0];
    b[3][2] = a[2][1];
    b[3][3] = a[0][2];
}

void showOutput(){
    cout<<"\n------------------------------\n";
    cout<<"YOUR MAGIC SQUARE:";
    cout<<"\n------------------------------\n";
    for(int i{0}; i<4; i++){
        for(int j{0}; j<4; j++){
            cout<<b[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"------------------------------\n";
    cout<<"Sum of Numbers is: "<<sum;
    cout<<"\n------------------------------\n";
}

int main() {
    getInput();
    executeProgram();
    showOutput();

    // getch(); // for cmd
    return 0;
}