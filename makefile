build:
	@echo begin build
	c++ -std=c++11 main.cpp -o ctouch

test:
	@echo -e "\033[31mtest format\033[0m"
	c++ -std=c++11 format_test.cpp -o format_test
	cat format_test.case | ./format_test

	@echo
	@echo -e "\033[31mtest parse file\033[0m"
	c++ -std=c++11 parse_format_file_test.cpp -o parse_format_file_test
	./parse_format_file_test

clean:
	rm -f a.out
	rm -f format_test
	rm -f parse_format_file_test
	rm -f touch
	rm -f ctouch

install:
	cp ctouch /usr/local/bin

install_template:
	rm -rf ~/.touch
	cp -r .touch ~
