#pragma once
#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <ctime>
#include <string>

namespace av
{
	enum typelog {
		DEBUG,
		INFO,
		WARN,
		ERROR
	};

	class Logger
	{
	public:
		Logger() = default;

		explicit Logger(typelog l_type)
		{
			this->msg_level_ = l_type;

			time_t rawtime;
			char time_buffer[80];

			time(&rawtime);
			const auto timeinfo = localtime(&rawtime);
			strftime(time_buffer, 80, "%T", timeinfo);

			operator << ("\n[" + getLevel(this->msg_level_) + "]" + time_buffer + ": ");
		}

		~Logger()
		{
			if (is_open_)
			{
				std::cout << std::endl;
			}
			is_open_ = false;
		}

		void SetLevel(typelog l_level)
		{
			msg_level_ = l_level;
		}

		typelog GetLevel() const
		{
			return msg_level_;
		}

		template<class T>
		Logger &operator<<(const T &l_msg)
		{

			std::cout << l_msg;
			is_open_ = true;

			return  *this;
		}

	private:
		bool is_open_ = false;
		typelog msg_level_;

		static std::string getLevel(const typelog l_type)
		{
			std::string label;
			switch (l_type) {
			case DEBUG: label = "DBG"; break;
			case INFO:  label = "INF"; break;
			case WARN:  label = "WRN"; break;
			case ERROR: label = "ERR"; break;
			}
			return label;
		}
	};

}