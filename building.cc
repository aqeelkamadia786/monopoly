#include "building.h"

using namespace std;

Building::Building(const string name) : Square(name), owner(NULL), mortgaged(false), improvements(0) {}

Building::~Building() {}
