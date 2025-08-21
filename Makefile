#OBJS specifies which files to compile as part of the project
OBJS = main.cpp game.cpp ball.cpp paddle.cpp input_handler.cpp score.cpp

# Include headers if needed for dependency tracking (optional)
DEPS = config.h game.h ball.h paddle.h input_handler.h score.h

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -Wall -Wextra

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2 -lSDL2_gfx -lSDL2_ttf

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = pong.out

#This is the target that compiles our executable
all : $(OBJ_NAME)

# Link object files to make executable
$(OBJ_NAME): $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $@
	
# Compile each .cpp into .o (object) and track headers
%.o: %.cpp $(DEPS)
	$(CC) -c $< $(COMPILER_FLAGS)

clean:
	rm -f $(OBJ_NAME)
