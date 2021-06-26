#include "promotions.h"
Promotion::Promotion(vector<char> promItems, vector<int> cnts, int promPrice, PromotionType promType)
{
    items = promItems;
    counts = cnts;
    promotionPrice = promPrice;
    promotionType = promType;
}

void PromotionEngine::addPromotion(vector<char> items, vector<int> counts, int price, PromotionType promotionType)
{
    switch(promotionType)
    {
        case nSKU:
            if (items.size() > 1 || counts.size() > 1)
                throw "Promotion type nSKU cannot have more than one SKU";
            promotions.push_back(Promotion(items, counts, price, promotionType));
            break;
        case SKU1_SKU2:
            if (items.size() > 2 || counts.size() > 2)
                throw "Promotion type SKU1_SKU2 cannot have more than two SKUs";
            promotions.push_back(Promotion(items, counts, price, promotionType));
            break;
        default:
            throw "Invalid promotion type";
    }
}

int PromotionEngine::applyPromotion(const SkuList& skuList, map<char, int>& cartItemsAndCnts, const Promotion& prom)
{
    int price = 0;
    switch(prom.promotionType)
    {
        case nSKU:   // apply romotion of type - multiple of a item
        {
            int curCnt = cartItemsAndCnts[prom.items[0]];
            int minCntForProm = prom.counts[0];
            int numOffers = curCnt / minCntForProm;
            if (numOffers > 0)
            {
                price += numOffers * prom.promotionPrice;
                cartItemsAndCnts[prom.items[0]] -= numOffers * minCntForProm;
            }
            break;
        }
        case SKU1_SKU2:  // apply promotion of type - different items buying together
        {
            int sku1 = prom.items[0];
            int sku2 = prom.items[1];
            int sku1Cnt = cartItemsAndCnts[sku1];
            int sku2Cnt = cartItemsAndCnts[sku2];
            if (sku1Cnt > 0 && sku2Cnt > 0)
            {
                price += prom.promotionPrice;
                cartItemsAndCnts[sku1] -= 1;
                cartItemsAndCnts[sku2] -= 1;
            }
            break;
        }
        default:
            throw "Invalid promotion type";
    }
    return price;
}

int PromotionEngine::applyAllPromotions(const SkuList& skuList, map<char, int>& cartItemsAndCnts)
{
    int price = 0;
    for (auto it : promotions)
    {
        price += applyPromotion(skuList, cartItemsAndCnts, it);
    }
    return price;
}

// Calculates total price of a given cart.
// Just use cart items and counts values without modifying the cart because in-practical
// user can add/delete items and recalculate the price again
int PromotionEngine::calculateCartPrice(const SkuList& skuList, const Cart& myCart)
{
    map<char, int> cartItemsAndCnts = myCart.getItemsAndCnts();
    int price = applyAllPromotions(skuList, cartItemsAndCnts);

    // Instead of accessing by each SKU name, just check what user has added
    // because in practical supported SKUs can be lot more than user cart has
    for (auto it = cartItemsAndCnts.begin(); it != cartItemsAndCnts.end(); it++)
    {
        char sku = it->first;
        int skuCnt = it->second;
        if (skuCnt > 0)
        {
            int skuPrice = skuList.getSkuPrice(sku);
            price += skuCnt * skuPrice;
            cartItemsAndCnts[it->first] = 0;
        }
    }

    return price;
}
