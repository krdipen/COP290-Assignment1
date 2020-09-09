all: object move

object:
	@echo Creating the object file of myPythonInC.c in ./Top/2
	@gcc -I/Library/Frameworks/Python.framework/Versions/3.7/include/python3.7m -c myPythonInC.c

move:
	@echo Moving myPythonInC.o from ./Top/2 to ./Top/obj
	@mv myPythonInC.o ./../obj
