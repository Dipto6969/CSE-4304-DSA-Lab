#include <iostream>
#include <string>
#include <deque>

using namespace std;

// Function to check if Bob wins the game
string isBobWinner(const string& S, const string& T) {
    if (S.length() != T.length()) {
        return "No";
    }

    deque<char> rotatedS(S.begin(), S.end());

    // Iterate through all possible rotations of S
    for (int i = 0; i < S.length(); ++i) {
        if (string(rotatedS.begin(), rotatedS.end()) == T) {
            return "Yes";
        }
        char lastChar = rotatedS.back();
        rotatedS.pop_back();
        rotatedS.push_front(lastChar); // Rotate S clockwise by one position
    }

    return "No";
}

int main() {
    string S, T;
    cin >> S >> T;

    // Check if Bob wins and print the result
    cout << isBobWinner(S, T) << endl;

    return 0;
}
