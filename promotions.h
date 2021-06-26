#ifndef _PROMOTIONS_H_
#define _PROMOTIONS_H_

#include <iostream>
#include <vector>
#include "cart.h"
#include "skulist.h"

using namespace std;

// Types of promotions supported
typedef enum
{
    nSKU = 1,      // promotion on multiples of the same item
    SKU1_SKU2 = 2  // promotion on two items bought together
} PromotionType;

// This defines a promotion - items involved in a promotion along with counts
class Promotion
{
    vector<char> items;
    vector<int> counts;
    int promotionPrice;
    PromotionType promotionType;

    Promotion(vector<char> promItems, vector<int> cnts, int promPrice, PromotionType promType);
    friend class PromotionEngine;
};

// Promotion engine, which holds all active promotions and executes them on given cart
class PromotionEngine
{
    vector<Promotion> promotions;

public:
    void addPromotion(vector<char> items, vector<int> counts, int price, PromotionType promotionType);

    int applyPromotion(const SkuList& skuList, map<char, int>& cartItemsAndCnts, const Promotion& prom);
    int applyAllPromotions(const SkuList& skuList, map<char, int>& cartItemsAndCnts);

    int calculateCartPrice(const SkuList& skuList, const Cart& myCart);

};

#endif