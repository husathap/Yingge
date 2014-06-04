#pragma once

#include "../lang/cs.h"

CUTSCENE(Crocobirdo)
	$ENTITY(background)
	$ENTITY(background2)
	$ENTITY(background3)
	$ENTITY(crocobirdo)

	$$CONSTRUCT
		$$SIMPLE_ENTITY(background, "background", -1, GLOBAL_TEXTURE(trigger), 0, 0)
		$$SIMPLE_ENTITY(background2, "background2", -1, GLOBAL_TEXTURE(vscrocobirdo), 0, 0)
		$$SIMPLE_ENTITY(background3, "background3", -1, GLOBAL_TEXTURE(statistics), 0, 0)
		$$SIMPLE_ENTITY(crocobirdo, "crocobirdo", 0, GLOBAL_TEXTURE(crocobirdo), 400, 250)
	x$$CONSTRUCT

	LABEL(gameOver)
		NAVIGATE(GameOver)
	xLABEL

	LABEL(last)
		TEXT("Crocobirdo: NOOOOO!!!!!!!!!!!!")
		REM_ENTITY("crocobirdo")
		TEXT("Protagonist: That was tough.")
		TEXT("Regina: I hope that the next guy is YOLO Bear. I want to go home!")
		NAVIGATE(RoomBeforeYOLOBear)
	xLABEL

	LABEL(Q5)
		TEXT("Crocobirdo: I shall send you into the Null Space!")
		DECIDE("In which statistical technique, Pearson r-value is used?",
			"Hypothesis testing", "Regression", "Finding the Second Raw Moment", "Bagging")
		THEN_SELECT
			CASE(0, gameOver)
			CASE(1, last)
			CASE(2, gameOver)
			CASE(3, gameOver)
		xTHEN_SELECT
	xLABEL

	LABEL(Q4)
		TEXT("Protagonist: *panting*")
		TEXT("Regina: You can do it!")
		DECIDE("Which of the tests used to see whether two variances are the same?",
			   "Normal distribution", "t-test", "F-test", "Chi-square test")
		THEN_SELECT
			CASE(0, gameOver)
			CASE(1, gameOver)
			CASE(2, Q5)
			CASE(3, gameOver)
		xTHEN_SELECT
	xLABEL

	LABEL(Q3)
		TEXT("Protagonist: I'm surviving, but barely. I'm just a high school math student after all.")
		TEXT("Crocobirdo: Didn't ya say that ya are the strongest?")
		DECIDE("Assume e is an event with 1000 outcomes and P(e = 1) = 0.4. If e will occur for 1000 times, how many actual instances of the e = 1 will there be for certain?",
			"200", "250", "300", "Unknown")
		THEN_SELECT
			CASE(0, gameOver)
			CASE(1, gameOver)
			CASE(2, gameOver)
			CASE(3, Q4)
		xTHEN_SELECT
	xLABEL

	LABEL(Q2)
		TEXT("Crocobirdo: Not too shabby kid! How about this!")
		TEXT("Protagonist: I am the strongest!")
		DECIDE("Adam has a model that can predict several cases extremely accurately; however, it fails miserably in general cases. What is his model suffering from?", 
			   "Underfitting", "Prefitting", "Amsterdam's Dilemma", "Overfitting") 
		THEN_SELECT
			CASE(0, gameOver)
			CASE(1, gameOver)
			CASE(2, gameOver)
			CASE(3, Q3)
		xTHEN_SELECT
	xLABEL

	MAIN
		ADD_ENTITY(background)
		ADD_ENTITY(crocobirdo)
		TEXT("Protagonist: Bugger off! I have no business with you. I'm going to beat YOLO Bear!")
		TEXT("Crocobirdo: Hey! YOLO Bear is my homie! You have to get past my dead body first!")
		REM_ENTITY("crocobirdo")
		REM_ENTITY("background")
		ADD_ENTITY(background2)
		REM_ENTITY("background2")
		ADD_ENTITY(background3)
		ADD_ENTITY(crocobirdo)

		TEXT("Crocobirdo: Eat uni level stats, suckers!")

		DECIDE("If the sample size is small, which test should be used?", 
			   "Wilcoxon signed-rank test", "t-test", "Normal distribution", "Bernoulli test") 
		THEN_SELECT
			CASE(0, Q2)
			CASE(1, gameOver)
			CASE(2, gameOver)
			CASE(3, gameOver)
		xTHEN_SELECT
	xMAIN

xCUTSCENE