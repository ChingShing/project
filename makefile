.PHONY: run clean
EXENAME = main test

run:
	make -C src/ all
	./test

clean:
	make -C src/ clean
	-rm -rf $(EXENAME) *.dSYM output/your_vector.txt output/valgrind_test.txt
