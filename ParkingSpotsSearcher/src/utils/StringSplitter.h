//
// Created by mateus on 05/04/18.
//

#ifndef PARKINGSPOTSSEARCHER_STRINGSPLITTER_H
#define PARKINGSPOTSSEARCHER_STRINGSPLITTER_H

#include <vector>
#include <string>

/**
 * This is class is needed to split strings based on delimiter tokens.
 */
class StringSplitter {
public:

    /**
     * Splits a string with a delimiter token.
     * @param s String to be split.
     * @param token Delimiter token.
     * @return Vector containing split string.
     */
    static std::vector<std::string> split(std::string s, char token);

};


#endif //PARKINGSPOTSSEARCHER_STRINGSPLITTER_H
