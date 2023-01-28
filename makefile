target = sfml-app
sources = main.cpp
objects = $(patsubst %.cpp, %.o, $(sources)) 
ex_params = -lsfml-graphics -lsfml-window -lsfml-system
all : $(objects)
	@g++ $(objects) -o $(target) ${ex_params}
$(objects) : $(sources)
	@g++ -c $(sources) -o $(objects)

.PHONY : clean
clean :
	@rm -f *.o
