#include "cart.h"

Cart::Cart(string name)
{
    userName = name;
    cartPrice = 0;
}

void Cart::updateItemCnt(char item, int cnt)
{
    if (item < 'A' || item > 'Z')
        throw "Invalid item name";

    itemsCnts[item] = cnt;
}

int Cart::getItemCnt(char item)
{
    if (item < 'A' || item > 'Z')
        throw "Invalid item name";

    return itemsCnts[item];
}

// Returns map of items in the cart to quantity of each
map<char, int> Cart::getItemsAndCnts() const
{
    return itemsCnts;
}

int Cart::getCartPrice()
{
    return cartPrice;
}

void Cart::updateCartPrice(int price)
{
    cartPrice = price;
}

