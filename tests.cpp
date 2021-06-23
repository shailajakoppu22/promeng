

int testCase1(skuList, promotions)
{
    Cart myCart;
    myCart.addItem('A', 4);

    promotions.calculateCartPrice(myCart);

    return myCart.getCartPrice(); // assert here
}

int testCase2(skuList, promotions)
{
    Cart myCart;
    myCart.addItem('B', 5);

    promotions.calculateCartPrice(myCart);

    return myCart.getCartPrice(); // assert here
}

