// StringTokenizer.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void tokenizeString(string& input, string& separators, vector<string>& output)
{
    // taken from: 
    //        https://stackoverflow.com/questions/42398090/most-efficient-way-to-iterate-over-words-in-a-string
    //        https://ideone.com/xZVR7A

    std::size_t pos = 0;
    while (pos != input.size()) {
        std::size_t from = input.find_first_not_of(separators, pos);
        if (from == std::string::npos) {
            break;
        }
        std::size_t to = input.find_first_of(separators, from + 1);
        if (to == std::string::npos) {
            to = input.size();
        }
        string temp;
        for (std::size_t i = from; i != to; i++) {
            temp.push_back(input[i]);
        }
        output.push_back(temp);
        pos = to;
    }
}

int main()
{
    string input = "quick \t\t brown \t fox jumps over the\nlazy dog";
    string separators = " \t\r\n";
    vector<string> output;

    cout << "INPUT:" << endl;
    cout << "\"" << input << "\"" << endl;
    cout << "/INPUT" << endl;

    cout << endl;

    cout << "OUTPUT:" << endl;
    tokenizeString(input, separators, output);
    for (int i = 0; i < output.size(); ++i)
    {
        cout << "\"" << output[i] << "\"" << endl;
    }
    cout << "/OUTPUT" << endl;

    return 0;
}