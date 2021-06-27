# Promotion Engine

Seller can be selling many different products (SKUs), In this case assuming product names from 'A' to 'Z'. Seller can be prmotoing multiple offers. A customer can add set of items to his/her cart, check cart price after applying all promotions available

This solution 4 classes 
- SkuList to maintain list of products seller has and price of each product
- Cart to maintain list of products customer like to buy and quantity of each selected product
- Promotion represents a single active promotion
- Promotion Engine maintains list of active promotions. When invoked with a cart, it applies all active promotions applicable and calculates price of the input cart

To build: make
To execute: ./promeng