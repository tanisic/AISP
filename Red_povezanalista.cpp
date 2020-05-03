
#include <iostream>
struct OE_ {
    int x;
    OE_* next;
};

typedef struct OE_ element;

class Red {
 public:
    element* head;
    element* last;
    element* first;

 
    Red()
    {
        head =last=first= new element;
        
    }

    bool Is_empty()
    {
        if (first == NULL && last == NULL)
        {
            return true;
        }
        return false;
    }

    void Push(int x)
    {
        element* novi = new element;
        if (novi == NULL)
        {
            std::cout << "Queue overflow. Aborting..." << std::endl;
            exit(1);
        }
        novi->x = x;
        novi->next = NULL;
        if (Is_empty())
        {
            first = last = novi;
        }
        else {

            last->next = novi;
            last = novi;
        }
    }

    int Pop()
    {
        element* zabrisanje;
        if (Is_empty())
        {
            std::cout << "Illegal POP. Aborting..." << std::endl;
            exit(1);
        }
        head->x = first->x;
        zabrisanje = first;
        first = first->next;
        if (first == NULL) {
        last = NULL;
        }
        free(zabrisanje);
        return head->x;
       

    }
    void Clear()
    {
        while (!Is_empty())
        {
            Pop();
        }
    }
    void PrintfList()
    {
        while ( head != NULL)
        {
            std::cout << head->x << std::endl;
            head = head->next;
        }
    }

};



int main()
{
    Red red = Red();
    std::cout << red.Is_empty() << std::endl;
    red.Push(1);
    red.Push(2);
    std::cout << red.Is_empty() << std::endl;
    red.PrintfList();
    red.Pop();
    red.Pop();
    std::cout << red.Is_empty() << std::endl;

}

