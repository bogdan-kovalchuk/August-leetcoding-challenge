#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Solution {
public:
    string toGoatLatin(string S) {
        /*  The rules of Goat Latin are as follows:

            If a word begins with a vowel (a, e, i, o, or u), append "ma" to the end of the word.
            For example, the word 'apple' becomes 'applema'.

            If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end,
            then add "ma". For example, the word "goat" becomes "oatgma".

            Add one letter 'a' to the end of each word per its word index in the sentence, starting with 1.
            For example, the first word gets "a" added to the end, the second word gets "aa" added to the end and so on.
         */

        string word, letters_a, vowels = "aeiouAEIOU";
        std::stringstream in(S), out;
        while(in >> word) {
            letters_a += 'a';
            if (vowels.find(word[0]) != std::string::npos){
                out << ' ' << word << "ma" << letters_a;
            } else {
                out << ' ' << word.substr(1) << word[0] << "ma" << letters_a;
            }
        }
        return out.str().substr(1);
    }
};


int main() {
    string str = "I speak Goat Latin";
    Solution solution;
    cout << solution.toGoatLatin(str) << endl;
    return 0;
}
