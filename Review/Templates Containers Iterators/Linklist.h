#ifndef LINKLIST_H
#define LINKLIST_H

#include "../std_lib_facilities.h"

namespace Linklist {
    template <typename T>
    class Link {
        public:
            Link<T>* next;
            T val;
    };

    template <typename T>
    class list {
        public:
            class iterator;
            list() { head = nullptr; }
            ~list();
            iterator begin();
            iterator end();
            void push_front(const T& val);
        private:
            Link<T>* head;
    };

    template <typename T>
    list<T>::~list() {
        Link<T>* temp(nullptr);
        head = temp;
        ++head;
        delete[] temp;
    }

    template<typename T>
    typename list<T>::iterator list<T>::begin() {
        return iterator(head);
    }

    template <typename T>
    typename list<T>::iterator list<T>::end() {
        return iterator(nullptr);
    }
    template <typename T>
    void list<T>::push_front(const T& val) {
        auto temp = new Link<T>;
        temp->val = val;
        temp->next = head;
        head = temp;
    }


    template <typename T>
    class list<T>::iterator {
        private:
            Link<T>* curr;
        public:
            iterator(Link<T>* p) { curr = p; }
            T& operator*() { return curr->val; }
            bool operator==(const iterator& b) const { return this->curr == b.curr; }
            bool operator!=(const iterator& b) const { return this->curr != b.curr; }   
            iterator& operator ++() {
                curr = curr->next;
                return *this;
            }    
    };
}

#endif