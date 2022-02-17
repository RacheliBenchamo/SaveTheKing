#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include "Macros.h"


class FileManager
{
public:
	~FileManager() {};
	static FileManager& p2FileManager();

	const sf::Texture* getIconTexture(icons );
	sf::Texture* getPlayAndStopIcon(bool );
    sf::SoundBuffer* getSound(sounds);
	sf::Texture* getMusicIcon(bool);
	sf::Texture* getRestartIcon();
	const sf::Texture* getBackGround(backgroundsType);
	sf::Font* getFont();

private:
	FileManager();
	FileManager(const FileManager&) = default;
	FileManager& operator=(const FileManager&) = default;

	void loadFromFileIcons();
	void loadAudio();
	void loadMusicIcon();
	void loadStopAndPlayIcon();
	void loadResetIcon();
	void loadBackgrounds();

	sf::Texture m_icons[NUM_OF_ICONS];
	sf::Texture m_backgrounds[NUM_OF_BACKGROUNDS];
	sf::Texture m_musicTexture[2];
	sf::Texture m_playStopTexture[2];
	sf::Texture m_restartIcon;
	sf::SoundBuffer m_audio[NUM_OF_SOUNDS];
	sf::Font m_font;
};


