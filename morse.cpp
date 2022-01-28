#include <iostream>
#include <sstream>

using namespace std;

int main () {
	
	string morse[26];
	string alph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	//morse
	morse[0] = ".-";
	morse[1] = "-...";
	morse[2] = "-.-.";
	morse[3] = "-..";
	morse[4] = ".";
	morse[5] = "..-.";
	morse[6] = "--.";
	morse[7] = "....";
	morse[8] = "..";
	morse[9] = ".---";
	morse[10] = "-.-";
	morse[11] = ".-..";
	morse[12] = "--";
	morse[13] = "-.";
	morse[14] = "---";
	morse[15] = ".--.";
	morse[16] = "--.-";
	morse[17] = ".-.";
	morse[18] = "...";
	morse[19] = "-";
	morse[20] = "..-";
	morse[21] = "...-";
	morse[22] = ".--";
	morse[23] = "-..-";
	morse[24] = "-.--";
	morse[25] = "--..";
	
	string code = "", message = "", translate;
	
	cout << "Enter Morse words, one per line:" << endl;
	getline(cin,code);
	
	//Get Morse Code
	while( code != "Quit")
	{
		
		stringstream ss(code);
	
		//for loop to match Morse with Alph
		while ( ss >> translate)
		{
			for(int i = 0; i < 26; i++){
					if (morse[i] == translate)
						message = message + alph[i];
			}
		}
		getline(cin,code);
		message = message + " ";
	}
	cout << '\n' << message;
}