/*
Key Square is generated
Now the code for encryption is to be written
*/
#include <iostream>
#include <string>
#include <cctype>

using std::cout; 
using std::cin;
using std::endl;
using std::string;

char keySquare[5][5];   //defining it globally will be an ease to use
string plainText, key, encryptedText;

//replacing j with i and making everything lowercase
void jWithIandLower(string &s){
    for(int i{0}; i<s.length(); i++){
        if(s[i]=='j' || s[i]=='J')
            s[i] = 'i';
        else
            s[i] = tolower(s[i]);   //working with lower case will be easy
    }
}

//getting input from user
void getInput(){
    cout<<"Enter the Plain Text: ";
    getline(cin, plainText);
    jWithIandLower(plainText);

    cout<<"Enter the key: ";
    getline(cin, key);
    jWithIandLower(key);
}

//this will generate the Key Square
void keySquareGen(){
    int ks1{0}, ks2{0}, count{0}, duplicateFound{0};
    for(int i{0}; i<key.length(); i++){
        for(int j{0}; j<i; j++){    //for skipping duplicates
            if(key[j]==key[i]){
                duplicateFound = 1;
                break;
            }
        }
        if(duplicateFound!=1){
            keySquare[ks1][ks2] = key[i];
            count++, ks2++;
            if(count==5){
                count=0;
                ks1++;
                ks2=0;
            }
        }
        else{
            duplicateFound=0;
        }
    }

    // Now adding the rest of the alphabets to the key square
    for(int i{97}; i<=122; i++){
        if(char(i) == 'j')      // for skipping j
            continue;
        
        for(int j{0}; j<key.length(); j++){
            if(key[j] == char(i)){
                duplicateFound=1;
                break;
            }
        }
        
        if(duplicateFound!=1){
            keySquare[ks1][ks2] = char(i);
            count++, ks2++;
            if(count==5){
                count=0;
                ks1++;
                ks2=0;
            }
        }
        else{
            duplicateFound=0;
        }
    }
}

//for printing the key square
void printKeySquare(){
    for(int i{0}; i<5; i++){
        for(int j{0}; j<5; j++){
            cout<<keySquare[i][j]<<" ";
        }
        cout<<"\n";
    }
}

string Encrypter(){
    
}

int main(){
    getInput();
    keySquareGen();

    printKeySquare();
    // encryptedText = Encrypter();

    return 0;
}