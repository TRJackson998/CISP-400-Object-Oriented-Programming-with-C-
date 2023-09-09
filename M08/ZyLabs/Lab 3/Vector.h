#include "iostream"
using namespace std;

namespace Vector {

    struct out_of_range { /* … */ };

    template<typename T>
    class vector {
	    private:    
            size_t sz;		// the size
	        T* elem;	// pointer to elements
            size_t space;      //space of memory allocated, elem + free space
        public:
            vector() : sz(0), elem(nullptr), space(0) {}           //default constructor
            explicit vector(size_t s);	                 // constructor, new allocates memory
            vector(std::initializer_list<T> lst);   // initializer-list constructor
            vector(const vector&);	                     // copy constructor
            vector(vector&&);                            //move constructor
            ~vector() { delete[ ] elem; }		       	// destructor, delete[] deallocates memory

            vector<T>& operator=(const vector& a);  //copy assignment operator
            vector<T>& operator=(vector&&);                 // move assignment
            T& operator[ ](int n) { return elem[n]; }  // unchecked access: return reference
            T& at(int n);			// checked access
           
            //T get(int n) { return elem[n]; } 	 	// access: read
            //void set(int n, T v) { elem[n]=v; }	// access: write
            int size() const { return sz; }			// the number of elements

            void reserve(int newalloc);                 //get more space
            void resize(int newsize);                   //grow
            void push_back(T d);                   //add element
            int capacity() const {return space;}        //current available space
    };

    template<typename T> vector<T>::vector(size_t s)	// constructor (s is the element count)
	    :sz{s}, elem{new T[s]}, space{s}
    {
	    for (size_t i=0; i<sz; ++i) elem[i]=0;
    }

    template<typename T> vector<T>::vector(std::initializer_list<T> lst)   // initializer-list constructor
	    :sz{lst.size()}, elem{new T[sz]}, space{lst.size()}
    {
	    std::copy(lst.begin(),lst.end(),elem); // copy lst to elem
    }

    template<typename T> vector<T>::vector(const vector& a) :sz{a.sz},  elem{new T[a.space]}, space{a.sz} {
        // allocate space for elements, then initialize them (by copying)
        for (int i = 0; i<sz; ++i) elem[i] = a.elem[i];
    }

    template<typename T> vector<T>& vector<T>::operator=(const vector& a)
    {
        if (this==&a) return *this;	// self-assignment, no work needed

        if (a.sz<=space) {		// enough space, no need for new allocation
            for (int i = 0; i<a.sz; ++i) elem[i] = a.elem[i];	// copy elements
            sz = a.sz;
            return *this;
        }

        T* p = new T[a.sz];			// copy and swap
        for (int i = 0; i<a.sz; ++i) p[i] = a.elem[i];	
        delete[ ] elem;			
        sz = a.sz;		
        space = a.sz;
        elem = p;
        return *this; 
    }

    template<typename T> vector<T>::vector(vector&& a)   	// move constructor
        :sz{a.sz}, elem{a.elem}, space{a.space}		// copy a's elem and sz
    {
        a.sz = 0;               			// make a the empty vector
        a.elem = nullptr;
    }

    template<typename T> vector<T>& vector<T>::operator=(vector&& a)	// move assignment
    {
        delete[] elem;			// deallocate old space
        elem = a.elem; 			// copy a's elem and sz
        sz = a.sz;
        space = a.space;
        a.elem = nullptr;	    // make a the empty vector
        a.sz = 0;
        return *this;       	// return a self-reference (see §17.10)
    }

    template<typename T> void vector<T>::reserve(int newalloc)
        // make the vector have space for newalloc elements
    {
        if (newalloc<=space) return;		// never decrease allocation
        T* p = new T[newalloc];	// allocate new space
        for (int i=0; i<sz; ++i) p[i]=elem[i];	// copy old elements
        delete[ ] elem;				// deallocate old space
        elem = p;	
        space = newalloc;		
    }

    template<typename T> void vector<T>::resize(int newsize)
        // make the vector have newsize elements
        // initialize each new element with the default value 0.0
    {
        reserve(newsize);		// make sure we have sufficient space
        for(int i = sz; i<newsize; ++i) elem[i] = 0;	// initialize new elements
        sz = newsize;	
    }

    template<typename T> void vector<T>::push_back(T d)
        // increase vector size by one
        // initialize the new element with d
    {
        if (sz==0) 			// no space: grab some
            reserve(8);
        else if (sz==space) 	// no more free space: get more space
            reserve(2*space);
        elem[sz] = d;		// add d at end
        ++sz;		// and increase the size (sz is the number of elements)
    }

    template<class T>  T& vector<T>::at (int n)
    {
        if (n<0 || sz<=n) throw out_of_range();
        return elem[n];
    }

    template<class T> ostream& operator<<(ostream& os, vector<T> v) {
        for(size_t i = 0; i < v.size(); i++) {
            os << v.at(i) << " ";
        }
        return os;
    }

}