#Set all the compilation flags
OS := $(shell uname)
ENV_FLAGS=-DDEBUG
CC=g++ -std=c++14 $(ENV_FLAGS)
ENGINE_PATH=AvalonEngine
PLATTFORM_PATH=AvalonPlattform
INCLUDE_ENGINE=-I $(ENGINE_PATH)
BUILD_DIR=Build/$(OS)
LINK_LIBARIES=-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -pthread

output: Main.o Game.o GameState.o Player.o Enemy.o Button.o MenuState.o Math.o PauseState.o \
Bullet.o Healthbar.o MouseCursor.o State.o DesktopAudioPlayer.o NullAudioPlayer.o Locator.o NullFileSystem.o \
DesktopFileSystem.o DesktopLogger.o NullLogger.o PlayerGraphicsComponent.o EnemyGraphicsComponent.o Level.o \
Tutorial.o
	g++ -std=c++14 -DDEBUG  Main.o Game.o GameState.o Player.o Enemy.o Button.o MenuState.o Math.o PauseState.o Bullet.o \
Healthbar.o MouseCursor.o State.o DesktopAudioPlayer.o NullAudioPlayer.o Locator.o NullFileSystem.o DesktopFileSystem.o \
DesktopLogger.o NullLogger.o PlayerGraphicsComponent.o EnemyGraphicsComponent.o Level.o Tutorial.o -o output $(LINK_LIBARIES)
	mkdir -p $(BUILD_DIR)
	mv *.o $(BUILD_DIR)
	mv output $(BUILD_DIR)

Main.o: $(PLATTFORM_PATH)/Main.cpp $(ENGINE_PATH)/States/GameState.hpp
	$(CC) $(INCLUDE_ENGINE) -c $(PLATTFORM_PATH)/Main.cpp

Game.o: $(PLATTFORM_PATH)/Game.cpp $(PLATTFORM_PATH)/Game.hpp
	$(CC) $(INCLUDE_ENGINE) -c $(PLATTFORM_PATH)/Game.cpp 

GameState.o: $(ENGINE_PATH)/States/GameState.cpp $(ENGINE_PATH)/States/GameState.hpp $(ENGINE_PATH)/Generators/EntityGenerator.hpp $(ENGINE_PATH)/EngineUI/MouseCursor.hpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/States/GameState.cpp

Player.o: $(ENGINE_PATH)/Entities/Player.cpp $(ENGINE_PATH)/Entities/Player.hpp $(ENGINE_PATH)/Entities/Entity.hpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/Entities/Player.cpp

Enemy.o: $(ENGINE_PATH)/Entities/Enemy.cpp $(ENGINE_PATH)/Entities/Enemy.hpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/Entities/Enemy.cpp

Bullet.o: $(ENGINE_PATH)/Entities/Bullet.cpp $(ENGINE_PATH)/Entities/Bullet.hpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/Entities/Bullet.cpp

MenuState.o: $(ENGINE_PATH)/States/MenuState.cpp $(ENGINE_PATH)/States/MenuState.hpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/States/MenuState.cpp

Button.o: $(ENGINE_PATH)/EngineUI/Button.cpp $(ENGINE_PATH)/EngineUI/Button.hpp $(ENGINE_PATH)/EngineUI/Utils/Math.hpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/EngineUI/Button.cpp

Math.o: $(ENGINE_PATH)/EngineUI/Utils/Math.cpp $(ENGINE_PATH)/EngineUI/Utils/Math.hpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/EngineUI/Utils/Math.cpp

PauseState.o: $(ENGINE_PATH)/States/PauseState.cpp $(ENGINE_PATH)/States/PauseState.hpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/States/PauseState.cpp

Healthbar.o: $(ENGINE_PATH)/GameUI/Healthbar.cpp $(ENGINE_PATH)/GameUI/Healthbar.hpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/GameUI/Healthbar.cpp

MouseCursor.o: $(ENGINE_PATH)/EngineUI/MouseCursor.cpp $(ENGINE_PATH)/EngineUI/MouseCursor.hpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/EngineUI/MouseCursor.cpp

State.o: $(ENGINE_PATH)/States/State.cpp $(ENGINE_PATH)/States/State.hpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/States/State.cpp

Locator.o: $(ENGINE_PATH)/Locator.hpp $(ENGINE_PATH)/Locator.cpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/Locator.cpp

DesktopAudioPlayer.o: $(ENGINE_PATH)/Audio/DesktopAudioPlayer.hpp $(ENGINE_PATH)/Audio/DesktopAudioPlayer.cpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/Audio/DesktopAudioPlayer.cpp

NullAudioPlayer.o: $(ENGINE_PATH)/Audio/NullAudioPlayer.hpp $(ENGINE_PATH)/Audio/NullAudioPlayer.cpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/Audio/NullAudioPlayer.cpp

DesktopFileSystem.o: $(ENGINE_PATH)/FileSystem/DesktopFileSystem.hpp $(ENGINE_PATH)/FileSystem/DesktopFileSystem.cpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/FileSystem/DesktopFileSystem.cpp

NullFileSystem.o: $(ENGINE_PATH)/FileSystem/NullFileSystem.hpp $(ENGINE_PATH)/FileSystem/NullFileSystem.cpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/FileSystem/NullFileSystem.cpp

DesktopLogger.o: $(ENGINE_PATH)/Logger/DesktopLogger.hpp $(ENGINE_PATH)/Logger/DesktopLogger.cpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/Logger/DesktopLogger.cpp

NullLogger.o: $(ENGINE_PATH)/Logger/NullLogger.hpp $(ENGINE_PATH)/Logger/NullLogger.cpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/Logger/NullLogger.cpp

PlayerGraphicsComponent.o: $(ENGINE_PATH)/Components/Graphics/PlayerGraphicsComponent.hpp $(ENGINE_PATH)/Components/Graphics/PlayerGraphicsComponent.cpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/Components/Graphics/PlayerGraphicsComponent.cpp

EnemyGraphicsComponent.o: $(ENGINE_PATH)/Components/Graphics/EnemyGraphicsComponent.hpp $(ENGINE_PATH)/Components/Graphics/EnemyGraphicsComponent.cpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/Components/Graphics/EnemyGraphicsComponent.cpp

Level.o: $(ENGINE_PATH)/Levels/Level.cpp $(ENGINE_PATH)/Levels/Level.hpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/Levels/Level.cpp

Tutorial.o: $(ENGINE_PATH)/Levels/Tutorial.cpp $(ENGINE_PATH)/Levels/Tutorial.hpp
	$(CC) $(INCLUDE_ENGINE) -c $(ENGINE_PATH)/Levels/Tutorial.cpp

clean:
	rm $(BUILD_DIR)/*.o $(BUILD_DIR)/output *.o
	
run:
	./$(BUILD_DIR)/output | c++filt -t