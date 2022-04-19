prog:mainfinal.o minimap.o enigme.o integration.o
	gcc mainfinal.o minimap.o integration.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
mainfinal.o:main.c
	gcc -c mainfinal.c -g
minimap.o:minimap.c
	gcc -c minimap.c -g
enigme.o:enigme.c
	gcc -c enigme.c -g
integration.o:integration.c
	gcc -c integration.c -g
all:
	gcc   -c main.c pres.c background.c collisionparfaite.c -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lm; 
	gcc    main.o pres.o background.o collisionparfaite.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lm; 
