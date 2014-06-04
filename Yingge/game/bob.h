#pragma once

#include "../lang/cs.h"

CUTSCENE(Bob)
	$ENTITY(background)
	$ENTITY(background2)
	$ENTITY(background3)
	$ENTITY(regina)
	$ENTITY(bob)

	$$CONSTRUCT
		$$SIMPLE_ENTITY(background, "background", -1, GLOBAL_TEXTURE(trigger), 0, 0)
		$$SIMPLE_ENTITY(background2, "background2", -1, GLOBAL_TEXTURE(vsbob), 0, 0)
		$$SIMPLE_ENTITY(background3, "background3", -1, GLOBAL_TEXTURE(algebra), 0, 0)
		$$SIMPLE_ENTITY(regina, "regina", 0, GLOBAL_TEXTURE(regina), 200, 250)
		$$SIMPLE_ENTITY(bob, "bob", 0, GLOBAL_TEXTURE(bob), 400, 300)
	x$$CONSTRUCT
	
	LABEL(gameOver)
		NAVIGATE(GameOver)
	xLABEL

	LABEL(last)
		TEXT("Bob the Fish: It seems that I will have to go to the Null Space alone!")

		TEXT("Protagonist: That was tough. I almost got beaten by a fish!")
		TEXT("Regina: Hehe!")
		TEXT("Protagonist: What are you laughing at?")
		TEXT("Regina: Nothing.")
		NAVIGATE(RoomBeforeCrocobirdo)
	xLABEL

	LABEL(Q5)
		TEXT("Protagonist: Wow! It's still a high school question though!")
		TEXT("Bob the Fish: One last question! Hahahaha!! See you on the other side.")
		DECIDE("What is trace([1 1000 1 303 4404; 0 -1 pi e 10000; 54 4.33 1 0 6754; -1 -1 -1 -1 -1; 0 0 0 0 -1]) ?",
			   "6754 + pi", "-2", "0", "-1")
		THEN_SELECT
			CASE(0, gameOver)
			CASE(1, gameOver)
			CASE(2, gameOver)
			CASE(3, last)
		xTHEN_SELECT
	xLABEL

	LABEL(Q4)
		TEXT("Bob the Fish: Good thing you still remember your midterm!")
		TEXT("Protagonist: Well, I'm a math prodigy.")
		TEXT("Bob the Fish: EAT THIS!")
		DECIDE("Which of the lines doesn't intersect the plane whose minimum basis is {(0, 0, 1), (1, 0, 0)}?",
			   "u(1, 2, 4)", "(1, 1, 1) + u(0, 0, 1)", "(1000, 1000, 1000) + u(0, 1, 0)", "u(1, 1, 1)")
		THEN_SELECT
			CASE(0, gameOver)
			CASE(1, Q5)
			CASE(2, gameOver)
			CASE(3, gameOver)
		xTHEN_SELECT
	xLABEL

	LABEL(Q3)
		TEXT("Protagonist: I'm a prodigy... This is unfair!")
		TEXT("Bob the Fish: Sorry, but this is not one of those fantastical math comic thingies. This is real math!")
		DECIDE("Which of these functions have no roots at x = 0?", "x ^ 1.5 + cos(x) + 10",
			   "60 cos(x)", "x ^ 500 - 700", "All of above")
		THEN_SELECT
			CASE(0, Q4)
			CASE(1, gameOver)
			CASE(2, gameOver)
			CASE(3, gameOver)
		xTHEN_SELECT
	xLABEL

	LABEL(Q2)
		TEXT("Protagonist: Very easy! You and your fish brain!")
		TEXT("Bob the Fish: That was just a starter! Now face the true terror!")
		DECIDE("Which of these is not an identity matrix?", "[1]", "[1 0 0; 0 1 0; 0 0 1]",
			   "[1; 1]", "[1 0; 0 1]") THEN_SELECT
			CASE(0, gameOver)
			CASE(1, gameOver)
			CASE(2, Q3)
			CASE(3, gameOver)
		xTHEN_SELECT
	xLABEL

	MAIN
		ADD_ENTITY(background)
		ADD_ENTITY(bob)
		TEXT("???: I must go into the Null Space to save my girlfriend!")
		ADD_ENTITY(regina)
		TEXT("Regina: Look at that fishy. He's wearing a flat cap. How cute! May I ask your name?")
		TEXT("???: My name is Bob the Fish.")
		TEXT("Protagonist: (thinking) That's Bob the Fish, the one we have to watch out for. I must threaten it so he will know not to mess with us!")
		TEXT("Protagonist: Your flat cap is stupid!")
		TEXT("Bob the Fish: What did you say?")
		TEXT("Protagonist: Your flat cap is stupid!")
		TEXT("Bob the Fish: All right! You're going down. I hate humans, but I can tolerate them. But I won't tolerate flat cap haters! I'll take you down the Null Space.")
		TEXT("Protagonist: But stupid fish, if you lose the game, you will go to the Null Space.")
		TEXT("Bob the Fish: I'm going there anywhere, losing or not. A certain man named Mike Peterson invited me!")
		TEXT("Protagonist: You're going there. ALONE!")
		TEXT("Bob the Fish: Come at me, bro!")

		REM_ENTITY(0)
		REM_ENTITY("background")
		ADD_ENTITY(background2)
		REM_ENTITY("background2")
		ADD_ENTITY(background3)
		ADD_ENTITY(bob)

		TEXT("Bob the Fish: I may be a mere fish. But I know uni level algebra!")
		TEXT("Protagonist: But I'm a math prodigy!")
		TEXT("Bob the Fish: We will see!")

		DECIDE("1 + 1 = ?", "1", "2", "3", "4") THEN_SELECT
			CASE(0, gameOver)
			CASE(1, Q2)
			CASE(2, gameOver)
			CASE(3, gameOver)
		xTHEN_SELECT
	xMAIN

xCUTSCENE