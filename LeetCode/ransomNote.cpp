#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution{
    public:
        bool canConstruct(string ransomNote, string magazine){
            unordered_map<char, int> letterCount;
            char currChar;
            for(int i=1; i<=magazine.length(); i++){
                currChar = magazine.at(i-1);
                if(letterCount.find(currChar) != letterCount.end())
                    letterCount[currChar] += 1;
                else
                    letterCount[currChar] = 1;
                cout << "Key: " << currChar << ", Value: " << letterCount[currChar] << endl;
            }
            cout << "Checking ransome note: " << endl;
            for(int i=1; i<=ransomNote.length(); i++){
                currChar = ransomNote.at(i-1);
                cout << "Current character: " << currChar << endl;
                if(letterCount.find(currChar) != letterCount.end()){
                    if(letterCount[currChar] > 0){
                        letterCount[currChar]--;
                        cout << "Updated value in the map: " << letterCount[currChar] << endl;
                    }
                    else
                        return false;
                }
                else
                    return false;
            }
            return true;
        };
};

int main(){
    Solution solution;
    string mag = "aabcc";
    string note = "abb";
    bool res = solution.canConstruct(note, mag);
    cout << "Result: " << res << endl;
}