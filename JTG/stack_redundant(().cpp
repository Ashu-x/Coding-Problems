// count redundant parentheses in an expression represented as a linked list
struct Node {
    char data;
    Node* next;
    Node(char x) : data(x), next(nullptr) {}
};

int countRedundantParentheses(Node* head) {
    stack<char> st;
    int count = 0;

    for (Node* curr = head; curr != nullptr; curr = curr->next) {
        char ch = curr->data;

        if (ch == ')') {
            if (st.empty()) continue; // invalid case (not expected normally)
            
            char top = st.top();
            st.pop();

            bool hasOperator = false;

            while (!st.empty() && top != '(') {
                if (top == '+' || top == '-' || top == '*' || top == '/')
                    hasOperator = true;
                top = st.top();
                st.pop();
            }

            if (!hasOperator) count++; // redundant
        } 
        else {
            st.push(ch);
        }
    }

    return count;
}