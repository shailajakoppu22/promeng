#ifndef _CART_H_
#define _CART_H_

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Cart holds items added by a user to the basket
class Cart
{
    string userName;
    map<char, int> itemsCnts; // each item added by the user along with counts
    int cartPrice;

public:
    Cart(string name);

    void updateItemCnt(char item, int cnt);

    int getItemCnt(char item);

    map<char, int> getItemsAndCnts() const;

    int getCartPrice();
    void updateCartPrice(int price);
};

#endif