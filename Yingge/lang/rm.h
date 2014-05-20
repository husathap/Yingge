#pragma once

#include "../core/sceneNavigation.h"
#include "../core/room.h"
#include "common.h"

#define ROOM(name) class name : public yingge::Room { public: name() { construct(); menu(); yingge::session->sceneName = #name; } private:

#define $TEXT_BUTTON(name) yingge::textButton name;
#define $SPRITE_BUTTON(name) yingge::spriteButton name;

#define $$TEXT_BUTTON(button, text, x, y, size) button.name = #button; button.setString(text); button.setPosition(x, y); button.setFont(*yingge::defaultFont); button.setCharacterSize(size);
#define $$SPRITE_BUTTON(button, texture, x, y) button.name = #button; button.setTexture(texture); button.setPosition(x, y);

#define FUNC(name) void name () {
#define xFUNC }

#define BIND_W_EVENT(button, ctOrEvent) bindButton(&button, [this]() { yingge::sceneManager->overlayScene(new ctOrEvent()); });
#define BIND_W_FUNC(button, f) bindButton(&button, [this]() { f(); });

// This define the keyword for readability
#define iCPP
#define iNAME
#define iTEXT
#define iX
#define iY
#define iSIZE
#define iFUNC

#define xROOM };