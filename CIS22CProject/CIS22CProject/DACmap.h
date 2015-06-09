#pragma once
#include <map>

using namespace std;

template <class KeyType, class ItemType>
class DACmapIterator
{
private:
	map<KeyType, ItemType> *pdacMap;
	typename map<KeyType, ItemType>::iterator mapIterator;

public:
	DACmapIterator(map<KeyType, ItemType> *p){
		pdacMap = p;
		mapIterator = (pdacMap->begin());

	}
	ItemType next(){ return (mapIterator++)->second; }
	bool hasNext() const { return mapIterator != (pdacMap->end()); }

};

template <class KeyType, class ItemType>
class DACmap
{
private:
	map<KeyType, ItemType> dacMap;
	DACmapIterator<KeyType, ItemType> *thisIterator;// init. to 0

public:
	DACmap(){ thisIterator = 0; }
	~DACmap(){ if (thisIterator != 0) delete thisIterator; }

	bool isEmpty() const { return dacMap.empty(); }
	int getNumberOfItems() const { return dacMap.size(); }
	bool add(const KeyType& searchKey, const ItemType& newItem);
	bool remove(const KeyType& searchKey);

	void clear();
	ItemType getItem(const KeyType& searchKey) const;
	bool contains(const KeyType& searchKey) const;

	/** Traverses the items in this dictionary in sorted search-key order
	and calls a given client function once for each item. */
	void traverse(void visit(ItemType&)) const;

	// For iterator
	DACmapIterator<KeyType, ItemType> *iterator();
};

template <class KeyType, class ItemType>
bool DACmap<KeyType, ItemType>::add(const KeyType& searchKey, const ItemType& newItem)
{
	if (contains(searchKey))
		return false;
	dacMap[searchKey] = newItem;
	return true;
}

template <class KeyType, class ItemType>
bool DACmap<KeyType, ItemType>::remove(const KeyType& searchKey)
{
	return dacMap.erase(searchKey) == 1;
}

template <class KeyType, class ItemType>
void DACmap<KeyType, ItemType>::clear()
{
	dacMap.clear();
}

template <class KeyType, class ItemType>
ItemType DACmap<KeyType, ItemType>::getItem(const KeyType& searchKey) const
{
	typename map<KeyType, ItemType>::const_iterator foundItem = dacMap.find(searchKey);
	if (foundItem == dacMap.end())
		return ItemType();
	return foundItem->second;
}

template <class KeyType, class ItemType>
bool DACmap<KeyType, ItemType>::contains(const KeyType& searchKey) const
{
	typename map<KeyType, ItemType>::const_iterator itemIter = dacMap.begin();
	// CHANGE TO SEARCH IN A LOOP WITH ITERATOR?
	for (; itemIter != dacMap.end(); ++itemIter)
	{
		if (itemIter->first == searchKey)
		{
			return true;
		}
	}
	return false; //
}

template <class KeyType, class ItemType>
DACmapIterator<KeyType, ItemType> *DACmap<KeyType, ItemType>::iterator()
{
	if (thisIterator != 0)
		delete thisIterator;
	thisIterator = new DACmapIterator<KeyType, ItemType>(&dacMap);
	return thisIterator;
}