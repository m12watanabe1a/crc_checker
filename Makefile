crc_checker:
	g++ $@.cpp -o $@

run: build
	./a.out

clean:
	a.out
