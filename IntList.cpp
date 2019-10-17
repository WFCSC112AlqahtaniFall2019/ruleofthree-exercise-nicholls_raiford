#include <iostream>
#include "IntList.h"
using namespace std;
//
// Created by Benjamin Raiford on 10/17/19.
//
void swap(int* th , int* rhs, int  size){
    cout<<"assignment operator"<<endl;
    for(int i=0; i<size; i++){

        th[i]=rhs[i];

        cout<<rhs[i]<<endl;
    }


}


IntList::IntList ( int size  , int initvalue) {
    if( size > 0){
        list_ = new int[ size ];
        size_ = size ;
        for( int i = 0; i < size_ ; i ++)
            list_ [i] = initvalue ;
    }
    else {
        list_ = 0;
        size_ = 0;
    }
}

//1) write a definition for the destructor
IntList::~IntList(){
    cout << "Destructor called" << endl;
    delete [] list_;
}

//2) fix the copy constructor
IntList :: IntList ( const IntList & L ){
    cout << "Copy constructor called" << endl;
    //list_ = L . list_ ;
    list_ = new int [ L.size_ ];
    for(int i = 0; i < size_; i++){
        list_ [i] = L.list_ [i];
    }

    size_ = L . size_ ;
}

//3) rewrite the copy assignment operator using an optimized method
IntList& IntList:: operator =(IntList rhs ){
    cout<<rhs.size_;
    swap(this->list_, rhs.list_, rhs.size_);
    return *this;
    /*size_ = rhs . size_ ;
    if( rhs . size_ > 0){
        list_ = new int [ rhs . size_ ];
        for ( int i = 0; i < rhs . size_ ; i ++)
            list_ [ i ] = rhs . list_ [ i ];
    }
    else
        list_ = 0;

    return *this;
     */
}