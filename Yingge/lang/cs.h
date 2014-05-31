#pragma once

/*
 * Here is Oriole specification for language to create a cutscene.
 */

/* Here is the import for the cutscene header. So if you import the language,
 * you won't need need to include cutscene and sceneNavigation.
 */
#include "../core/cutscene.h"
#include "../core/sceneNavigation.h"
#include "common.h"

// Here is the content of the language itself for defining a cutscene.
#define CUTSCENE(name) class name : public yingge::Cutscene { public: name() { construct(); main(); } private:
#define EVENT(name) class name : public yingge::Cutscene { public: name() { construct(); main(); } private:

// Here are the keywords for creating the functions used in the cutscene.
#define MAIN void main() {
#define xMAIN }
#define LABEL(name)	void name() {
#define xLABEL }

// Here are the keywords used for making a decision.
#define DECIDE(question, ...) decide(question, {__VA_ARGS__});

// Here are the multiplexing keywords.
#define SELECT(var) then([this]() { switch(var) {
#define THEN_SELECT then([this]() { switch(decision) {
#define CASE(eq, b) case eq: b(); break;
#define DEFAULT(b) default: b(); break;
#define xSELECT }});
#define xTHEN_SELECT }});
#define THEN_SET_NUMBER(varname) yingge::session->numbers.insert(std::pair<std::string, double> (#varname, (double)decision));

#define IF(cond, b) then([this]() { if(cond) b();
#define ELSEIF(cond, b) else if (cond) b();
#define ELSE(b) else b();
#define xIF });

// Here are the keywords for writing texts.
#define TEXT(t) text(t);

// Here are the keywords for playing music.
#define PLAY_MUSIC(path) playMusic(path);
#define PAUSE_MUSIC	pauseMusic();
#define RESUME_MUSIC resumeMusic();
#define STOP_MUSIC stopMusic();

#define NAVIGATE_TITLE navigateFirst();
#define NAVIGATE(s) navigate(yingge::getScene(#s));

// Here are keywords that are only for enhancing readability.
#define iANSWERS
#define iCPP
#define iKEY
#define iNAME
#define iQUESTION
#define iSOURCE
#define iTHEN
#define iTEXTURE
#define iX
#define iY
#define iZORDER

// Here is the ending keyword.
#define END	}
#define xCUTSCENE };
#define xEVENT };