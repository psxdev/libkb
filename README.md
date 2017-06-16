# libkb
libkb a little library for VITA for your bluetooth keyboard
DEBUGNET FOR VITA
=================
 
 What does this do?
===================
 
  libkb is a vita small library to use bluetooth keyboard with your homebrew code. It is not finished but people can see how to use the Hid api for keyboard
  
  How do I use it?
==================

 1) Compile and install library and include file

  
  ```
  cd libkb
  make
  make install
  ```
 
  
 2) Compile sample
  
  
  ```
  cd sample
  edit main.c and change your server ip and port to listen udp messages from PlayStation Vita
  make
  ```

 3) Open a terminal and execute (change port if you don't use 18194). It can be in osx, linux or if you have socat like tool on windows
   
  ```
  socat udp-recv:18194 stdout 
  ```
  
 4) Install kbsample.vpk in your vita an run it before you must pair your bluetooth keyboard i am using de playstation model CECH-ZKB1ES
 
 You will see in socat terminal window output from your PlayStation Vita:
 
 ```
 debugnet initialized
 Copyright (C) 2010,2015 Antonio Jose Ramos Marquez aka bigboss @psxdev
 This Program is subject to the terms of the Mozilla Public
 License, v. 2.0. If a copy of the MPL was not distributed with this
 file, You can obtain one at http://mozilla.org/MPL/2.0/.
 ready to have a lot of fun...
 ```
 and in the screen of your TV some message, you can use your keyboard now
 
 5) ready to have a lot of fun :P 
 
 6) TODO
 
 Let different keymapper and let custom keymapper for emulators to bypass and manage from them the right codes
 

  Change log
===========================
 - 15/06/2017 Initial release
 

  Credits
===========================
  
  Special thanks goes to:
  
  - team molecule for bring henkaku to make life easier for homebrew developer 
  - All people working in vitasdk
  
