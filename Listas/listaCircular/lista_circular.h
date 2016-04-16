class IntNode {
public:
    int info;
    IntNode *next;
    IntNode(int el, IntNode *ptr = 0)
    {
        info = el; next = ptr;
    }
};

class CList {
public:
    IntNode *head, *tail;
    CList()
    {
        head = tail = nullptr;
    }
    ~CList();
    int isEmpty()
    {
        return head==0;
    }
    void addToHead(int);
    void addToTail(int);
    int deleteFromHead();
    int deleteFromTail();
    void deleteNode(int);
    bool isInList(int) const;
//private:

};
