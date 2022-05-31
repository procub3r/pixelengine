cc := clang
cflags := -std=c99 -g -Wall -pipe -Ipixel/
libs := `pkg-config --static --libs glew glfw3`

target := bin/main
mkdir = mkdir -p $(@D)

src := $(shell find ./ -type f -name "*.c")
obj := $(addprefix bin/,$(src:.c=.o))

$(target): $(obj)
	$(cc) $(libs) $^ -o $@

bin/%.o: %.c
	$(mkdir)
	$(cc) $(cflags) -c $^ -o $@

.PHONY: run, clean

run: $(target)
	MESA_GL_VERSION_OVERRIDE=3.3 MESA_GLSL_VERSION_OVERRIDE=330 $(target)

clean:
	rm -r bin/
