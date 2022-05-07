# SolarSystem
Solar system model based on Qt3D framework. <br />
Some features used from Qt Planet QML example. <br />
Some textures used from: <br />
http://www.solarsystemscope.com <br />

Created in 2017 <br />
<br />
Thanks to Qt Company. <br />
<br />
![alt tag](http://ipic.su/img/img7/fs/SolarSystemScreen.1562931855.jpg) <br />
<br />

<h2>Build for Windows/Linux/MacOS/Android</h2>
<h3>Build dependencies</h3>
<ul>
<li>Qt6.0</li>
<li>Compiler with C++17 support</li>
<li><a href="https://cmake.org/download/">Cmake 3.16</a> or newest</li>

On Windows:<br/>

It is necessary to run in the terminal, which sets the environment variables for building a Visual Studio project

>```sh
>git clone https://github.com/Instand/SolarSystem.git
>cd node
>git submodule update --init --recursive
>mkdir build
>cd build
>cmake -DCMAKE_BUILD_TYPE=Release -A x64 ..
>cmake --build . --target ALL_BUILD --config Release
On Linux/MacOS:<br/>
>```sh
>git clone https://github.com/Instand/SolarSystem.git
>cd node
>git submodule update --init --recursive
>mkdir build
>cd build
>cmake -DCMAKE_BUILD_TYPE=Release ..
>make -j4

<h3>Binaries</h3>

Release binaries available at https://github.com/Instand/SolarSystem/releases <br />
