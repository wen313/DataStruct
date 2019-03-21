#include <iostream>

using namespace std;

template<class Item>
class ArrayStack{
private:
    Item* items;
    int count;//目前的大小
    int n;//最大的大小
public: 
    ArrayStack(){};
    ArrayStack(int n):n(n),count(0){
        items = new Item[n];
    };

    void push(const Item& item){
        if(n == count) return ;
        items[count++] = item;
    };

    Item pop(){
        if(count == 0) return NULL;
        Item item = items[--count];
        return item;
    };
    bool isEmpty(){
        return count == 0;
    };
    int size(){
        return count+1;
    };
    Item Top(){
        if(count == 0) return NULL;
        Item item = items[count];
        return item;
    };

    ~ArrayStack(){
        delete []items;
    }
};

int main(){
    ArrayStack<int> stack(10);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    cout<<stack.pop()<<endl;
    cout<<stack.pop()<<endl;
    cout<<stack.pop()<<endl;
    cout<<stack.pop()<<endl;
    return 0;
}