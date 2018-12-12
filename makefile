build:
	@echo begin build
	clang++ -std=c++11 main.cpp -o touch

test:
	@echo "\033[31mtest format\033[0m"
	clang++ -std=c++11 format_test.cpp -o format_test
	cat format_test.case | ./format_test

	@echo
	@echo "\033[31mtest parse file\033[0m"
	clang++ -std=c++11 parse_format_file_test.cpp -o parse_format_file_test
	./parse_format_file_test

clean:
	rm -f a.out
	rm -f format_test
	rm -f parse_format_file_test

install:
	cp touch /usr/local/bin

install_template:
	rm -rf ~/.touch
	cp -r .touch ~