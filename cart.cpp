// Test


cart::cart()
{
    myCartPrice = 0;
}

void cart::updateCount(char item, int cnt)
{
    if (item < 'A' || item > 'Z')
        Throw "Invalid item name";

    itemCount['A'] = cnt;
}

int cart::getCnt(char item)
{
    if (item < 'A' || item > 'Z')
        Throw "Invalid item name";

    return itemCount[item-'A'];
}