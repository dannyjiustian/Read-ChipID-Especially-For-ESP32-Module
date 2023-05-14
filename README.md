# Read Chip ID ESP32

This code has a function to read a chip ID from the MCU module, especially the ESP32 module. This code runs base C++ and I'm using the IO Platforms extension from Visual Studio Code to run this code. You can use this code to get a Chip ID. The Chip ID base from MAC Address ESP32 and converted to a string. You can see the code in folder src!.


## The Core Code

```cpp
String get_id(){
  String id;
  uint64_t chipid;
  char ssid[13];
  chipid = ESP.getEfuseMac();
  uint16_t chip = (uint16_t)(chipid >> 32);
  snprintf(ssid, 13, "%04X%08X", chip, (uint32_t)chipid);
  for ( int i = 0; i < 12; i++){
    id += String(ssid[i]);
  }
  return String(id);
}
```


## Authors Files

- [dannyjiustian - github.com](https://www.github.com/dannyjiustian)
