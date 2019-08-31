/*
 * 给定一个单词列表，
 * 只返回可以使用在键盘同一行的字母打印出来的单词。
*/
#include <string>
#include <set>
#include <vector>
#include <stdio.h>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        set<char> s1 = {'q','w','e','r','t','y','u','i','o','p',
                       'Q','W','E','R','T','Y','U','I','O','P'};
        set<char> s2 = {'a','s','d','f','g','h','j','k','l',
                        'A','S','D','F','G','H','J','K','L'};
        set<char> s3 = {'z','x','c','v','b','n','m',
                        'Z','X','C','V','B','N','M'};
        
        for (size_t i = 0; i < words.size(); i++){
            int len = words[i].length();
            if(s1.count(words[i][0])){
                for (int k = 1; k < len; k++){
                    if (!s1.count(words[i][k])){
                        words.erase(words.begin()+i);
                        i--;
                        break;
                    }
                }
            }
            else if(s2.count(words[i][0])){
                for (int k = 0; k < len; k++){
                    if (!s2.count(words[i][k])){
                        words.erase(words.begin()+i);
                        i--;
                        break;
                    }
                }
            }
            else{
                for (int k = 0; k < len; k++){
                    if (!s3.count(words[i][k])){
                        words.erase(words.begin()+i);
                        i--;
                        break;
                    }
                }
            }
        }
        return words;
    }
};

int main()
{
	Solution s;
	vector<string> words = {"Hello","Alaska","Dad","Peace"};
	vector<string> yes;
	for (size_t i = 0; i < words.size(); i++)
		cout << words[i] << " ";
	cout << endl;
	yes = s.findWords(words);
	for (size_t i = 0; i < yes.size(); i++)
		cout << yes[i] << " ";
	cout << endl;
	return 0;
}
