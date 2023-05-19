#include <stdio.h>
# include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

char * getWord()
{
    std::srand(std::time(nullptr));

    char * words[] = {"BARALHO", "JOGO", "COMPUTADOR"};

    int ArraySize = sizeof words / sizeof words[0];
    int randomNumber = rand() % ArraySize;
    char * word= words[randomNumber];

    return word;
}

int getSize(char work[]){
    int size = 0;
    while(work[size] != '\0'){
        size++;
    }

    return size;
}

int main()
{
    char * word = getWord();
    int size = getSize(word);
    char wordSecret[size];

    int attempts = 5;
    int hits = 0;
    bool game = true;
    bool winner = false;

    for(int i = 0; i < size; i++){
        wordSecret[i] = '_';
    }

    while(game){
        char letter;
        bool hit = false;

        cout << "JOGO DA FORCA \n \n";
        cout << "Voce tem "<< attempts << " chances restantes \n";

        cout << "Palavra secreta: ";
        for(int i = 0; i < size; i++){
            cout << wordSecret[i];
        }

        cout << "\nDe seu palpite: ";
        cin >> letter;

        char letterUppercase = toupper(letter);

        for(int i = 0; i < size; i++){
            if(letterUppercase == word[i]){
                hits++;
                hit = true;
                wordSecret[i] = word[i];
            }
        }

        if(!hit){
            attempts--;
        }


        if(attempts <= 0){
            game = false;
        } else if(hits == size){
            game = false;
            winner = true;
        }

        system("cls");
    }

    winner ? cout << "Parabens voce venceu" : cout << "Voce perdeu, a palavra era: " << word; 
}