#pragma once
#include<iostream>
#include<string>
#include<initializer_list>

/**
 * @brief klasa Greater "rodzic"
 * 
 */
class Greater{
public:
    /**
     * @brief do drukwoania
     * 
     */
    virtual void print()const = 0;
    /**
     * @brief operator>
     * 
     * @param a 
     * @return true 
     * @return false 
     */
    virtual bool operator>(const Greater &a) const = 0;

private:
};

/**
 * @brief zwraca wieksza wartosc z dwoch greater
 * 
 * @param a 
 * @param b 
 * @return const Greater& 
 */
const Greater& max(const Greater &a, const Greater &b);

/**
 * @brief klasa int posiadajaca int
 * 
 */
class Int : public Greater{
public:
    /**
     * @brief Construct a new Int object
     * 
     */
    Int() = default;

    /**
     * @brief Construct a new Int object using already existing int
     * 
     * @param a 
     */
    Int(int a): _int(a){};

    /**
     * @brief drukowanie
     * 
     */
    void print()const{
        std::cout << _int;
    }

    /**
     * @brief Get the Int object
     * 
     * @return int 
     */
    int getInt()const{return _int;}

    /**
     * @brief operator <<
     * 
     * @param ostr 
     * @param a 
     * @return std::ostream& 
     */
    friend std::ostream &operator<<(std::ostream &ostr, const Int &a){
        return ostr<<a._int;
    }

    /**
     * @brief operator >, potrzebny do max
     * 
     * @param a 
     * @return true 
     * @return false 
     */
    bool operator>(const Greater &a)const{
        return (_int > dynamic_cast<const Int&>(a).getInt());
    }

    /**
     * @brief operator int 
     * 
     * @return int 
     */
    operator int()const{return _int;}

protected:
    int _int;
};

/**
 * @brief klasa string pisadajaca string
 * 
 */
class String : public Greater{
public:
    /**
     * @brief Construct a new String object
     * 
     */
    String() = default;

    /**
     * @brief Construct a new String object using string element
     * 
     * @param str 
     */
    String(const std::string str): _str(str){};
    /**
     * @brief Construct a new String object using char element
     * 
     * @param str 
     */
    String(const char* str): _str(str){};

    /**
     * @brief drukuje
     * 
     */
    void print()const{
        std::cout << _str;
    }

    /**
     * @brief Get the String object
     * 
     * @return std::string 
     */
    std::string getString()const{return _str;}

    /**
     * @brief operator <<
     * 
     * @param ostr 
     * @param a 
     * @return std::ostream& 
     */
    friend std::ostream &operator<<(std::ostream &ostr, const String &a){
        return ostr<< a._str;
    } 

    /**
     * @brief operator > potrzebny do max
     * 
     * @param a 
     * @return true 
     * @return false 
     */
    bool operator>(const Greater &a)const{
        return (_str > dynamic_cast<const String&>(a).getString());
    }

    /**
     * @brief operator char*
     * 
     * @return char* 
     */
    operator char*()const{return const_cast<char*>(_str.c_str());}

protected:
    std::string _str;
};
