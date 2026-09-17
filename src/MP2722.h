#pragma once

#include <Arduino.h>
#include <Wire.h>

class MP2722 {
public:
  // Datasheet I2C address. Override through the constructor or init() when the
  // board has a different address.
  static constexpr uint8_t DEFAULT_ADDRESS = 0x3F;

  // Pass as muxPin when the board has no USB data-line mux; the mux helpers
  // then become no-ops.
  static constexpr int8_t NO_MUX_PIN = -1;

  explicit MP2722(TwoWire& wirePort = Wire,
                  uint8_t address = DEFAULT_ADDRESS,
                  int8_t muxPin = NO_MUX_PIN);

  bool begin();
  bool isConnected();

  // Structs
  struct MP2722_DPDMStatus {
    uint8_t code;
    float currentLimitA;
    const char* description;
  };

  struct MP2722_ChargeStatus {
    uint8_t code;
    const char* description;
  };

  struct DPDMResult {
      uint8_t code;
      const char* description;
      float currentLimitA;
  };

  // Register-level access
  bool writeReg(uint8_t reg, uint8_t value);
  bool readReg(uint8_t reg, uint8_t &value);

  // Helper functions
  bool init(uint8_t sda, uint8_t scl,
            uint8_t address = DEFAULT_ADDRESS,
            int8_t muxPin = NO_MUX_PIN);
  void setAddress(uint8_t address);
  void setMuxPin(int8_t muxPin);
  void printDiagnostics();
  bool setCCMode(uint8_t cc_cfg);
  bool setBoostCurrentLimit(float amps);
  bool getDPDMStatus(MP2722_DPDMStatus &out);
  bool getChargeStatus(MP2722_ChargeStatus &out);
  bool isBatteryLow(bool &low);
  bool setBoost(bool enable);
  bool getBoostState(bool &enabled);
  bool getDPDMStatus(DPDMResult &out);
  bool getOTGNeed(bool &boostNeeded);
  bool setFastChargeCurrent(uint16_t mA);

  void setUSBControlESP();
  void setUSBControlBMS();

private:
  TwoWire* _wire;
};

// Initialization of MP2722 Class
extern MP2722 PowerSystem;