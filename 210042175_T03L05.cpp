#include <iostream>
#include <deque>

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::deque<int> deck;


        for (int i = 1; i <= n; ++i) {
            deck.push_back(i);
        }

        std::cout << "Discarded cards:";
        bool firstDiscard = true;

        while (deck.size() >= 2) {
            
            if (!firstDiscard) {
                std::cout << ",";
            }
            std::cout << " " << deck.front();

            deck.pop_front(); 

            deck.push_back(deck.front());
            deck.pop_front();
            firstDiscard = false;
        }

        std::cout << std::endl;
        std::cout << "Remaining card: " << deck.front() << std::endl;
    }

    return 0;
}
