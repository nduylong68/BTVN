#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
int GenerateRandom() {
    srand(time(NULL)) ;
    int v1 = rand() % 100;
    return v1;
}
int PlayerguessNumber() {
    int PlayerguessNumber;
    cin >> PlayerguessNumber;
    return PlayerguessNumber;
}
void CheckAndPrint(int Guess, int Answ) {
  if  (Guess < Answ) {
    cout << "You need bigger number !" << endl;
  }
  else if (Guess > Answ) {
    cout << "You need smaller number !" << endl;
  }
}
int main() {
    cout << "Guess what number am I thinking :>> . It's between 0 and 100" << endl;
    int AnswerNumber = GenerateRandom();
    int number;
    while (true) {
        number = PlayerguessNumber();
        CheckAndPrint(number, AnswerNumber);
            if(number == AnswerNumber) { break;
             cout << " Amazing ! You're got the right number !!"; }
    }
    return 0;
}
