miette: main.c
	@echo "you MAKE miette?"
	$(CC) main.c -o miette

clean:
	rm -f miette

.PHONY: clean
