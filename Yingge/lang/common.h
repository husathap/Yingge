#pragma once

#include "../global.h"

/* This file contains fragments that are common to all languages. */

// Here are the keywords used for declaration and constructions.
#define $TEXTURE(name) sf::Texture name;
#define $ENTITY(name) yingge::Entity name;

#define $$CONSTRUCT void construct() {
#define x$$CONSTRUCT }
#define $$NO_CONSTRUCT void construct() {}

#define $$TEXTURE(name, filename) name.loadFromFile(filename);
#define $$GLOBAL_TEXTURE(name, filename) yingge::textures->insert(std::pair<std::string, sf::Texture *> (#name, new sf::Texture())); yingge::textures->at(#name)->loadFromFile(filename);
#define GLOBAL_TEXTURE(name) yingge::textures[#name]

#define $$NUMBER(name, init) yingge::session->numbers.insert(std::pair<std::string, float>(#name, init));
#define NUMBER(name) yingge::session->numbers.at(#name);
#define SET_NUMBER(name, val) yingge::session->numbers.at(#name) = val;

#define $$BOOL(name, init) yingge::session->booleans.insert(std::pair<std::string, bool>(#name, init));
#define BOOL(name) yingge::session->numbers.at(#name);
#define SET_BOOL(name, val) yingge::session->booleans.at(#name) = val;

#define $$STRING(name, init) yingge::session->strings.insert(std::pair<std::string, std::string>(#name, init));
#define STRING(name) yingge::session->strings.at(#name);
#define SET_STRING(name, val) yingge::session->strings.at(#name) = val;

#define ADD_ENTITY(name) addEntity(&name);
#define REM_ENTITY(cond) removeEntity(cond);

#define $$SIMPLE_ENTITY(entity, k, zorder, texture, x, y) entity.key = k; entity.ZOrder = zorder; entity.setTexture(texture); entity.setPosition(x, y);
#define $$BACKGROUND_ENTITY(entity, k, texture) entity.key = "background"; entity.ZOrder = -1; entity.setTexture(texture); entity.setPosition(0, 0);