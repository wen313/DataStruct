#include <iostream>

using namespace std;

/**
 * @brief 
 * 只考虑单向队列
 * @tparam Item 
 */
template<class Item>
class ArrayQueue{
private:
    Item* items;
    int n;
    int head;//队列头
    int tail;//队列尾
public: 
    ArrayQueue(){};
    ArrayQueue(int n)
        :n(n),
        head(0),
        tail(0){
        items = new Item[n];
    };

    void enqueue(const Item& item){
        if(tail == n) {//判断是否真的满了
            if(head==0)return ;
            for(int i=head;i<n;i++){
                items[i-head] = items[i];
            }
            tail = n-head;
            head = 0;
            
        }
        items[tail++] = item;
    };

    Item dequeue(){
        if(head == tail) return NULL;
        Item item = items[head++];
        return item;
    };
    bool isEmpty(){
        return head==0&&head == tail;
    };
    int size(){
        return tail-head;
    };

    ~ArrayQueue(){
        delete []items;
    }
};


/**
 * @brief 
 * 循环队列
 * @tparam Item 
 */
template<class Item>
class ArrayCircleQueue{
private:
    Item* items;
    int n;
    int head;//队列头
    int tail;//队列尾
public: 
    ArrayCircleQueue(){};
    ArrayCircleQueue(int n)
        :n(n),
        head(0),
        tail(0){
        items = new Item[n];
    };

    void enqueue(const Item& item){
        if( (tail + 1) % n == head ) return ;//队列满
        items[tail] = item;
        tail = ( tail + 1) % n;
    };

    Item dequeue(){
        if(head == tail) return NULL;
        Item item = items[head];
        head = (head + 1) % n;
        return item;
    };

    bool isEmpty(){
        return tail == head;
    };
    int size(){
        return tail-head;
    };

    ~ArrayCircleQueue(){
        delete []items;
    }
};

int main(){
    ArrayCircleQueue<int> queue(10);
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);

    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;

    queue.enqueue(5);
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.enqueue(9);
    queue.enqueue(10);
    queue.enqueue(11);
    queue.enqueue(12);

    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    cout<<queue.dequeue()<<endl;
    

    return 0;
}