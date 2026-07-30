# MP2722_Arduino

Arduino library for the **MP2722** battery charger IC from MPS (Monolithic Power Systems).

## Usage

```cpp
#include <MP2722.h>

void setup() {
  Wire.begin(8, 9); // SDA, SCL
  PowerSystem.init(8, 9);
}

void loop() {
  MP2722::MP2722_ChargeStatus chg;
  if (PowerSystem.getChargeStatus(chg)) {
    Serial.println(chg.description);
  }
  delay(5000);
}
```

## API

| Method                       | Description                                  |
|------------------------------|----------------------------------------------|
| `init(sda, scl)`             | Initialize I2C, configure charger            |
| `setFastChargeCurrent(mA)`   | Set fast charge current (up to 5040mA)       |
| `setBoost(bool)`             | Enable/disable boost mode                    |
| `setBoostCurrentLimit(amps)` | Set boost current limit (0.5/1.5/2.1/3.0A)   |
| `setCCMode(mode)`            | Set CC pin mode                              |
| `getChargeStatus(status)`    | Read charge state                            |
| `getDPDMStatus(status)`      | Read USB DPDM detection result               |
| `isBatteryLow(bool&)`        | Check battery low flag                       |
| `printDiagnostics()`         | Print full charge/boost/DPDM state to Serial |

## License

MIT
