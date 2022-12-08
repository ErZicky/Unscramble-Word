#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

string words[466463];
string possiblewords[466463];
string ScrambledWord;
void FillWords();
int FindWord();
bool IsAnagram(string);





int main() {

    FillWords(); // read dictionary
    string c;
    do
    {
        cout << "type scrambled word:" << "\n";
    
        cin >> ScrambledWord;

        transform(ScrambledWord.begin(), ScrambledWord.end(), ScrambledWord.begin(),
        [](unsigned char c){ return tolower(c); }); //we lowercase the readed string


        FindWord();

        cout << "What do you want to do now? (0 to exit / anything else to search another word):" << "\n";
        cin >> c;
       

    } while (c != "0");
    

 
}


int FindWord() //run preliminary test and create eliminated words list
{


    for(int i = 0; i < 466463; i++)
    {

        if(words[i].length() != ScrambledWord.length())
        {
           
        }
        else
        {
           if(IsAnagram(words[i]))
           {
                cout << "the scrambled word is: " << words[i] << "\n";
                return 0;
           }
           else
           {

           }
        }
        
    }

    cout << "no word finded"<<"\n";
    return 0;

}

bool IsAnagram(string possible) //check if the current word is the anagram of the input word
{

    int AsciiInput[256]; //we use the Char -> Int Conversion
    int AsciiPossible[256];

    // Reset all flags to 0
    for(int i=0; i<256; i++)
    {
       AsciiInput[i] = 0;
       AsciiPossible[i] = 0;
       
    }


    for(int i=0; i<ScrambledWord.length(); i++)
    {
        /*we increase the Int at the slot corrisponding to the char's Ascii
        i.e if both words have an 'a' both array will have the int at [97] set to 1*/
        AsciiInput[ScrambledWord[i]]++;  
        AsciiPossible[possible[i]]++;
    }

    for(int i=0; i<256; i++)
    {
        if(AsciiInput[i] != AsciiPossible[i])
            return false;
    }

    return true;
}


void FillWords() //Read dictionary
{
    ifstream file("dictionary.txt");
    string tempS;
     for(int i = 0; i < 466463; i++)
     { 

            file >> tempS; 
            transform(tempS.begin(), tempS.end(), tempS.begin(), //we lowercase the readed string
    [](unsigned char c){ return tolower(c); });

            words[i] = tempS;
     } 

   
}
