#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

const int max_wrong_guess = 7;
const char WORD_LIST[] = "HM_WL.txt";

string choose_word(const char* file_word);
void renderGame(string guessing_word, int wrong_guess_times);
bool check(char Input, string Chosen_Word);
char read_guess();
string update(string guessing_word, string Chosen_Word, char guessed_char);
bool Play_Again(char play_again);


int main() {
bool play = true;
do {
srand(time(0));
string Chosen_Word = choose_word(WORD_LIST);
if(Chosen_Word.length() < 1) {
    cout << "Cannot find any word!! " << endl;
    return -1;
}
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
    cout << "The word is  " << Chosen_Word << endl;
}
cout << "***** Do you want to play again ?? Y/N *****" << endl;
char play_again;
cin >> play_again;
play = Play_Again(play_again);
} while (play == true);
return 0;
}


string choose_word(const char* file_word){
    vector <string> word;
    ifstream file(file_word);
    if ( file.is_open() ) {
        string Choosing_Word;
        while (file >> Choosing_Word){
            word.push_back(Choosing_Word);
        }
        file.close();
    }
    if (word.size() > 0) {
        int RandomNum = rand() % word.size();
        return word[RandomNum];
    }
}

const string IMAGE[] = {
        "   -------------    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |                \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |                \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |           |    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|    \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |                \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          /     \n"
        "   |     \n"
        " -----   \n",
        "   -------------    \n"
        "   |           |    \n"
        "   |           O    \n"
        "   |          /|\\  \n"
        "   |          / \\  \n"
        "   |     \n"
        " -----   \n"
    };
void renderGame(string guessing_word, int wrong_guess_times) {
    cout << IMAGE[wrong_guess_times];
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

bool Play_Again(char play_again){
    char pg = toupper(play_again);
 if  (pg == 'Y') {
    return true;
 }
 else if ( pg == 'N') {
    return false;
 }
}
