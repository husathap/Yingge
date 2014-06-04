Yingge
======

An experimental game engine that exploits the functional programming capability of C++11 and macro definition ability. The engine allows people to create simple point-and-click games. This engine uses macro definition to create a new programming language! For a good example, check out file cs1.h and rm1.h and you will see that there is barely any C++. (They are actually C++ since the preprocessor will turn them into C++ before compilation!) Also check out lang folder's contents to see how the new languages are implemented.

Currently, the engine should be ready for general usage and it has been dogfooded.

Etymology
---------

The name Yingge actually comes from a Taiwanese district. It literally means "Oriole Song" in English. The name might be a bit lousy but Hefei or Dadu actually would win the contest of terrible namings.

Tips
----

The project was created in VS13 and it should work with VS13. The engine should be modified first before importing it into other IDE. It also has no makefiles as well so you should create some if you do not plan to work with IDE.
