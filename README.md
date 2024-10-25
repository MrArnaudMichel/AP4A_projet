# AP4A Project
https://we.tl/t-OgnP9vmMU6
## Overview

This project is a C++ application that involves a `Server` class responsible for logging sensor data. The `Server` class provides functionalities to notify, log, and log data to a file.

## Files

- `Server.h`: Header file for the `Server` class.
- `Server.cpp`: Implementation file for the `Server` class.
- `log.csv`: CSV file where sensor data logs are stored.

## Classes

### Server

- **Methods:**
  - `static void notify(const Sensor & sensor)`: Notifies the server about a sensor update.
  - `static std::string getDateFormatted()`: Returns the current date and time formatted as a string.
  - `static void log(const Sensor & sensor, const std::string & message)`: Logs a message to the console.
  - `static void logOnFile(const Sensor & sensor, const std::string & message)`: Logs a message to the `log.csv` file.
  - `static bool isFileEmpty()`: Checks if the `log.csv` file is empty.

## Usage

To use the `Server` class, include the `Server.h` header file and call the static methods as needed.

```cpp
#include "Server.h"

// Example usage
Sensor sensor;
Server::notify(sensor);
```

## Dependencies

- C++ Standard Library
- `<iostream>`
- `<fstream>`
- `<ctime>`

## Build

To build the project, use the provided CMake configuration.

```sh
mkdir build
cd build
cmake ..
make
```

## License

This project is licensed under the MIT License.
