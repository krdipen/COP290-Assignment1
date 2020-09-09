all: dir1 dir2 dir3 dir4 object move

dir1:
	@echo Invoking Makefile in ./Top/1
	@make --directory=1

dir2:
	@echo Invoking Makefile in ./Top/2
	@make --directory=2

dir3:
	@echo Invoking Makefile in ./Top/3
	@make --directory=3

dir4:
	@echo Invoking Makefile in ./Top/4
	@make --directory=4

object:
	@echo Creating the object file of myApp.c in ./Top 
	@gcc -c myApp.c

move:
	@echo Moving myApp.o from ./Top to ./Top/obj
	@mv myApp.o ./obj

execute:
	@echo Creating the final executable in ./Top
	@gcc ./obj/*.o -o App -L/Library/Frameworks/Python.framework/Versions/3.7/lib -lpython3.7m
	@echo Moving App from ./Top to ./Top/exe
	@mv App ./exe

run:
	@./exe/App

clean:
	@echo Removing all the object files in ./Top/obj
	@rm ./obj/*.o
	@echo Removing the final executable in ./Top/exe
	@rm ./exe/App
