bsearch: bsearch.c
	gcc -fsanitize=address -g $^ -o $@ -lm -lSDL -lpthread -lSDL_gfx

.PHONY: clean

clean:
	-rm bsearch
