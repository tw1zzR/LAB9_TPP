#include "GildedRose.h"
#include <cassert>
#include <iostream>

void runTests() {
    {
        std::vector<Item> items = {Item("Elixir of the Mongoose", 5, 7)};
        GildedRose app(items);
        app.updateQuality();
        assert(items[0].sellIn == 4 && items[0].quality == 6);
    }
    {
        std::vector<Item> items = {Item("Elixir of the Mongoose", 0, 7)};
        GildedRose app(items);
        app.updateQuality();
        assert(items[0].sellIn == -1 && items[0].quality == 5);
    }
    {
        std::vector<Item> items = {Item("Elixir of the Mongoose", 0, 1)};
        GildedRose app(items);
        app.updateQuality();
        assert(items[0].quality == 0);
    }
    {
        std::vector<Item> items = {Item("Aged Brie", 2, 0)};
        GildedRose app(items);
        app.updateQuality();
        assert(items[0].sellIn == 1 && items[0].quality == 1);
    }
    {
        std::vector<Item> items = {Item("Aged Brie", 0, 50)};
        GildedRose app(items);
        app.updateQuality();
        assert(items[0].quality == 50);
    }
    {
        std::vector<Item> items = {Item("Sulfuras, Hand of Ragnaros", 0, 80)};
        GildedRose app(items);
        app.updateQuality();
        assert(items[0].sellIn == 0 && items[0].quality == 80);
    }
    {
        std::vector<Item> items = {Item("Backstage passes to a TAFKAL80ETC concert", 10, 20)};
        GildedRose app(items);
        app.updateQuality();
        assert(items[0].sellIn == 9 && items[0].quality == 22);
    }
    {
        std::vector<Item> items = {Item("Backstage passes to a TAFKAL80ETC concert", 5, 20)};
        GildedRose app(items);
        app.updateQuality();
        assert(items[0].sellIn == 4 && items[0].quality == 23);
    }
    {
        std::vector<Item> items = {Item("Backstage passes to a TAFKAL80ETC concert", 0, 20)};
        GildedRose app(items);
        app.updateQuality();
        assert(items[0].sellIn == -1 && items[0].quality == 0);
    }
    {
        std::vector<Item> items = {Item("Conjured Mana Cake", 3, 6)};
        GildedRose app(items);
        app.updateQuality();
        assert(items[0].sellIn == 2 && items[0].quality == 4);
    }
    {
        std::vector<Item> items = {Item("Conjured Mana Cake", 0, 6)};
        GildedRose app(items);
        app.updateQuality();
        assert(items[0].sellIn == -1 && items[0].quality == 2);
    }
}

int main() {
    runTests();
    std::cout << "All 11 unit tests passed successfully!" << std::endl;

    std::vector<Item> inventory = {
        Item("+5 Dexterity Vest", 10, 20),
        Item("Aged Brie", 2, 0),
        Item("Sulfuras, Hand of Ragnaros", 0, 80),
        Item("Backstage passes to a TAFKAL80ETC concert", 5, 20),
        Item("Conjured Mana Cake", 3, 6)
    };

    GildedRose app(inventory);
    app.updateQuality();

    for (const auto& item : inventory) {
        std::cout << item.name << " | sellIn: " << item.sellIn
                  << " | quality: " << item.quality << std::endl;
    }

    return 0;
}