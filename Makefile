.PHONY: clean

quicksort: main.c
	cc main.c -o quicksort

clean:
	rm quicksort
