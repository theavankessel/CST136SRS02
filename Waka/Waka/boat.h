#ifndef boat_h
#define boat_h

#include <string>
#include <vector>
#include <functional>
#include "environment.h"
#include "wind.h"
#include "hull.h"
#include "propulsion.h"

//Abstract class has at least one pure virtual function
class Boat
{
public:
    virtual ~Boat() = default;
    std::string getName() const noexcept;
    int getHull() const noexcept;
    int getWaveHeight(); //Get the height of the current waves
    
    //Determine if the height of the current wave is larger than the maximumWaveHeight -- capsize or not?
    
    int getWindSpeed();
    int getMinTurnRadius() const noexcept;
    int getMaxWaveHeight() const;
    double getKnots() const noexcept;
    
protected:
    explicit Boat(Hull& hull); //Hull cannot be treated like a boat with explicit
    Boat(Hull& hull, std::vector<std::reference_wrapper<Propulsion>>& propulsion);
    //pure virtual function
    virtual std::string do_getName() const noexcept = 0;
    
private:
    const Hull& hull_;
    const std::vector<std::reference_wrapper<Propulsion>>& propulsion_{};
};

#endif /* boat_h */
