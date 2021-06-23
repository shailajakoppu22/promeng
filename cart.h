// Test

class cart
{
    map<char, int> itemsCount;
    int myCartPrice;

    cart();

    void addItem(char item, int cnt);

    int getItemCnt(char item);

    map<char, int> getItemsAndCnts();
};