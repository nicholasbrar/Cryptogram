#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

string swapCharacters(const string& input, const unordered_map<char, char>& swaps) {
    string output = input;
    unordered_set<char> swappedCharacters;

    for (char& c : output) {
        if (swaps.count(c) && swappedCharacters.find(c) == swappedCharacters.end()) {
            c = swaps.at(c);
            swappedCharacters.insert(c); 
        }
    }
    return output;
}

int main() {
    unordered_map<char, char> charSwaps = {
        {'A', '.'}, {'B', '.'}, {'C', '.'}, {'D', 'S'}, {'E', 'Y'}, {'F', '.'},
        {'G', 'P'}, {'H', '.'}, {'I', 'T'}, {'J', 'Z'}, {'K', '.'}, {'L', 'E'},
        {'M', '.'}, {'N', 'U'}, {'O', '.'}, {'P', 'G'}, {'Q', '.'}, {'R', 'V'},
        {'S', '.'}, {'T', 'H'}, {'U', 'Q'}, {'V', 'W'}, {'W', '.'}, {'X', 'J'},
        {'Y', 'R'}, {'Z', 'X'}
    };

    string cipher = "YLDLFYGTLYDPYMHFQNBASGNKSRLYDSIEMKAMKWSDAFKOFKKMNKGLOIMOFEITFIITLETFRLPMNKOFVFEIMINYKSYMKSKIMWMAOITLYLSDVSOLDQYLFODCLQISGSDHSKITLFGFOLHSGGMHHNKSIETMVLRLYITLDGSLKISDIDPYMHDIMKEBYMMCFYLMPPLYSKWIMWSRLILKQMNKODMPQNYLWMAOIMFKEMKLVTMFDCDPMYSIIMQYMRLITLSYQMSKIFAAIYFOSKWSKWMAOGMHQFKSLDVFDTFAILOMKITLDIMGCLZGNPKWLD";

    string swapped = swapCharacters(cipher, charSwaps);
    cout << swapped << endl;

    return 0;
}
