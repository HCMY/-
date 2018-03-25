#include<iostream>
#include <string>
#include <sstream>

using namespace std;


void int2string(int num){
	string string_temp;

	 stringstream stream;
      stream<<num;
      stream>>string_temp;

      cout<<string_temp<<endl;
}

void string2int(string str){
	int result;

	stringstream stream;
    stream<<str;
    stream>>result;
    cout<<result+1<<endl;
}


void char2int(char ch){
	cout<<(ch-'0')+1<<endl;//method 1
}

#include<stdlib.h>
void int2char(int number){
	char ch = '0'+number;
	char test = ch;
	cout<<test<<endl;
}



int main(int argc, char const *argv[])
{
	///test int2string
	int2string(1235);
	///test string2int
	string2int("1235");
	/// test char to int
	char2int('2');
	///test int to char
	int2char(4);
	return 0;
}
