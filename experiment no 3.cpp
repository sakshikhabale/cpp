#include <iostream>
#include <string>

struct Song {
    std::string title;
    Song* next = nullptr;
    Song* prev = nullptr;
};

int main() {
    Song* s1 = new Song{"Blinding Lights"};
    Song* s2 = new Song{"Bohemian Rhapsody"};
    Song* s3 = new Song{"Stay"};

    s1->next = s2;
    s2->prev = s1;
    s2->next = s3;
    s3->prev = s2;

    Song* current = s1;
    std::cout << "Playing: " << current->title << "\n";

    // Safe Forward Navigation
    if (current->next != nullptr) {
        current = current->next; 
        std::cout << "Next: " << current->title << "\n";
    }

    if (current->next != nullptr) {
        current = current->next; 
        std::cout << "Next: " << current->title << "\n";
    }

    // Safe Backward Navigation
    if (current->prev != nullptr) {
        current = current->prev; 
        std::cout << "Back: " << current->title << "\n";
    }

    delete s1; 
    delete s2; 
    delete s3;
    return 0;
}

