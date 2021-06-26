#include "skulist.h"

SkuList::SkuList()
{
    skuPrices = vector<int>(MAX_ITEMS, 0);
}

void SkuList::addSkuPrice(char sku, int price)
{
    if (sku < 'A' || sku > 'Z')
        throw invalid_argument("Invalid SKU name");

    skuPrices[sku-'A'] = price;
}

int SkuList::getSkuPrice(char sku) const
{
    if (sku < 'A' || sku > 'Z')
        throw invalid_argument("Invalid SKU name");

    return skuPrices[sku-'A'];
}