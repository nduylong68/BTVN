#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>

using namespace std;

const int max_wrong_guess = 7;
string Word;

string choose_word();
void renderGame(string guessing_word, int wrong_guess_times);
bool check(char Input, string Chosen_Word);
char read_guess();
string update(string guessing_word, string Chosen_Word, char guessed_char);


int main() {
string Chosen_Word = choose_word();
string guessing_word = string( Chosen_Word.length(), '-' );
int wrong_guess_times = 0;
do {
    renderGame(guessing_word, wrong_guess_times);
    cout << "U're guessing: ";
    char guessed_char = read_guess();
    if (check(guessed_char, Chosen_Word) == true) {
        guessing_word = update(guessing_word, Chosen_Word, guessed_char);
        cout << endl;
        cout << "You're right !" << endl;
        cout << "----------------" << endl;
        cout << endl;
    }
    else {
        wrong_guess_times += 1;
        cout << endl;
        cout << "Nahh, u're wrong !" << endl;
        cout << "----------------" << endl;
        cout << endl;
    }
} while ((wrong_guess_times < max_wrong_guess) && (guessing_word != Chosen_Word));
if (wrong_guess_times < max_wrong_guess) {
    cout << "Congratulations ! You've won !!" << endl;
}
else {
    cout << "Sorry, You've lost :< " << endl;
}
return 0;
}
string choose_word(){
string word = "Long";
return word;
}
void renderGame(string guessing_word, int wrong_guess_times) {
cout << "The word is: " << guessing_word << endl;
cout << "Wrong time : " <<  wrong_guess_times << endl;
}

bool check(char Input, string Chosen_Word) {
    if (Chosen_Word.find_first_of(Input) != -1) {
        return true;
    }
    else return false;
}

char read_guess() {
char input;
cin >> input;
return input;
}

string update(string guessing_word, string Chosen_Word, char guessed_char){
int i = Chosen_Word.find_first_of(guessed_char);
guessing_word[i] = guessed_char;
return guessing_word;
}
