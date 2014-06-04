#pragma once

#include "../lang/cs.h"

CUTSCENE(YOLOBear)
	$ENTITY(background)
	$ENTITY(background2)
	$ENTITY(background3)
	$ENTITY(yolobear)
	$ENTITY(regina)

	$$CONSTRUCT
		$$SIMPLE_ENTITY(background, "background", -1, GLOBAL_TEXTURE(trigger), 0, 0)
		$$SIMPLE_ENTITY(background2, "background2", -1, GLOBAL_TEXTURE(vsyolobear), 0, 0)
		$$SIMPLE_ENTITY(background3, "background3", -1, GLOBAL_TEXTURE(logic), 0, 0)
		$$SIMPLE_ENTITY(regina, "regina", 0, GLOBAL_TEXTURE(regina), 300, 250)
		$$SIMPLE_ENTITY(yolobear, "yolobear", 0, GLOBAL_TEXTURE(yolobear), 200, 250)
	x$$CONSTRUCT

	LABEL(gameOver)
		NAVIGATE(GameOver)
	xLABEL

	LABEL(last)
		TEXT("Protagonist: That was tough.")
		TEXT("YOLO Bear: NOOOO!!!!!!!!!!!! YOLO!")
		REM_ENTITY("yolobear")
		NAVIGATE(Ending)
	xLABEL

	LABEL(Q5)
		TEXT("Protagonist: No! No more!")
		TEXT("YOLO Bear: I shall send you into the Null Space!")
		DECIDE("If A is false, which statement could be false?",
			"A implies B", "A or not A", "B implies A", "A xor not A")
		THEN_SELECT
			CASE(0, gameOver)
			CASE(1, gameOver)
			CASE(2, last)
			CASE(3, gameOver)
		xTHEN_SELECT
	xLABEL

	LABEL(Q4)
		TEXT("YOLO Bear: To be a good logician, you also need to know its history!")
		DECIDE("Who demonstrated that (P implies Q) implies P?",
			   "Charles Sander Peirce", "Aristotle", "Godel", "Plutarch")
		THEN_SELECT
			CASE(0, Q5)
			CASE(1, gameOver)
			CASE(2, gameOver)
			CASE(3, gameOver)
		xTHEN_SELECT
	xLABEL

	LABEL(Q3)
		TEXT("Protagonist: I'm dying! DYING! I've never seen these things before!")
		TEXT("Crocobirdo: You can take a break in the Null Space!")
		DECIDE("Which of the statements is a proof by contradiction?",
			   "Lily is wearing a pink shirt; she must like pink.", 
			   "Assume f(x) = g(x), but f(0) = 0 while g(0) = 1.",
			   "Assume f(x) = g(x) and f(0) = g(0) = 1.", 
			   "Lily loves yachts but likes swimming too.")
		THEN_SELECT
			CASE(0, gameOver)
			CASE(1, Q4)
			CASE(2, gameOver)
			CASE(3, gameOver)
		xTHEN_SELECT
	xLABEL

	LABEL(Q2)
		TEXT("YOLO Bear: Hmm! Well, that was basic logic. It will only get harder!")
		DECIDE("Assume we are proving that n(n-1)/2 is correct by induction, what would the base case be?", 
			   "No base case", "Case 0: 0(0-1)/2 = 0", "Case 10: 10(10-1)/2 = 45", "Therefore, by induction, the proof is correct.") 
		THEN_SELECT
			CASE(0, gameOver)
			CASE(1, Q3)
			CASE(2, gameOver)
			CASE(3, gameOver)
		xTHEN_SELECT
	xLABEL

	MAIN
		ADD_ENTITY(background)
		ADD_ENTITY(regina)

		TEXT("Regina: Thanks to my mutation, I can smell bears pretty easily. This should be it.")

		ADD_ENTITY(yolobear)
		
		TEXT("???: Hehehe, kid! It's me YOLO Bear! I'm a bear that swags YOLO all day! Because you only live once!")
		TEXT("Protagonist: Whatever you want to do, do it now. Because your life's about to end!")
		TEXT("YOLO Bear: Do you want to kill me?")
		TEXT("Protagonist: Yes. That Mike Peterson guy asked us to kill you so we can go home.")
		TEXT("YOLO Bear: Because YOLO, I will try to preserve myself. It is you who are going to the Null Space!")

		REM_ENTITY("background")
		REM_ENTITY(0)

		ADD_ENTITY(background2)
		REM_ENTITY("background2")

		ADD_ENTITY(background3)
		ADD_ENTITY(yolobear)

		TEXT("YOLO Bear: YOLO!")
		DECIDE("Which of the following statement is tautology?", 
			   "A or not A", "B implies not B", "P implies Q implies C", "A or B") 
		THEN_SELECT
			CASE(0, Q2)
			CASE(1, gameOver)
			CASE(2, gameOver)
			CASE(3, gameOver)
		xTHEN_SELECT
	xMAIN

xCUTSCENE