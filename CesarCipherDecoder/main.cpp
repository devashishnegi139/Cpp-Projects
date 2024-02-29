#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::string;

void printSubtracting(string s, int n){
    // s = string
    // n = number subtracted
    int spaceFound{0};                      // if there is space, then we want to ignore it

    // writing a code to subtract from each word, acoordingly
    for(size_t i{0}; i<s.length(); i++){
        if(s[i] == ' ')                     // simple code for space found
            spaceFound = 1;

        if(spaceFound!=1){                  // whenever we don't have a space, we run the algorithm
            int temp = int(s[i]) - 97;      // a temp will have the value, ex. a = 1, b = 2
            temp = (temp-n)%26;             // if key used is greater then 26, this will keep it in check
            if(temp<0){                     // if we got negative value
                temp += (97+26);            // we need to add 26 to it
            }else{                          // else we simply add 97 to follow to ASCII code
                temp+=97;
            }
            cout<<char(temp);               // this will print the character
        }else{
            spaceFound=0;                   // whenever we have found a whitespace after that we need to make it 0 again
            cout<<" ";                      // and print white space back
        }
    }

    int temp2 = (n%26)+96+1;                // this is just to print the character which we subtracted
    cout<<"\tKey= "<<char(temp2);
}

int main(){
    cout<<"Enter the secret code: ";
    string s;
    getline(cin, s);
    // Got the Encrypted Message

    // we will try to subtract manually and see which key makes sense
    for(int i{0}; i<26; i++){
        cout<<"Subtracting "<<i<<"\t";
        printSubtracting(s, i);
        cout<<"\n";
    }

    return 0;
}