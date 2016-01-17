#ifndef __ACADEMICBUILDING__
#define __ACADEMICBUILDING__
#include "building.h"
#include <string>

class Player;

class AcademicBuilding : public Building {
public:
    const int cost;
    const int improvementCost;
    const int tuitionIndex[6];
    const std::string faculty;
    void buy(Player *player);
    void addImprovement();
    void removeImprovement();
    void landOn(Player *player);
    void Mortgage(bool answer);
    AcademicBuilding(const std::string name, const std::string faculty, const int cost, const int ic, const int tc0, const int tc1, const int tc2, const int tc3, const int tc4, const int tc5);
    ~AcademicBuilding();
};

#endif

