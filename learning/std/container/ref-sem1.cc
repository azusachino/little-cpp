#include <algorithm>
#include <deque>
#include <iostream>
#include <memory>
#include <set>
#include <string>

class Item {
private:
    std::string name;
    float       price;

public:
    Item(const std::string& n, float p = 0) : name(n), price(p) {}
    std::string getName() const { return name; }
    void        setName(const std::string& n) { name = n; }
    float       getPrice() const { return price; }
    void        setPrice(float p) { price = p; }
};

template <typename Coll>
void printItems(const std::string& msg, const Coll& coll) {
    std::cout << msg << std::endl;
    for (const auto& e : coll) {
        std::cout << " " << e->getName() << ": " << e->getPrice() << std::endl;
    }
}

int main() {
    using namespace std;
    typedef shared_ptr<Item> ItemPtr;
    set<ItemPtr>             allItems;
    deque<ItemPtr>           bestSellers;

    bestSellers = {ItemPtr(new Item("A", 20.10)), ItemPtr(new Item("B", 14.10)),
                   ItemPtr(new Item("C", 24.10))};
    allItems    = {ItemPtr(new Item("D", 4.10)), ItemPtr(new Item("E", 5.10))};
    allItems.insert(bestSellers.begin(), bestSellers.end());
    printItems("bestSellers: ", bestSellers);
    printItems("all: ", allItems);
    cout << endl;

    for_each(bestSellers.begin(), bestSellers.end(),
             [](shared_ptr<Item>& e) { e->setPrice(e->getPrice() * 2); });
    bestSellers[1] =
        *(find_if(allItems.begin(), allItems.end(),
                  [](shared_ptr<Item> e) { return e->getName() == "E"; }));
    bestSellers[0]->setPrice(54.33);
    printItems("bestSellers: ", bestSellers);
    printItems("all: ", allItems);
}