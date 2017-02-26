# Logitech G27 and other steering wheels data-logger 
Data-logger for Logitech G27 and other compatible steering wheels or joystick, part of a driver logging system.

C++ program that enables you to log joystick data whilst the device is being used in a game or other application.

## Dependencies
Cmake enables to be used in any operating system with [SMFL](http://www.sfml-dev.org/download/sfml/2.4.2/).
If using windows, please edit ```CMakeLists.txt```line 33, to point towards your installed SFML. 
If using windows and want to do everything using cmd, enable your build tools before running cmake for your OS and architecture, e.g.:

```
mkdir build
cd build
cmake -G "Visual Studio 14 Win 64" ..
msbuild lg27uob.sln /property:Configuration=Release
```

## License

Please feel free to share and modify it as you please, but remember to acknowledge our hard work :). Happy coding!

Copyright 2017 Erwin Lopez

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
