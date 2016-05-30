CC      = x86_64-w64-mingw32-gcc
CFLAGS  = -ISDL2-2.0.4/x86_64-w64-mingw32/include
LDFLAGS = -lmingw32 -lSDL2main -lSDL2 -LSDL2-2.0.4/x86_64-w64-mingw32/lib
PUBLISH =win
ENAME   =main.exe
BDIR   =./

DEPS  = main.o

$(ENAME): $(DEPS)
	$(CC) -o $(BDIR)$(ENAME) $(DEPS) $(CFLAGS) $(LDFLAGS)
	
clean:
	$(RM) $(BDIR)$(ENAME) $(DEPS)
publish:
	make
	mkdir $(PUBLISH)
	cp $(BDIR)$(ENAME) $(DEPS) SDL2-2.0.4/x86_64-w64-mingw32/bin/SDL2.dll $(PUBLISH)
	make clean


