#include <iostream>
using namespace std;

class ArrayList{
private:
    int* items;
    int head; //first element
    int tail; //last element
    int capacity; //array size
    int size; //current array size
public:
    ArrayList(int c);
    bool empty();
    bool full();
    int getSize();
    int getCapacity();
    int getFirst();
    int getLast();
    int getNext(int p);
    int getPrev(int p);
    int retrieve(int p);
    void append(int x); //appends list with x value
    void preppend(int x); //preppends list with x value

    void insert(int p, int x);//inserts x on p index
    void del(int p);//deletes p index
    void clear(); //deletes entire array

    int locate(int x); //returns index of first x apperance
    void deleteX(int x); //deletes first x apperance
    void deleteAllX(int x); //deletes all x apperance
    void concat(ArrayList& l); //appends arraylist with another array list
    void sort();
    void insertSorted(int x);

    friend ostream& operator<<(ostream& out, ArrayList& a);
    ~ArrayList();

};

ArrayList::ArrayList(int c){
    items = new int[c];
    capacity=c;
    size=0;
    head=0;
    tail=-1;
}

ArrayList::~ArrayList(){

}

bool ArrayList::empty(){
    if(size==0){
        return true;
    }
    else{
        return false;
    }
}

int ArrayList::getSize(){
    return size;
}

int ArrayList::getCapacity(){
    return capacity;
}
bool ArrayList::full(){
    if(size==capacity){
        return true;
    }
    else{
        return false;
    }
}

int ArrayList::getFirst(){
    if(empty()){
        cout<<"Array empty error: ";
        return 420;
    }
    else{
        return head;
    }
}

int ArrayList::getLast(){
    if(empty()){
        cout<<"Array empty error: ";
        return 420;
    }
    else{
        return tail;
    }
}

int ArrayList::getNext(int p){
    if( p<getFirst() || p>getLast()){
        cout<<"Position doesnt exist error: ";
        return -1;
    }else{
        return p+1;
    }
}

int ArrayList::getPrev(int p){
    if( p<=getFirst() || p>getLast()){
        cout<<"Position doesnt exist error: ";
        return -1;
    }else{
        return p-1;
    }
}

int ArrayList::retrieve(int p){
    if(empty()){
        cout<<"Array empty error:  ";
        return 420;
    }
    else if( p<getFirst() || p>getLast()){
        cout<<"Position doesnt exist error: ";
        return -1;
    }
    else{
        return items[p];
    }
}

void ArrayList::append(int x){
    if(full()){
        cout<<"Array full"<<endl;
    }
    else{
        tail++;
        size++;
        items[tail]=x;
    }
}
void ArrayList::preppend(int x){
    if(full()){
        cout<<"Array full"<<endl;
    }
    else{
        for(int i=getLast(); i>=getFirst();i--){
            items[i+1]=items[i];
        }
        size++;
        tail++;
        items[getFirst()]=x;
    }
}

void ArrayList::insert(int p, int x){
    if(full()){
        cout<<"Array full"<<endl;
    }else if(p<getFirst() || p>getLast()+1){
        cout<<"Position doesnt exist"<<endl;
    }else{
        for(int i=getLast(); i>=p;i--){
            items[i+1]=items[i];
        }
        items[p]=x;
        tail++;
        size++;
    }
}
void ArrayList::del(int p){
    if(empty()){
        cout<<"Array empty"<<endl;
    }else if(p<getFirst() || p>getLast()){
        cout<<"Position doesnt exist"<<endl;
    }else{
        for(int i=p; i<=getLast()-1;i++){
            items[i]=items[i+1];
        }
        tail--;
        size--;
    }
}

void ArrayList::clear(){
    while(empty()==false){
        del(head);
    }
}

int ArrayList::locate(int x){
    for(int i=getFirst(); i<=getLast(); i++){
        if(retrieve(i)==x){
            return i;
        }
    }

    return -1;
}

void ArrayList::deleteX(int x){
    if(locate(x)==-1){
        cout<<"There's no element with this value"<<endl;
    }else{
        del(locate(x));
    }
}

void ArrayList::deleteAllX(int x){
    while(locate(x)!=-1){
        del(locate(x));
    }
}

void ArrayList::concat(ArrayList& l){
    if(getSize() + l.getSize() <= getCapacity()){
        for(int i=0; i<l.getSize(); i++)
        {
            tail++;
            size++;
            items[tail]=l.retrieve(i);
        }
    }
}

void ArrayList::sort(){
    int tmp;
    for(int i=0; i<getSize();i++)
    {
        for(int j=i+1;j<getSize();j++)
        {
            tmp=items[j];
            if(items[j]<items[i]){
                tmp=items[j];
                items[j]=items[i];
                items[i]=tmp;
            }
        }
    }
}

void ArrayList::insertSorted(int x){
    int tmp;
    for(int i=getFirst(); i<=getLast(); i++)
    {
        cout<<retrieve(i)<<" "<<x<<" " <<i<<endl;
        if(retrieve(i)<=x && i==getLast()){
            tmp=i+1;
            break;
        }else if(retrieve(i)>=x){
            tmp=i;
            break;
        }
    }

    insert(tmp,x);

}

ostream& operator<<(ostream& out , ArrayList& a){ //prints array
    for(int i=a.getFirst(); i<=a.getLast(); i++)
    {
        out<<a.retrieve(i)<<" ";
    }
}

int main(){
    ArrayList a(20);
    ArrayList b(20);

    b.append(1);
    b.append(2);
    b.append(3);
    b.append(4);

    a.getFirst();
    cout<<endl;
    a.getLast();
    cout<<endl;
    a.getNext(3);
    cout<<endl;
    a.getPrev(3);
    cout<<endl;
    cout<<a.retrieve(1)<<endl;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);

    cout<<endl;
    cout<<endl;
    cout<<a;

    a.preppend(69);
    a.preppend(70);
    cout<<endl;
    cout<<endl;
    cout<<a;

    cout<<endl;
    a.insert(3,420);
    a.insert(7,58);
    cout<<endl;
    cout<<endl;
    cout<<a;

    cout<<endl;
    cout<<endl;
    a.del(3);
    cout<<a;

    cout<<endl;
    cout<<endl;
    cout<<"Pozycja czworki: "<< a.locate(4)<<endl;
    a.deleteX(4);
    a.insert(1,1);
    a.insert(5,1);
    a.deleteAllX(1);
    cout<<a;

    cout<<endl;
    cout<<endl;
    a.concat(b);
    cout<<a;

    a.sort();
    cout<<endl;
    cout<<endl;
    cout<<a;

    cout<<endl;
    cout<<endl;
    a.insertSorted(5);
    a.insertSorted(10);
    a.insertSorted(66);
    a.insertSorted(70);
    a.insertSorted(30);
    a.insertSorted(300);
    a.insertSorted(3000);
    cout<<a;

    cout<<endl;
    cout<<endl;
    a.clear();
    cout<<a;

}
