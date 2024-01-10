#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class UniqueProduct 
{
public:
    int identifier;
    string productName;
    double productCost;

    UniqueProduct(int _identifier, const string& _productName, double _productCost)
        : identifier(_identifier), productName(_productName), productCost(_productCost) {}
};

class DistinctiveWarehouseKeeper 
{
private:
    vector<UniqueProduct> treasureChest;

public:
    void depositProduct(const UniqueProduct& rareArtifact) 
    {
        treasureChest.push_back(rareArtifact);
        cout << "Exquisite product added to the treasure chest. " << endl;
    }

    void banishProductById(int forbiddenId) 
    {
        auto it = remove_if(treasureChest.begin(), treasureChest.end(), [forbiddenId](const UniqueProduct& relic) { return relic.identifier == forbiddenId; });

        if (it != treasureChest.end()) 
        {
            treasureChest.erase(it, treasureChest.end());
            cout << "Exquisite product with ID " << forbiddenId << " banished from the treasure chest. " << endl;
        } 
        else
            cout << "Exquisite product with ID " << forbiddenId << " not found in the treasure chest. " << endl;
    }

    void displayTreasureChest() const 
    {
        cout << "Current Exquisite Treasure Chest: " << endl;
        for (const auto& rareArtifact : treasureChest)
            cout << "ID: " << rareArtifact.identifier << "\tName: " << rareArtifact.productName << "\tCost: $" << rareArtifact.productCost << " " << endl;
    }
};

int main() 
{
    DistinctiveWarehouseKeeper keeperOfTreasures;

    UniqueProduct rareArtifact1(1, "Collector's Item", 999.99);
    UniqueProduct rareArtifact2(2, "Ancient Relic", 499.99);

    keeperOfTreasures.depositProduct(rareArtifact1);
    keeperOfTreasures.depositProduct(rareArtifact2);

    cout << "*** Displaying the current exquisite treasure chest ***" << endl;
    keeperOfTreasures.displayTreasureChest();

    keeperOfTreasures.banishProductById(1);

    cout << "*** Displaying the updated exquisite treasure chest after banishment of ID 1 ***" << endl;
    keeperOfTreasures.displayTreasureChest();

    return 0;
}
