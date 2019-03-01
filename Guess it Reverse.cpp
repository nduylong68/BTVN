#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
    int GuessNumber(int limRight, int limLeft  ) {
        srand(time(0));
        int Guess = 1;
        do {
         Guess = rand()%limRight;
        }
        while (Guess <= limLeft);
        cout << "Is the number " << Guess << " ?" << endl;
        return Guess;
}
    bool CheckTheAnswer(string Answer, int &limR, int &limL, int Gss) {
        if (Answer == "bigger") {
            limL = Gss;
            return false;
            }
        else if (Answer == "smaller") {
            limR = Gss;
            return false;
        }
        else if (Answer == "bingo") {
            return true;
        }
    }
    int main(){
    cout << "Think a number, I'll guess it. If i am wrong, type 'bigger' or 'smaller'. If i am right, type 'bingo'. Let's play! " << endl;
    bool Answ;
    int limRight = 100, limLeft = 0, Guess;
    do {
        Guess = GuessNumber(limRight, limLeft);
        string Answer;
        cin >> Answer;
        Answ = CheckTheAnswer(Answer, limRight, limLeft, Guess);
    }
    while (Answ == false);
    if (Answ == true) {
        cout << "Yeee I'm so good !";
    }
    return 0;
}
