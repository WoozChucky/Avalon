#pragma once

#include "Audio/AudioPlayer.h"
#include <mutex>
#include <map>

#include <SFML/Audio.hpp>

namespace av
{
	class DesktopAudioPlayer : public AudioPlayer
	{
	public:
		DesktopAudioPlayer();
		~DesktopAudioPlayer();

		void PlaySFX(audio::SFX l_sfx, bool l_repeat) override;
		void PlayMusic(audio::MUSIC l_music, bool l_repeat) override;

		void SetSFXVolume(float l_volume) override;
		void SetMusicVolume(float l_volume) override;

		void PauseSFX() override;
		void PauseMusic() override;

		void StopSFX() override;
		void StopMusic() override;

	private:
		static sf::String as_string(audio::MUSIC l_value);
		static sf::String as_string(audio::SFX l_value);

		void PlayAsync(audio::SFX l_sfx, bool l_repeat = false);
		void ClearFinishedSFX();

		sf::Music m_music_;

		std::vector<sf::Sound> m_sound_;
		std::map<audio::SFX, sf::SoundBuffer> m_sound_buffer_;

		//Threading
		std::thread m_cleanup_thread_;
		std::thread m_sfx_thread_;
		std::mutex m_mutex_buffer_;

		float m_sfx_volume_ = 100;
		float m_music_volume_ = 100;
	};
}


