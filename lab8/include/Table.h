#pragma once
#include"Data.h"

class Table{
public:
    /**
     * @brief Construct a new Table object
     * 
     */
    Table() = default;

    /**
     * @brief drukuje wszystkie elementy zapisane w _tab
     * 
     */
    void print(){
        auto print = [](const Data& a) { a.print(); };
        for_each(_tab.begin(), _tab.end(), print);
        std::cout << std::endl;
    };

    /**
     * @brief powinno sortowac po k-tej kolumnie
     * 
     * @param k 
     * @return Table 
     */
    Table sort(int k){
        int min = std::numeric_limits<int>::max();
        for (const auto& data : _tab) {
            min = std::min(min, static_cast<int>(data.getVector().size()));
        }

        if (k < 0 || k >= min){
            std::cout << "Indeks " << k << " nieprawidlowy!" << std::endl;
        }else{
            auto cmp = [k](const Data& a, const Data& b) {
            return a.getVector()[k] < b.getVector()[k];};
            std::sort(_tab.begin(), _tab.end(), cmp);
        }
    return *this;
    }

    /**
     * @brief sortuje za pomoca podanej funkcji
     * 
     * @param cmp 
     * @return Table 
     */
    Table sortBy(std::function<bool(const Data& a, const Data&b)> cmp){
        std::sort(_tab.begin(), _tab.end(), cmp);
        return *this;
    }

    /**
     * @brief operator += dla table i data
     * 
     * @param a 
     */
    void operator+=(Data a){
        _tab.push_back(a);
    }
private:
    std::vector<Data> _tab;
};