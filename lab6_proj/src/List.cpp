#include"List.h"

List::~List(){
    Node *current = _head;
    while(current != nullptr){
        Node* next = current->next;
        delete current;
        current = next;
    }
}

List::List(const List& cp){
    _head = nullptr;
    _end = nullptr;
    Node *current = cp._head;
    while(current != nullptr){
        insert(*current->data, End);
        current = current->next;
    }
}

List& List::insert(Data& dat, Insertion position){
    Node *new_node = new Node{&dat, nullptr};
    if(_head == nullptr){
        _head = _end = new_node;
    }else if(position == Begin){
        new_node->next = _head;
        _head = new_node;
    }else{
        _end->next = new_node;
        _end = new_node;
    }

    return *this;
}

List& List::insert(Fraction frac, Insertion position){
    Node *new_node = new Node{new Fraction(frac), nullptr};
    if(_head == nullptr){
        _head = _end = new_node;
    }else if(position == Begin){
        new_node->next = _head;
        _head = new_node;
    }else{
        _end->next = new_node;
        _end = new_node;
    }

    return *this;
}

List& List::insert(StringData str, Insertion position){
    Node *new_node = new Node{new StringData(str), nullptr};
    if(_head == nullptr){
        _head = _end = new_node;
    }else if(position == Begin){
        new_node->next = _head;
        _head = new_node;
    }else{
        _end->next = new_node;
        _end = new_node;
    }

    return *this;
}

void List::print()const{
    std::cout << "[ ";
    Node *current = _head;
    while(current != nullptr){
        current->data->print();
        std::cout << " ";
        current = current->next;
    }
    std::cout << "]" << std::endl;
}

List& List::operator=(const List& cp){
    if(this != &cp){
        Node *current = _head;
        while(current != nullptr){
            Node *next = current->next;
            delete current;
            current = next;
        }

        _head = _end = nullptr;
        Node *current_cp = cp._head;
        while(current_cp != nullptr){
            Data *dat_new = current_cp->data;
            Node *new_node = new Node{dat_new, nullptr};
            if(_head == nullptr){
                _head = _end = new_node;
            }else{
                _end->next = new_node;
                _end = new_node;
            }
            current_cp = current_cp->next;
        }
    }

    return *this;
}