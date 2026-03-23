#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<int> v; // Declare a vector of integers

    cout<<"size: "<<v.size()<<endl; 
    cout<<"capacity: "<<v.capacity()<<endl; // Output the current capacity of the vector

    v.push_back(1); // Add an element to the vector
    cout<<"size: "<<v.size()<<endl;
    cout<<"capacity: "<<v.capacity()<<endl; // Output the new capacity after adding an element

    v.push_back(2); // Add another element to the vector
    cout<<"size: "<<v.size()<<endl;
    cout<<"capacity: "<<v.capacity()<<endl; // Output the capacity after adding another element

    v.push_back(3); // Add a third element to the vector
    cout<<"size: "<<v.size()<<endl;
    cout<<"capacity: "<<v.capacity()<<endl; // Output the capacity after adding a third element
    
    v.resize(10);
    cout<<"size: "<<v.size()<<endl;
    cout<<"capacity: "<<v.capacity()<<endl;

    v.pop_back();
    v.pop_back();
    cout<<"size: "<<v.size()<<endl;
    cout<<"capacity: "<<v.capacity()<<endl;

    return 0;

}