#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);

    std::stack<Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            // Process opening bracket
            opening_brackets_stack.push(Bracket(next, position + 1));
        }

        if (next == ')' || next == ']' || next == '}') {
            // Process closing bracket
            if (opening_brackets_stack.empty()) {
                std::cout << position + 1 << std::endl;
                return 0;
            }

            Bracket top = opening_brackets_stack.top();
            if (top.Matchc(next)) {
                opening_brackets_stack.pop();
            } else {
                std::cout << position + 1 << std::endl;
                return 0;
            }
        }
    }

    // Check if there are any unmatched opening brackets left
    if (!opening_brackets_stack.empty()) {
        std::cout << opening_brackets_stack.top().position << std::endl;
    } else {
        std::cout << "Success" << std::endl;
    }

    return 0;
}
