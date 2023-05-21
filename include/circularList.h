#pragma once
#include<iostream>
#include<string>
#include<memory>

/**
 * @brief template dla node
 * 
 * @tparam T 
 */
template<typename T> class Node{
public:
    /**
     * @brief Construct a new Node object majac tylko val
     * 
     * @param val 
     */
    Node (T val): _val(val), _next(nullptr){};
    /**
     * @brief Construct a new Node object majac val i next
     * 
     * @param val 
     * @param next 
     */
    Node(T val, std::shared_ptr<Node<T>> next): _val(val), _next(next){};
    /**
     * @brief zwraca element val
     * 
     * @return T 
     */
    T data()const{
        return _val;
    }
    
    std::shared_ptr<Node<T>> _next;
protected:
    T _val;
};

template<typename T> class CircularList{
public:
    /**
     * @brief Construct a new Circular List object
     * 
     */
    CircularList() = default;

    /**
     * @brief daje element na poczatek listy
     * 
     * @param val 
     * @return CircularList& 
     */
    CircularList& push_front(T val){
        if(!_head){
            _head =_tail = std::make_shared<Node<T>>(val);
        }else{
            std::shared_ptr<Node<T>> newNode;
            newNode = std::make_shared<Node<T>>(val);
            _tail->_next = newNode;
            newNode->_next = _head;
            _head = newNode;
        }
        return *this;
    };

    /**
     * @brief daje element na koniec listy
     * 
     * @param val 
     * @return CircularList& 
     */
    CircularList& push_back(T val){
        if(!_head){
            _head =_tail = std::make_shared<Node<T>>(val);
        }else{
            std::shared_ptr<Node<T>> newNode;
            newNode = std::make_shared<Node<T>>(val);
            newNode->_next = _head;
            _tail->_next = newNode;
            _tail = newNode;
        }
        return *this;
    };

    /**
     * @brief wypisanie wszystkich elementow listy
     * 
     */
    void print(){
        if(!_head){
            std::cout << "Lista pusta" << std::endl;
        }else{
            std::shared_ptr<Node<T>> cur = _head;
            while(cur != _tail){
                std::cout << cur->data() << " ";
                cur = cur->_next;
            }
            std::cout << _tail->data() << " ";
            std::cout<<std::endl;
        }
    };

    /**
     * @brief dodaje element w miejscu dla sortowania
     * 
     * @param val 
     * @return CircularList& 
     */
    CircularList& add_sorted(T val){
        if(!_head){
            _head =_tail = std::make_shared<Node<T>>(val);
        }else if(_head->data()>val){
            this->push_front(val);
        }else if(_tail->data()<val){
            this->push_back(val);
        }else{
            std::shared_ptr<Node<T>> cur = _head;
            std::shared_ptr<Node<T>> next = _head->_next;
            std::shared_ptr<Node<T>> newNode;
            newNode = std::make_shared<Node<T>>(val);

            while(cur){
                if(cur->data()<val && next->data()>=val){
                    newNode->_next = next;
                    cur->_next = newNode;
                    return *this;
                }else{
                    cur = cur -> _next;
                    next = next -> _next;
                }
            }
        }
        return *this;
    };

    /**
     * @brief zwraca element posiadajacy val == val
     * 
     * @param val 
     * @return std::shared_ptr<Node<T>> 
     */
    std::shared_ptr<Node<T>> find(T val){
        if(!_head){
            return nullptr;
        }else{
            std::shared_ptr<Node<T>> cur = _head;
            while(cur != _tail){
                if(cur->data() == val){
                    return cur;
                }
                cur = cur->_next;
            }
            if(cur == _tail && cur->data() == val) return cur;
        }
        return nullptr;
    };

    /**
     * @brief Get the Next object in list
     * 
     * @param elem 
     * @return std::shared_ptr<Node<T>> 
     */
    std::shared_ptr<Node<T>> getNext(std::shared_ptr<Node<T>> elem){
       if(!_head) return nullptr;
       if(elem==_tail) return _head;
       std::shared_ptr<Node<T>> found_one = this->find(elem->data());
       return found_one->_next;
    };

    /**
     * @brief powinno usuwac element z listy
     * 
     * @param val 
     * @return CircularList& 
     */
    CircularList& remove(T val){
        if(!_head) return *this;
        if(_head->data() == val){
            if(_head == _tail){
                _head = _tail = nullptr;
            }else{
                _head = _head->_next;
                _tail->_next = _head;
            }
            return *this;
        }

        std::shared_ptr<Node<T>> cur = _head;
        std::shared_ptr<Node<T>> prev = nullptr;
        while(cur){
            if(cur->data() == val){
                prev->_next = cur->_next;
                if(cur == _tail){
                    _tail = prev;
                }
                break;
            }
        prev = cur;
        cur = cur->_next;
    }

    return *this;
        
    }
    
protected:
    std::shared_ptr<Node<T>> _head;
    std::shared_ptr<Node<T>> _tail;
};