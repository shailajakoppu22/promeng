#include "skulist.h"
#include "cart.h"
#include "promotions.h"

void testCase1_A1B1C1(SkuList& skuList, PromotionEngine& promotions)
{
    Cart myCart("User1");
    myCart.updateItemCnt('A', 1);
    myCart.updateItemCnt('B', 1);
    myCart.updateItemCnt('C', 1);

    int price = promotions.calculateCartPrice(skuList, myCart);

    if (100 == price)
        cout << __FUNCTION__ << ": PASS \n";
    else
        cout << __FUNCTION__ << ": FAIL \n";
}

void testCase2_A5B5C1(SkuList& skuList, PromotionEngine& promotions)
{
    Cart myCart("User2");
    myCart.updateItemCnt('A', 5);
    myCart.updateItemCnt('B', 5);
    myCart.updateItemCnt('C', 1);

    int price = promotions.calculateCartPrice(skuList, myCart);

    if (370 == price)
        cout << __FUNCTION__ << ": PASS \n";
    else
        cout << __FUNCTION__ << ": FAIL \n";
}

void testCase3_A3B5C1D1(SkuList& skuList, PromotionEngine& promotions)
{
    Cart myCart("User3");
    myCart.updateItemCnt('A', 3);
    myCart.updateItemCnt('B', 5);
    myCart.updateItemCnt('C', 1);
    myCart.updateItemCnt('D', 1);

    int price = promotions.calculateCartPrice(skuList, myCart);

    if (280 == price)
        cout << __FUNCTION__ << ": PASS \n";
    else
        cout << __FUNCTION__ << ": FAIL \n";
}

void testCase4_empty(SkuList& skuList, PromotionEngine& promotions)
{
    Cart myCart("User4");

    int price = promotions.calculateCartPrice(skuList, myCart);

    if (0 == price)
        cout << __FUNCTION__ << ": PASS \n";
    else
        cout << __FUNCTION__ << ": FAIL \n";
}

void testCase5_noDiscount(SkuList& skuList, PromotionEngine& promotions)
{
    Cart myCart("User5");
    myCart.updateItemCnt('X', 3);

    int price = promotions.calculateCartPrice(skuList, myCart);

    if (0 == price)
        cout << __FUNCTION__ << ": PASS \n";
    else
        cout << __FUNCTION__ << ": FAIL \n";
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
        testCase1_A1B1C1(skuList, promEng);
        testCase2_A5B5C1(skuList, promEng);
        testCase3_A3B5C1D1(skuList, promEng);
        testCase4_empty(skuList, promEng);
        testCase5_noDiscount(skuList, promEng);

    }
    catch(const std::exception& e)
    {
        std::cerr << "Execption: " <<e.what() << '\n';
    }
}