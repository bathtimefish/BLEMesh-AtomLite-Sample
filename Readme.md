# BLE Mesh Atomlite Sample

This is an example for BLE Mesh that works on M5 AtomLite. This code is based on the [basic sample](https://gitlab.com/painlessMesh/painlessMesh/-/tree/develop/examples/basic) of painlessMesh.

To compile this code, the following libraries are required. You have to install bellow in Arduino IDE before compile the code.

- [ArduinoJson](https://github.com/bblanchon/ArduinoJson)
- [TaskScheduler](https://github.com/arkhipenko/TaskScheduler)
- [AsyncTCP](https://github.com/me-no-dev/AsyncTCP)
- [painlessMesh](https://gitlab.com/painlessMesh/painlessMesh)

# NOTE

This code contains a customized [M5Atom](https://github.com/m5stack/M5Atom). This is because some of the classes in M5Atom and TaskScheduler were duplicated, which caused a compile error. This code contains an updated M5Atom.h, etc. to work around that.