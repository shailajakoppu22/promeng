

void PromotionEngine::addPromotion(vector<char> items, vector<int> counts, int price, PromotionType promotionType)
{
    switch(promotionType)
    {
        case nSKU:
            if (items.size() > 1 || counts.size() > 1)
                Throw "Promotion type nSKU cannot have more than one SKU";
            promotions.push_back(Promotion(items, counts, price, promotionType));
            break;
        case SKU1_SKU2:
            if (items.size() > 2 || counts.size() > 2)
                Throw "Promotion type SKU1_SKU2 cannot have more than two SKUs";
            promotions.push_back(Promotion(items, counts, price, promotionType));
            break;
        default:
            Throw "Invalid promotion type";
    }
}

int PromotionEngine::applyPromotion(SkuList skuList, Cart& myCart, Promotion prom)
{
    switch(prom.promotionType)
    {
        case nSKU:
            int curCnt = myCart.getCnt(prom.items[0]);
            int minCntForProm = prom.cnt[0];
            int numOffers = curCnt / minCntForProm;
            if (numOffers > 0)
            {
                myCart.addToCartPrice(numOffers * prom.price);
                myCart.reduceCnt(prom.items[0], numOffers * minCntForProm);
            }
            break;
        case SKU1_SKU2:
            int sku1 = prom.items[0];
            int sku2 = prom.items[1];
            int sku1Cnt = myCart.getCnt(sku1);
            int sku2Cnt = myCart.getCnt(sku2);
            if (sku1Cnt > 0 && sku2Cnt > 0)
            {
                myCart.addToCartPrice(prom.price);
                myCart.reduceCnt(sku1, 1);
                myCart.reduceCnt(sku2, 1);
            }
            break;
        default:
            Throw "Invalid promotion type";
    }
}

int PromotionEngine::applyPromotions(SkuList skuList, Cart& myCart)
{
    for (auto it : promotions)
    {
        applyPromotion(myCart);
    }
}

int PromotionEngine::calculateCartPrice(SkuList skuList, Cart& myCart)
{
    applyPromotions(skuList, myCart);

    map<char, int> cartItemsAndCnts = myCart.getItemsAndCnts();
    for (auto it = cartItemsAndCnts.begin(); it != cartItemsAndCnts.end(); it++)
    {
        char sku = it->first;
        int skuCnt = it->second;
        if (skuCnt > 0)
        {
            int skuPrice = skuList.getPrice(sku);
            myCart.addToCartPrice(skuCnt * skuPrice);
            myCart.reduceCnt(sku, skuCnt);
        }
    }
}
