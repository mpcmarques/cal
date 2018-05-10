//
// Created by mateus on 10-05-2018.
//

#ifndef PARKINGSPOTSSEARCHER_KMPMATCHER_H
#define PARKINGSPOTSSEARCHER_KMPMATCHER_H

#include <string>
#include <vector>

class KmpMatcher {
private:
    std::vector<int> computePrefixFunction(std::string p);

public:
    static bool matches(std::string t, std::string p);


};


#endif //PARKINGSPOTSSEARCHER_KMPMATCHER_H
