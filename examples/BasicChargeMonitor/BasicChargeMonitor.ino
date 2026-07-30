#include <MP2722.h>

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println(F("MP2722 Charge Monitor"));

  // Initialize MP2722 on the default I2C pins
  if (PowerSystem.init(8, 9)) {
    Serial.println(F("MP2722 initialized"));
  } else {
    Serial.println(F("MP2722 init failed"));
  }
}

void loop() {
  // Read and print charge status
  MP2722::MP2722_ChargeStatus chg;
  if (PowerSystem.getChargeStatus(chg)) {
    Serial.print(F("Charge: "));
    Serial.println(chg.description);
  }

  // Read and print DPDM (USB adapter type)
  MP2722::MP2722_DPDMStatus dpdm;
  if (PowerSystem.getDPDMStatus(dpdm)) {
    Serial.print(F("USB: "));
    Serial.print(dpdm.description);
    Serial.print(F(" ("));
    Serial.print(dpdm.currentLimitA);
    Serial.println(F("A)"));
  }

  // Check battery low
  bool low;
  if (PowerSystem.isBatteryLow(low)) {
    Serial.print(F("Battery low: "));
    Serial.println(low ? F("YES") : F("NO"));
  }

  Serial.println();
  delay(5000);
}
