Yingge
======

An experimental game engine that exploits the functional programming capability of C++11 and macro definition ability. The engine allows people to create simple point-and-click games. This engine uses macro definition to create a new programming language! For a good example, check out file cs1.h and rm1.h and you will see that there is barely any C++. (They are actually C++ since the preprocessor will turn them into C++ before compilation!) Also check out lang folder's contents to see how the new languages are implemented.

Currently, the engine is in the dogfooding stage. I will be using the engine to create a simple demo game. I will not be putting up much documentation at this point since I will use the dogfooding as a chance to do so.

Etymology
---------

The name Yingge actually comes from a Taiwanese district. It literally means "Oriole Song" in English. The name might be a bit lousy but Hefei or Dadu actually would win the contest of terrible namings.

Tips
----

The tip here is that when you create a scene and you want to be able to save in or load into the room, you must also "register" it. To do so check out the file scenemanifest.cpp.

Credits and Stuffs
------------------

I would like to say that I also use other people's stuffs at this point such as the picture of the mayor of Calgary. I will give proper crediting once the dogfooding is done. Some of the stuffs will also be removed as well. If you intend to use my engine for whatever reason you have, make sure to properly source the stuffs.
