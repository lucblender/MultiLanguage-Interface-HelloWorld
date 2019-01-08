all: run

helloWorld.class: helloWorld.java
	javac helloWorld.java

hello_world: hello_world.c
	gcc -o hello_world \
	-L /usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/jre/lib/arm/server \
	-ljvm \
	-I /usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/include \
	-I /usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/include/linux \
	hello_world.c

run: helloWorld.class hello_world
	export LD_LIBRARY_PATH="/usr/lib/jvm/jdk-8-oracle-arm32-vfp-hflt/jre/lib/arm/server/"
	./hello_world

clean:
	rm -f helloWorld.class hello_world
