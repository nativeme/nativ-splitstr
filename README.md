# nativ-splitstr

[![PlatformIO Registry](https://badges.registry.platformio.org/packages/nativeme/library/nativ-splitstr.svg)](https://registry.platformio.org/libraries/nativeme/nativ-splitstr)

Personal micro library for string splitting, mainly for usage in arduino framework.  
Should work everywhere.

If you found it useful feel free to use it.  

## Header files
##### **`SplitString.hpp`**
Include this for functionality.
``` c++
// Arduino
namespace sc = softcast;
auto splitted = sc::split_str("This is some C-style test string to split.");
for (auto &&str : splitted_c){
    Serial.println(str);
}
```
Example: [examples](/../../tree/master/examples)  