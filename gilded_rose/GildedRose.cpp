#include "GildedRose.h"
#include <algorithm>

void BaseItemUpdater::increaseQuality(Item& item, int amount) {
    item.quality = std::min(50, item.quality + amount);
}

void BaseItemUpdater::decreaseQuality(Item& item, int amount) {
    item.quality = std::max(0, item.quality - amount);
}

void NormalItemUpdater::update(Item& item) const {
    decreaseQuality(item, 1);
    item.sellIn -= 1;
    if (item.sellIn < 0) {
        decreaseQuality(item, 1);
    }
}

void AgedBrieUpdater::update(Item& item) const {
    increaseQuality(item, 1);
    item.sellIn -= 1;
    if (item.sellIn < 0) {
        increaseQuality(item, 1);
    }
}

void SulfurasUpdater::update(Item& item) const {
}

void BackstagePassUpdater::update(Item& item) const {
    increaseQuality(item, 1);
    if (item.sellIn < 11) {
        increaseQuality(item, 1);
    }
    if (item.sellIn < 6) {
        increaseQuality(item, 1);
    }
    item.sellIn -= 1;
    if (item.sellIn < 0) {
        item.quality = 0;
    }
}

void ConjuredItemUpdater::update(Item& item) const {
    decreaseQuality(item, 2);
    item.sellIn -= 1;
    if (item.sellIn < 0) {
        decreaseQuality(item, 2);
    }
}

std::unique_ptr<IItemUpdater> ItemUpdaterFactory::create(const std::string& itemName) {
    if (itemName == "Aged Brie") {
        return std::make_unique<AgedBrieUpdater>();
    }
    if (itemName == "Sulfuras, Hand of Ragnaros") {
        return std::make_unique<SulfurasUpdater>();
    }
    if (itemName == "Backstage passes to a TAFKAL80ETC concert") {
        return std::make_unique<BackstagePassUpdater>();
    }
    if (itemName.rfind("Conjured", 0) == 0) {
        return std::make_unique<ConjuredItemUpdater>();
    }
    return std::make_unique<NormalItemUpdater>();
}

GildedRose::GildedRose(std::vector<Item>& items) : items(items) {}

void GildedRose::updateQuality() {
    for (auto& item : items) {
        auto updater = ItemUpdaterFactory::create(item.name);
        updater->update(item);
    }
}