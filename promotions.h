
typedef enum
{
    nSKU = 1,
    SKU1_SKU2 = 2
} PromotionType;

class Promotion
{
    vector<char> items;
    vector<int> counts;
    int price;
    PromotionType promotionType;
};

class PromotionEngine
{
    vector<Promotions> promotions;

    void addPromotion(vector<char> items, vector<int> counts, int price, PromotionType promotionType);

    int applyPromotion(Cart& myCart, Promotion prom);

    int applyPromotions(Cart& myCart);

    int calculateCartPrice(Cart& myCart);

};