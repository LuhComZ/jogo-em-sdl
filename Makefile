./bin/a.exe: ./obj/game.o ./obj/GameObject.o ./obj/main.o ./obj/map.o ./obj/ObjectManager.o ./obj/Scene.o ./obj/sprite.o ./obj/Vector2D.o
	g++ ./obj/*.o	-o ./bin/a.exe -lSDL2 -lSDL2main -lSDL2_image

./obj/game.o: ./src/game.cpp ./src/game.h
	g++ -c ./src/game.cpp -o ./obj/game.o

./obj/GameObject.o: ./src/GameObject.cpp  ./src/GameObject.h
	g++ -c ./src/GameObject.cpp -o ./obj/GameObject.o

./obj/map.o: ./src/map.cpp  ./src/map.h
	g++ -c ./src/map.cpp -o ./obj/map.o

./obj/main.o: ./src/main.cpp  ./src/GameObject.h
	g++ -c ./src/main.cpp -o ./obj/main.o

./obj/ObjectManager.o: ./src/ObjectManager.cpp  ./src/ObjectManager.h
	g++ -c ./src/ObjectManager.cpp -o ./obj/ObjectManager.o

./obj/Scene.o: ./src/Scene.cpp  ./src/Scene.h
	g++ -c ./src/Scene.cpp -o ./obj/Scene.o

./obj/Vector2D.o: ./src/Vector2D.cpp  ./src/Vector2D.h
	g++ -c ./src/Vector2D.cpp -o ./obj/Vector2D.o

./obj/sprite.o: ./src/sprite.cpp  ./src/sprite.h
	g++ -c ./src/sprite.cpp -o ./obj/sprite.o

clean:
	rm -rf *.o