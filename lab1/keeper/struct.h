#include "..\entity\Garage.h"
struct Node
{
    Garage* PtrGarage;
    Node* next;

    Node(Garage* g): PtrGarage(g), next(nullptr){}
};
