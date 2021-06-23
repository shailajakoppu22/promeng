// Test

SkuList::SkuList()
{
    itemsPrices = vector<int>(MAX_ITEMS, 0);
}

void SkuList::initPrice(char item, int price)
{
    if (item < 'A' || item > 'Z')
        Throw "Invalid item name";

    itemPrices[item-'A'] = price;
}
