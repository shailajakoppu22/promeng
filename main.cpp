#include "skulist.h"
#include "cart.h"
#include "promotions.h"

bool testCase1(SkuList& skuList, PromotionEngine& promotions)
{
    Cart myCart("User1");
    myCart.updateItemCnt('A', 1);
    myCart.updateItemCnt('B', 1);
    myCart.updateItemCnt('C', 1);

    int price = promotions.calculateCartPrice(skuList, myCart);

    if (100 == price)
        return true;
    return false;
}

bool testCase2(SkuList& skuList, PromotionEngine& promotions)
{
    Cart myCart("User2");
    myCart.updateItemCnt('A', 5);
    myCart.updateItemCnt('B', 5);
    myCart.updateItemCnt('C', 1);

    int price = promotions.calculateCartPrice(skuList, myCart);

    if (370 == price)
        return true;
    return false;
}

bool testCase3(SkuList& skuList, PromotionEngine& promotions)
{
    Cart myCart("User3");
    myCart.updateItemCnt('A', 3);
    myCart.updateItemCnt('B', 5);
    myCart.updateItemCnt('C', 1);
    myCart.updateItemCnt('D', 1);

    int price = promotions.calculateCartPrice(skuList, myCart);

    if (280 == price)
        return true;
    return false;
}

int main()
{
    try
    {
        // Setup SKU prices list
        SkuList skuList;
        skuList.addSkuPrice('A', 50);
        skuList.addSkuPrice('B', 30);
        skuList.addSkuPrice('C', 20);
        skuList.addSkuPrice('D', 15);

        // Create promotion engine and add each active promotion
        PromotionEngine promEng;
        promEng.addPromotion({'A'}, {3}, 130, nSKU);
        promEng.addPromotion({'B'}, {2}, 45, nSKU);
        promEng.addPromotion({'C', 'D'}, {1, 1}, 30, SKU1_SKU2);

        // Test with different carts
        cout << "TestCase 1: " << (testCase1(skuList, promEng) ? "PASSED" : "FAILED") <<endl;
        cout << "TestCase 2: " << (testCase2(skuList, promEng) ? "PASSED" : "FAILED") <<endl;
        cout << "TestCase 3: " << (testCase2(skuList, promEng) ? "PASSED" : "FAILED") <<endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << "Execption: " <<e.what() << '\n';
    }
}