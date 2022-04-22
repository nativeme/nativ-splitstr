#ifndef _SPLITSTRING_HPP_
#define _SPLITSTRING_HPP_
#include "Arduino.h"

namespace softcast{

struct StrSplitOut
: public std::vector<const char*>{
    ~StrSplitOut(){
        for (auto &&str_buffer : *this){
            delete[] str_buffer;
        }
    }
};

/**
 * @brief 
 * Splits C-style string to vector of C-style strings.
 * @param char_array C style string
 * @param split_by delimiter
 * @return StrSplitOut Vector of C style strings that auto destroyes underlying pointers.
 */
inline StrSplitOut split_str(const char* char_array, const char& split_by = ' '){
    StrSplitOut splited;
    uint16_t word_start = 0;
    uint16_t word_end = 0;
    uint16_t word_length = 0;

    for (size_t i = 0; i <= std::strlen(char_array); i++){
        if(char_array[i] == split_by || i == std::strlen(char_array)){
            word_end = i;
            word_length = word_end - word_start;
            
            char* buffer = new char[word_length + 1];

            for (int j = word_start, k = 0; j <= word_end; j++, k++){
                if (char_array[j] == ' ') buffer[k] = '\0';
                else buffer[k] = char_array[j];
            }

            splited.push_back(const_cast<const char*>(buffer));

            word_start = word_end + 1;
        }
    }
    return splited;
}

/* implementation for Arduino Strings */
#ifdef Arduino_h
/**
 * @brief 
 * Splits Arduino String to vector of Arduino Strings.
 * @param string string to split
 * @param split_by delimiter
 * @return std::vector<String> Vector of Arduino Strings.
 */
inline std::vector<String> split_str(const String& string, const char& split_by = ' '){
    std::vector<String> splitted;
    String str = string;
    
    while(str.indexOf(split_by) != -1){
        splitted.push_back( str.substring(0, str.indexOf(split_by)) );
        str = str.substring(str.indexOf(split_by) + 1, str.length());
    }
    splitted.push_back(str);
    return splitted;
}
#endif

}
#endif
