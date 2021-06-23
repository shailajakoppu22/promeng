

int main()
{
    SKULIST skuList;
    skuList.addItemPrice('A', 10);

    Promotions promotions;
    promotions.addPromotion({'A'}, {3}, 30, nSKU);
    promotions.addPromotion({'C', 'D'}, 50, SKU1_SKU2);

    cout << "Test1: " << testCase1(skuList, promotions) <<endl;

    cout << "Test2: " << testCase1(skuList, promotions) <<endl;
}