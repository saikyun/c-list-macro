list: list.h
	cc -Werror list.h -c build/list.o

test-list: list.h
	cc -Werror test-list.c -o build/test-list

run: test-list
	@./build/test-list

clean:
	rm -rf build/*