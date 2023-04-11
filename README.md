## C/C++ compilation test
MaximSDK toolchain calls on a number of distributed Makefiles. I've grabbed some of the main dependencies in this repo but to fully build, one would need the MaximSDK downloaded. (https://www.stg-maximintegrated.com/en/design/software-description.html/swpart=SFW0001500A)

Source files are bundled up into Makefile variables in the "Makefile" file and the final compiling/linking steps occur in "gcc.mk" which is imported in the main "Makefile".