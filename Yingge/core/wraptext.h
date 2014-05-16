#pragma once

#include <SFML/Graphics.hpp>

/* This file is used to contain the function wrapText.
 *
 * CREDIT TO: LiquidHelium
 * CODE TAKEN FROM: https://gist.github.com/LiquidHelium/7858095 */

sf::String wrapText(sf::String string, unsigned width, const sf::Font &font, unsigned charicterSize, bool bold = false){
	unsigned currentOffset = 0;
	bool firstWord = true;
	std::size_t wordBegining = 0;

	for (std::size_t pos(0); pos < string.getSize(); ++pos) {
		auto currentChar = string[pos];
		if (currentChar == '\n'){
			currentOffset = 0;
			firstWord = true;
			continue;
		}
		else if (currentChar == ' ') {
			wordBegining = pos;
			firstWord = false;
		}

		auto glyph = font.getGlyph(currentChar, charicterSize, bold);
		currentOffset += glyph.advance;

		if (!firstWord && currentOffset > width) {
			pos = wordBegining;
			string[pos] = '\n';
			firstWord = true;
			currentOffset = 0;
		}
	}

	return string;
}