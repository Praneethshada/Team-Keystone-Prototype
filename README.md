# Team Keystone - Design Thinking Project
## Book Spine Sensor
Use Link: `https://praneethshada.github.io/Book-Spine-Sensor/`
### Smart Library Shelf Prototype
#### Spine Width Detection System
1. Project Overview
This prototype simulates an IoT-enabled "Smart Shelf" designed for libraries to automatically detect misplaced books. This concept uses a mechanical spine width measurement system.
#### The Core Idea
By measuring the precise width of the book inserted into a specific slot and comparing it against a "Calibrated" (correct) value, the system can determine if the wrong book has been returned to that location.
2. How It Works (Logic)
- The simulation uses a strict "Calibration" logic rather than just checking if a book is present.
#### Calibration (The "Set" Phase):
- When the library staff arranges the shelf correctly and presses "SET / CALIBRATE", the system records the exact spine width of the book currently in each slot.
#### Detection (The "Check" Phase):
- The system continuously monitors the width of any book placed in a slot.
- Match: If the detected width matches the calibrated width, the system assumes the correct book is present.
- Mismatch: If a book is inserted with a significantly different width (e.g., swapping a thin book for a thick one), the system flags an error.
- Empty Slot: Removing a book does not trigger an error (Status remains Green). This prevents the alarm from going off while library users are simply reading a book.
### Limitations & Future Scope
- This may not be a Most efficient solution. Because some books share identical spine widths.
- Older, puffed-out books may exceed tolerance levels and cause false mismatch errors.
- These can be adrdressed using Multi-Modal Sensing. Adding weight or color sensors to distinguish between different books of the same size.
