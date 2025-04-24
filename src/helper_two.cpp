#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

// Function to find and print the most common substrings of given lengths
void findMostCommonSubstrings(const std::string& input, const std::vector<int>& lengths) {
    std::map<std::string, int> substringCount;

    // Calculate frequencies of all possible substrings for the specified lengths
    for (int len : lengths) {
        for (size_t i = 0; i <= input.size() - len; ++i) {
            std::string substring = input.substr(i, len);
            substringCount[substring]++;
        }
    }

    // Process each length and find the most common substring
    for (int len : lengths) {
        std::map<int, std::vector<std::string>, std::greater<int>> frequencyMap;

        // Group substrings by their frequencies
        for (const auto& pair : substringCount) {
            if (pair.first.size() == len) {
                frequencyMap[pair.second].push_back(pair.first);
            }
        }

        // Find the most common substrings of the current length
        if (!frequencyMap.empty()) {
            const auto& mostCommon = frequencyMap.begin();
            std::cout << "Most common substrings of length " << len << ":\n";
            for (const auto& substr : mostCommon->second) {
                std::cout << "Substring: " << substr << ", Frequency: " << mostCommon->first << "\n";
            }
        }
    }
}

int main() {
    std::vector<int> lengths = {3, 4, 5};
    findMostCommonSubstrings("ILNTPYQBVYNXIMRNANLICGXSCRVGNSSMWKKUUWCLKFUWPKUUXKQTYIWWPESBPISBVEDNBLZUXKYNFFOQWIXGUSIUUSUQWWWIYIDTILCLFSYTNQITPONKVQSAQSNPCKSBVFQNYLRAQGWPRNUASEDUFLBTIIDTNGCTUICLSDZGWHNQWKOJIMWKPYVUZPVGCKGQWWCZVIVSAMXSYDWXANITGMKWSMPSOMUTFTWNNCNXWYCQSMAGWRVQDLCGAMCSSFKISYPWCKGAUWWIYGWPAFUAVDFNNTPISLYUUIDTNIWOMLJOXPUEVD", lengths);

    return 0;
}
