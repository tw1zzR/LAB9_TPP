#pragma once
#include <memory>
#include <string>
#include <utility>
#include <vector>

class Item {
public:
    std::string name;
    int sellIn;
    int quality;

    Item(std::string name, int sellIn, int quality)
        : name(std::move(name)), sellIn(sellIn), quality(quality) {}
};

class IItemUpdater {
public:
    virtual void update(Item& item) const = 0;
    virtual ~IItemUpdater() = default;
};

class BaseItemUpdater : public IItemUpdater {
protected:
    static void increaseQuality(Item& item, int amount = 1);
    static void decreaseQuality(Item& item, int amount = 1);
};

class NormalItemUpdater : public BaseItemUpdater {
public:
    void update(Item& item) const override;
};

class AgedBrieUpdater : public BaseItemUpdater {
public:
    void update(Item& item) const override;
};

class SulfurasUpdater : public IItemUpdater {
public:
    void update(Item& item) const override;
};

class BackstagePassUpdater : public BaseItemUpdater {
public:
    void update(Item& item) const override;
};

class ConjuredItemUpdater : public BaseItemUpdater {
public:
    void update(Item& item) const override;
};

class ItemUpdaterFactory {
public:
    static std::unique_ptr<IItemUpdater> create(const std::string& itemName);
};

class GildedRose {
public:
    std::vector<Item>& items;
    explicit GildedRose(std::vector<Item>& items);
    void updateQuality();
};