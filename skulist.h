#ifndef _SKULIST_H_
#define _SKULIST_H_

#include <iostream>
#include <vector>

using namespace std;

#define MAX_ITEMS 26

// List of SKUs supported, along with default prices
class SkuList
{
    vector<int> skuPrices;

public:
    SkuList();
    void addSkuPrice(char sku, int price);
    int getSkuPrice(char sku) const;
};

#endif