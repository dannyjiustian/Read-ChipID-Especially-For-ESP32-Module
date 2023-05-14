#include <Arduino.h>

String get_id(){
  String id;
  uint64_t chipid;
  char ssid[13];
  chipid = ESP.getEfuseMac();//The chip ID is essentially its MAC address(length: 6 bytes).
  uint16_t chip = (uint16_t)(chipid >> 32);
  snprintf(ssid, 13, "%04X%08X", chip, (uint32_t)chipid);
  for ( int i=0; i < 12; i++){
    id += String(ssid[i]);
  }
  return String(id);
}

void setup() {
  Serial.begin(115200);
}

void loop() {
  // Serial.println(ESP.getChipCores());
  // Serial.println(ESP.getChipModel());
  // Serial.println(ESP.getChipRevision());
  // Serial.println(ESP.getCpuFreqMHz());
  // Serial.println(ESP.getCycleCount());
  // Serial.println(ESP.getEfuseMac());
  // Serial.println(ESP.getFlashChipMode());
  // Serial.println(ESP.getFlashChipSize());
  // Serial.println(ESP.getFlashChipSpeed());
  // Serial.println(ESP.getFreeHeap());
  // Serial.println(ESP.getFreePsram());
  // Serial.println(ESP.getFreeSketchSpace());
  // Serial.println(ESP.getHeapSize());
  // Serial.println(ESP.getMaxAllocHeap());
  // Serial.println(ESP.getMaxAllocPsram());
  // Serial.println(ESP.getMinFreeHeap());
  // Serial.println(ESP.getPsramSize());
  // Serial.println(ESP.getSdkVersion());
  // Serial.println(ESP.getSketchMD5());
  // Serial.println(ESP.getSketchSize());
  Serial.println(get_id());
  delay(15000);
}