
//using T = double;
template<typename T>
class List {
    struct Node {
        T data;
        Node* next;

        Node(T _data) {
            data = _data;
            next = nullptr;
        }
    };
    
    Node* start;

    void push_back(T element, Node* current) {
        if (current->next == nullptr) {
            current->next = new Node(element);
            return;
        }
        push_back(element, current->next);
    }

    void delete_elements(Node* current) {
        if (current != nullptr) {
            delete_elements(current->next);
            delete current;
        }
    }
public:
    List() {
        start = nullptr;
    }

    ~List() {
        delete_elements(start);
    }

    void push_back(T element) {
        if (start == nullptr) {
            start = new Node(element);
        }
        else {
            push_back(element, start);
        }
    }

    void print_elements() {
        Node* current = start;
        while(current != nullptr) {
            cout << current->data << ' ';
            current = current->next;
        }
    }
};