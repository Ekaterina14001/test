
#include <iostream>
#include <string>


struct ListNode
{
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    ListNode* rand = nullptr;
    std::string data;
};


class List {

private:
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    int count = 0;
public:

    List()
    {
        ListNode* h = new ListNode;
        ListNode* t = new ListNode;

        h->data = "";
        h->next = t;
        h->prev = nullptr;
        h->rand = nullptr;

        t->data = "";
        t->next = nullptr;
        t->prev = h;
        t->rand = nullptr;
        head = h;
        tail = t;
    }
    void push_back(std::string val)
    {
       
        if (tail->data == ""&& head->data=="")
        {
            head->data = val;
        }
        else if (tail->data == "")
        {
            tail->data = val;
        }
        else {
            ListNode* node = new ListNode;
            node->data = val;
            node->prev = tail;
            tail->next = node;
            node->rand = head;
            tail = node;
        }
        count++;
    }
    void push_front(std::string val)
    {
        if (head->data == "")
        {
            head->data = val;
        }
        else {
            ListNode* node = new ListNode;
            node->data = val;
            node->next = head;
            head->prev = node;
            if(tail->data == "")
                node->rand = head;
            else
                node->rand = tail;
            head = node;
        }
        count++;
    }
    void print()
    {

        for (auto p = head; p != tail; p=p->next)
        {
            std::cout << p->data << " ";
           }
        std::cout << tail->data << std::endl;
    }
    
    void Serialize(FILE* file)
    {
        if (!file)
        {
            std::cout << "file not found" << std::endl;
            return;
        }
   
        for (auto p = head; p != tail; p = p->next)
        {
          std:: fputs(p->data.c_str(),file);
          std::fputs("->", file);
        }
        std::fputs(tail->data.c_str(),file);
        std::fclose(file);


    }

    void Deserialize(FILE* file)
    {
        if (this->head->data != "" || this->tail->data != "")
        {
            std::cout << "not empty object"<<std::endl;
            return;
        }

        char str[1024];
        if (fgets(str, sizeof(str), file) == NULL) {
            std::cout << "fgets error" << std::endl;
            return;
        }
        std::cout << "file contents: " << str << std::endl;
        fclose(file);

        int i = 0;
        std::string buf;
        while (str[i] != NULL)
        {
            if (str[i] == '-' && str[i + 1] == '>')
            {
                    this->push_back(buf);
                    buf.clear();
                    i = i + 2;
                    continue;

            }

            buf.push_back(str[i]);
            i++;

        }
        this->push_back(buf);
    }

    ~List() {
        auto pNode = head;

        while (NULL != pNode)
        {
            auto pNext = pNode->next;
            delete pNode;
            pNode = pNext;
        }
    }
};

int main(int argc, char** argv)
{
    
    List list;
    list.push_back("three");
    list.push_back("four");
    list.push_front("two");
    list.push_front("one");
    list.print();

    FILE* file = fopen("C:\\Users\\User\\source\\repos\\Serialized\\file.txt", "wb");
    list.Serialize(file);

    List deserialize;
    file = fopen("C:\\Users\\User\\source\\repos\\Serialized\\file.txt", "rb");
    deserialize.Deserialize(file);
    deserialize.print();
    
}

