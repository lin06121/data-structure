#include <iostream>
#include <fstream>
#include <cstring>

class Stack {
private:
    static const int MAX_SIZE = 100;
    std::string data[MAX_SIZE];
    int topIndex;
public:
    Stack() : topIndex(-1) {}

    bool isFull() const {
        return topIndex >= MAX_SIZE - 1;
    }
    
    void push(const std::string &val) {
        if (!isFull()) {
            data[++topIndex] = val;
        } else {
            std::cerr << "Error: Stack overflow!" << std::endl;
        }
    }
    
    std::string pop() {
        if (!empty()) {
            return data[topIndex--];
        }
        return "";
    }
    
    std::string top() const {
        return (!empty()) ? data[topIndex] : "";
    }
    
    bool empty() const {
        return topIndex == -1;
    }
};

bool checkPascalIfElse(std::ifstream &in) {
    Stack st;
    char word[100];
    
    while (in >> word && strcmp(word, "end") != 0) {
        if (strcmp(word, "if") == 0) {
            st.push("if");
        } else if (strcmp(word, "then") == 0) {
            if (st.empty() || st.top() != "if") {
                return false;
            }
            st.pop();
            st.push("then");
        } else if (strcmp(word, "else") == 0) {
            if (st.empty() || st.top() != "then") {
                return false;
            }
            st.pop();
        }
    }

    return st.empty();
}

int main() {
    char filename[50];
    std::ifstream in;
    char word[100];

    std::cout << "Please input the name of the Pascal source file: ";
    std::cin >> filename;

    in.open(filename);
    if (!in) {
        std::cerr << "Error: File not found!" << std::endl;
        return 1;
    }

    while (in >> word && strcmp(word, "begin") != 0) {
        if (strcmp(word, "end") == 0) {
            std::cerr << "Error: 'begin' not found before 'end'!" << std::endl;
            in.close();
            return 1;
        }
    }

    if (!checkPascalIfElse(in)) {
        std::cerr << "Error: Incorrect if-then-else matching!" << std::endl;
        in.close();
        return 1;
    }

    if (in >> word) {
        std::cerr << "Error: Unused statement after 'end'!" << std::endl;
    } else {
        std::cout << "Correct Pascal if-then-else syntax." << std::endl;
    }

    in.close();
    return 0;
}

