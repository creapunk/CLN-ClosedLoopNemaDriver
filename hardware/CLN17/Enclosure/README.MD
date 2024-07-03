# Enclosure Design

> The enclosure design is compatible with all CLN17 drivers of versions V1.5, V2.0, [V2.5 future development].

### Stack

The enclosure consists of two halves: the **base plate**, which faces the motor, and the **cover**.

The **base plate** is responsible for positioning the board relative to the motor shaft and dissipating heat from the driver chip. The **cover** positions and secures the board within the **base plate** and protects the board from dust and mechanical damage.

A silicone thermal pad should be placed between the board and the **base plate**, specifically under the driver chip area.

The **cover** and **base plate** clamp the board between them using two DIN7991 M3x8mm screws located in two diametrically opposed threaded holes.

### Thermal Design

The most efficient heat dissipation from the driver chip is achieved through the copper and thermal vias in the board, rather than direct contact with the enclosure (due to R<sub>θJB</sub> Junction-to-board thermal resistance **<** R<sub>θJC(top)</sub> Junction-to-case thermal resistance).

Therefore, heat is conducted from the driver through PCB to the aluminum base plate via a silicone thermal pad.

The heat is then effectively distributed throughout the base plate due to its substantial thickness (2.5mm), reducing the temperature right under the driver chip.

Owing to the large thermal contact area between the base plate and the motor, the heat is evenly distributed between the motor and the base plate.

As a result, the driver can operate in an enhanced mode for an extended period without critical overheating, thanks to the motor's high thermal capacity.

Additionally, the built-in temperature sensor in the microcontroller allows for quick temperature readings (settling time <10s) of the aluminum plate (and consequently the motor), which further allows to optimize heat dissipation through algorithms.

### Enclosure Manufacturing

To manufacture the enclosure, two parts are required:

One `BASE-ALUMINUM.STEP` and one of [`COVER-POLYMER.STEP` or `COVER-POLYMER-TRANSPARENT.STEP` or `COVER-ALUMINUM.STEP`]. The choice is up to you.

Polymer parts can be made using any 3D printing process, though SLA is recommended.

For aluminum parts, the following requirements must be met to achieve best result:

- **Material:** Aluminum Alloys 6061, 5083, or 7075.
- **Minimum milling volume:** 45x45mm, with a thickness up to 10mm.
- **Milling Technology:** 3-axis milling on both sides.
- **Minimum tolerances and end mill diameter:** XY tolerance ±0.1mm, Z tolerance ±0.05mm, end mill diameter ≤ 2.0mm.
- **Postprocessing:** **Threading** of 2xM3 threads to a depth of 3mm, **chamfering**.
- **Surface finish:** Abrasive blasting, **anodizing** (preferably black).
