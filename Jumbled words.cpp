/*
Program: Solve Jumble Words
Description: This program will solve the jumble words and will will print all the possible answers for the words. like if you give lacpsie then it will print plaices and   special
Author: Lord Hypersonic
Email: lordhypersonic.522@gmail.com
Website: www.lordhypersonic.blogspot.in
*/
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <conio.h>

using namespace std;

//function to sort the string
string sortString(string word)
{
    int len=word.length(); //length of given word
    for(int i=0; i<len; i++) // loop for converting lower alpha to upper alpha
    {
        if(islower(word[i])) word[i]=toupper(word[i]);
    }
    string Jumble;
    int TEMP[len];
    for(int i=0; i<len; i++) TEMP[i]=0; //initializing array TEMP with 0.
    for(int i=0; i<len; i++) //loop for storing ascii code of alphabets in given word
    {
        TEMP[i]=word[i];
    }
    for(int i=0; i<len; i++) // loop for sorting numbers
    {
        for(int j=0; j<len; j++)
        {
            if(TEMP[j]>TEMP[j+1])
            {
                int temp=TEMP[j];
                TEMP[j]=TEMP[j+1];
                TEMP[j+1]=temp;
            }
        }
    }
    for(int i=0; i<len; i++) //loop for creating sorted string of given word like: dance will be ACDEN
    {
        Jumble.push_back(TEMP[i]);
    }
    return Jumble; //returning sorted string
}
int main()
{
    while(1) {
	    string line="",jumble="",Jb="";
	    int c=1; // counter
	    cout<<"Enter jumbled word: "; getline(cin,jumble); //asking for jumble words
    	Jb=sortString(jumble); //sorting jumble word
	    ifstream words("words.txt"); //opening words.txt wordlist
	    cout<<"\nPossible words are:- "<<endl;
	    if(words) //if file is open
        {
            while(getline(words,line)) // loop until end of file, copying string in words to line
            {
                string Wds=sortString(line); //sorting word in file
                if(Wds==Jb) //if sorted word is equal to sorted jumble word then it is the answer
                {
                    cout<<c++<<". "<<line<<endl; //printing answer.
                }
            }
            words.close();//closing words.txt
            _getch();
            cout<<endl<<endl;
        }
        else //if not able to find word.txt
        {
            cout<<"\nwords.txt is missing........... can not do further processing :( \n";
            _getch();
        }
    }
	return 0;
}
