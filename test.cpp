#include <iostream>

template<class T>
struct TNode{
    T data;
    struct TNode* next;
    struct TNode* prev;
};

typedef TNode<int> Node;


int a_data[] =  {8, 9, 10, 2, 34};

Node* createNodeList()
{
    Node* head = new Node; 
    if (head == NULL) {
        return NULL;
    }
    head->data = a_data[0];
    head->next = NULL;
    head->prev = NULL;

    Node* tail = head;

    for (int i = 1; i < sizeof(a_data)/sizeof(a_data[0]); ++i) {
        Node* node = new Node;
        if (node == NULL) {
            std::cerr << "insert '" << a_data[i] << "' failed." << std::endl;
            continue;
        }
        node->data = a_data[i];
        tail->next = node;
        node->prev = tail;
        node->next = NULL;
        tail = node;
    }

    return head;
}

void traverseNodeList(const Node* head)
{
    if (head == NULL) {
        std::cerr << "Empty Node list!" << std::endl;
        return;
    }
    Node *p = const_cast<Node*>(head);
    std::cout << p->data;
    p = p->next;
    while(p) {
        std::cout << "<->" << p->data;
        p = p->next;
    }
    std::cout << std::endl;
}

void destroyNodeList(Node** head)
{
    Node* p = *head;
    Node* q = NULL;
    while(p) {
        q = p->next;
        delete p;
        p = q;
    }
    *head = NULL;
}

int main()
{
    Node* head = createNodeList();
    if (head == NULL) {
        std::cerr << "create node list failed." << std::endl;
        return -1;
    }

    traverseNodeList(head);
    destroyNodeList(&head);

    return 0;
}
