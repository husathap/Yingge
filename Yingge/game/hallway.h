#pragma once

#include "../lang/cs.h"
#include "../lang/rm.h"

CUTSCENE(Classroom)
	$$NO_CONSTRUCT

	MAIN
		TEXT("Protagonist: I just came out from the room, why would I need to go back again? The school's over anyway!")
	xMAIN
xCUTSCENE

CUTSCENE(GoodEnding)
	$$NO_CONSTRUCT

	MAIN
		TEXT("Protagonist: So I decide to go home. It was an uneventful evening. The school exploded on the next day with a person disappearing. But that's none of my problems!")
		TEXT("GOOD ENDING!")
		NAVIGATE_TITLE
	xMAIN
xCUTSCENE

CUTSCENE(Lab)
	$ENTITY(regina)
	$ENTITY(divisor)
	$ENTITY(background)
	$ENTITY(background2)

	$$CONSTRUCT
		$$SIMPLE_ENTITY(background, "background", -1, GLOBAL_TEXTURE(science), 0, 0)
		$$SIMPLE_ENTITY(regina, "regina", 0, GLOBAL_TEXTURE(regina), 150, 200)
		$$SIMPLE_ENTITY(divisor, "divisor", 0, GLOBAL_TEXTURE(divisor), 400, 180)
		$$SIMPLE_ENTITY(background2, "background", -1, GLOBAL_TEXTURE(trigger), 0, 0)
	x$$CONSTRUCT

	MAIN
		ADD_ENTITY(background)
		TEXT("Protagonist: Someone is here! Who are you?")
		ADD_ENTITY(regina)
		TEXT("???: It's me Regina!")
		TEXT("Regina Raffleson is one of my class mate. Not much is known about her except that her pink hair is caused by a genetic mutation.")
		ADD_ENTITY(divisor)
		TEXT("Regina: I have come across this machine labeled 'Divisor'. The label also says that 'It allows a number to be divided with 0 onto the fabric of space and time.'")
		TEXT("Protagonist: Wait, what? You shouldn't mess around with the science club's machine.")
		TEXT("Regina: But I want to find out what it actually does. I'm going to push that red button. Let's go!")
		TEXT("Protagonist: I don't think that's a good ide...........")
		
		REM_ENTITY(-1)
		REM_ENTITY(0)
		ADD_ENTITY(background2)
		ADD_ENTITY(regina)
		TEXT("Regina: Where are we?")
		TEXT("???: Welcome to this strange space that is not ours. My name is Mike Peterson, the ruler of the Null Space.")
		TEXT("Protagonist: Mike Peterson?")
		TEXT("Mike Peterson: I don't have much time but we can give you some pointers. This space is the Quiz Space!")
		TEXT("Regina: What does this mean?")
		TEXT("Mike Peterson: Anyone can quiz you on any math topic and if you fail, you will be sent into the Null Space where I rule!")
		TEXT("Protagonist: What would you do to us if we get sent there?")
		TEXT("Mike Peterson: Turn you into my minions! Well, I can help you get back home if you can beat YOLO Bear. We hate that guy.")
		TEXT("Regina: YOLO Bear...")
		TEXT("Mike Peterson: YES! ALSO WATCH OUT FOR BOB THE FISH! He hates humans. He's badass enough to go across the spaces. You're not badass like him, so you will have to beat YOLO Bear first to get our helps!")
		TEXT("Regina: It's a deal then. You need our help and we need your help. We will beat YOLO Bear for you!")

		NAVIGATE(RoomBeforeBob)
	xMAIN
xCUTSCENE

ROOM(Hallway)
	$ENTITY(hallway)
	
	$TEXT_BUTTON(goHome)
	$TEXT_BUTTON(goLab)
	$TEXT_BUTTON(goClass)

	$$CONSTRUCT
		$$SIMPLE_ENTITY(hallway, "background", -1, GLOBAL_TEXTURE(hallway), 0, 0)
		ADD_ENTITY(hallway)

		$$TEXT_BUTTON(goHome, "Go Home", 330, 400, 30)
		$$TEXT_BUTTON(goLab, "Go to Lab", 60, 400, 30)
		$$TEXT_BUTTON(goClass, "Go to Class", 635, 400, 30)

		BIND_W_EVENT_UNREG(goHome, GoodEnding)
		BIND_W_EVENT_UNREG(goClass, Classroom)
		BIND_W_EVENT_UNREG(goLab, Lab)
	x$$CONSTRUCT
xROOM